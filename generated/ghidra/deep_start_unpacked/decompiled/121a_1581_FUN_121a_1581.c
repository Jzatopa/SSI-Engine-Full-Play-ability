
int __stdcall16far FUN_121a_1581(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  byte local_13;
  int local_12;
  int local_6;
  int local_4;
  
  if (((uint)(int *)param_1 | param_1._2_2_) == 0) {
    local_6 = 0;
  }
  else {
    cVar1 = *(char *)0x44c8;
    local_6 = CONCAT11((char)(((uint)(int *)param_1 | param_1._2_2_) >> 8),cVar1);
    if (cVar1 == '\0') {
      iVar2 = ((int *)param_1)[1];
      local_12 = 0;
      local_6 = param_2 * 8;
      iVar3 = local_6 + *param_1 + -1;
      if (local_6 <= iVar3) {
        while( true ) {
          FUN_1cc0_1aaf(iVar2 * 2,param_3 << 1,*(undefined2 *)(local_6 * 2 + 0x4c1a),
                        (int)(int *)param_1 + local_12 + 0x1b,param_1._2_2_);
          local_12 = local_12 + iVar2 * 2;
          if (local_6 == iVar3) break;
          local_6 = local_6 + 1;
        }
      }
    }
    else if (cVar1 == '\x01') {
      local_12 = 0;
      local_6 = param_2 * 8;
      iVar2 = local_6 + *param_1 + -1;
      iVar3 = param_3 + ((int *)param_1)[1] + -1;
      out(0x3c4,2);
      if (local_6 <= iVar2) {
        while( true ) {
          if (param_3 <= iVar3) {
            local_4 = param_3;
            while( true ) {
              local_13 = 0;
              while( true ) {
                out(0x3c5,*(undefined1 *)(local_13 + 0x22ec));
                *(undefined1 *)(*(int *)(local_6 * 2 + 0x4daa) + local_4) =
                     *(undefined1 *)((int)(int *)param_1 + local_12 + 0x1b);
                local_12 = local_12 + 1;
                if (local_13 == 3) break;
                local_13 = local_13 + 1;
              }
              if (local_4 == iVar3) break;
              local_4 = local_4 + 1;
            }
          }
          if (local_6 == iVar2) break;
          local_6 = local_6 + 1;
        }
      }
      local_6 = CONCAT11((char)((uint)local_6 >> 8),0xf);
      out(0x3c5,0xf);
    }
    else if (cVar1 == '\x02') {
      iVar2 = ((int *)param_1)[1];
      local_12 = 0;
      local_6 = param_2 * 8;
      iVar3 = local_6 + *param_1 + -1;
      if (local_6 <= iVar3) {
        while( true ) {
          FUN_1cc0_1aaf(iVar2 * 4,param_3 << 2,*(undefined2 *)(local_6 * 2 + 0x4f3a),
                        (int)(int *)param_1 + local_12 + 0x1b,param_1._2_2_);
          local_12 = local_12 + iVar2 * 4;
          if (local_6 == iVar3) break;
          local_6 = local_6 + 1;
        }
      }
    }
    else if (cVar1 == '\x03') {
      iVar2 = ((int *)param_1)[1];
      local_12 = 0;
      local_6 = param_2 * 8;
      iVar3 = local_6 + *param_1 + -1;
      if (local_6 <= iVar3) {
        while( true ) {
          FUN_1cc0_1aaf(iVar2 * 8,param_3 * 8 + local_6 * 0x140,0xa000,
                        (int)(int *)param_1 + local_12 + 0x1b,param_1._2_2_);
          local_12 = local_12 + iVar2 * 8;
          if (local_6 == iVar3) break;
          local_6 = local_6 + 1;
        }
      }
    }
  }
  return local_6;
}


