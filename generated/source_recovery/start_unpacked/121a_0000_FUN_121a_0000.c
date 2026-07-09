/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:0000
 * Ghidra name: FUN_121a_0000
 * Linear address: 0x121A0
 * Body addresses: 94
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

char __stdcall16far FUN_121a_0000(undefined4 param_1,char param_2)

{
  undefined2 unaff_SS;
  byte local_f;
  byte local_e;
  char local_c;
  char local_b [9];
  
  FUN_1cc0_09f6(8,local_b,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  local_c = '\0';
  local_e = 0x80;
  local_f = 0;
  while( true ) {
    if (local_b[local_f] == param_2) {
      local_c = local_c + local_e;
    }
    local_e = local_e >> 1;
    if (local_f == 7) break;
    local_f = local_f + 1;
  }
  return local_c;
}


