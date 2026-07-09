
void __stdcall16far FUN_1000_a257(undefined2 param_1,undefined1 param_2,byte param_3)

{
  undefined2 in_AX;
  byte bVar2;
  int iVar1;
  undefined2 unaff_DS;
  
  bVar2 = (byte)((uint)in_AX >> 8);
  iVar1 = (uint)bVar2 * 0x100;
  if (*"" != '\0') {
    iVar1 = iVar1 + 1;
  }
  FUN_1000_a0fa(param_1,iVar1,(uint)bVar2 << 8,CONCAT11(bVar2,0xfe),CONCAT11(bVar2,0xfe),
                CONCAT11(bVar2,param_2),CONCAT11(bVar2,param_3));
  FUN_0000_39b7();
  bVar2 = (byte)(param_3 + 3 >> 8);
  iVar1 = (uint)bVar2 * 0x100;
  if (*"" != '\0') {
    iVar1 = iVar1 + 1;
  }
  FUN_1000_a0fa(param_1,iVar1,CONCAT11(bVar2,1),CONCAT11(bVar2,0xfe),CONCAT11(bVar2,0xfe),
                CONCAT11(bVar2,param_2),param_3 + 3);
  FUN_0000_39b7();
  return;
}


