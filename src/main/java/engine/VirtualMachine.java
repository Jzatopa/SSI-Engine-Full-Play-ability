package engine;

import static engine.EngineInputAction.CONTINUE_ACTION;
import static engine.EngineInputAction.MENU_HANDLER;
import static engine.EngineInputAction.SELECT_ACTION;
import static engine.EngineInputAction.YES_NO_ACTIONS;
import static engine.script.EclOpCode.CALL;
import static engine.script.EclOpCode.GOSUB;
import static engine.script.EclOpCode.GOTO;
import static io.vavr.API.Seq;
import static io.vavr.collection.Map.entry;
import static shared.MenuType.HORIZONTAL;
import static shared.MenuType.PARTY;
import static shared.MenuType.VERTICAL;

import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.Random;
import java.util.concurrent.ConcurrentLinkedDeque;
import java.util.function.Consumer;
import java.util.function.Function;

import io.vavr.collection.Array;
import io.vavr.collection.HashMap;
import io.vavr.collection.Map;
import io.vavr.collection.Seq;

import common.ByteBufferWrapper;
import data.Resource;
import data.character.AbstractCharacter;
import engine.character.CharacterSheetImpl;
import engine.combat.CombatEncounterFactory;
import engine.combat.CombatUiBridge;
import engine.combat.EclCombatBridge;
import engine.combat.EclCombatBridge.EclCombatResult;
import engine.combat.SsiEclCombatAdapter;
import data.script.EclProgram;
import engine.rulesystem.GameMechanics;
import engine.rulesystem.UnresolvedGameMechanics;
import engine.script.EclArgument;
import engine.script.EclInstruction;
import engine.script.EclOpCode;
import shared.CustomGoldboxString;
import shared.GoldboxString;

public class VirtualMachine {
	private final Map<EclOpCode, Consumer<EclInstruction>> IMPL;

	private EngineCallback engine;

	private VirtualMemory memory;
	private Deque<Integer> gosubStack = new ConcurrentLinkedDeque<>();
	private int compareResult = 0;
	private Random rnd = new Random();
	private Function<Integer, Resource<? extends AbstractCharacter>> characterLoader;
	private Deque<AbstractCharacter> queuedMonsters = new ConcurrentLinkedDeque<>();
	private SsiEclCombatAdapter combatAdapter = new SsiEclCombatAdapter();
	private static final int MAX_QUEUED_MONSTERS = 63;
	private final GameMechanics gameMechanics;

	private int forLoopAddress;
	private int forLoopMax;

	private boolean stopped = true;

	private int eclCodeBaseAddress;
	private ByteBufferWrapper eclCode;
	private EclInstruction onMove;
	private EclInstruction onSearchLocation;
	private EclInstruction onRest;
	private EclInstruction onRestInterruption;
	private EclInstruction onInit;

	public VirtualMachine(EngineCallback engine, VirtualMemory memory, int eclCodeBaseAddress) {
		this(engine, memory, eclCodeBaseAddress, id -> Resource.empty());
	}

	public VirtualMachine(EngineCallback engine, VirtualMemory memory, int eclCodeBaseAddress,
		Function<Integer, Resource<? extends AbstractCharacter>> characterLoader) {
		this(engine, memory, eclCodeBaseAddress, characterLoader, new UnresolvedGameMechanics());
	}

	/**
	 * @param gameMechanics title/ruleset mechanics boundary (see
	 *                      engine.rulesystem.GameMechanics). Defaults to
	 *                      {@link UnresolvedGameMechanics} via the other
	 *                      constructors, which keeps every routed opcode a no-op
	 *                      exactly as before this boundary was wired in.
	 */
	public VirtualMachine(EngineCallback engine, VirtualMemory memory, int eclCodeBaseAddress,
		GameMechanics gameMechanics) {
		this(engine, memory, eclCodeBaseAddress, id -> Resource.empty(), gameMechanics);
	}

	public VirtualMachine(EngineCallback engine, VirtualMemory memory, int eclCodeBaseAddress,
		Function<Integer, Resource<? extends AbstractCharacter>> characterLoader, GameMechanics gameMechanics) {
		this.engine = engine;
		this.memory = memory;
		this.eclCodeBaseAddress = eclCodeBaseAddress;
		this.characterLoader = characterLoader;
		this.gameMechanics = gameMechanics != null ? gameMechanics : new UnresolvedGameMechanics();
		IMPL = initImpl();
	}

	VirtualMemory getMemory() {
		return memory;
	}

	int queuedMonsterCount() {
		return queuedMonsters.size();
	}

	int queueMonsterCopies(int monsterId, int requestedCopies) {
		int copies = requestedCopies <= 0 ? 1 : requestedCopies;
		int available = Math.max(0, MAX_QUEUED_MONSTERS - queuedMonsters.size());
		int copiesToQueue = Math.min(copies, available);
		if (copiesToQueue == 0) return 0;

		final int[] added = { 0 };
		characterLoader.apply(monsterId)
			.ifPresentAndSuccess(monster -> {
				for (int i = 0; i < copiesToQueue; i++) {
					queuedMonsters.add(monster);
					added[0]++;
				}
			})
			.ifFailure(t -> engine.addText(new CustomGoldboxString("MONSTER LOAD FAILED: " + monsterId), true));
		return added[0];
	}

	public void setCombatAdapter(SsiEclCombatAdapter combatAdapter) {
		if (combatAdapter == null) {
			throw new IllegalArgumentException("combatAdapter must not be null");
		}
		this.combatAdapter = combatAdapter;
	}

	public void setCombatUiBridge(CombatUiBridge uiBridge) {
		if (uiBridge == null) {
			throw new IllegalArgumentException("uiBridge must not be null");
		}
		this.combatAdapter = new SsiEclCombatAdapter(new EclCombatBridge(new CombatEncounterFactory(), uiBridge));
	}

	public void newEcl(EclProgram ecl) {
		eclCode = ecl.getCode().duplicate();
		onMove = EclInstruction.parseNext(eclCode);
		onSearchLocation = EclInstruction.parseNext(eclCode);
		onRest = EclInstruction.parseNext(eclCode);
		onRestInterruption = EclInstruction.parseNext(eclCode);
		onInit = EclInstruction.parseNext(eclCode);
		memory.writeProgram(eclCodeBaseAddress, eclCode);

		gosubStack.clear();
		compareResult = 0;
	}

	public void startMove() {
		System.out.println("onMove:");
		startEvent(onMove);
	}

	public void startSearchLocation() {
		System.out.println("onSearchLocation:");
		startEvent(onSearchLocation);
	}

	public void startRest() {
		System.out.println("onRest:");
		startEvent(onRest);
	}

	public void startRestInterruption() {
		System.out.println("onRestInterruption:");
		startEvent(onRestInterruption);
	}

	public void startInit() {
		System.out.println("onInit:");
		startEvent(onInit);
	}

	private void startEvent(EclInstruction eventInst) {
		stopped = false;
		exec(eventInst, true);
		runVM();
	}

	public void startAtAddress(int address) {
		if (eclCode == null) {
			throw new IllegalStateException("No ECL program loaded.");
		}
		int position = address - eclCodeBaseAddress;
		if (position < 0 || position >= eclCode.limit()) {
			throw new IllegalArgumentException("ECL address outside current program: " + Integer.toHexString(address));
		}
		eclCode.position(position);
		stopped = false;
		runVM();
	}

	private void runVM() {
		while (!stopped) {
			exec(EclInstruction.parseNext(eclCode), true);
		}
	}

	public void stopVM() {
		stopped = true;
	}

	private void exec(EclInstruction in, boolean execute) {
		System.out.println(toString(in, execute));
		if (execute) {
			IMPL.get(in.getOpCode()).get().accept(in);
		}
	}

	private String toString(EclInstruction in, boolean execute) {
		EclOpCode op = in.getOpCode();
		StringBuilder sb = new StringBuilder();
		sb.append(String.format("0x%04X", eclCodeBaseAddress + in.getPosition()));
		sb.append(": ");
		if (op.hasDestAddress()) {
			EclArgument arg = in.getArgument(op.getArgIndexDestAddress());
			sb.append(arg.toString());
			sb.append(" = ");
		}
		sb.append(op);
		sb.append("(");
		Seq<String> args = Array.range(0, in.getArguments().length).map(i -> {
			if (op.hasDestAddress() && op.getArgIndexDestAddress() == i)
				return "*";
			final EclArgument arg = in.getArgument(i);
			if (arg.isMemAddress() && op != GOTO && op != GOSUB && op != CALL) {
				if (arg.isStringValue())
					return arg.toString() + "{=" + stringValue(arg) + "}";
				return arg.toString() + "{=" + intValue(arg) + "}";
			}
			return arg.toString();
		});
		sb.append(args.mkString(", "));
		sb.append(")");
		if (in.getOpCode().hasDynArgs()) {
			sb.append(in.getDynArgs().map(EclArgument::toString).mkString("(", ", ", ")"));
		}
		if (!execute)
			sb.append(" (SKIPPED)");
		return sb.toString();
	}

	private void goTo(EclArgument a) {
		if (a.isMemAddress()) {
			eclCode.position(a.valueAsInt() - eclCodeBaseAddress);
		} else {
			System.err.println("GOTO " + a.toString());
		}
	}

	private int intValue(EclArgument a) {
		if (!a.isNumberValue()) {
			return 0;
		}
		return a.isMemAddress() ? memory.readMemInt(a) : a.valueAsInt();
	}

	private GoldboxString stringValue(EclArgument a) {
		if (!a.isStringValue()) {
			return null;
		}
		return a.isMemAddress() ? memory.readMemString(a) : a.valueAsString();
	}

	/** Live party members as the GameMechanics boundary type, for mechanic-stub routing. */
	private List<AbstractCharacter> partyMembers() {
		List<AbstractCharacter> party = new ArrayList<>();
		for (int i = 0; i < memory.getPartyMemberCount(); i++) {
			party.add(memory.getPartyMemberAsCharacterSheet(i).getCharacter());
		}
		return party;
	}

	/** Currently selected/loaded character, or null if none is selected (no bounds crash). */
	private AbstractCharacter selectedCharacter() {
		int index = memory.getLoadedCharacter();
		if (index < 0 || index >= memory.getPartyMemberCount()) {
			return null;
		}
		return memory.getPartyMemberAsCharacterSheet(index).getCharacter();
	}

	/** Resolved integer values of every fixed argument of {@code inst}, for GameMechanics routing. */
	private List<Integer> argValues(EclInstruction inst) {
		List<Integer> values = new ArrayList<>();
		for (EclArgument a : inst.getArguments()) {
			values.add(intValue(a));
		}
		return values;
	}

	private Map<EclOpCode, Consumer<EclInstruction>> initImpl() {
		return HashMap.ofEntries( //
			entry(EclOpCode.EXIT, inst -> {
				stopVM();
			}), //
			entry(EclOpCode.GOTO, inst -> {
				goTo(inst.getArgument(0));
			}), //
			entry(EclOpCode.GOSUB, inst -> {
				gosubStack.push(eclCode.position());
				goTo(inst.getArgument(0));
			}), //
			entry(EclOpCode.COMPARE, inst -> {
				if (inst.getArgument(0).isStringValue() && inst.getArgument(1).isStringValue()) {
					compareResult = stringValue(inst.getArgument(0)).toString()
						.compareTo(stringValue(inst.getArgument(1)).toString());
				} else if (inst.getArgument(0).isNumberValue() && inst.getArgument(1).isNumberValue()) {
					compareResult = intValue(inst.getArgument(0)) - intValue(inst.getArgument(1));
				}
			}), //
			entry(EclOpCode.ADD, inst -> {
				memory.writeMemInt(inst.getArgument(2), intValue(inst.getArgument(0)) + intValue(inst.getArgument(1)));
			}), //
			entry(EclOpCode.SUBTRACT, inst -> {
				memory.writeMemInt(inst.getArgument(2), intValue(inst.getArgument(1)) - intValue(inst.getArgument(0)));
			}), //
			entry(EclOpCode.DIVIDE, inst -> {
				int arg1 = intValue(inst.getArgument(0));
				int arg2 = intValue(inst.getArgument(1));
				memory.writeMemInt(inst.getArgument(2), arg1 / arg2);
				memory.setDivisionModulo(arg1 % arg2);
			}), //
			entry(EclOpCode.MULTIPLY, inst -> {
				memory.writeMemInt(inst.getArgument(2), intValue(inst.getArgument(0)) * intValue(inst.getArgument(1)));
			}), //
			entry(EclOpCode.RANDOM, inst -> {
				memory.writeMemInt(inst.getArgument(1), rnd.nextInt(intValue(inst.getArgument(0)) + 1));
			}), //
			entry(EclOpCode.WRITE_MEM, inst -> {
				if (inst.getArgument(0).isNumberValue()) {
					memory.writeMemInt(inst.getArgument(1), intValue(inst.getArgument(0)));
				}
				if (inst.getArgument(0).isStringValue()) {
					memory.writeMemString(inst.getArgument(1), stringValue(inst.getArgument(0)));
				}
			}), //
			entry(EclOpCode.LOAD_CHAR, inst -> {
				memory.setLoadedCharacter(intValue(inst.getArgument(0)));
			}), //
			entry(EclOpCode.LOAD_MON, inst -> {
				int monsterId = intValue(inst.getArgument(0));
				int copies = intValue(inst.getArgument(1));
				queueMonsterCopies(monsterId, copies);
			}), //
			entry(EclOpCode.SPRITE_START3, inst -> {
				engine.showSprite(intValue(inst.getArgument(0)), intValue(inst.getArgument(1)),
					intValue(inst.getArgument(2)));
				engine.delayCurrentThread();
			}), //
			entry(EclOpCode.SPRITE_START4, inst -> {
				engine.showSprite(intValue(inst.getArgument(0)), intValue(inst.getArgument(1)),
					intValue(inst.getArgument(2)));
				engine.delayCurrentThread();
			}), //
			entry(EclOpCode.SPRITE_ADVANCE, inst -> {
				engine.advanceSprite();
				engine.delayCurrentThread();
			}), //
			entry(EclOpCode.PICTURE, inst -> {
				engine.showPicture(intValue(inst.getArgument(0)));
			}), //
			entry(EclOpCode.INPUT_NUMBER, inst -> {
				engine.setInputNumber(intValue(inst.getArgument(0)));
				int value = Integer.parseUnsignedInt(memory.getInput().toString());
				memory.writeMemInt(inst.getArgument(1), value);
			}), //
			entry(EclOpCode.INPUT_STRING, inst -> {
				engine.setInputString(intValue(inst.getArgument(0)));
				GoldboxString value = memory.getInput();
				memory.writeMemString(inst.getArgument(1), value);
			}), //
			entry(EclOpCode.PRINT, inst -> {
				EclArgument a0 = inst.getArgument(0);
				if (a0.isStringValue())
					engine.addText(stringValue(a0), false);
				else
					engine.addText(new CustomGoldboxString(Integer.toString(intValue(a0))), false);
			}), //
			entry(EclOpCode.PRINT_CLEAR, inst -> {
				EclArgument a0 = inst.getArgument(0);
				if (a0.isStringValue())
					engine.addText(stringValue(a0), true);
				else
					engine.addText(new CustomGoldboxString(Integer.toString(intValue(a0))), true);
			}), //
			entry(EclOpCode.RETURN, inst -> {
				eclCode.position(gosubStack.pop());
			}), //
			entry(EclOpCode.COMPARE_AND, inst -> {
				boolean r1 = intValue(inst.getArgument(0)) == intValue(inst.getArgument(1));
				boolean r2 = intValue(inst.getArgument(2)) == intValue(inst.getArgument(3));
				compareResult = r1 && r2 ? 0 : 1;
			}), //
			entry(EclOpCode.MENU_VERTICAL, inst -> {
				engine.setECLMenu(VERTICAL, //
					inst.getDynArgs().map(EclArgument::valueAsString), //
					stringValue(inst.getArgument(1)));
				memory.writeMemInt(inst.getArgument(0), memory.getMenuChoice());
			}), //
			entry(EclOpCode.IF_EQUALS, inst -> {
				EclInstruction next = EclInstruction.parseNext(eclCode);
				exec(next, compareResult == 0);
			}), //
			entry(EclOpCode.IF_NOT_EQUALS, inst -> {
				EclInstruction next = EclInstruction.parseNext(eclCode);
				exec(next, compareResult != 0);
			}), //
			entry(EclOpCode.IF_LESS, inst -> {
				EclInstruction next = EclInstruction.parseNext(eclCode);
				exec(next, compareResult < 0);
			}), //
			entry(EclOpCode.IF_GREATER, inst -> {
				EclInstruction next = EclInstruction.parseNext(eclCode);
				exec(next, compareResult > 0);
			}), //
			entry(EclOpCode.IF_LESS_EQUALS, inst -> {
				EclInstruction next = EclInstruction.parseNext(eclCode);
				exec(next, compareResult <= 0);
			}), //
			entry(EclOpCode.IF_GREATER_EQUALS, inst -> {
				EclInstruction next = EclInstruction.parseNext(eclCode);
				exec(next, compareResult >= 0);
			}), //
			entry(EclOpCode.CLEAR_MON, inst -> {
				engine.clearSprite();
			}), //
			entry(EclOpCode.INPUT_RETURN_1D, inst -> {
				engine.setMenu(HORIZONTAL, CONTINUE_ACTION, null);
			}), //
			entry(EclOpCode.UNUSED_1F, inst -> {
				// No IMPL entry previously existed for this opcode id/arg-count combination;
				// dispatch fell through to IMPL.get(...).get() and threw NoSuchElementException
				// (live crash risk for Curse/Krynn/Pool profiles that select this form of 0x1F).
				System.err.println("UNUSED_1F dispatched (opcode 0x1F, 0-arg form) — safe no-op.");
			}), //
			entry(EclOpCode.PARTY_STRENGTH, inst -> {
				// Routing only: no confirmed destination argument for this opcode (see
				// docs/coab-java-stub-audit.md). UnresolvedGameMechanics returns empty, so
				// this stays a true no-op until a title mechanics provider is wired in.
				gameMechanics.partyStrength(partyMembers(), intValue(inst.getArgument(0)));
			}), //
			entry(EclOpCode.PARTY_CHECK, inst -> {
				gameMechanics.partyCheck(partyMembers(), argValues(inst));
			}), //
			entry(EclOpCode.JOURNAL_ENTRY, inst -> {
				engine.addText(
					new CustomGoldboxString("THIS IS RECORDED AS JOURNAL ENTRY " + intValue(inst.getArgument(0)) + "."),
					true);
				engine.setMenu(HORIZONTAL, CONTINUE_ACTION, null);
			}), //
			entry(EclOpCode.SPACE_COMBAT, inst -> {

			}), //
			entry(EclOpCode.NEW_ECL, inst -> {
				stopVM();
				engine.loadEcl(intValue(inst.getArgument(0)));
			}), //
			entry(EclOpCode.LOAD_AREA_MAP_DECO, inst -> {
				engine.loadArea(intValue(inst.getArgument(0)), 127, 127);
				engine.loadAreaDecoration(intValue(inst.getArgument(1)), 127, 127);
			}), //
			entry(EclOpCode.LOAD_AREA_MAP, inst -> {
				engine.loadArea(intValue(inst.getArgument(0)), intValue(inst.getArgument(1)),
					intValue(inst.getArgument(2)));
			}), //
			entry(EclOpCode.INPUT_YES_NO_22, inst -> {
				engine.setMenu(HORIZONTAL, YES_NO_ACTIONS, null);
				compareResult = memory.getMenuChoice();
			}), //
			entry(EclOpCode.PARTY_SKILL_CHECK2, inst -> {
				gameMechanics.partySkillCheck(partyMembers(), argValues(inst));
			}), //
			entry(EclOpCode.PARTY_SKILL_CHECK3, inst -> {
				// Was: unconditional memory.writeMemInt(arg2, 100) — a fabricated always-pass
				// (evidence-discipline violation, see docs/coab-java-stub-audit.md and
				// docs/engine-completion-plan-2026-07-09.md section 3). Investigated whether
				// the literal 100 is load-bearing for the Matrix ECL flow exercised by
				// scripts/run-combat-scene.sh (Caloris ECL 17, event 7): that harness never
				// dispatches this opcode, and no test asserts on the written value, so there
				// is no evidence it is load-bearing. Routed through GameMechanics instead;
				// on empty (the UnresolvedGameMechanics default) this is now a true no-op,
				// consistent with every other unresolved mechanic stub in this file.
				gameMechanics
					.partySkillCheck(partyMembers(),
						java.util.List.of(intValue(inst.getArgument(0)), intValue(inst.getArgument(1))))
					.ifPresent(result -> memory.writeMemInt(inst.getArgument(2), result));
			}), //
			entry(EclOpCode.STOP_MOVE_23, inst -> {
				stopVM();
				engine.updatePosition();
				engine.clear();
			}), //
			entry(EclOpCode.SURPRISE, inst -> {
				gameMechanics.surprise(partyMembers(), argValues(inst));
			}), //
			entry(EclOpCode.SKILL_CHECK, inst -> {
				// Destination argument (index 2) is inferred by analogy to the sibling
				// three-argument opcode PARTY_SKILL_CHECK3 (same opcode-id family, same
				// arg shape); not independently confirmed against Matrix ECL evidence.
				AbstractCharacter character = selectedCharacter();
				if (character != null) {
					gameMechanics
						.characterSkillCheck(character,
							java.util.List.of(intValue(inst.getArgument(0)), intValue(inst.getArgument(1))))
						.ifPresent(result -> memory.writeMemInt(inst.getArgument(2), result));
				}
			}), //
			entry(EclOpCode.COMBAT, inst -> {
				List<AbstractCharacter> monsters = new ArrayList<>();
				AbstractCharacter monster;
				while ((monster = queuedMonsters.poll()) != null) {
					monsters.add(monster);
				}
				if (monsters.isEmpty()) {
					engine.addText(new CustomGoldboxString("COMBAT: NO MONSTERS QUEUED."), true);
					memory.setCombatResult(0);
				} else {
					List<CharacterSheetImpl> party = new ArrayList<>();
					for (int i = 0; i < memory.getPartyMemberCount(); i++) {
						party.add(memory.getPartyMemberAsCharacterSheet(i));
					}
					EclCombatResult result = combatAdapter.resolveQueued(monsters, party);
					memory.setCombatResult(result.combatResult());
					System.out.println("COMBAT_RESULT=" + result.combatResult() + " resolver=" + result.resolverName());
					if (!Boolean.getBoolean("matrix.combat.debugAutoContinue")) {
						engine.addText(new CustomGoldboxString(result.transcript()), true);
						engine.setMenu(HORIZONTAL, CONTINUE_ACTION, null);
					}
				}
			}), //
			entry(EclOpCode.ON_GOTO, inst -> {
				if (intValue(inst.getArgument(0)) >= intValue(inst.getArgument(1))
					|| intValue(inst.getArgument(0)) < 0) {
					System.err.println("ON GOTO value=" + intValue(inst.getArgument(0)));
					return;
				}
				goTo(inst.getDynArgs().get(intValue(inst.getArgument(0))));
			}), //
			entry(EclOpCode.ON_GOSUB, inst -> {
				if (intValue(inst.getArgument(0)) >= intValue(inst.getArgument(1))
					|| intValue(inst.getArgument(0)) < 0) {
					System.err.println("ON GOSUB value=" + intValue(inst.getArgument(0)));
					return;
				}
				gosubStack.push(eclCode.position());
				goTo(inst.getDynArgs().get(intValue(inst.getArgument(0))));
			}), //
			entry(EclOpCode.TREASURE, inst -> {
				gameMechanics.treasure(partyMembers(), argValues(inst));
			}), //
			entry(EclOpCode.TREASURE_MULTICOIN, inst -> {
				gameMechanics.treasure(partyMembers(), argValues(inst));
			}), //
			entry(EclOpCode.TREASURE_MULTICOIN4, inst -> {
				gameMechanics.treasure(partyMembers(), argValues(inst));
			}), //
			entry(EclOpCode.ROB, inst -> {
				gameMechanics.rob(partyMembers(), argValues(inst));
			}), //
			entry(EclOpCode.ENCOUNTER_MENU, inst -> {
				// TODO Determine party movement rates
				int pt_move_min = 6, pt_move_max = 12;
				int distance = engine.showSprite(intValue(inst.getArgument(0)), intValue(inst.getArgument(1)),
					intValue(inst.getArgument(2)));

				boolean do_another_round;
				do {
					do_another_round = false;

					GoldboxString desc;
					int index = distance;
					do {
						desc = stringValue(inst.getArgument(9 + index));
						index = (index + 1) % 3;
					} while (desc.getLength() == 0 && index != distance);
					if (desc.getLength() != 0) {
						engine.addText(desc, true);
					}
					engine.setMenu(HORIZONTAL, CONTINUE_ACTION, null);

					engine.setMenu(HORIZONTAL, Seq( //
						new EngineInputAction(MENU_HANDLER, "COMBAT", 0), //
						new EngineInputAction(MENU_HANDLER, "WAIT", 1), //
						new EngineInputAction(MENU_HANDLER, "FLEE", 2), //
						distance != 0 ? //
							new EngineInputAction(MENU_HANDLER, "ADVANCE", 3) : //
							new EngineInputAction(MENU_HANDLER, "PARLAY", 4) //
					), null);

					int enc_move_min = intValue(inst.getArgument(12));
					int enc_move_max = intValue(inst.getArgument(13));
					int choice = memory.getMenuChoice();
					int behaviour = intValue(inst.getArgument(4 + choice));
					switch (behaviour) {
						case 0: // aggressive monsters
							int result0 = choice != 2 || pt_move_min < enc_move_min ? 1 : 2; // Combat or Party flees
							memory.writeMemInt(inst.getArgument(3), result0);
							break;
						case 1: // passive monsters
							if (choice == 0) {
								memory.writeMemInt(inst.getArgument(3), 1); // Combat
							} else if (choice == 1) {
								engine.addText(new CustomGoldboxString("BOTH SIDES WAIT."), true);
								engine.setMenu(HORIZONTAL, CONTINUE_ACTION, null);
								do_another_round = true;
							} else if (choice == 2) {
								memory.writeMemInt(inst.getArgument(3), 2); // Party flees
							} else if (choice == 4) {
								memory.writeMemInt(inst.getArgument(3), 3); // Parlay
							} else if (distance > 0) {
								engine.advanceSprite();
								distance--;
								do_another_round = true;
							} else {
								engine.addText(new CustomGoldboxString("BOTH SIDES WAIT."), true);
								engine.setMenu(HORIZONTAL, CONTINUE_ACTION, null);
								do_another_round = true;
							}
							break;
						case 2: // cowardly monsters
							int result2 = choice == 0 && pt_move_max > enc_move_max ? 1 : 0; // Combat or Monsters flee
							memory.writeMemInt(inst.getArgument(3), result2);
							if (choice != 0 || enc_move_max > pt_move_max) {
								engine.addText(new CustomGoldboxString("THE MONSTERS FLEE."), true);
								engine.setMenu(HORIZONTAL, CONTINUE_ACTION, null);
							}
							break;
						case 3: // cautious monsters
							if (choice == 0) {
								memory.writeMemInt(inst.getArgument(3), 1); // Combat
							} else if (choice == 1) {
								engine.addText(new CustomGoldboxString("BOTH SIDES WAIT."), true);
								engine.setMenu(HORIZONTAL, CONTINUE_ACTION, null);
								do_another_round = true;
							} else if (choice == 2) {
								memory.writeMemInt(inst.getArgument(3), 2); // Party flees
							} else if (distance > 0) {
								engine.advanceSprite();
								distance--;
								do_another_round = true;
							} else {
								memory.writeMemInt(inst.getArgument(3), 3); // Parlay
							}
							break;
						case 4: // confident monsters
							if (choice == 0) {
								memory.writeMemInt(inst.getArgument(3), 1); // Combat
							} else if (choice == 2) {
								memory.writeMemInt(inst.getArgument(3), 2); // Party flees
							} else if (distance > 0) {
								engine.advanceSprite();
								distance--;
								do_another_round = true;
							} else {
								memory.writeMemInt(inst.getArgument(3), 3); // Parlay
							}
							break;
					}
				} while (do_another_round);
			}), //
			entry(EclOpCode.INPUT_RETURN_29, inst -> {
				engine.setMenu(HORIZONTAL, CONTINUE_ACTION, null);
			}), //
			entry(EclOpCode.POD_29, inst -> {

			}), //
			entry(EclOpCode.COPY_MEM, inst -> {
				memory.copyMemInt(inst.getArgument(0), intValue(inst.getArgument(1)), inst.getArgument(2));
			}), //
			entry(EclOpCode.MENU_HORIZONTAL, inst -> {
				if (inst.getDynArgs().size() == 1) {
					engine.setECLMenu(HORIZONTAL, //
						Seq(stringValue(inst.getDynArgs().get(0))), null);
				} else {
					engine.setECLMenu(HORIZONTAL, //
						inst.getDynArgs().map(EclArgument::valueAsString), //
						null);
					memory.writeMemInt(inst.getArgument(0), memory.getMenuChoice());
				}
			}), //
			entry(EclOpCode.PARLAY, inst -> {
				engine.setMenu(HORIZONTAL, Seq( //
					new EngineInputAction(MENU_HANDLER, "HAUGHTY", 0), //
					new EngineInputAction(MENU_HANDLER, "SLY", 1), //
					new EngineInputAction(MENU_HANDLER, "NICE", 2), //
					new EngineInputAction(MENU_HANDLER, "MEEK", 3), //
					new EngineInputAction(MENU_HANDLER, "ABUSIVE", 4) //
				), null);
				memory.writeMemInt(inst.getArgument(5), intValue(inst.getArgument(memory.getMenuChoice())));
			}), //
			entry(EclOpCode.SOUND_EVENT_2C, inst -> {

			}), //
			entry(EclOpCode.INPUT_YES_NO_2C, inst -> {
				engine.setMenu(HORIZONTAL, YES_NO_ACTIONS, null);
				compareResult = memory.getMenuChoice();
			}), //
			entry(EclOpCode.CALL, inst -> {
				switch (inst.getArgument(0).valueAsInt()) {
					case 0x0809: // GttSF
						engine.setMenu(HORIZONTAL, CONTINUE_ACTION, null);
						break;
					case 0x080C: // GttSF
						engine.setMenu(HORIZONTAL, YES_NO_ACTIONS, null);
						compareResult = memory.getMenuChoice() == 0 ? 1 : 0;
						break;
					case 0x0001: // PoD
					case 0x2C90: // PoR
					case 0x2DCB: // BR, SotSB
					case 0x2E10: // CotAB, GttSF
						engine.updatePosition();
						engine.clearSprite();
						break;
					case 0x0002: // PoD
					case 0xC01E: // PoR, CotAB, GttSF
						memory.setDungeonX((memory.getDungeonX() + memory.getDungeonDir().getDeltaX()) & 0xF);
						memory.setDungeonY((memory.getDungeonY() + memory.getDungeonDir().getDeltaY()) & 0xF);
						engine.updatePosition();
						break;
					default:
				}
			}), //
			entry(EclOpCode.DAMAGE, inst -> {
				gameMechanics.damage(partyMembers(), argValues(inst));
			}), //
			entry(EclOpCode.AND, inst -> {
				int result = intValue(inst.getArgument(0)) & intValue(inst.getArgument(1));
				memory.writeMemInt(inst.getArgument(2), result);
				compareResult = result == 0 ? 0 : 1;
			}), //
			entry(EclOpCode.OR, inst -> {
				int result = intValue(inst.getArgument(0)) | intValue(inst.getArgument(1));
				memory.writeMemInt(inst.getArgument(2), result);
				compareResult = result == 0 ? 0 : 1;
			}), //
			entry(EclOpCode.SPRITE_OFF, inst -> {
				engine.clearSprite();
			}), //
			entry(EclOpCode.SELECT_ACTION, inst -> {
				engine.addText(new CustomGoldboxString("WHAT DO YOU DO?"), false);
				engine.setECLMenu(HORIZONTAL, //
					inst.getDynArgs().map(EclArgument::valueAsString), //
					null);
				memory.writeMemInt(inst.getArgument(0), memory.getMenuChoice());
			}), //
			entry(EclOpCode.FIND_ITEM, inst -> {
				gameMechanics.findItem(partyMembers(), intValue(inst.getArgument(0)));
			}), //
			entry(EclOpCode.GTTSF_32, inst -> {

			}), //
			entry(EclOpCode.PRINT_RETURN, inst -> {
				engine.addNewline();
			}), //
			entry(EclOpCode.CLOCK1, inst -> {

			}), //
			entry(EclOpCode.CLOCK2, inst -> {
				memory.stepClock(intValue(inst.getArgument(1)), intValue(inst.getArgument(0)));
			}), //
			entry(EclOpCode.WRITE_MEM_BASE_OFF, inst -> {
				memory.writeMemInt(inst.getArgument(1), intValue(inst.getArgument(2)), intValue(inst.getArgument(0)));
			}), //
			entry(EclOpCode.NPC_ADD, inst -> {
				engine.addNpc(intValue(inst.getArgument(0)));
			}), //
			entry(EclOpCode.NPC_FIND, inst -> {

			}), //
			entry(EclOpCode.LOAD_AREA_DECO, inst -> {
				engine.loadAreaDecoration(intValue(inst.getArgument(0)), intValue(inst.getArgument(1)),
					intValue(inst.getArgument(2)));
			}), //
			entry(EclOpCode.PROGRAM, inst -> {

			}), //
			entry(EclOpCode.WHO, inst -> {
				engine.setMenu(PARTY, SELECT_ACTION, stringValue(inst.getArgument(0)));
			}), //
			entry(EclOpCode.DELAY, inst -> {
				engine.delayCurrentThread();
			}), //
			entry(EclOpCode.SPELL, inst -> {
				AbstractCharacter character = selectedCharacter();
				if (character != null) {
					gameMechanics.castSpell(character, argValues(inst));
				}
			}), //
			entry(EclOpCode.PRINT_RUNES, inst -> {
				engine.addRunicText(memory.readMemString(inst.getArgument(0)));
			}), //
			entry(EclOpCode.COPY_PROTECTION, inst -> {

			}), //
			entry(EclOpCode.STORE, inst -> {

			}), //
			entry(EclOpCode.CLEAR_BOX, inst -> {

			}), //
			entry(EclOpCode.NPC_REMOVE, inst -> {
				engine.removeNpc(memory.getLoadedCharacter());
			}), //
			entry(EclOpCode.HAS_EFFECT, inst -> {
				AbstractCharacter character = selectedCharacter();
				if (character != null) {
					gameMechanics.hasEffect(character, intValue(inst.getArgument(0)));
				}
			}), //
			entry(EclOpCode.LOGBOOK_ENTRY, inst -> {
				engine.addText(new CustomGoldboxString(" AND YOU RECORD "), false);
				engine.addText(stringValue(inst.getArgument(0)), false);
				engine.addText(new CustomGoldboxString(" AS LOGBOOK ENTRY " + intValue(inst.getArgument(1)) + "."),
					false);
				engine.setMenu(HORIZONTAL, CONTINUE_ACTION, null);
			}), //
			entry(EclOpCode.DESTROY_ITEM, inst -> {
				gameMechanics.destroyItem(partyMembers(), intValue(inst.getArgument(0)));
			}), //
			entry(EclOpCode.GTTSF_40, inst -> {

			}), //
			entry(EclOpCode.GIVE_EXP, inst -> {
				gameMechanics.giveExperience(partyMembers(), intValue(inst.getArgument(0)), intValue(inst.getArgument(1)));
			}), //
			entry(EclOpCode.UNUSED_42, inst -> {
				// Same crash risk as UNUSED_1F: no IMPL entry previously existed for this
				// opcode id/arg-count combination.
				System.err.println("UNUSED_42 dispatched (opcode 0x42, 0-arg form) — safe no-op.");
			}), //
			entry(EclOpCode.STOP_MOVE_42, inst -> {
				stopVM();
				engine.updatePosition();
				engine.clear();
			}), //
			entry(EclOpCode.LOAD_AREA_MAP_DECOS, inst -> {
				engine.loadArea(intValue(inst.getArgument(0)), 127, 127);
				engine.loadAreaDecoration(intValue(inst.getArgument(1)), intValue(inst.getArgument(2)),
					intValue(inst.getArgument(3)));
			}), //
			entry(EclOpCode.SOUND_EVENT_43, inst -> {

			}), //
			entry(EclOpCode.UNKNOWN_44, inst -> {

			}), //
			entry(EclOpCode.RANDOM0, inst -> {
				int rndVal = intValue(inst.getArgument(1));
				if (rndVal > 0)
					rndVal = rnd.nextInt(rndVal + 1);
				memory.writeMemInt(inst.getArgument(0), rndVal);
			}), //
			entry(EclOpCode.FOR_START, inst -> {
				memory.setForLoopCount(intValue(inst.getArgument(0)));
				forLoopMax = intValue(inst.getArgument(1));
				forLoopAddress = inst.getPosition() + inst.getSize();
			}), //
			entry(EclOpCode.FOR_REPEAT, inst -> {
				memory.setForLoopCount(memory.getForLoopCount() + 1);
				if (memory.getForLoopCount() <= forLoopMax) {
					eclCode.position(forLoopAddress);
				}
			}), //
			entry(EclOpCode.UNKNOWN_48, inst -> {

			}), //
			entry(EclOpCode.UNKNOWN_49, inst -> {

			}), //
			entry(EclOpCode.UNKNOWN_4A, inst -> {

			}), //
			entry(EclOpCode.UNKNOWN_4B, inst -> {

			}), //
			entry(EclOpCode.PICTURE2, inst -> {
				engine.showPicture(intValue(inst.getArgument(0)), intValue(inst.getArgument(1)));
			}));
	}
}
