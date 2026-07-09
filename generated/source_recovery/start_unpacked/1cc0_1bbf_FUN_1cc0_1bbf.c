/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:1bbf
 * Ghidra name: FUN_1cc0_1bbf
 * Linear address: 0x1E7BF
 * Body addresses: 65
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_1bbf(void)

{
  code *pcVar1;
  char cVar2;
  char extraout_DL;
  undefined2 unaff_DS;
  undefined2 local_82;
  char local_80;
  
  FUN_1cc0_1c2a();
  if ((char)local_82 == '\0') {
    return;
  }
  if ((char)((uint)local_82 >> 8) == ':') {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    pcVar1 = (code *)swi(0x21);
    cVar2 = (*pcVar1)();
    if (cVar2 != extraout_DL) {
      *(undefined2 *)0x3dce = 0xf;
      return;
    }
    if (local_80 == '\0') {
      return;
    }
  }
  FUN_1cc0_1c45();
  return;
}


