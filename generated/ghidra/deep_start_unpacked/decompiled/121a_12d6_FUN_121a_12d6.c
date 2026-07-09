
uint __stdcall16far FUN_121a_12d6(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined2 unaff_DS;
  char local_15;
  int local_14;
  int local_10;
  uint local_6;
  int local_4;
  
  if (((uint)(int *)param_1 | param_1._2_2_) == 0) {
    local_6 = 0;
  }
  else {
    cVar1 = *(char *)0x44c8;
    local_6 = CONCAT11((char)(((uint)(int *)param_1 | param_1._2_2_) >> 8),cVar1);
    if (cVar1 == '\0') {
      iVar2 = ((int *)param_1)[1];
      local_14 = 0;
      local_6 = param_2 * 8;
      uVar3 = (local_6 + *param_1) - 1;
      if ((int)local_6 <= (int)uVar3) {
        while( true ) {
          FUN_1cc0_1aaf(iVar2 * 2,(int)(int *)param_1 + local_14 + 0x1b,param_1._2_2_,param_3 << 1,
                        *(undefined2 *)(local_6 * 2 + 0x4c1a));
          local_14 = local_14 + iVar2 * 2;
          if (local_6 == uVar3) break;
          local_6 = local_6 + 1;
        }
      }
    }
    else if (cVar1 == '\x01') {
      local_14 = 0;
      local_6 = param_2 * 8;
      uVar3 = (local_6 + *param_1) - 1;
      iVar2 = param_3 + ((int *)param_1)[1] + -1;
      out(0x3ce,5);
      out(0x3cf,0);
      out(0x3ce,4);
      if ((int)local_6 <= (int)uVar3) {
        while( true ) {
          if (param_3 <= iVar2) {
            local_4 = param_3;
            while( true ) {
              local_15 = '\0';
              while( true ) {
                out(0x3cf,local_15);
                *(undefined1 *)((int)(int *)param_1 + local_14 + 0x1b) =
                     *(undefined1 *)(*(int *)(local_6 * 2 + 0x4daa) + local_4);
                local_14 = local_14 + 1;
                if (local_15 == '\x03') break;
                local_15 = local_15 + '\x01';
              }
              if (local_4 == iVar2) break;
              local_4 = local_4 + 1;
            }
          }
          if (local_6 == uVar3) break;
          local_6 = local_6 + 1;
        }
      }
      out(0x3cf,0);
      out(0x3ce,5);
      local_6 = local_6 & 0xff00;
      out(0x3cf,0);
    }
    else if (cVar1 == '\x03') {
      local_10 = param_2 * 0xa00 + param_3 * 8;
      local_14 = 0;
      iVar2 = ((int *)param_1)[1];
      local_6 = param_2 * 8;
      uVar3 = (local_6 + *param_1) - 1;
      if ((int)local_6 <= (int)uVar3) {
        while( true ) {
          FUN_1cc0_1aaf(iVar2 * 8,(int)(int *)param_1 + local_14 + 0x1b,param_1._2_2_,local_10,
                        0xa000);
          local_14 = local_14 + iVar2 * 8;
          local_10 = local_10 + 0x140;
          if (local_6 == uVar3) break;
          local_6 = local_6 + 1;
        }
      }
    }
    else if (cVar1 == '\x02') {
      iVar2 = ((int *)param_1)[1];
      local_14 = 0;
      local_6 = param_2 * 8;
      uVar3 = (local_6 + *param_1) - 1;
      if ((int)local_6 <= (int)uVar3) {
        while( true ) {
          FUN_1cc0_1aaf(iVar2 * 4,(int)(int *)param_1 + local_14 + 0x1b,param_1._2_2_,param_3 << 2,
                        *(undefined2 *)(local_6 * 2 + 0x4f3a));
          local_14 = local_14 + iVar2 * 4;
          if (local_6 == uVar3) break;
          local_6 = local_6 + 1;
        }
      }
    }
  }
  return local_6;
}


