/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:f1bd
 * Ghidra name: FUN_1000_f1bd
 * Linear address: 0x1F1BD
 * Original GAME.OVR file offset: 127429
 * Body addresses: 138
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Instruction at (ram,0x0001f22f) overlaps instruction at (ram,0x0001f22c)
    */

void FUN_1000_f1bd(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  byte *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  bool in_CF;
  bool bVar3;
  bool in_ZF;
  undefined1 uVar4;
  byte in_SF;
  byte in_OF;
  undefined4 uVar5;
  undefined2 uVar6;
  
  if (in_CF) {
    pbVar1 = unaff_SI;
    *pbVar1 = *pbVar1 >> 5 | *pbVar1 << 3;
    if (!in_ZF && (in_OF & 1) == in_SF) {
      func_0x0000d74f();
      func_0x0000e40c(0xcc0);
      func_0x0000e43a(0xcc0,1,unaff_BP + -0x112);
      uVar5 = func_0x0000e5d4(0xcc0,unaff_BP + -0x112);
      if (((int)((ulong)uVar5 >> 0x10) == 0) && (*(int *)(unaff_BP + 0x10) == (int)uVar5)) {
        uVar5 = FUN_0000_ce3f(0xcc0,0x2e);
        *(int *)((undefined *)&DAT_0000_ffab + unaff_BP) = (int)uVar5;
        *(int *)((undefined *)&DAT_0000_ffad + unaff_BP) = (int)((ulong)uVar5 >> 0x10);
        uVar5 = FUN_0000_ce3f(0xcc0,0x2e);
        *(int *)((undefined *)&DAT_0000_ffa3 + unaff_BP) = (int)uVar5;
        *(int *)((undefined *)&DAT_0000_ffa5 + unaff_BP) = (int)((ulong)uVar5 >> 0x10);
        FUN_0000_e6d2(0);
        FUN_0000_e6d2(0);
        func_0x0000e58d(0xcc0,*(undefined2 *)(unaff_BP + 0x14),0,unaff_BP + -0x112);
        func_0x0000e525(0xcc0,unaff_BP + -0x92);
        func_0x0000e58d(0xcc0,*(undefined2 *)(unaff_BP + 0x12),0,unaff_BP + -0x112);
        uVar4 = 1;
        func_0x0000e525(0xcc0,0,0,1,unaff_BP + -0x164);
        func_0x0000d6dc(0xcc0,0x28,(int)*(undefined4 *)((undefined *)&DAT_0000_ffa3 + unaff_BP),
                        (int)((ulong)*(undefined4 *)((undefined *)&DAT_0000_ffa3 + unaff_BP) >> 0x10
                             ),unaff_BP + -0x72);
        func_0x0000d70e(0xcc0,4,9,unaff_BP + -0x72);
        uVar6 = 0;
        FUN_0000_d7c7(0xcc0,0,0xcc0);
        if ((bool)uVar4) {
                    /* WARNING: Subroutine does not return */
          FUN_0000_d6c2(5,0xcc0,unaff_BP + -0x475,unaff_SS,uVar6);
        }
        *(undefined1 *)(unaff_BP + -0x163) = 0;
                    /* WARNING: Subroutine does not return */
        FUN_0000_d6c2((int)*(undefined4 *)((undefined *)&DAT_0000_ffab + unaff_BP),
                      (int)((ulong)*(undefined4 *)((undefined *)&DAT_0000_ffab + unaff_BP) >> 0x10),
                      unaff_BP + -0x375,unaff_SS,uVar6);
      }
      func_0x0000e4bb(0xcc0,unaff_BP + -0x112);
      func_0x0000c530(0xcc0,unaff_BP + -0x90);
      goto code_r0x0001f20a;
    }
    bVar3 = true;
    if ((char)*pbVar1 < '\0') goto code_r0x0001f1c4;
  }
  else {
    puVar2 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    uVar6 = in(in_DX);
    *puVar2 = uVar6;
    pbVar1 = (byte *)((int)unaff_DI + unaff_BP + 0x61);
    bVar3 = false;
    *pbVar1 = *pbVar1 & (byte)((uint)in_DX >> 8);
    in_ZF = *pbVar1 == 0;
code_r0x0001f1c4:
    if (bVar3 || in_ZF) goto LAB_1000_f22b;
    *(byte *)(in_BX + 0x61) = *(byte *)(in_BX + 0x61) & (byte)((uint)in_AX >> 8);
    uVar6 = in(in_DX);
    *unaff_DI = uVar6;
    *(byte *)((int)unaff_DI + -0x75) = *(byte *)((int)unaff_DI + -0x75) & (byte)in_DX;
    in(0x81);
    in(in_DX);
    func_0x0000d6dc();
    *(undefined2 *)((undefined *)&DAT_0000_ffab + unaff_BP) = 0;
    *(undefined2 *)((undefined *)&DAT_0000_ffad + unaff_BP) = 0;
    *(undefined2 *)((undefined *)&DAT_0000_ffa3 + unaff_BP) = 0;
    *(undefined2 *)((undefined *)&DAT_0000_ffa5 + unaff_BP) = 0;
    FUN_0000_c4f2(unaff_BP + -0x90,unaff_SS,0);
code_r0x0001f20a:
    if (*(int *)0x9f48 != 0) {
      FUN_1000_f567();
      return;
    }
    if (*(char *)0x74ae != '\x01') {
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2(0x51d4,unaff_DS,unaff_BP + -0x275,unaff_SS);
    }
  }
  unaff_DI = (undefined2 *)0x50d4;
LAB_1000_f22b:
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(unaff_DI);
}


