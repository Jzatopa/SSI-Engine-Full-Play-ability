// Export deeper Ghidra analysis for Matrix Cubed binaries.
// @category MatrixCubed

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.data.DataType;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.util.exception.CancelledException;

public class DumpDeepProgramSummary extends GhidraScript {
    @Override
    protected void run() throws Exception {
        if (currentProgram == null) {
            println("No current program");
            return;
        }

        String outDirPath = getScriptArgs().length > 0 ? getScriptArgs()[0] : "generated/ghidra/deep";
        int maxDecompiled = getScriptArgs().length > 1 ? Integer.parseInt(getScriptArgs()[1]) : 120;
        File outDir = new File(outDirPath);
        File decompiledDir = new File(outDir, "decompiled");
        decompiledDir.mkdirs();

        writeProgramSummary(new File(outDir, "program_summary.md"));
        writeFunctions(new File(outDir, "functions.tsv"));
        writeStrings(new File(outDir, "strings.tsv"));
        writeDecompilerOutput(decompiledDir, new File(outDir, "decompile_summary.tsv"), maxDecompiled);
        println("Wrote deep Ghidra summary to " + outDir.getAbsolutePath());
    }

    private void writeProgramSummary(File path) throws Exception {
        path.getParentFile().mkdirs();
        try (PrintWriter out = new PrintWriter(new FileWriter(path))) {
            out.println("# Ghidra Deep Program Summary");
            out.println();
            out.println("- Program: `" + currentProgram.getName() + "`");
            out.println("- Executable path: `" + currentProgram.getExecutablePath() + "`");
            out.println("- Executable MD5: `" + currentProgram.getExecutableMD5() + "`");
            out.println("- Language: `" + currentProgram.getLanguageID() + "`");
            out.println("- Compiler spec: `" + currentProgram.getCompilerSpec().getCompilerSpecID() + "`");
            out.println("- Image base: `" + currentProgram.getImageBase() + "`");
            out.println("- Min address: `" + currentProgram.getMinAddress() + "`");
            out.println("- Max address: `" + currentProgram.getMaxAddress() + "`");
            out.println();
            out.println("## Memory Blocks");
            out.println();
            for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
                out.println("- `" + block.getName() + "` start `" + block.getStart() + "` end `" + block.getEnd()
                        + "` size `" + block.getSize() + "` execute `" + block.isExecute()
                        + "` write `" + block.isWrite() + "` initialized `" + block.isInitialized() + "`");
            }
            out.println();
            out.println("## Counts");
            out.println();
            out.println("- Functions: `" + countFunctions() + "`");
            out.println("- Defined strings: `" + countStrings() + "`");
        }
    }

    private void writeFunctions(File path) throws Exception {
        path.getParentFile().mkdirs();
        try (PrintWriter out = new PrintWriter(new FileWriter(path))) {
            out.println("entry\tname\tbody_addresses\tentry_block\tis_thunk\tcalling_convention");
            for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
                monitor.checkCancelled();
                AddressSetView body = function.getBody();
                out.println(function.getEntryPoint() + "\t" + clean(function.getName()) + "\t"
                        + body.getNumAddresses() + "\t" + clean(blockName(function)) + "\t"
                        + function.isThunk() + "\t" + clean(function.getCallingConventionName()));
            }
        }
    }

    private void writeStrings(File path) throws Exception {
        path.getParentFile().mkdirs();
        try (PrintWriter out = new PrintWriter(new FileWriter(path))) {
            out.println("address\tdata_type\tlength\ttext");
            for (Data data : currentProgram.getListing().getDefinedData(true)) {
                monitor.checkCancelled();
                if (!isString(data)) {
                    continue;
                }
                Object value = data.getValue();
                String text = value == null ? "" : value.toString();
                out.println(data.getAddress() + "\t" + clean(data.getDataType().getName()) + "\t"
                        + data.getLength() + "\t" + clean(text));
            }
        }
    }

    private void writeDecompilerOutput(File outDir, File summaryPath, int maxDecompiled) throws Exception {
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        try (PrintWriter summary = new PrintWriter(new FileWriter(summaryPath))) {
            summary.println("entry\tname\tcompleted\ttimed_out\terror\toutput_file");
            int count = 0;
            for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
                monitor.checkCancelled();
                if (count >= maxDecompiled) {
                    break;
                }
                count++;
                String safeName = safeFileName(function.getEntryPoint() + "_" + function.getName() + ".c");
                File outFile = new File(outDir, safeName);
                DecompileResults results = decompiler.decompileFunction(function, 30, monitor);
                boolean completed = results.decompileCompleted();
                String error = results.getErrorMessage();
                if (completed && results.getDecompiledFunction() != null) {
                    try (PrintWriter out = new PrintWriter(new FileWriter(outFile))) {
                        out.println(results.getDecompiledFunction().getC());
                    }
                }
                summary.println(function.getEntryPoint() + "\t" + clean(function.getName()) + "\t"
                        + completed + "\t" + results.isTimedOut() + "\t" + clean(error) + "\t"
                        + (completed ? clean(outFile.getPath()) : ""));
            }
        } finally {
            decompiler.dispose();
        }
    }

    private int countFunctions() {
        int count = 0;
        for (Function ignored : currentProgram.getFunctionManager().getFunctions(true)) {
            count++;
        }
        return count;
    }

    private int countStrings() throws CancelledException {
        int count = 0;
        for (Data data : currentProgram.getListing().getDefinedData(true)) {
            monitor.checkCancelled();
            if (isString(data)) {
                count++;
            }
        }
        return count;
    }

    private String blockName(Function function) {
        MemoryBlock block = currentProgram.getMemory().getBlock(function.getEntryPoint());
        return block == null ? "" : block.getName();
    }

    private boolean isString(Data data) {
        DataType type = data.getDataType();
        String name = type == null ? "" : type.getName().toLowerCase();
        return name.contains("string");
    }

    private String clean(String value) {
        if (value == null) {
            return "";
        }
        return value.replace("\t", " ").replace("\r", "\\r").replace("\n", "\\n");
    }

    private String safeFileName(String value) {
        return value.replaceAll("[^A-Za-z0-9._-]", "_");
    }
}
