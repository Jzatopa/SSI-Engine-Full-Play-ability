
void __stdcall16far FUN_2000_768a(char *param_1,int param_2,char param_3,undefined4 param_4)

{
  int *piVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  undefined4 local_a;
  int local_6;
  int iStack_4;
  
  local_a = (char *)CONCAT22(param_2,param_1);
  if (param_1 == (char *)0x0 && param_2 == 0) {
    uVar5 = (undefined2)((ulong)param_4 >> 0x10);
    local_a = (char *)CONCAT22(*(undefined2 *)((int)param_4 + 0xfd),
                               (char *)*(undefined2 *)((int)param_4 + 0xfb));
    while( true ) {
      if (((char *)local_a == (char *)0x0 && local_a._2_2_ == 0) || (*local_a == param_3)) break;
      local_a = (char *)CONCAT22(*(undefined2 *)((char *)local_a + 7),
                                 *(char **)((char *)local_a + 5));
    }
  }
  if (((uint)(char *)local_a | local_a._2_2_) != 0) {
    if (((char *)local_a)[4] != '\0') {
      uVar3 = (undefined1)(((uint)(char *)local_a | local_a._2_2_) >> 8);
      FUN_2000_77e5(CONCAT11(uVar3,1),(char *)local_a,local_a._2_2_,&param_4,unaff_SS,
                    CONCAT11(uVar3,param_3));
    }
    uVar5 = (undefined2)((ulong)param_4 >> 0x10);
    iVar4 = (int)param_4;
    if ((*(uint *)(iVar4 + 0xfd) == local_a._2_2_) &&
       ((char *)*(undefined2 *)(iVar4 + 0xfb) == (char *)local_a)) {
      uVar2 = *(undefined2 *)((char *)local_a + 7);
      *(undefined2 *)(iVar4 + 0xfb) = *(undefined2 *)((char *)local_a + 5);
      *(undefined2 *)(iVar4 + 0xfd) = uVar2;
    }
    else {
      iStack_4 = *(int *)(iVar4 + 0xfd);
      local_6 = *(int *)(iVar4 + 0xfb);
      while ((local_6 != 0 || iStack_4 != 0 &&
             ((*(uint *)(local_6 + 7) != local_a._2_2_ ||
              ((char *)*(undefined2 *)(local_6 + 5) != (char *)local_a))))) {
        piVar1 = (int *)(local_6 + 5);
        iStack_4 = *(int *)(local_6 + 7);
        local_6 = *piVar1;
      }
      uVar5 = *(undefined2 *)((char *)local_a + 7);
      *(undefined2 *)(local_6 + 5) = *(undefined2 *)((char *)local_a + 5);
      *(undefined2 *)(local_6 + 7) = uVar5;
    }
    FUN_0000_ce54();
  }
  return;
}


