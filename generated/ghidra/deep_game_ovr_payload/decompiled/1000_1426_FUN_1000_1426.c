
void __stdcall16far FUN_1000_1426(void)

{
  undefined4 uVar1;
  char cVar2;
  undefined2 uVar3;
  byte bVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 unaff_DS;
  undefined4 *in_stack_0000000a;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  
  uVar1 = *(undefined4 *)((int)*in_stack_0000000a + 0xf3);
  uVar6 = (undefined2)((ulong)uVar1 >> 0x10);
  iVar5 = (int)uVar1;
  uVar10 = *(undefined2 *)(iVar5 + 10);
  *(undefined2 *)0x72d5 = *(undefined2 *)(iVar5 + 8);
  *(undefined2 *)&DAT_0000_72d7 = uVar10;
  if (*(int *)0x72d5 != 0 || *(int *)&DAT_0000_72d7 != 0) {
    uVar7 = (undefined2)((ulong)in_stack_0000000a >> 0x10);
    uVar10 = *(undefined2 *)((int)(undefined4 *)in_stack_0000000a + 2);
    uVar6 = *(undefined2 *)in_stack_0000000a;
    uVar9 = *(undefined2 *)&DAT_0000_72d7;
    uVar8 = *(undefined2 *)0x72d5;
    uVar3 = func_0x00000a23();
    if ((((byte)uVar3 < 2) && (*(char *)((int)*(undefined4 *)0x72d5 + 0xd5) != '\0')) &&
       (bVar4 = (byte)((uint)uVar3 >> 8),
       *(char *)((int)*(undefined4 *)0x72d5 + 0xd6) != *(char *)((int)*in_stack_0000000a + 0xd6))) {
      cVar2 = FUN_0000_0963(0x99,(uint)bVar4 << 8,CONCAT11(bVar4,6),*(undefined2 *)0x72d5,
                            *(undefined2 *)&DAT_0000_72d7,uVar8,uVar9,uVar6,uVar10);
      if (cVar2 == '\0') {
        *(undefined1 *)0x72c6 = 8;
      }
      else {
        *(undefined1 *)0x72c6 = 4;
      }
      *(undefined1 *)0x7511 = 0;
      func_0x00000594(0x92,1,*(undefined1 *)0x72c6,*(undefined1 *)0x72c6,*(undefined2 *)0x72d5,
                      *(undefined2 *)&DAT_0000_72d7,*(undefined2 *)in_stack_0000000a,
                      *(undefined2 *)((int)(undefined4 *)in_stack_0000000a + 2));
      *(undefined1 *)0x7816 = 1;
    }
  }
  return;
}


