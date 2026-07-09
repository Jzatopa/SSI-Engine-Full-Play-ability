
void __stdcall16far FUN_0000_ae00(undefined4 param_1)

{
  char cVar1;
  undefined1 extraout_AH;
  int iVar2;
  undefined2 uVar3;
  byte bVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 *puVar8;
  undefined1 in_stack_0000ffe8;
  undefined1 in_stack_0000ffea;
  undefined1 in_stack_0000ffec;
  undefined2 local_12;
  undefined1 local_f [7];
  int local_8;
  int iStack_6;
  char local_4;
  char local_3;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  if (*(char *)(iVar5 + 0xd5) == '\0') {
    FUN_0000_0a28();
  }
  else {
    local_4 = '\0';
    local_12 = CONCAT11(local_12._1_1_,1);
    while (local_4 == '\0') {
      *(undefined1 *)0x7457 = 1;
      puVar8 = &local_12;
      uVar3 = unaff_SS;
      FUN_0000_b25b(unaff_CS,&local_3);
      uVar7 = unaff_CS;
      if (*(char *)0x7458 == '\0') {
        iVar2 = CONCAT11(extraout_AH,local_3);
        if (local_3 == 'M') {
          FUN_0000_b73b(&local_4,unaff_SS,CONCAT11(extraout_AH,0x20),iVar5,uVar6);
        }
        else if (local_3 == 'T') {
          FUN_0000_ad9c(iVar5,uVar6);
          FUN_0000_05bc(unaff_CS,local_f);
          uVar7 = 0x56;
        }
        else {
          if (local_3 == 'V') {
            FUN_0000_0832(&local_4);
                    /* WARNING: Subroutine does not return */
            thunk_FUN_0000_d6c2(iVar5,uVar6,unaff_SS,in_stack_0000ffe8,in_stack_0000ffea);
          }
          if (local_3 == 'I') {
            FUN_0000_05d0(unaff_CS,iVar5,uVar6);
            local_4 = FUN_0000_0a28(0x56,iVar5,uVar6);
            uVar7 = 0x99;
          }
          else if (local_3 == 'Q') {
            FUN_0000_bbb6(iVar5,uVar6);
            FUN_0000_7329(unaff_CS);
            FUN_0000_872f();
            FUN_0000_c05c(200,in_stack_0000ffe8,in_stack_0000ffea,in_stack_0000ffec);
            local_4 = '\x01';
            in_stack_0000ffec = (undefined1)param_1;
            in_stack_0000ffea = 0xdc;
            in_stack_0000ffe8 = 5;
            local_12 = uVar6;
            FUN_0000_0445();
            uVar7 = 0x42;
          }
          else if (local_3 == 'A') {
            FUN_0000_080f(unaff_CS,iVar5,uVar6);
            local_4 = FUN_0000_0a28(0x7e,iVar5,uVar6);
            uVar7 = 0x99;
          }
          else if (local_3 == 'S') {
            if (*(char *)(iVar5 + 0xd4) != '\v') {
              *(undefined1 *)(iVar5 + 0xd4) = 0xb;
              iVar2 = (uint)*(byte *)((int)*(undefined4 *)(iVar5 + 0xf3) + 3) << 1;
              *(undefined1 *)((int)*(undefined4 *)(iVar5 + 0xf3) + 3) = (char)iVar2;
            }
            FUN_0000_b73b(&local_4,unaff_SS,CONCAT11((char)((uint)iVar2 >> 8),0x20),iVar5,uVar6);
          }
          else if (local_3 == 'D') {
            *(undefined1 *)(iVar5 + 0xd4) = 10;
            local_4 = FUN_0000_0a28(unaff_CS,iVar5,uVar6);
            uVar7 = 0x99;
          }
          else if (local_3 == 'J') {
            uVar7 = 0x56;
            func_0x000005e4(unaff_CS,iVar5,uVar6);
            local_4 = *(char *)((int)*(undefined4 *)(iVar5 + 0xf3) + 1) == '\0';
          }
          else if (local_3 == 'W') {
            *(undefined1 *)((int)*(undefined4 *)(iVar5 + 0xf3) + 1) = 1;
            *(undefined1 *)0x7817 = *(undefined1 *)0x7637;
            iVar2 = (*(char *)0x7817 + 1) * 4;
            _local_8 = CONCAT22(*(undefined2 *)((undefined *)&DAT_0000_7515 + iVar2),
                                *(undefined2 *)((undefined *)&DAT_0000_7513 + iVar2));
            while( true ) {
              if ((local_8 == 0 && iStack_6 == 0) || ('G' < *(char *)0x7817)) break;
              cVar1 = *(char *)0x7817;
              *(int *)((undefined *)&DAT_0000_7513 + cVar1 * 4) = local_8;
              *(int *)((undefined *)&DAT_0000_7515 + cVar1 * 4) = iStack_6;
              *(char *)0x7817 = *(char *)0x7817 + '\x01';
              iVar2 = (*(char *)0x7817 + 1) * 4;
              _local_8 = CONCAT22(*(undefined2 *)((undefined *)&DAT_0000_7515 + iVar2),
                                  *(undefined2 *)((undefined *)&DAT_0000_7513 + iVar2));
            }
            cVar1 = *(char *)0x7817;
            *(int *)((undefined *)&DAT_0000_7513 + cVar1 * 4) = iVar5;
            *(undefined2 *)((undefined *)&DAT_0000_7515 + cVar1 * 4) = uVar6;
            *(char *)0x7637 = *(char *)0x7637 + -1;
            local_4 = '\x01';
          }
          else if (local_3 == 'G') {
            local_4 = func_0x0000058a(unaff_CS,iVar5,uVar6);
            uVar7 = 0x56;
          }
          else if (local_3 == 'E') {
            local_4 = FUN_0000_0a28(unaff_CS,iVar5,uVar6);
            uVar7 = 0x99;
          }
          else if (local_3 == ' ') {
            _local_8 = CONCAT22(*(undefined2 *)0x5801,*(undefined2 *)0x57ff);
            while( true ) {
              if (local_8 == 0 && iStack_6 == 0) break;
              in_stack_0000ffea = (undefined1)((ulong)_local_8 >> 8);
              in_stack_0000ffec = (undefined1)((ulong)_local_8 >> 0x18);
              if (((*(char *)(local_8 + 0xd6) == '\0') && (*(char *)(local_8 + 0x4c) == '\0')) &&
                 (*(char *)((int)*(undefined4 *)(local_8 + 0xf3) + 0xf) == '\0')) {
                *(undefined1 *)(local_8 + 0xd7) = 0;
              }
              _local_8 = CONCAT22(*(undefined2 *)(local_8 + 0x101),*(undefined2 *)(local_8 + 0xff));
            }
          }
        }
      }
      else if ((local_3 == '\x10') || (local_3 == '\x1e')) {
        *(char *)0x7637 = *(char *)0x7637 + -1;
        *(undefined1 *)((int)*(undefined4 *)(iVar5 + 0xf3) + 1) = 0x14;
        _local_8 = CONCAT22(*(undefined2 *)0x5801,*(undefined2 *)0x57ff);
        while( true ) {
          if (local_8 == 0 && iStack_6 == 0) break;
          puVar8 = (undefined2 *)0xb11c;
          uVar3 = unaff_CS;
          FUN_0000_bbb6(local_8,iStack_6);
          uVar7 = (undefined2)((ulong)_local_8 >> 0x10);
          _local_8 = CONCAT22(*(undefined2 *)((int)_local_8 + 0x101),
                              *(undefined2 *)((int)_local_8 + 0xff));
        }
        uVar7 = 0xb136;
        FUN_0000_7329(unaff_CS);
        FUN_0000_c05c(200,puVar8,uVar3,uVar7,unaff_CS);
        local_4 = '\x01';
        uVar7 = 0xbdc;
      }
      else if (local_3 == '-') {
        uVar3 = FUN_0000_05cb(unaff_CS);
        bVar4 = (byte)((uint)uVar3 >> 8);
        uVar7 = 0x56;
        if ((char)uVar3 != '\0') {
          func_0x00000e43(0x56,(uint)bVar4 << 8,CONCAT11(bVar4,3),iVar5,uVar6);
          local_4 = '\x01';
          uVar7 = 0xdb;
        }
      }
      unaff_CS = uVar7;
      if (local_4 == '\0') {
        func_0x00000e43(uVar7,1,2,iVar5,uVar6);
        *(undefined *)&DAT_0000_7515 = 1;
        unaff_CS = 0x99;
        func_0x000009c9(0xdb,iVar5,uVar6);
      }
    }
  }
  return;
}


