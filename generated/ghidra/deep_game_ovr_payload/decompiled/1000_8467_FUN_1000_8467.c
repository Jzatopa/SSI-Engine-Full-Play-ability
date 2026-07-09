
void __stdcall16far FUN_1000_8467(void)

{
  undefined4 uVar1;
  undefined1 uVar2;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  uVar1 = *(undefined4 *)0x57fb;
  local_3 = 1;
  while( true ) {
    uVar2 = FUN_0000_088a(unaff_CS,local_3,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd);
    *(undefined1 *)((int)uVar1 + (uint)local_3 + 0x4c) = uVar2;
    if (local_3 == 0x55) break;
    local_3 = local_3 + 1;
    unaff_CS = 0x86;
  }
  return;
}


