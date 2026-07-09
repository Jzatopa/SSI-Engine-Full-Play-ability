
/* WARNING: Instruction at (ram,0x00007391) overlaps instruction at (ram,0x00007390)
    */
/* WARNING: Removing unreachable block (ram,0x0000735e) */
/* WARNING: Removing unreachable block (ram,0x0000736a) */
/* WARNING: Removing unreachable block (ram,0x00007376) */
/* WARNING: Removing unreachable block (ram,0x000073de) */
/* WARNING: Removing unreachable block (ram,0x0000736f) */
/* WARNING: Removing unreachable block (ram,0x000073d6) */
/* WARNING: Removing unreachable block (ram,0x00007371) */
/* WARNING: Removing unreachable block (ram,0x00007374) */
/* WARNING: Removing unreachable block (ram,0x000073e3) */
/* WARNING: Removing unreachable block (ram,0x00007379) */
/* WARNING: Removing unreachable block (ram,0x000073ec) */
/* WARNING: Removing unreachable block (ram,0x000073ee) */
/* WARNING: Removing unreachable block (ram,0x000073e8) */
/* WARNING: Removing unreachable block (ram,0x000073f0) */
/* WARNING: Removing unreachable block (ram,0x0000738b) */
/* WARNING: Removing unreachable block (ram,0x00007396) */

void FUN_0000_733e(int param_1,undefined1 *param_2,undefined2 param_3,int param_4,undefined2 param_5
                  ,char param_6,undefined2 param_7)

{
  char *pcVar1;
  undefined2 uVar2;
  byte in_AL;
  byte bVar3;
  undefined1 uVar4;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_CF;
  undefined2 *in_stack_00000000;
  int in_stack_00000042;
  int in_stack_00000048;
  char in_stack_0000004c;
  int in_stack_0000004e;
  undefined2 *puStack0050;
  int iStack0052;
  undefined1 *in_stack_00000054;
  int in_stack_00000058;
  undefined2 in_stack_0000005a;
  byte in_stack_0000005c;
  byte in_stack_0000005e;
  
  bVar3 = in_AL + 0x54;
  if (0xab < in_AL || CARRY1(bVar3,in_CF)) {
    *(char *)(param_4 + param_1) = *(char *)(param_4 + param_1) + (char)param_7;
    *(char *)(param_4 + param_1) = *(char *)(param_4 + param_1) + (char)param_7;
    *(char *)((int)in_stack_00000000 + -0x77) =
         *(char *)((int)in_stack_00000000 + -0x77) + (char)param_5;
    in(0x81);
    in(param_5);
    in_stack_00000054 = param_2;
code_r0x000073ba:
    uVar4 = func_0x00000a91();
    in_stack_00000054[-0x106] = uVar4;
    param_7 = *(undefined2 *)0x57ff;
  }
  else {
    if ((byte)(bVar3 + in_CF) == '\0') {
      *(int *)(in_stack_00000048 + in_stack_00000042) =
           *(int *)(in_stack_00000048 + in_stack_00000042) + in_stack_0000004e;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + in_stack_0000004c;
      bVar3 = (byte)in_stack_0000004e;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + bVar3;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + bVar3;
      *(byte *)(in_stack_00000048 + in_stack_00000042) =
           *(byte *)(in_stack_00000048 + in_stack_00000042) | bVar3;
      *(byte *)(in_stack_00000048 + in_stack_00000042) =
           *(byte *)(in_stack_00000048 + in_stack_00000042) | bVar3;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + bVar3;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + bVar3;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + bVar3;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + bVar3;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + bVar3;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + bVar3;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + bVar3;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + bVar3;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + bVar3;
      *(char *)(in_stack_00000048 + in_stack_00000042) =
           *(char *)(in_stack_00000048 + in_stack_00000042) + bVar3;
LAB_0000_73ae_2:
      in_stack_00000054 = &stack0x0366;
      goto code_r0x000073ba;
    }
    if (0xab >= in_AL && !CARRY1(bVar3,in_CF)) goto LAB_0000_73ae_2;
    if ((char)(bVar3 + in_CF) < '\0') {
      uVar2 = in(param_5);
      *in_stack_00000000 = uVar2;
      puVar5 = puStack0050 + 1;
      uVar2 = in(in_stack_0000005a);
      *puStack0050 = uVar2;
      in_stack_00000054[iStack0052] = in_stack_00000054[iStack0052] & in_stack_0000005e;
      *(byte *)(in_stack_00000058 + iStack0052) =
           *(byte *)(in_stack_00000058 + iStack0052) & in_stack_0000005c;
      (in_stack_00000054 + (int)puVar5)[0x67e] = (in_stack_00000054 + (int)puVar5)[0x67e] + -1;
      goto code_r0x000073d7;
    }
    pcVar1 = (char *)(param_4 + param_1 + -0x57a);
    *pcVar1 = *pcVar1 + param_6;
    pcVar1 = (char *)((int)in_stack_00000000 + param_4 + 0x57ff);
    *pcVar1 = *pcVar1 + '\x01';
    in_stack_00000054 = param_2;
  }
  uVar2 = *(undefined2 *)0x5801;
  *(undefined2 *)(in_stack_00000054 + -4) = param_7;
  *(undefined2 *)(in_stack_00000054 + -2) = uVar2;
  puVar5 = *(undefined2 **)(in_stack_00000054 + 6);
code_r0x000073d7:
  *(undefined1 *)((int)puVar5 + -5) = 0;
  if (*(int *)(in_stack_00000054 + -4) == 0 && *(int *)(in_stack_00000054 + -2) == 0) {
    FUN_0000_792f();
    return;
  }
  if (((undefined *)&DAT_0000_fffa)[*(int *)(in_stack_00000054 + 6)] != '\0') {
    FUN_0000_792f();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(in_stack_00000054 + -4) + 0xd4) == '\x01') {
    in_stack_00000054[-0x105] = 0;
    func_0x00001140();
    func_0x00006e7f();
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2();
  }
  FUN_0000_7919();
  return;
}


