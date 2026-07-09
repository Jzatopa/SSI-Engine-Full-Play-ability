/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:fad0
 * Ghidra name: FUN_1000_fad0
 * Linear address: 0x1FAD0
 * Original GAME.OVR file offset: 129752
 * Body addresses: 193
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - save_character (save_load), next candidate, distance 205 byte(s), source offset 129547
 */

void __cdecl16far FUN_1000_fad0(void)

{
  undefined4 uVar1;
  char cVar2;
  int unaff_BP;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  ulong uVar6;
  
  cVar2 = FUN_1000_f67d();
  if (cVar2 == '\0') {
    *(undefined1 *)(unaff_BP + -1) = 0;
    *(undefined1 *)(unaff_BP + -1) = *(undefined1 *)0x50d2;
    *(undefined1 *)0x50d2 = 1;
    *(undefined1 *)((int)*(undefined4 *)0x441c + 0x312) = *(undefined1 *)0x50d2;
    uVar1 = *(undefined4 *)0x4418;
    iVar3 = (int)uVar1 + 0x200;
    *(int *)0x534a = iVar3;
    *(undefined2 *)0x534c = (int)((ulong)uVar1 >> 0x10);
    FUN_0000_07d7(CONCAT11((char)((uint)iVar3 >> 8),10),*(undefined2 *)0x534a,*(undefined2 *)0x534c)
    ;
    *(undefined1 *)0x50d2 = *(undefined1 *)(unaff_BP + -1);
    *(undefined2 *)0x5360 = 0;
    *(undefined2 *)0x5362 = 0;
    uVar1 = *(undefined4 *)0x4418;
    *(int *)0x5360 = (int)uVar1 + 0x85;
    *(undefined2 *)0x5362 = (int)((ulong)uVar1 >> 0x10);
    uVar1 = *(undefined4 *)0x5360;
    *(undefined2 *)(unaff_BP + -5) = (int)uVar1;
    *(undefined2 *)(unaff_BP + -3) = (int)((ulong)uVar1 >> 0x10);
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -5) + 0x36) = 0;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -5) + 0x34) = 0;
    *(int *)(unaff_BP + -9) = ((uint)*(byte *)0x26aa + (uint)*(byte *)0x2698) * 3 + 0x25e8;
    *(undefined2 *)(unaff_BP + -7) = unaff_DS;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -5) + 0x39) =
         *(undefined1 *)*(undefined4 *)(unaff_BP + -9);
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -5) + 0x3a) =
         *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -9) + 1);
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -5) + 0x38) = 0x57;
    return;
  }
  *(undefined2 *)(unaff_BP + -0xde) = 0;
  *(int *)(unaff_BP + -0xde) = *(int *)(unaff_BP + -0xde) + 0x103;
  uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 10) >> 0x10);
  iVar3 = (int)*(undefined4 *)(unaff_BP + 10);
  if (*(int *)(iVar3 + 0xf7) == 0 && *(int *)(iVar3 + 0xf9) == 0) {
    uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 10) >> 0x10);
    iVar3 = (int)*(undefined4 *)(unaff_BP + 10);
    if (*(int *)(iVar3 + 0xb4) != 0 || *(int *)(iVar3 + 0xb6) != 0) {
      uVar5 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 10) >> 0x10);
      iVar3 = (int)*(undefined4 *)(unaff_BP + 10);
      uVar4 = *(undefined2 *)(iVar3 + 0xb6);
      *(undefined2 *)((undefined *)&DAT_0000_ff42 + unaff_BP) = *(undefined2 *)(iVar3 + 0xb4);
      *(undefined2 *)((undefined *)&DAT_0000_ff44 + unaff_BP) = uVar4;
      while (*(int *)((undefined *)&DAT_0000_ff42 + unaff_BP) != 0 ||
             *(int *)((undefined *)&DAT_0000_ff44 + unaff_BP) != 0) {
        *(int *)(unaff_BP + -0xde) = *(int *)(unaff_BP + -0xde) + 0x3e;
        uVar5 = (undefined2)((ulong)*(undefined4 *)((undefined *)&DAT_0000_ff42 + unaff_BP) >> 0x10)
        ;
        iVar3 = (int)*(undefined4 *)((undefined *)&DAT_0000_ff42 + unaff_BP);
        uVar4 = *(undefined2 *)(iVar3 + 0x2c);
        *(undefined2 *)((undefined *)&DAT_0000_ff42 + unaff_BP) = *(undefined2 *)(iVar3 + 0x2a);
        *(undefined2 *)((undefined *)&DAT_0000_ff44 + unaff_BP) = uVar4;
      }
    }
  }
  else {
    uVar5 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 10) >> 0x10);
    iVar3 = (int)*(undefined4 *)(unaff_BP + 10);
    uVar4 = *(undefined2 *)(iVar3 + 0xf9);
    *(undefined2 *)((undefined *)&DAT_0000_ff42 + unaff_BP) = *(undefined2 *)(iVar3 + 0xf7);
    *(undefined2 *)((undefined *)&DAT_0000_ff44 + unaff_BP) = uVar4;
    while (*(int *)((undefined *)&DAT_0000_ff42 + unaff_BP) != 0 ||
           *(int *)((undefined *)&DAT_0000_ff44 + unaff_BP) != 0) {
      *(int *)(unaff_BP + -0xde) = *(int *)(unaff_BP + -0xde) + 0x3e;
      uVar5 = (undefined2)((ulong)*(undefined4 *)((undefined *)&DAT_0000_ff42 + unaff_BP) >> 0x10);
      iVar3 = (int)*(undefined4 *)((undefined *)&DAT_0000_ff42 + unaff_BP);
      uVar4 = *(undefined2 *)(iVar3 + 0x2c);
      *(undefined2 *)((undefined *)&DAT_0000_ff42 + unaff_BP) = *(undefined2 *)(iVar3 + 0x2a);
      *(undefined2 *)((undefined *)&DAT_0000_ff44 + unaff_BP) = uVar4;
    }
  }
  uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 10) >> 0x10);
  iVar3 = (int)*(undefined4 *)(unaff_BP + 10);
  if (*(int *)(iVar3 + 0xfb) != 0 || *(int *)(iVar3 + 0xfd) != 0) {
    uVar5 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 10) >> 0x10);
    iVar3 = (int)*(undefined4 *)(unaff_BP + 10);
    uVar4 = *(undefined2 *)(iVar3 + 0xfd);
    *(undefined2 *)((undefined *)&DAT_0000_ff3e + unaff_BP) = *(undefined2 *)(iVar3 + 0xfb);
    *(undefined2 *)((undefined *)&DAT_0000_ff40 + unaff_BP) = uVar4;
    while (*(int *)((undefined *)&DAT_0000_ff3e + unaff_BP) != 0 ||
           *(int *)((undefined *)&DAT_0000_ff40 + unaff_BP) != 0) {
      *(int *)(unaff_BP + -0xde) = *(int *)(unaff_BP + -0xde) + 9;
      uVar5 = (undefined2)((ulong)*(undefined4 *)((undefined *)&DAT_0000_ff3e + unaff_BP) >> 0x10);
      iVar3 = (int)*(undefined4 *)((undefined *)&DAT_0000_ff3e + unaff_BP);
      uVar4 = *(undefined2 *)(iVar3 + 7);
      *(undefined2 *)((undefined *)&DAT_0000_ff3e + unaff_BP) = *(undefined2 *)(iVar3 + 5);
      *(undefined2 *)((undefined *)&DAT_0000_ff40 + unaff_BP) = uVar4;
    }
  }
  ((undefined *)&DAT_0000_ff47)[unaff_BP] = 0x4f;
  FUN_0000_e854(*(undefined1 *)0x50d5);
  uVar6 = func_0x0000c4be(0xcc0);
  if ((0x7fffffff < uVar6) ||
     (((long)uVar6 < 0x10000 && ((uint)uVar6 < *(uint *)(unaff_BP + -0xde))))) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(0x828,0xc3e,unaff_BP + -0x101,unaff_SS,*(uint *)(unaff_BP + -0xde) & 0xff00);
  }
  if (((undefined *)&DAT_0000_ff47)[unaff_BP] != 'O') {
    FUN_1000_fad0();
    return;
  }
  if (((undefined *)&DAT_0000_fff6)[unaff_BP] != '\0') {
    func_0x0000d6dc(0xc3e,4,unaff_BP + -0xb8);
    func_0x0000d6dc(0xcc0,0x28,unaff_BP + -0xb3);
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(0x50d4,unaff_DS,unaff_BP + -0x1de,unaff_SS,unaff_BP + -0x8a);
  }
  func_0x0000d6dc(0xc3e,4,unaff_BP + -0xb8);
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x876,0xcc0,unaff_BP + -0xe0,unaff_SS,(int)*(undefined4 *)(unaff_BP + 10));
}


