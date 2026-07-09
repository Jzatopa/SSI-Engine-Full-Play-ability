
void __stdcall16far FUN_1000_14df(void)

{
  undefined4 uVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  int iVar6;
  undefined4 *puVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 unaff_DS;
  undefined4 *in_stack_0000000a;
  undefined2 uVar11;
  
  uVar1 = *(undefined4 *)((int)*in_stack_0000000a + 0xf3);
  uVar8 = (undefined2)((ulong)uVar1 >> 0x10);
  iVar6 = (int)uVar1;
  uVar5 = *(undefined2 *)(iVar6 + 10);
  *(undefined2 *)0x72d5 = *(undefined2 *)(iVar6 + 8);
  *(undefined2 *)&DAT_0000_72d7 = uVar5;
  if (*(int *)0x72d5 != 0 || *(int *)&DAT_0000_72d7 != 0) {
    uVar9 = (undefined2)((ulong)in_stack_0000000a >> 0x10);
    puVar7 = (undefined4 *)in_stack_0000000a;
    uVar5 = *(undefined2 *)((int)puVar7 + 2);
    uVar8 = *(undefined2 *)in_stack_0000000a;
    uVar10 = *(undefined2 *)&DAT_0000_72d7;
    uVar11 = *(undefined2 *)0x72d5;
    bVar2 = func_0x00000a23();
    if (((bVar2 < 0xd) && (*(char *)((int)*(undefined4 *)0x72d5 + 0xd5) != '\0')) &&
       (*(char *)((int)*(undefined4 *)0x72d5 + 0xd6) != *(char *)((int)*in_stack_0000000a + 0xd6)))
    {
      *(undefined1 *)0x7816 = 1;
      func_0x000009c9(0x99,*(undefined2 *)in_stack_0000000a,*(undefined2 *)((int)puVar7 + 2),uVar11,
                      uVar10,uVar8,uVar5);
      uVar5 = func_0x00000dd5(0x99,*(undefined2 *)0x72d5,*(undefined2 *)&DAT_0000_72d7,
                              *(undefined2 *)in_stack_0000000a,*(undefined2 *)((int)puVar7 + 2));
      uVar1 = *(undefined4 *)((int)*in_stack_0000000a + 0xf3);
      *(undefined1 *)((int)uVar1 + 7) = (char)uVar5;
      uVar1 = *(undefined4 *)((int)*in_stack_0000000a + 0xf3);
      bVar2 = (byte)((uint)uVar5 >> 8);
      func_0x00000e1b(0xdb,(uint)bVar2 << 8,CONCAT11(bVar2,1),
                      CONCAT11(bVar2,*(undefined1 *)((int)uVar1 + 7)),
                      *(undefined2 *)in_stack_0000000a,*(undefined2 *)((int)puVar7 + 2));
      uVar5 = *(undefined2 *)0x72d5;
      uVar8 = *(undefined2 *)&DAT_0000_72d7;
      uVar1 = *(undefined4 *)((int)*in_stack_0000000a + 0xf3);
      uVar10 = (undefined2)((ulong)uVar1 >> 0x10);
      iVar6 = (int)uVar1;
      *(undefined2 *)(iVar6 + 8) = uVar5;
      *(undefined2 *)(iVar6 + 10) = uVar8;
      uVar10 = 0x8f4;
      bVar2 = (byte)((uint)uVar5 >> 8);
      uVar8 = CONCAT11(bVar2,10);
      iVar6 = (uint)bVar2 << 8;
      func_0x000009f6(0xdb,iVar6,uVar8,0x8f4);
      uVar5 = *(undefined2 *)0x2330;
      FUN_0000_7840(0x99,uVar5);
      FUN_0000_5138(CONCAT11(extraout_AH,0x12),uVar5,iVar6,uVar8,uVar10);
      cVar3 = FUN_0000_0e20(0x21a,*(undefined2 *)in_stack_0000000a,*(undefined2 *)((int)puVar7 + 2))
      ;
      cVar3 = FUN_0000_0e25(*(undefined2 *)in_stack_0000000a,*(undefined2 *)((int)puVar7 + 2),
                            (int)cVar3);
      cVar3 = FUN_0000_0e20(0xdb,*(undefined2 *)0x72d5,*(undefined2 *)&DAT_0000_72d7,(int)cVar3);
      cVar3 = FUN_0000_0e25(*(undefined2 *)0x72d5,*(undefined2 *)&DAT_0000_72d7,(int)cVar3);
      func_0x00000a00(0xdb,CONCAT11(cVar3 >> 7,0x2d),CONCAT11(cVar3 >> 7,4),(int)cVar3);
      uVar5 = FUN_0000_09b5(CONCAT11(extraout_AH_00,0x1e));
      if ((char)uVar5 == '\0') {
        *(undefined1 *)0x72c6 = 0;
      }
      else {
        uVar4 = FUN_0000_09ba(0x99,8,2);
        *(undefined1 *)0x72c6 = uVar4;
        uVar5 = FUN_0000_0a0f(0x99,*(undefined1 *)0x72c6,*(undefined2 *)0x72d5,
                              *(undefined2 *)&DAT_0000_72d7);
      }
      *(undefined1 *)0x7511 = 0;
      bVar2 = (byte)((uint)uVar5 >> 8);
      iVar6 = (uint)bVar2 * 0x100;
      if (*(char *)0x72c6 != '\0') {
        iVar6 = iVar6 + 1;
      }
      func_0x00000594(0x99,iVar6,CONCAT11(bVar2,*(undefined1 *)0x72c6),
                      CONCAT11(bVar2,*(undefined1 *)0x72c6),*(undefined2 *)0x72d5,
                      *(undefined2 *)&DAT_0000_72d7,*(undefined2 *)in_stack_0000000a,
                      *(undefined2 *)((int)puVar7 + 2));
    }
  }
  return;
}


