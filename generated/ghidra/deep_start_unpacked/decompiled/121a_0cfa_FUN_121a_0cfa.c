
void __stdcall16far
FUN_121a_0cfa(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined1 param_4,
             undefined1 param_5,undefined2 param_6,undefined2 param_7)

{
  char cVar1;
  undefined2 unaff_DS;
  
  cVar1 = *(char *)0x44c8;
  if (cVar1 == '\0') {
    FUN_121a_3103(param_1,param_2,(int)param_3,param_3._2_2_,param_4,param_5,param_6,param_7,
                  *(undefined2 *)0x44ce,*(undefined2 *)0x44d0);
  }
  else if (cVar1 == '\x01') {
    FUN_121a_3394(param_1,param_2,(int)param_3,param_3._2_2_,param_4,param_5,param_6,param_7,
                  *(undefined2 *)0x44ce,*(undefined2 *)0x44d0);
  }
  else if (cVar1 == '\x02') {
    FUN_121a_3646(param_1,param_2,(int)param_3,param_3._2_2_,param_4,param_5,param_6,param_7,
                  *(undefined2 *)0x44ce,*(undefined2 *)0x44d0);
  }
  else if (cVar1 == '\x03') {
    FUN_121a_3a09(param_1,param_2,(int)param_3,param_3._2_2_,param_4,param_5,
                  *(undefined1 *)((int)param_3 + 0x16),param_6,param_7,*(undefined2 *)0x44ce,
                  *(undefined2 *)0x44d0);
  }
  return;
}


