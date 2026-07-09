
void __stdcall16far FUN_1000_11fa(void)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  undefined2 *in_stack_0000000a;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  
  uVar5 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
  iVar4 = (int)*(undefined4 *)0x57fb;
  iVar1 = *(int *)(iVar4 + 0xeb);
  iVar4 = *(int *)(iVar4 + 0xed);
  if (((iVar1 != 0 || iVar4 != 0) &&
      (((undefined *)&DAT_0000_5370)[(uint)*(byte *)(iVar1 + 0x2e) * 9] != '\0')) &&
     ((byte)((undefined *)&DAT_0000_5370)[(uint)*(byte *)(iVar1 + 0x2e) * 9] < 6)) {
    uVar5 = *(undefined2 *)0x57fd;
    uVar8 = *(undefined2 *)0x57fb;
    uVar7 = ((undefined2 *)in_stack_0000000a)[1];
    uVar6 = *in_stack_0000000a;
    bVar2 = func_0x00000a23();
    if (1 < bVar2) {
      cVar3 = FUN_0000_09b5(0x32,uVar6,uVar7,uVar8,uVar5);
      if (cVar3 != '\0') {
        *(undefined1 *)0x72c6 = 0;
      }
    }
  }
  return;
}


