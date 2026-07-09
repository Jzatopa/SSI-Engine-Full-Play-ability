
void FUN_2000_2986(undefined2 param_1,char param_2,char param_3)

{
  undefined2 unaff_DS;
  undefined1 local_107 [256];
  undefined1 local_7;
  undefined1 local_6 [4];
  
  if (param_2 == '\0') {
    local_7 = 0xf;
  }
  else {
    local_7 = 0xd;
  }
  func_0x00001140();
  FUN_0000_733e(0xec,CONCAT11(param_3 >> 7,
                              *(undefined1 *)((int)*(undefined4 *)0x57fb + (int)param_3 + 0x10)),
                local_107);
  func_0x0000d6dc(0x602,3,local_6);
  return;
}


