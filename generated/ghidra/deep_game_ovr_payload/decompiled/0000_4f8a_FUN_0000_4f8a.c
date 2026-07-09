
void FUN_0000_4f8a(void)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  undefined2 in_AX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  cVar3 = *(char *)0x468a;
  pcVar1 = (char *)(in_BX + unaff_SI + -0x1f2f);
  *pcVar1 = *pcVar1 + '\x01';
  pcVar1 = (char *)((int)*(undefined4 *)(unaff_BP + 0xc) +
                    CONCAT11((char)((uint)in_AX >> 8),(char)in_AX + cVar3) * 3 + 0x3e);
  *pcVar1 = *pcVar1 + -1;
  if ((*(int *)(unaff_BP + 0xe) == *(int *)0x534c) && (*(int *)(unaff_BP + 0xc) == *(int *)0x534a))
  {
    func_0x00000a5f();
  }
  if (*(char *)(unaff_BP + -2) != '\a') {
    FUN_0000_4ebe();
    return;
  }
  if (*(char *)(unaff_BP + -8) != '\0') {
    FUN_0000_4a92(*(undefined2 *)(unaff_BP + 6),1,100);
  }
  cVar3 = FUN_0000_09b5(*(uint *)(unaff_BP + 8) >> 1);
  if ((cVar3 != '\0') && (*(int *)((int)*(undefined4 *)(unaff_BP + 0xc) + 0x30) != 0)) {
    piVar2 = (int *)((int)*(undefined4 *)(unaff_BP + 0xc) + 0x30);
    *piVar2 = *piVar2 + -1;
  }
  return;
}


