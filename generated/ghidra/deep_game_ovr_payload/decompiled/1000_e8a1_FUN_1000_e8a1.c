
void __stdcall16far FUN_1000_e8a1(uint param_1,int param_2,uint param_3,int param_4)

{
  undefined2 unaff_DS;
  
  FUN_0000_e6d2(0);
  if ((param_4 == param_2) && (param_3 == param_1)) {
    *(undefined1 *)0x7648 = 1;
  }
  if ((param_4 != param_2) || (param_3 != param_1)) {
    *(undefined1 *)0x7649 = 1;
  }
  if ((param_4 < param_2) || ((param_4 <= param_2 && (param_3 < param_1)))) {
    *(undefined1 *)0x764a = 1;
  }
  if ((param_2 < param_4) || ((param_2 <= param_4 && (param_1 < param_3)))) {
    *(undefined1 *)0x764b = 1;
  }
  if ((param_4 < param_2) || ((param_4 <= param_2 && (param_3 <= param_1)))) {
    *(undefined1 *)0x764c = 1;
  }
  if ((param_2 < param_4) || ((param_2 <= param_4 && (param_1 <= param_3)))) {
    *(undefined1 *)0x764d = 1;
  }
  return;
}


