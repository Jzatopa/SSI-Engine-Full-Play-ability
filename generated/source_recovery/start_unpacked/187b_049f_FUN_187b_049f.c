/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:049f
 * Ghidra name: FUN_187b_049f
 * Linear address: 0x18C4F
 * Body addresses: 228
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Removing unreachable block (ram,0x00018ca1) */
/* WARNING: Removing unreachable block (ram,0x00018ca6) */

undefined1 __stdcall16far FUN_187b_049f(undefined4 param_1)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar3;
  undefined1 local_103 [256];
  undefined1 local_3;
  
  FUN_1cc0_0adc(0xff,local_103,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  local_3 = 0;
  *(undefined2 *)0x9ee8 = 0;
  cVar1 = FUN_187b_0132(local_103,unaff_SS);
  if (cVar1 != '\0') {
    FUN_187b_1543();
    uVar2 = FUN_187b_155c(*(undefined2 *)0x9ede,*(undefined2 *)0x9ee0);
    *(undefined2 *)0x9eea = uVar2;
    uVar3 = FUN_187b_1570(*(undefined2 *)0x9eea);
    *(undefined2 *)0x9eec = (int)uVar3;
    *(undefined2 *)0x9eee = (int)((ulong)uVar3 >> 0x10);
    if (*(int *)((int)*(undefined4 *)0x9eec + 2) == 3) {
      cVar1 = FUN_187b_1581(*(undefined2 *)((int)*(undefined4 *)0x9eec + 0x12),
                            *(undefined2 *)((int)*(undefined4 *)0x9eec + 0x10),
                            *(undefined2 *)((int)*(undefined4 *)0x9eec + 0xe),
                            *(undefined2 *)((int)*(undefined4 *)0x9eec + 0xc),*(undefined2 *)0x9eea)
      ;
      if (cVar1 == '\0') {
        FUN_187b_026d();
      }
      else {
        FUN_187b_159e(*(undefined2 *)((int)*(undefined4 *)0x9eec + 0x12),
                      *(undefined2 *)((int)*(undefined4 *)0x9eec + 0x10),
                      *(undefined2 *)((int)*(undefined4 *)0x9eec + 0xe),
                      *(undefined2 *)((int)*(undefined4 *)0x9eec + 0xc),*(undefined2 *)0x9eea);
        local_3 = 1;
      }
    }
    else {
      FUN_187b_026d();
    }
  }
  return local_3;
}


