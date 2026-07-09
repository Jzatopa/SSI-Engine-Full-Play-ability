/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1836:01c7
 * Ghidra name: FUN_1836_01c7
 * Linear address: 0x18527
 * Body addresses: 366
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined2 __cdecl16far FUN_1836_01c7(void)

{
  int *piVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined2 uVar4;
  undefined2 unaff_DS;
  bool bVar5;
  int local_8;
  int iStack_6;
  char local_4;
  
  *(undefined1 *)0x8d71 = 0;
  uVar2 = FUN_1bdc_02fb();
  if ((char)uVar2 == '\0') {
    if ((*(char *)0x8db8 == '\0') && (*(char *)0x8d70 == '\0')) {
      if (*(char *)0x443a == '\0') {
        uVar2 = FUN_1bdc_030d();
        local_4 = (char)uVar2;
      }
      else {
        local_4 = '\0';
      }
    }
    else {
      if (*(char *)0x8d70 == '\0') {
        FUN_1836_006b(&stack0xfffe);
      }
      else {
        FUN_1836_011e(&stack0xfffe);
      }
      uVar2 = FUN_1bdc_02fb();
      if ((char)uVar2 != '\0') {
        uVar2 = FUN_1bdc_030d();
        local_4 = (char)uVar2;
      }
    }
  }
  else {
    uVar2 = FUN_1bdc_030d();
    local_4 = (char)uVar2;
  }
  uVar4 = 0x1bdc;
  if (local_4 == '\x13') {
    bVar5 = *(char *)0x50cc == '\0';
    uVar3 = (undefined1)(uVar2 >> 8);
    if (bVar5) {
      uVar4 = 0x1cc0;
      uVar2 = FUN_1cc0_0d77(0x19d,0x1bdc,CONCAT11(uVar3,*(undefined1 *)0x50cd));
      if (!bVar5) {
        uVar2 = CONCAT11((char)(uVar2 >> 8),*(undefined1 *)0x50cd);
        *(undefined1 *)0x50cc = *(undefined1 *)0x50cd;
        if (*(char *)0x50d0 == '\x01') {
          uVar4 = 0x19e3;
          uVar2 = FUN_19e3_0000(*(undefined2 *)0x232c);
        }
      }
    }
    else {
      uVar2 = CONCAT11(uVar3,*(undefined1 *)0x50cc);
      *(undefined1 *)0x50cd = *(undefined1 *)0x50cc;
      if (*(char *)0x50d0 == '\x01') {
        uVar4 = 0x19e3;
        uVar2 = FUN_19e3_0000(*(undefined2 *)0x232a);
      }
      *(undefined1 *)0x50cc = 0;
    }
  }
  if (local_4 == '\x15') {
    uVar2 = uVar2 & 0xff00;
    if (*(char *)0x50ce == '\0') {
      uVar2 = uVar2 + 1;
    }
    *(undefined1 *)0x50ce = (char)uVar2;
    if (*(char *)0x50ce == '\0') {
      uVar4 = 0x187b;
      uVar2 = FUN_187b_02c3();
    }
  }
  uVar3 = (undefined1)(uVar2 >> 8);
  if (local_4 == '\x04') {
    *(bool *)0x4440 = *(char *)0x4440 == '\0';
    if (*(char *)0x4440 == '\0') {
      FUN_1cc0_05bf(0x8c4e,unaff_DS);
      uVar3 = extraout_AH_00;
    }
    else {
      FUN_1cc0_04f5(0x1bd,uVar4,0x8c4e,unaff_DS);
      FUN_1cc0_056a(0x1cc0,0x8c4e);
      uVar3 = extraout_AH;
    }
  }
  else if (local_4 == '\x1a') {
    if (*(char *)0x4440 != '\0') {
      iStack_6 = *(int *)0x5801;
      local_8 = *(int *)0x57ff;
      while (uVar3 = 0, local_8 != 0 || iStack_6 != 0) {
        FUN_1836_005f(local_8,iStack_6);
        piVar1 = (int *)(local_8 + 0xff);
        iStack_6 = *(int *)(local_8 + 0x101);
        local_8 = *piVar1;
      }
    }
  }
  else if (local_4 == '\x03') {
    FUN_1836_0000();
    uVar3 = extraout_AH_01;
  }
  return CONCAT11(uVar3,local_4);
}


