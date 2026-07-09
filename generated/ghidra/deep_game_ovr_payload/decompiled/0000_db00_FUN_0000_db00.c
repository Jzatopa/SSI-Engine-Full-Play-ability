
void __stdcall16far FUN_0000_db00(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined2 *)0x3dd2;
  *(undefined2 *)0x4014 = *(undefined2 *)0x3dd0;
  *(undefined2 *)0x4016 = uVar1;
  *(undefined2 *)0x3dd0 = param_1;
  *(undefined2 *)0x3dd2 = param_2;
  return;
}


