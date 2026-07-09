/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:f2b4
 * Ghidra name: FUN_1000_f2b4
 * Linear address: 0x1F2B4
 * Original GAME.OVR file offset: 127676
 * Body addresses: 215
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_1000_f2b4(void)

{
  int unaff_BP;
  undefined2 *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar1;
  undefined2 uVar2;
  
  *unaff_DI = *unaff_SI;
  FUN_0000_e6d2(0);
  FUN_0000_e6d2(0);
  FUN_0000_e58d(*(undefined2 *)(unaff_BP + 0x14));
  func_0x0000e525(0xcc0,unaff_BP + -0x92);
  FUN_0000_e58d(*(undefined2 *)(unaff_BP + 0x12));
  uVar1 = 1;
  func_0x0000e525(0xcc0,0,0,1,unaff_BP + -0x164);
  func_0x0000d6dc(0xcc0,0x28,(int)*(undefined4 *)((undefined *)&DAT_0000_ffa3 + unaff_BP),
                  (int)((ulong)*(undefined4 *)((undefined *)&DAT_0000_ffa3 + unaff_BP) >> 0x10),
                  unaff_BP + -0x72);
  FUN_0000_d70e(4,9,unaff_BP + -0x72,unaff_SS,unaff_BP + -0x275);
  uVar2 = 0;
  FUN_0000_d7c7(0xcc0,0,0xcc0);
  if ((bool)uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(5,0xcc0,unaff_BP + -0x475,unaff_SS,uVar2);
  }
  *(undefined1 *)(unaff_BP + -0x163) = 0;
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2((int)*(undefined4 *)((undefined *)&DAT_0000_ffab + unaff_BP),
                (int)((ulong)*(undefined4 *)((undefined *)&DAT_0000_ffab + unaff_BP) >> 0x10),
                unaff_BP + -0x375,unaff_SS,uVar2);
}


