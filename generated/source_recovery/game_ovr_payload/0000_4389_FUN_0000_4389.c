/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:4389
 * Ghidra name: FUN_0000_4389
 * Linear address: 0x04389
 * Original GAME.OVR file offset: 17297
 * Body addresses: 141
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_4389(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_102 [256];
  
  uVar4 = (undefined2)((ulong)param_5 >> 0x10);
  if ((int)param_3 != 0 || param_3._2_2_ != 0) {
    func_0x0000d6dc();
    return;
  }
  if ((param_4._2_2_ == *(int *)0x534c) && ((int)param_4 == *(int *)0x534a)) {
    func_0x0000d6dc();
    return;
  }
  uVar2 = 1;
  uVar3 = 4;
  cVar1 = FUN_0000_09ba();
  if (cVar1 == '\x01') {
    func_0x0000d6dc(0x99,0xff,(int)param_5,uVar4,0x43,0x99,uVar3,uVar2);
    return;
  }
  if (cVar1 == '\x02') {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(*(char *)((int)param_4 + 0x3a) * 0xe + 0x135c,unaff_DS,local_102,unaff_SS,uVar3);
  }
  func_0x0000d6dc(0x99,0xff,(int)param_5,uVar4,(int)param_4,param_4._2_2_,uVar3,uVar2);
  return;
}


