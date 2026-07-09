
void __cdecl16far FUN_2000_bf38(void)

{
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  
  if (-1 < *(char *)0x5368) {
    unaff_CS = 0x21a;
    FUN_0000_3721();
  }
  *(undefined1 *)0x5368 = *(undefined1 *)((int)*(undefined4 *)0x5360 + 0x39);
  *(undefined1 *)0x5369 = *(undefined1 *)((int)*(undefined4 *)0x5360 + 0x3a);
  func_0x00003476(unaff_CS,*(undefined2 *)0x5364,*(undefined2 *)0x5366,
                  *(byte *)((int)*(undefined4 *)0x5360 + 0x3a) + 1,
                  *(byte *)((int)*(undefined4 *)0x5360 + 0x39) + 0x11);
  FUN_0000_13ba(CONCAT11((char)(*(byte *)((int)*(undefined4 *)0x5360 + 0x38) + 0x128 >> 8),1));
  return;
}


