
void __stdcall16far FUN_2000_dc31(int param_1,char param_2)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar1;
  int local_4;
  
  local_4 = 0;
  if (param_2 == '\0') {
    while ((local_4 < *(int *)((undefined *)&DAT_0000_ffa7 + param_1) &&
           (uVar1 = FUN_2000_c3ce(*(undefined2 *)(param_1 + 0x14),*(undefined2 *)(param_1 + 0x16),
                                  *(undefined2 *)*(undefined4 *)(param_1 + 10)),
           *(char *)((int)uVar1 + 0x29) != '\0'))) {
      local_4 = local_4 + 1;
      *(int *)*(undefined4 *)(param_1 + 10) = *(int *)*(undefined4 *)(param_1 + 10) + -1;
      if (*(int *)*(undefined4 *)(param_1 + 10) < *(int *)0x7455) {
        *(int *)*(undefined4 *)(param_1 + 10) =
             *(int *)0x7455 + *(int *)((undefined *)&DAT_0000_ffa7 + param_1) + -1;
      }
      if (*(int *)((undefined *)&DAT_0000_ffa9 + param_1) + -1 <
          *(int *)*(undefined4 *)(param_1 + 10)) {
        *(int *)*(undefined4 *)(param_1 + 10) = *(int *)((undefined *)&DAT_0000_ffa9 + param_1) + -1
        ;
      }
    }
  }
  else {
    while ((local_4 < *(int *)((undefined *)&DAT_0000_ffa7 + param_1) &&
           (uVar1 = FUN_2000_c3ce(*(undefined2 *)(param_1 + 0x14),*(undefined2 *)(param_1 + 0x16),
                                  *(undefined2 *)*(undefined4 *)(param_1 + 10)),
           *(char *)((int)uVar1 + 0x29) != '\0'))) {
      local_4 = local_4 + 1;
      *(int *)*(undefined4 *)(param_1 + 10) = *(int *)*(undefined4 *)(param_1 + 10) + 1;
      if (*(int *)0x7455 + *(int *)((undefined *)&DAT_0000_ffa7 + param_1) + -1 <
          *(int *)*(undefined4 *)(param_1 + 10)) {
        *(undefined2 *)*(undefined4 *)(param_1 + 10) = *(undefined2 *)0x7455;
      }
      if (*(int *)((undefined *)&DAT_0000_ffa9 + param_1) + -1 <
          *(int *)*(undefined4 *)(param_1 + 10)) {
        *(undefined2 *)*(undefined4 *)(param_1 + 10) = *(undefined2 *)0x7455;
      }
    }
  }
  return;
}


