/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 19e3:12c9
 * Ghidra name: FUN_19e3_12c9
 * Linear address: 0x1B0F9
 * Body addresses: 57
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined2 __cdecl16far FUN_19e3_12c9(void)

{
  code *pcVar1;
  undefined1 uVar2;
  uint uVar3;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  out(0x40,0xff);
  out(0x40,0xff);
  uVar2 = in(0x61);
  uVar3 = CONCAT11(0xff,uVar2) & 0xfffc;
  out(0x61,(char)uVar3);
  out(0xc0,0x9f);
  out(0xc0,0xbf);
  out(0xc0,0xdf);
  out(0xc0,0xff);
  return CONCAT11((char)(uVar3 >> 8),0xff);
}


