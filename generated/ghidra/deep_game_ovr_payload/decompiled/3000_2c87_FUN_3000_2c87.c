
void __stdcall16far
FUN_3000_2c87(undefined1 param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4)

{
  uint uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 4) = param_1;
  uVar1 = FUN_3000_25e3(param_3,param_4);
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 5) =
       ((undefined *)&DAT_0000_69f0)[(uVar1 & 0xff) * 4];
  if (*(char *)0x7516 != '\0') {
    uVar2 = FUN_3000_256b(param_3,param_4);
    uVar3 = FUN_3000_2593(param_3,param_4);
    FUN_3000_2316(8,param_2,uVar3,uVar2);
  }
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 4) = 0;
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 5) = 1;
  return;
}


