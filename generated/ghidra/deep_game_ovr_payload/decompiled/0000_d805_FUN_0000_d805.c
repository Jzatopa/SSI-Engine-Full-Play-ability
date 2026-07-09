
/* WARNING: Removing unreachable block (ram,0x0000d8b5) */
/* WARNING: Removing unreachable block (ram,0x0000d8a6) */

void FUN_0000_d805(void)

{
  undefined2 uVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 unaff_DS;
  char in_stack_00000008;
  undefined4 in_stack_0000000a;
  char local_5;
  
  uVar10 = (undefined2)((ulong)in_stack_0000000a >> 0x10);
  iVar6 = (int)in_stack_0000000a;
  uVar11 = (undefined2)((ulong)*(undefined4 *)(iVar6 + 0xf3) >> 0x10);
  iVar7 = (int)*(undefined4 *)(iVar6 + 0xf3);
  iVar8 = *(int *)(iVar7 + 8);
  iVar7 = *(int *)(iVar7 + 10);
  if (iVar8 != 0 || iVar7 != 0) {
    if ((*(char *)(iVar8 + 0xd6) != *(char *)(iVar6 + 0xd6)) && (*(char *)(iVar8 + 0xd5) != '\0')) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_0000_643a();
    }
    uVar11 = (undefined2)((ulong)*(undefined4 *)(iVar6 + 0xf3) >> 0x10);
    iVar8 = (int)*(undefined4 *)(iVar6 + 0xf3);
    *(undefined2 *)(iVar8 + 8) = 0;
    *(undefined2 *)(iVar8 + 10) = 0;
  }
  uVar11 = (undefined2)((ulong)*(undefined4 *)(iVar6 + 0xf3) >> 0x10);
  iVar8 = (int)*(undefined4 *)(iVar6 + 0xf3);
  if (*(int *)(iVar8 + 8) != 0 || *(int *)(iVar8 + 10) != 0) {
    FUN_0000_d9cf();
    return;
  }
  local_5 = '\x14';
  uVar5 = 0xff;
  iVar8 = iVar6;
  uVar11 = uVar10;
  cVar3 = func_0x00000a1e();
  bVar2 = false;
  while( true ) {
    if (local_5 == '\0') {
      FUN_0000_d9c2();
      return;
    }
    if (bVar2) break;
    if (cVar3 == '\0') {
      FUN_0000_d9c2();
      return;
    }
    local_5 = local_5 + -1;
    bVar4 = FUN_0000_09ba(0x99,cVar3,1,uVar5,iVar8,uVar11);
    if (((undefined *)&DAT_0000_74ba)[bVar4] != '\0') {
      iVar7 = (uint)(byte)((undefined *)&DAT_0000_74ba)[bVar4] * 4;
      uVar1 = *(undefined2 *)((undefined *)&DAT_0000_7081 + iVar7);
      if ((in_stack_00000008 == '\0') || (*(char *)((int)*(undefined4 *)0x71dc + 6) == '\0')) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_0000_643a(0x99,*(undefined2 *)((undefined *)&DAT_0000_707f + iVar7),uVar1,iVar6,
                            uVar10);
      }
      bVar2 = true;
      uVar12 = (undefined2)((ulong)*(undefined4 *)(iVar6 + 0xf3) >> 0x10);
      iVar9 = (int)*(undefined4 *)(iVar6 + 0xf3);
      *(undefined2 *)(iVar9 + 8) = *(undefined2 *)((undefined *)&DAT_0000_707f + iVar7);
      *(undefined2 *)(iVar9 + 10) = uVar1;
    }
  }
  FUN_0000_d9c2();
  return;
}


