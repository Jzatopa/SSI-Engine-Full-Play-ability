
void __cdecl16far FUN_1b6f_0000(void)

{
  undefined1 uVar1;
  undefined1 extraout_AH;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_7;
  undefined1 local_6 [2];
  undefined1 local_4 [2];
  
  FUN_1cc0_1ad2(0,0x38,0x8d80,unaff_DS);
  if (*(char *)0x8db8 != '\0') {
    uVar1 = FUN_1b6f_060d(&local_7,unaff_SS,local_6,unaff_SS,local_4,unaff_SS,
                          CONCAT11(extraout_AH,1));
    *(undefined1 *)0x8db8 = uVar1;
  }
  return;
}


