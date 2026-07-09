/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:0e41
 * Ghidra name: FUN_121a_0e41
 * Linear address: 0x12FE1
 * Body addresses: 141
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

int __stdcall16far FUN_121a_0e41(uint param_1)

{
  undefined2 unaff_DS;
  
  return (param_1 & *(uint *)0x22e9) * 0x4000 + (param_1 & *(uint *)0x22e7) * 0x400 +
         (param_1 & *(uint *)0x22e5) * 0x40 + (param_1 & *(uint *)0x22e3) * 4 +
         ((param_1 & *(uint *)0x22e1) >> 2) + ((param_1 & *(uint *)0x22df) >> 6) +
         ((param_1 & *(uint *)0x22dd) >> 10) + ((param_1 & *(uint *)0x22db) >> 0xe);
}


