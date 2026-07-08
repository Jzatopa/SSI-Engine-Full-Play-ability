package main;

import static io.vavr.API.Seq;

import java.util.function.Consumer;

import character.CharacterGender;
import character.CharacterRace;
import character.ClassSelection;
import common.FileMap;
import data.ContentType;
import data.Resource;
import data.ResourceLoader;
import data.character.AbstractCharacter;
import data.script.EclProgram;
import engine.EngineCallback;
import engine.EngineConfiguration;
import engine.EngineInputAction;
import engine.VirtualMachine;
import engine.VirtualMemory;
import engine.character.CharacterSheetImpl;
import engine.character.PlayerDataFactory;
import engine.rulesystem.Flavor;
import engine.script.EclInstruction;
import io.vavr.collection.Seq;
import shared.CustomGoldboxString;
import shared.GoldboxString;
import shared.InputAction;
import shared.MenuType;

public class MatrixCubedCombatScene {
	private static final String DEFAULT_GAME_DIR = "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX";
	private static final int CALORIS_ECL_ID = 17;
	private static final int CALORIS_EVENT_7_COMBAT_ADDRESS = 0x8C54;

	public static void main(String[] args) throws Exception {
		String gameDir = args.length > 0 ? args[0] : DEFAULT_GAME_DIR;
		Result result = runToCombat(gameDir);
		System.out.println("Final COMBAT_RESULT=" + result.memory().getCombatResult());
	}

	/**
	 * Boots a headless VM against the real Caloris ECL (event 7 / "RETURN THE
	 * INSULT" branch) with an empty party, exactly as the original {@code main}
	 * did before this method was extracted.
	 */
	public static Result runToCombat(String gameDir) throws Exception {
		return runToCombat(gameDir, partyBuilder -> {
		});
	}

	/**
	 * Same headless VM run as {@link #runToCombat(String)}, but lets the caller
	 * populate the party (via {@link PartyBuilder}) before the ECL script is
	 * driven into the COMBAT opcode, so the real ECL/VM combat handoff resolves
	 * against caller-supplied characters instead of the encounter factory's
	 * scaffold default party.
	 */
	public static Result runToCombat(String gameDir, Consumer<PartyBuilder> partySetup) throws Exception {
		FileMap fileMap = new FileMap(gameDir);
		EngineConfiguration cfg = new EngineConfiguration(fileMap);
		EclInstruction.configOpCodes(cfg.getOpCodes());
		AbstractCharacter.configValues(cfg.getCharacterValues());
		ResourceLoader resources = new ResourceLoader(fileMap);
		PlayerDataFactory playerDataFactory = new PlayerDataFactory(resources, cfg);
		VirtualMemory memory = new VirtualMemory(cfg);
		partySetup.accept(new PartyBuilder(playerDataFactory, memory, cfg.getFlavor()));

		HeadlessCallback callback = new HeadlessCallback(memory);
		VirtualMachine vm = new VirtualMachine(callback, memory, cfg.getCodeBase(), playerDataFactory::loadCharacter);

		Resource<EclProgram> eclResource = resources.find(CALORIS_ECL_ID, EclProgram.class, ContentType.ECL);
		if (!eclResource.isPresentAndSuccess()) {
			throw new IllegalStateException("Could not load ECL " + CALORIS_ECL_ID + " from " + gameDir);
		}

		vm.newEcl(eclResource.get());
		callback.printHeader(gameDir);
		vm.startAtAddress(CALORIS_EVENT_7_COMBAT_ADDRESS);
		return new Result(cfg, resources, playerDataFactory, memory, vm);
	}

	/** Live engine objects left over from a {@link #runToCombat} call, for callers that want to inspect state. */
	public static final class Result {
		private final EngineConfiguration config;
		private final ResourceLoader resources;
		private final PlayerDataFactory playerDataFactory;
		private final VirtualMemory memory;
		private final VirtualMachine vm;

		private Result(EngineConfiguration config, ResourceLoader resources, PlayerDataFactory playerDataFactory,
			VirtualMemory memory, VirtualMachine vm) {
			this.config = config;
			this.resources = resources;
			this.playerDataFactory = playerDataFactory;
			this.memory = memory;
			this.vm = vm;
		}

		public EngineConfiguration config() {
			return config;
		}

		public ResourceLoader resources() {
			return resources;
		}

		public PlayerDataFactory playerDataFactory() {
			return playerDataFactory;
		}

		public VirtualMemory memory() {
			return memory;
		}

		public VirtualMachine vm() {
			return vm;
		}
	}

	/** Small helper so callers can add real {@link PlayerDataFactory}-created characters to the VM party before combat. */
	public static final class PartyBuilder {
		private final PlayerDataFactory playerDataFactory;
		private final VirtualMemory memory;
		private final Flavor flavor;

		private PartyBuilder(PlayerDataFactory playerDataFactory, VirtualMemory memory, Flavor flavor) {
			this.playerDataFactory = playerDataFactory;
			this.memory = memory;
			this.flavor = flavor;
		}

		public AbstractCharacter addMember(CharacterRace race, CharacterGender gender, ClassSelection classes, String name) {
			AbstractCharacter character = playerDataFactory.createCharacter(race, gender, classes);
			character.setName(name);
			memory.addPartyMember(new CharacterSheetImpl(flavor, character));
			return character;
		}
	}

	private static final class HeadlessCallback implements EngineCallback {
		private final VirtualMemory memory;

		HeadlessCallback(VirtualMemory memory) {
			this.memory = memory;
		}

		void printHeader(String gameDir) {
			System.out.println("Matrix Cubed Java combat scene harness");
			System.out.println("Game dir: " + gameDir);
			System.out.println("ECL: " + CALORIS_ECL_ID);
			System.out.println("Address: 0x" + Integer.toHexString(CALORIS_EVENT_7_COMBAT_ADDRESS).toUpperCase());
			System.out.println();
		}

		@Override
		public void clear() {
		}

		@Override
		public void setInputNumber(int maxDigits) {
		}

		@Override
		public void setInputString(int maxLetters) {
		}

		@Override
		public void setECLMenu(MenuType type, Seq<GoldboxString> menuItems, GoldboxString description) {
			System.out.println("MENU " + type + ": " + menuItems.mkString(", "));
			for (int i = 0; i < menuItems.size(); i++) {
				if ("RETURN THE INSULT".equals(menuItems.get(i).toString())) {
					memory.setMenuChoice(i);
					System.out.println("CHOICE " + i + ": " + menuItems.get(i));
					return;
				}
			}
			memory.setMenuChoice(0);
		}

		@Override
		public void setMenu(MenuType type, Seq<InputAction> menuItems, GoldboxString description) {
			System.out.println("MENU " + type + ": " + menuItems.map(Object::toString).mkString(", "));
			memory.setMenuChoice(0);
		}

		@Override
		public void advanceSprite() {
			System.out.println("SPRITE ADVANCE");
		}

		@Override
		public void clearSprite() {
			System.out.println("SPRITE CLEAR");
		}

		@Override
		public int showSprite(int spriteId, int index, int picId) {
			System.out.println("SPRITE id=" + spriteId + " index=" + index + " pic=" + picId);
			return index;
		}

		@Override
		public void showPicture(int id) {
			System.out.println("PICTURE " + id);
		}

		@Override
		public void showPicture(int gameState, int id) {
			System.out.println("PICTURE state=" + gameState + " id=" + id);
		}

		@Override
		public void addText(GoldboxString str, boolean clear) {
			if (clear) {
				System.out.println();
			}
			System.out.println(str.toString());
		}

		@Override
		public void addRunicText(GoldboxString str) {
			System.out.println(str.toString());
		}

		@Override
		public void addNewline() {
			System.out.println();
		}

		@Override
		public void loadEcl(int id) {
			System.out.println("LOAD ECL " + id);
		}

		@Override
		public void loadArea(int id1, int id2, int id3) {
			System.out.println("LOAD AREA " + id1 + "," + id2 + "," + id3);
		}

		@Override
		public void loadAreaDecoration(int id1, int id2, int id3) {
			System.out.println("LOAD AREA DECO " + id1 + "," + id2 + "," + id3);
		}

		@Override
		public void updatePosition() {
		}

		@Override
		public void delayCurrentThread() {
		}

		@Override
		public void addNpc(int id) {
			System.out.println("ADD NPC " + id);
		}

		@Override
		public void removeNpc(int index) {
			System.out.println("REMOVE NPC " + index);
		}
	}
}
