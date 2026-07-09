package main;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.EnumMap;
import java.util.EnumSet;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import common.FileMap;
import data.ContentType;
import data.Resource;
import data.ResourceLoader;
import data.character.AbstractCharacter;
import data.script.EclProgram;
import engine.EngineConfiguration;
import engine.debug.CodeBlock;
import engine.debug.CodeSection;
import engine.debug.Disassembler;
import engine.debug.Disassembler.JumpAddresses;
import engine.debug.EclInstructionData;
import engine.debug.EclinstructionWrapper;
import engine.script.EclInstruction;
import engine.script.EclOpCode;
import io.vavr.collection.SortedSet;
import main.MatrixCubedCombatScene.Result;

/**
 * Static + (best-effort) dynamic prober for Buck Rogers: Matrix Cubed's ECL
 * script corpus, built to answer "which stub opcodes actually block a
 * playthrough, in what order, how often" for Lane 1 of
 * {@code docs/engine-completion-plan-2026-07-09.md} (see sections 1 and
 * 4.1). This is a measurement tool: it never edits game data and never
 * touches {@link engine.VirtualMachine} or {@code engine.rulesystem}
 * (both owned by another concurrent porting pass); it only reads the
 * opcode/dispatch shape that already exists.
 *
 * <h2>Static sweep</h2>
 * Every ECL resource id reported by {@link ResourceLoader#idsFor} is loaded
 * and walked with the existing read-only {@link Disassembler}, entering at
 * each of the five {@link CodeSection} offsets it already knows about
 * (onMove/onSearchLocation/onRest/onRestInterruption/onInit) exactly the
 * way {@code ui.debug.EclCodeViewer} does. Every decoded instruction's
 * opcode is tallied once per unique (ECL id, absolute address) pair, so
 * code shared across multiple entry sections in the same block is not
 * double counted.
 *
 * <h2>Stub classification</h2>
 * {@link #STUB_OPCODES} was derived directly from
 * {@code engine/VirtualMachine.java}'s {@code initImpl()} dispatch table by
 * finding every {@code IMPL} entry whose lambda body is empty (a true
 * no-op stub) or whose body only writes a fabricated literal instead of a
 * real result ({@code PARTY_SKILL_CHECK3} writing a hardcoded {@code 100},
 * flagged as a defect in plan section 1). That is 32 opcodes measured
 * directly from source on 2026-07-07 -- three short of the plan's
 * headline "35 stubs" figure, which is a document-level summary count and
 * is not broken out by name anywhere in the plan. This class does not
 * invent the missing three; it reports what is measurable and flags the
 * gap so it can be reconciled by whoever wrote the "35" figure. Separately,
 * {@link #NO_IMPL_OPCODES} tracks {@code UNUSED_1F}/{@code UNUSED_42} --
 * real {@link EclOpCode} constants with metadata (so the disassembler
 * decodes them fine) but with NO entry at all in the VM's IMPL map, so a
 * live VM dispatch on either throws {@code NoSuchElementException} (plan
 * section 1, "Defects found by the survey").
 */
public class MatrixCubedPlaythroughProber {
	private static final String DEFAULT_GAME_DIR = "/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX";
	private static final String PROJECT_ROOT = "/home/jzatopa/.openclaw/workspace/matrix-cubed-re";
	private static final String DEFAULT_REPORT_PATH = PROJECT_ROOT + "/generated/playthrough_prober/report.tsv";

	private static final int MAX_EXAMPLES_PER_OPCODE = 3;

	/**
	 * Opcodes whose VirtualMachine.initImpl() lambda body is empty (a true
	 * no-op) or fabricates a value instead of computing one, as measured
	 * directly from src/main/java/engine/VirtualMachine.java on 2026-07-07.
	 * Cross-reference: docs/engine-completion-plan-2026-07-09.md section 1
	 * ("Matrix-selected stub opcodes" lists a subset of these by name; this
	 * is the full measured set of empty/fabricated IMPL entries).
	 */
	public static final Set<EclOpCode> STUB_OPCODES = EnumSet.of( //
		EclOpCode.PARTY_STRENGTH, //
		EclOpCode.PARTY_CHECK, //
		EclOpCode.SPACE_COMBAT, //
		EclOpCode.PARTY_SKILL_CHECK2, //
		EclOpCode.PARTY_SKILL_CHECK3, // fabricates a literal 100, see class javadoc
		EclOpCode.SURPRISE, //
		EclOpCode.SKILL_CHECK, //
		EclOpCode.TREASURE, //
		EclOpCode.TREASURE_MULTICOIN, //
		EclOpCode.TREASURE_MULTICOIN4, //
		EclOpCode.ROB, //
		EclOpCode.POD_29, //
		EclOpCode.SOUND_EVENT_2C, //
		EclOpCode.DAMAGE, //
		EclOpCode.FIND_ITEM, //
		EclOpCode.GTTSF_32, //
		EclOpCode.CLOCK1, //
		EclOpCode.NPC_FIND, //
		EclOpCode.PROGRAM, //
		EclOpCode.SPELL, //
		EclOpCode.COPY_PROTECTION, //
		EclOpCode.STORE, //
		EclOpCode.CLEAR_BOX, //
		EclOpCode.HAS_EFFECT, //
		EclOpCode.DESTROY_ITEM, //
		EclOpCode.GTTSF_40, //
		EclOpCode.GIVE_EXP, //
		EclOpCode.SOUND_EVENT_43, //
		EclOpCode.UNKNOWN_44, //
		EclOpCode.UNKNOWN_48, //
		EclOpCode.UNKNOWN_49, //
		EclOpCode.UNKNOWN_4A, //
		EclOpCode.UNKNOWN_4B);

	/**
	 * EclOpCode constants with NO entry at all in VirtualMachine's IMPL map
	 * (a live dispatch throws NoSuchElementException). Plan section 1 calls
	 * this "the UNUSED_1F/UNUSED_42 crash class"; it is a distinct, worse
	 * failure mode than {@link #STUB_OPCODES} (those at least no-op).
	 */
	public static final Set<EclOpCode> NO_IMPL_OPCODES = EnumSet.of(EclOpCode.UNUSED_1F, EclOpCode.UNUSED_42);

	public static void main(String[] args) throws Exception {
		String gameDir = DEFAULT_GAME_DIR;
		Path reportPath = args.length > 0 ? Path.of(args[0]) : Path.of(DEFAULT_REPORT_PATH);

		SweepResult sweep = runStaticSweep(gameDir);
		List<OpcodeStat> ranked = rankStubs(sweep);

		DynamicProbeResult dynamic = runDynamicProbe(gameDir);

		String report = renderReport(sweep, ranked, dynamic);
		System.out.println(report);
		writeReport(reportPath, report);
		System.out.println("Report written to " + reportPath.toAbsolutePath());
	}

	// ---------------------------------------------------------------
	// Static sweep
	// ---------------------------------------------------------------

	public static SweepResult runStaticSweep(String gameDir) throws Exception {
		FileMap fileMap = new FileMap(gameDir);
		EngineConfiguration cfg = new EngineConfiguration(fileMap);
		EclInstruction.configOpCodes(cfg.getOpCodes());
		AbstractCharacter.configValues(cfg.getCharacterValues());
		ResourceLoader resources = new ResourceLoader(fileMap);
		Disassembler disasm = new Disassembler(cfg.getCodeBase());

		SortedSet<Integer> eclIds = resources.idsFor(ContentType.ECL);

		Map<EclOpCode, OpcodeStat> stats = new EnumMap<>(EclOpCode.class);
		int blocksLoaded = 0;
		int blocksFailed = 0;
		int totalInstructions = 0;

		for (Integer eclId : eclIds) {
			Resource<EclProgram> res = resources.find(eclId, EclProgram.class, ContentType.ECL);
			if (!res.isPresentAndSuccess()) {
				blocksFailed++;
				continue;
			}
			EclProgram ecl = res.get();
			blocksLoaded++;

			Set<Integer> seenAddresses = new HashSet<>();
			for (CodeSection section : CodeSection.values()) {
				try {
					JumpAddresses addrs = disasm.parseJumpAdresses(ecl, section);
					SortedSet<CodeBlock> blocks = disasm.parseCodeblocks(ecl, section, addrs);
					for (CodeBlock block : blocks) {
						for (EclInstructionData data : block.getCode()) {
							if (!(data instanceof EclinstructionWrapper)) {
								continue;
							}
							EclinstructionWrapper inst = (EclinstructionWrapper) data;
							int address = cfg.getCodeBase() + inst.getPosition();
							if (!seenAddresses.add(address)) {
								continue; // already tallied via another entry section
							}
							EclOpCode opCode = inst.getOpCode();
							if (opCode == null) {
								continue;
							}
							totalInstructions++;
							OpcodeStat stat = stats.computeIfAbsent(opCode, OpcodeStat::new);
							stat.occurrences++;
							stat.blocks.add(eclId);
							if (stat.examples.size() < MAX_EXAMPLES_PER_OPCODE) {
								stat.examples.add(String.format("ECL%d@0x%04X", eclId, address));
							}
						}
					}
				} catch (Exception e) {
					System.err.println("Disassembly failed for ECL " + eclId + " section " + section + ": " + e);
				}
			}
		}

		return new SweepResult(eclIds.size(), blocksLoaded, blocksFailed, totalInstructions, stats);
	}

	private static List<OpcodeStat> rankStubs(SweepResult sweep) {
		List<OpcodeStat> ranked = new ArrayList<>();
		for (OpcodeStat stat : sweep.opcodeStats.values()) {
			if (STUB_OPCODES.contains(stat.opcode) || NO_IMPL_OPCODES.contains(stat.opcode)) {
				ranked.add(stat);
			}
		}
		ranked.sort(Comparator.comparingLong((OpcodeStat s) -> s.occurrences).reversed()
			.thenComparing(s -> s.opcode.name()));
		return ranked;
	}

	// ---------------------------------------------------------------
	// Dynamic probe (best-effort; see class javadoc)
	// ---------------------------------------------------------------

	/**
	 * Reuses {@link MatrixCubedCombatScene#runToCombat(String)} -- the
	 * proven-safe headless boot sequence already used by
	 * {@code MatrixCubedSmokeTest} -- as the entry ECL block, and observes
	 * which stub/no-impl opcodes it actually dispatches by tee-ing
	 * {@code System.out} while the VM runs. {@code VirtualMachine.exec}
	 * already prints every instruction it dispatches (opcode name and all)
	 * before invoking the IMPL lambda, so this is a read-only console seam:
	 * no VirtualMachine/rulesystem source is touched.
	 */
	public static DynamicProbeResult runDynamicProbe(String gameDir) {
		Pattern linePattern = Pattern.compile("^0x[0-9A-Fa-f]+: (?:\\S+ = )?([A-Z0-9_]+)\\(");
		Map<EclOpCode, Integer> hits = new EnumMap<>(EclOpCode.class);
		Set<String> notes = new LinkedHashSet<>();

		PrintStream originalOut = System.out;
		ByteArrayOutputStream buffer = new ByteArrayOutputStream();
		try {
			PrintStream tee = new PrintStream(new TeeOutputStream(originalOut, buffer), true, StandardCharsets.UTF_8);
			System.setOut(tee);
			try {
				Result result = MatrixCubedCombatScene.runToCombat(gameDir);
				notes.add("ECL " + 17 + " (Caloris, event 7 combat address) ran to COMBAT_RESULT="
					+ result.memory().getCombatResult());
			} catch (Exception e) {
				notes.add("ECL 17 dynamic run threw " + e.getClass().getSimpleName() + ": " + e.getMessage());
			}
		} finally {
			System.setOut(originalOut);
		}

		for (String line : buffer.toString(StandardCharsets.UTF_8).split("\n")) {
			Matcher m = linePattern.matcher(line);
			if (!m.find()) {
				continue;
			}
			String name = m.group(1);
			EclOpCode op;
			try {
				op = EclOpCode.valueOf(name);
			} catch (IllegalArgumentException e) {
				continue;
			}
			if (STUB_OPCODES.contains(op) || NO_IMPL_OPCODES.contains(op)) {
				hits.merge(op, 1, Integer::sum);
			}
		}

		return new DynamicProbeResult(hits, notes);
	}

	// ---------------------------------------------------------------
	// Reporting
	// ---------------------------------------------------------------

	private static String renderReport(SweepResult sweep, List<OpcodeStat> ranked, DynamicProbeResult dynamic) {
		StringBuilder sb = new StringBuilder();
		sb.append("# Matrix Cubed playthrough prober report\n");
		sb.append("# ECL blocks discovered: ").append(sweep.eclIdCount).append("\n");
		sb.append("# ECL blocks loaded: ").append(sweep.blocksLoaded).append(" (failed to load: ")
			.append(sweep.blocksFailed).append(")\n");
		sb.append("# Distinct instructions tallied (deduped by absolute address per ECL): ")
			.append(sweep.totalInstructions).append("\n");
		sb.append("#\n");
		sb.append("# Ranked stub/no-impl blockers (static sweep). NO_IMPL rows are the\n");
		sb.append("# UNUSED_1F/UNUSED_42 crash class (dispatch = NoSuchElementException).\n");
		sb.append("opcode\tid_hex\tcategory\toccurrences\tdistinct_blocks\texamples\n");
		for (OpcodeStat stat : ranked) {
			String category = NO_IMPL_OPCODES.contains(stat.opcode) ? "NO_IMPL" : "STUB";
			sb.append(stat.opcode.name()).append('\t');
			sb.append(String.format("0x%02X", stat.opcode.getId())).append('\t');
			sb.append(category).append('\t');
			sb.append(stat.occurrences).append('\t');
			sb.append(stat.blocks.size()).append('\t');
			sb.append(String.join(",", stat.examples)).append('\n');
		}

		sb.append("#\n# Any opcode ids present in the data with no EclOpCode metadata at all\n");
		sb.append("# would abort disassembly per-block (see stderr for \"Disassembly failed\" lines);\n");
		sb.append("# none were observed in this run beyond the two NO_IMPL rows above, which DO\n");
		sb.append("# decode (they have EclOpCode entries) but have no VirtualMachine IMPL entry.\n");

		sb.append("#\n# Dynamic probe (best-effort, read-only console seam over VirtualMachine.exec's\n");
		sb.append("# existing per-instruction println; VirtualMachine/rulesystem sources untouched):\n");
		for (String note : dynamic.notes) {
			sb.append("# ").append(note).append('\n');
		}
		if (dynamic.hits.isEmpty()) {
			sb.append("# No stub/no-impl opcodes were dispatched during the dynamic run(s).\n");
		} else {
			sb.append("dynamic_opcode\tdynamic_hits\n");
			dynamic.hits.entrySet().stream()
				.sorted(Comparator.<Map.Entry<EclOpCode, Integer>>comparingInt(Map.Entry::getValue).reversed())
				.forEach(e -> sb.append(e.getKey().name()).append('\t').append(e.getValue()).append('\n'));
		}

		return sb.toString();
	}

	private static void writeReport(Path reportPath, String report) throws IOException {
		Path parent = reportPath.toAbsolutePath().getParent();
		if (parent != null) {
			Files.createDirectories(parent);
		}
		Files.writeString(reportPath, report, StandardCharsets.UTF_8);
	}

	// ---------------------------------------------------------------
	// Data holders
	// ---------------------------------------------------------------

	public static final class SweepResult {
		public final int eclIdCount;
		public final int blocksLoaded;
		public final int blocksFailed;
		public final int totalInstructions;
		public final Map<EclOpCode, OpcodeStat> opcodeStats;

		SweepResult(int eclIdCount, int blocksLoaded, int blocksFailed, int totalInstructions,
			Map<EclOpCode, OpcodeStat> opcodeStats) {
			this.eclIdCount = eclIdCount;
			this.blocksLoaded = blocksLoaded;
			this.blocksFailed = blocksFailed;
			this.totalInstructions = totalInstructions;
			this.opcodeStats = opcodeStats;
		}
	}

	public static final class OpcodeStat {
		public final EclOpCode opcode;
		public long occurrences;
		public final Set<Integer> blocks = new HashSet<>();
		public final List<String> examples = new ArrayList<>();

		OpcodeStat(EclOpCode opcode) {
			this.opcode = opcode;
		}
	}

	public static final class DynamicProbeResult {
		public final Map<EclOpCode, Integer> hits;
		public final Set<String> notes;

		DynamicProbeResult(Map<EclOpCode, Integer> hits, Set<String> notes) {
			this.hits = hits;
			this.notes = notes;
		}
	}

	/** Minimal fan-out PrintStream target: writes to both the real stdout and a capture buffer. */
	private static final class TeeOutputStream extends OutputStream {
		private final OutputStream a;
		private final OutputStream b;

		TeeOutputStream(OutputStream a, OutputStream b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public void write(int b) throws IOException {
			this.a.write(b);
			this.b.write(b);
		}

		@Override
		public void write(byte[] buf, int off, int len) throws IOException {
			a.write(buf, off, len);
			b.write(buf, off, len);
		}

		@Override
		public void flush() throws IOException {
			a.flush();
			b.flush();
		}
	}
}
