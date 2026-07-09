
void __stdcall16far FUN_0000_e7ea(char param_1,char param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 unaff_CS;
  undefined2 uVar3;
  undefined2 unaff_DS;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_3 = 0;
  while( true ) {
    local_4 = 0;
    uVar3 = unaff_CS;
    while( true ) {
      unaff_CS = uVar3;
      if (*(char *)((int)*(undefined4 *)0x71dc + (uint)local_4 * 0x32 + (uint)local_3 + 7) == '\x06'
         ) {
        uVar2 = (undefined1)((uint)local_4 * 0x32 >> 8);
        local_5 = param_2;
        if (param_1 != '\0') {
          unaff_CS = 0x99;
          cVar1 = FUN_0000_09ba(uVar3,CONCAT11(uVar2,param_1),CONCAT11(uVar2,1));
          local_5 = param_2 + cVar1 + -1;
        }
        *(char *)((int)*(undefined4 *)0x71dc + (uint)local_4 * 0x32 + (uint)local_3 + 7) = local_5;
      }
      if (local_4 == 0x18) break;
      local_4 = local_4 + 1;
      uVar3 = unaff_CS;
    }
    if (local_3 == 0x31) break;
    local_3 = local_3 + 1;
  }
  return;
}


