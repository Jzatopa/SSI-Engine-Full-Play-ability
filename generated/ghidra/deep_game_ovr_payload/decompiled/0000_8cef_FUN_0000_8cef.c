
void FUN_0000_8cef(void)

{
  int *piVar1;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_25 [7];
  int local_1e;
  int iStack_1c;
  undefined1 local_1a;
  undefined2 local_6;
  undefined2 local_4;
  
  local_1a = 1;
  iStack_1c = *(int *)0x72c0;
  local_1e = *(int *)0x72be;
  while (local_1e != 0 || iStack_1c != 0) {
    FUN_0000_09bf(unaff_CS,0,0,0,0,local_1e,iStack_1c,0,0);
    piVar1 = (int *)(local_1e + 0x2a);
    iStack_1c = *(int *)(local_1e + 0x2c);
    unaff_CS = 0x99;
    local_1e = *piVar1;
  }
  local_6 = *(undefined2 *)0x72be;
  local_4 = *(undefined2 *)0x72c0;
  *(undefined1 *)0x7457 = 1;
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x963,unaff_CS,local_25,unaff_SS);
}


