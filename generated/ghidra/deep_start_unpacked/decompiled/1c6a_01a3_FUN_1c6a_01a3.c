
void __stdcall16far FUN_1c6a_01a3(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  if ((*(int *)0x3da4 != 0) && (*(int *)0x3da2 == 0)) {
    uVar1 = FUN_1c6a_024e();
    if (*(uint *)0x3d96 <= uVar1) {
      uVar2 = uVar1 + *(uint *)0x3d9c;
      if ((CARRY2(uVar1,*(uint *)0x3d9c)) || (*(uint *)0x3db2 < uVar2)) {
        uVar3 = 0xfffd;
      }
      else {
        *(uint *)0x3da0 = uVar2;
        *(uint *)0x3daa = uVar2;
        *(uint *)0x3dae = uVar2;
        *(uint *)0x3db6 = uVar2;
        uVar3 = 0;
        *(undefined2 *)0x3dac = 0;
        *(undefined2 *)0x3db4 = 0;
      }
      goto LAB_1c6a_01e2;
    }
  }
  uVar3 = 0xffff;
LAB_1c6a_01e2:
  *(undefined2 *)0x3d84 = uVar3;
  return;
}


