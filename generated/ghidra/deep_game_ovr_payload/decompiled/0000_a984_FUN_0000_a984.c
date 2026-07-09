
void __cdecl16far FUN_0000_a984(void)

{
  int *piVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  int local_7;
  int iStack_5;
  
  *(undefined1 *)0x4438 = 5;
  func_0x000005df();
  uVar3 = 0x45;
  FUN_0000_0475(0x56);
  bVar2 = false;
  if ((*(char *)0x72c2 == '\0') || (*(char *)0x72c3 == '\0')) {
    bVar2 = true;
  }
  else {
    *(undefined1 *)0x8c2d = 1;
  }
  while (!bVar2) {
    func_0x00000a19(uVar3);
    FUN_0000_05d5(0x99);
    iStack_5 = *(int *)0x5801;
    local_7 = *(int *)0x57ff;
    while (local_7 != 0 || iStack_5 != 0) {
      FUN_0000_058f(0x56,local_7,iStack_5);
      piVar1 = (int *)(local_7 + 0xff);
      iStack_5 = *(int *)(local_7 + 0x101);
      local_7 = *piVar1;
    }
    *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2cb) = 0;
    FUN_0000_aaa7();
    local_7 = *(int *)0x7517;
    iStack_5 = *(int *)0x7519;
    *(undefined1 *)0x7637 = 1;
    uVar3 = 0x56;
    while ((local_7 != 0 || iStack_5 != 0 && (!bVar2))) {
      FUN_0000_ac2d(local_7,iStack_5);
      *(char *)0x7637 = *(char *)0x7637 + '\x01';
      if (*(byte *)0x7637 < 0x49) {
        local_7 = *(int *)((undefined *)&DAT_0000_7513 + (uint)*(byte *)0x7637 * 4);
        iStack_5 = *(int *)((undefined *)&DAT_0000_7515 + (uint)*(byte *)0x7637 * 4);
      }
      else {
        local_7 = 0;
        iStack_5 = 0;
      }
      func_0x00000a19(uVar3);
      uVar3 = 0x99;
      if (((*(char *)0x72c2 == '\0') || (*(char *)0x72c3 == '\0')) ||
         (*(byte *)&DAT_0000_74ba <= *(byte *)0x74b9)) {
        bVar2 = true;
      }
    }
    FUN_0000_b5a3(uVar3);
  }
  FUN_0000_a872();
  *(undefined1 *)0x4448 = 1;
  return;
}


