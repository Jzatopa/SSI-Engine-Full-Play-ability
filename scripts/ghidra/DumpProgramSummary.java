// Dump basic Ghidra analysis results for a program.
// @category MatrixCubed

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.data.DataType;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.util.exception.CancelledException;

public class DumpProgramSummary extends GhidraScript {
    @Override
    protected void run() throws Exception {
        if (currentProgram == null) {
            println("No current program");
            return;
        }
        String outPath = getScriptArgs().length > 0 ? getScriptArgs()[0] : "ghidra_program_summary.md";
        File outFile = new File(outPath);
        File parent = outFile.getParentFile();
        if (parent != null) {
            parent.mkdirs();
        }

        try (PrintWriter out = new PrintWriter(new FileWriter(outFile))) {
            writeHeader(out);
            writeMemoryBlocks(out);
            writeFunctions(out);
            writeStrings(out);
        }
        println("Wrote " + outFile.getAbsolutePath());
    }

    private void writeHeader(PrintWriter out) {
        out.println("# Ghidra Program Summary");
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
    }

    private void writeMemoryBlocks(PrintWriter out) {
        out.println("## Memory Blocks");
        out.println();
        for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
            out.println("- `" + block.getName() + "` start `" + block.getStart() + "` end `" + block.getEnd()
                    + "` size `" + block.getSize() + "` execute `" + block.isExecute()
                    + "` write `" + block.isWrite() + "`");
        }
        out.println();
    }

    private void writeFunctions(PrintWriter out) {
        int count = 0;
        for (Function ignored : currentProgram.getFunctionManager().getFunctions(true)) {
            count++;
        }

        out.println("## Functions");
        out.println();
        out.println("Total functions: " + count);
        out.println();
        int shown = 0;
        for (Function function : currentProgram.getFunctionManager().getFunctions(true)) {
            if (shown >= 200) {
                break;
            }
            AddressSetView body = function.getBody();
            out.println("- `" + function.getEntryPoint() + "` `" + function.getName()
                    + "` body `" + body.getNumAddresses() + "`");
            shown++;
        }
        out.println();
    }

    private void writeStrings(PrintWriter out) throws CancelledException {
        out.println("## Defined Strings");
        out.println();
        int count = 0;
        for (Data data : currentProgram.getListing().getDefinedData(true)) {
            monitor.checkCancelled();
            if (isString(data)) {
                count++;
            }
        }
        out.println("Total defined strings: " + count);
        out.println();
        int shown = 0;
        for (Data data : currentProgram.getListing().getDefinedData(true)) {
            monitor.checkCancelled();
            if (!isString(data)) {
                continue;
            }
            if (shown >= 200) {
                break;
            }
            Object value = data.getValue();
            String text = value == null ? "" : value.toString().replace("\n", "\\n").replace("\r", "\\r");
            out.println("- `" + data.getAddress() + "` `" + text + "`");
            shown++;
        }
        out.println();
    }

    private boolean isString(Data data) {
        DataType type = data.getDataType();
        String name = type == null ? "" : type.getName().toLowerCase();
        return name.contains("string");
    }
}
