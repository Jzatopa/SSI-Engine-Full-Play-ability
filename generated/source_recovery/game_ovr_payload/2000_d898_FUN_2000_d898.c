/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:d898
 * Ghidra name: FUN_2000_d898
 * Linear address: 0x2D898
 * Original GAME.OVR file offset: 186528
 * Body addresses: 257
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_d898(int param_1,undefined2 param_2)

{
  char cVar1;
  undefined1 extraout_AH;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  
  uVar7 = 0x745e;
  uVar6 = 0x19;
  FUN_0000_e6d2(0xff);
  func_0x00001140(0xcc0,CONCAT11(extraout_AH,*(undefined1 *)(param_1 + 0x18)),
                  CONCAT11(extraout_AH,*(undefined1 *)(param_1 + 0x1a)),
                  CONCAT11(extraout_AH,*(undefined1 *)(param_1 + 0x1c)),
                  CONCAT11(extraout_AH,*(undefined1 *)(param_1 + 0x1e)),uVar6,uVar7);
  func_0x0000b5d1(0xec);
  uVar5 = FUN_2000_c3ce(*(undefined2 *)(param_1 + 0x14),*(undefined2 *)(param_1 + 0x16),param_2);
  uVar4 = (uint)((ulong)uVar5 >> 0x10);
  FUN_2000_d805(param_1,*(undefined2 *)(param_1 + 0x14),*(undefined2 *)(param_1 + 0x16),param_2);
  cVar1 = *(char *)(param_1 + 0x1c);
  ((undefined *)&DAT_0000_ffab)[param_1] = 1;
  uVar2 = (uint)uVar5 | uVar4;
  if ((uVar2 != 0) && (bVar3 = (byte)(uVar2 >> 8), cVar1 <= *(char *)(param_1 + 0x18))) {
    if (*(char *)((uint)uVar5 + 0x29) == '\0') {
      ((undefined *)&DAT_0000_745d)[(byte)((undefined *)&DAT_0000_ffab)[param_1]] = cVar1;
                    /* WARNING: Subroutine does not return */
      FUN_0000_643a(0xb58,uVar5,0,*(undefined1 *)0x7480,cVar1,*(undefined1 *)(param_1 + 0x1e));
    }
                    /* WARNING: Subroutine does not return */
    FUN_0000_643a(0xb58,uVar5,(uint)bVar3 << 8,CONCAT11(bVar3,*(undefined1 *)0x747f),
                  CONCAT11(bVar3,cVar1),CONCAT11(bVar3,*(undefined1 *)(param_1 + 0x1e)));
  }
  FUN_0000_b5b0(0xb58);
  return;
}


