
void __stdcall16far FUN_2000_ddf3(int param_1,char param_2)

{
  int iVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (param_2 == '\0') {
    *(int *)*(undefined4 *)(param_1 + 10) = *(int *)*(undefined4 *)(param_1 + 10) + -1;
    if (*(int *)*(undefined4 *)(param_1 + 10) < *(int *)0x7455) {
      *(int *)*(undefined4 *)(param_1 + 10) =
           *(int *)0x7455 + *(int *)((undefined *)&DAT_0000_ffa7 + param_1) + -1;
    }
    iVar1 = *(int *)((undefined *)&DAT_0000_ffa9 + param_1) + -1;
    if (iVar1 < *(int *)*(undefined4 *)(param_1 + 10)) {
      iVar1 = *(int *)((undefined *)&DAT_0000_ffa9 + param_1) + -1;
      *(int *)*(undefined4 *)(param_1 + 10) = iVar1;
    }
  }
  else {
    *(int *)*(undefined4 *)(param_1 + 10) = *(int *)*(undefined4 *)(param_1 + 10) + 1;
    if (*(int *)0x7455 + *(int *)((undefined *)&DAT_0000_ffa7 + param_1) + -1 <
        *(int *)*(undefined4 *)(param_1 + 10)) {
      *(undefined2 *)*(undefined4 *)(param_1 + 10) = *(undefined2 *)0x7455;
    }
    iVar1 = *(int *)((undefined *)&DAT_0000_ffa9 + param_1) + -1;
    if (iVar1 < *(int *)*(undefined4 *)(param_1 + 10)) {
      iVar1 = *(int *)0x7455;
      *(int *)*(undefined4 *)(param_1 + 10) = iVar1;
    }
  }
  FUN_2000_dc31(param_1,CONCAT11((char)((uint)iVar1 >> 8),param_2));
  return;
}


