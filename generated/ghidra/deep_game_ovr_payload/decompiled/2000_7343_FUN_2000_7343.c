
void __cdecl16far FUN_2000_7343(void)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined2 unaff_DS;
  undefined2 uVar7;
  undefined2 local_6;
  undefined2 uStack_4;
  
  local_6 = *(int *)0x57ff;
  uStack_4 = *(int *)0x5801;
  bVar4 = FUN_2000_72e9();
  uVar7 = 0;
  if ((*(int *)0x72bc < 1) && ((*(int *)0x72bc < 0 || (*(int *)0x72ba == 0)))) {
    *(undefined1 *)0x748e = 0;
  }
  else {
    uVar5 = FUN_0000_d62d();
    uVar6 = (uint)bVar4;
    FUN_0000_d62d(0xcc0,uVar7);
    while (local_6 != 0 || uStack_4 != 0) {
      if (*(byte *)(local_6 + 0xe7) < 0x80) {
        puVar1 = (uint *)(local_6 + 0x2b);
        uVar3 = *puVar1;
        *puVar1 = *puVar1 + uVar5;
        *(int *)(local_6 + 0x2d) = *(int *)(local_6 + 0x2d) + (uint)CARRY2(uVar3,uVar5);
        if (uVar6 != 0) {
          puVar1 = (uint *)(local_6 + 0x2b);
          uVar3 = *puVar1;
          *puVar1 = *puVar1 + 1;
          *(int *)(local_6 + 0x2d) = *(int *)(local_6 + 0x2d) + (uint)(0xfffe < uVar3);
          uVar6 = uVar6 - 1;
        }
      }
      piVar2 = (int *)(local_6 + 0xff);
      uStack_4 = *(int *)(local_6 + 0x101);
      local_6 = *piVar2;
    }
    *(undefined1 *)0x748e = 0;
    *(undefined2 *)0x72ba = 0;
    *(undefined2 *)0x72bc = 0;
  }
  return;
}


