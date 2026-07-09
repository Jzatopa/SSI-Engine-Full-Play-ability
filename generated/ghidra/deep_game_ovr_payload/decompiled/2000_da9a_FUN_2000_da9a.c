
void FUN_2000_da9a(undefined2 param_1,int param_2,undefined2 param_3)

{
  uint uVar1;
  undefined2 unaff_SS;
  undefined1 local_108 [256];
  undefined1 local_8;
  undefined1 local_7;
  undefined4 local_6;
  
  local_6 = FUN_2000_c3ce(*(undefined2 *)(param_2 + 0x14),*(undefined2 *)(param_2 + 0x16),param_3);
  local_7 = FUN_2000_da08();
  uVar1 = FUN_2000_da54();
  uVar1 = ((uVar1 & 0xff) - param_2) + 1;
  local_8 = (undefined1)uVar1;
  FUN_0000_d70e(uVar1 & 0xff,local_7,local_6,local_108);
                    /* WARNING: Subroutine does not return */
  FUN_0000_643a(0xcc0);
}


