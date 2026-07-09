
void __cdecl16far FUN_2000_ea42(void)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 unaff_DS;
  
  if (*(char *)0x4446 == '\0') {
    cVar1 = *(char *)((int)*(undefined4 *)0x4418 + 0xe6);
    if ((cVar1 == -0x5e) || (cVar1 == -0x58)) {
      if (*(char *)0x74aa != '\0') {
        func_0x00000bbe();
      }
    }
    else if (cVar1 == 'p') {
      FUN_0000_0ba5();
    }
    else {
      if (*(char *)0x4438 != '\x04') {
        return;
      }
      uVar3 = (uint)*(byte *)0x7369;
      uVar4 = (uint)*(byte *)0x736a;
      uVar2 = func_0x00000d44();
      *(undefined1 *)0x736d = uVar2;
      if (*(byte *)0x736d < 0x80) {
        *(undefined1 *)0x7364 =
             *(undefined1 *)(*(byte *)((int)*(undefined4 *)0x4418 + 0xfd) + 0xebc);
      }
      else {
        *(undefined1 *)0x7364 =
             *(undefined1 *)(*(byte *)((int)*(undefined4 *)0x4418 + 0xfe) + 0xebc);
      }
      uVar2 = 0;
      if (*"" == '\0') {
        if (*(char *)0x8c37 == '\0') {
          *(undefined1 *)0x7367 = 8;
        }
        else {
          uVar2 = FUN_2000_e99c(&stack0xfffe,*(undefined1 *)0x7639);
          *(undefined1 *)0x7365 = uVar2;
          uVar2 = FUN_2000_e9d0(&stack0xfffe,*(undefined1 *)0x7639);
          *(undefined1 *)0x7366 = uVar2;
          uVar2 = FUN_2000_ea04(&stack0xfffe,*(code *)FUN_0000_7638);
          *(undefined1 *)0x7367 = uVar2;
          FUN_0000_0d35(0xd1,*(undefined1 *)0x7367,*(undefined1 *)0x7366,*(undefined1 *)0x7365,
                        *(undefined1 *)0x7364,uVar4,uVar3);
          uVar2 = extraout_AH;
        }
      }
      if (*(char *)0x9ed7 != '\0') {
        FUN_0000_49de(0x96c7,unaff_DS);
        *(undefined1 *)0x9ed7 = 0;
        uVar2 = extraout_AH_00;
      }
      if ((*(char *)((int)*(undefined4 *)0x4418 + 0xfb) != '\0') ||
         (*(char *)((int)*(undefined4 *)0x4418 + 0x1fd) != -1)) {
        *(undefined1 *)0x7368 = 0;
      }
      FUN_0000_0d49(CONCAT11(uVar2,*(undefined1 *)0x736b),CONCAT11(uVar2,*(undefined1 *)0x736a),
                    CONCAT11(uVar2,*(undefined1 *)0x7369));
    }
    *(undefined1 *)0x74aa = 0;
  }
  return;
}


