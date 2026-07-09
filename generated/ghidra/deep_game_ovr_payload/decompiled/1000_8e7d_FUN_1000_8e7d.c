
void __stdcall16far FUN_1000_8e7d(int param_1)

{
  char cVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte local_3;
  
  if ((((undefined *)&DAT_0000_ffcc)[param_1] == '\a') && (1 < *(byte *)*(undefined4 *)0x57fb)) {
    if (*(char *)(param_1 + -0x3d) == *(char *)*(undefined4 *)0x57fb) {
      *(char *)*(undefined4 *)0x57fb = *(char *)*(undefined4 *)0x57fb + -1;
      *(undefined1 *)(param_1 + -0x3d) = *(undefined1 *)*(undefined4 *)0x57fb;
    }
    else {
      cVar1 = *(char *)*(undefined4 *)0x57fb;
      local_3 = *(byte *)(param_1 + -0x3d);
      if (local_3 <= (byte)(cVar1 - 1U)) {
        for (; *(undefined1 *)((int)*(undefined4 *)0x57fb + (uint)local_3) =
                    *(undefined1 *)((int)*(undefined4 *)0x57fb + local_3 + 1),
            local_3 != (byte)(cVar1 - 1U); local_3 = local_3 + 1) {
        }
      }
      *(char *)*(undefined4 *)0x57fb = *(char *)*(undefined4 *)0x57fb + -1;
    }
  }
  return;
}


