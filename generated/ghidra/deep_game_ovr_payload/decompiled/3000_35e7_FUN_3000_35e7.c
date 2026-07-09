
void __stdcall16far FUN_3000_35e7(byte param_1,byte param_2,byte param_3,char param_4,char param_5)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  undefined2 *puVar5;
  undefined2 local_6;
  undefined2 uStack_4;
  
  iVar3 = (uint)param_1 * 8 + (uint)param_2 * 4;
  if (*(int *)(iVar3 + 0x68c0) != 0 || *(int *)(iVar3 + 0x68c2) != 0) {
    if (param_3 < 4) {
      uVar2 = param_4 * 3;
      iVar3 = (uint)param_1 * 8 + (uint)param_2 * 4;
      FUN_0000_2e9a(*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,*(undefined2 *)(iVar3 + 0x68c0),
                    *(undefined2 *)(iVar3 + 0x68c2),CONCAT11((char)(uVar2 >> 8),1),uVar2 & 0xff00,
                    uVar2,param_5 * 3);
    }
    else {
      puVar5 = &local_6;
      FUN_0000_444d();
      uVar1 = *(undefined4 *)((uint)param_1 * 8 + (uint)param_2 * 4 + 0x68c0);
      uVar4 = (undefined2)((ulong)_local_6 >> 0x10);
      *(undefined1 *)((int)_local_6 + 0x16) = *(undefined1 *)((int)uVar1 + 0x16);
      iVar3 = (uint)param_1 * 8 + (uint)param_2 * 4;
      FUN_0000_309f((int)_local_6,uVar4,*(undefined2 *)(iVar3 + 0x68c0),
                    *(undefined2 *)(iVar3 + 0x68c2),puVar5);
      uVar2 = param_4 * 3;
      FUN_0000_2e9a(*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,local_6,uStack_4,
                    CONCAT11((char)(uVar2 >> 8),1),uVar2 & 0xff00,uVar2,param_5 * 3);
      FUN_0000_453c(&local_6);
    }
  }
  return;
}


