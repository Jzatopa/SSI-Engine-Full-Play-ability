
void __cdecl16far FUN_187b_02c3(void)

{
  undefined2 unaff_DS;
  undefined1 local_3;
  
  FUN_187b_1548(0,0);
  FUN_187b_026d();
  FUN_187b_029c();
  local_3 = 0;
  while( true ) {
    if (*(int *)((uint)local_3 * 4 + -0x60f8) != 0 || *(int *)((uint)local_3 * 4 + -0x60f6) != 0) {
      FUN_1cc0_0254(*(undefined2 *)0x9f2c,*(undefined2 *)((uint)local_3 * 4 + -0x60f8),
                    *(undefined2 *)((uint)local_3 * 4 + -0x60f6));
      *(undefined2 *)((uint)local_3 * 4 + -0x60f8) = 0;
      *(undefined2 *)((uint)local_3 * 4 + -0x60f6) = 0;
    }
    if (local_3 == 8) break;
    local_3 = local_3 + 1;
  }
  if (*(int *)0x9ef2 != 0 || *(int *)0x9ef4 != 0) {
    FUN_1cc0_0254(*(undefined2 *)0x9ef0,*(undefined2 *)0x9ef2,*(undefined2 *)0x9ef4);
    *(undefined2 *)0x9ef2 = 0;
    *(undefined2 *)0x9ef4 = 0;
  }
  *(undefined1 *)0x50cf = *(undefined1 *)0x50d0;
  *(undefined1 *)0x50d0 = 0;
  return;
}


