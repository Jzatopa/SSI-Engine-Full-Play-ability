
undefined2 __stdcall16far FUN_1000_d4dd(char param_1,char param_2,char param_3)

{
  bool bVar1;
  undefined2 in_AX;
  undefined1 uVar2;
  undefined2 unaff_CS;
  undefined2 uVar3;
  undefined2 unaff_DS;
  byte local_5;
  
  uVar2 = (undefined1)((uint)in_AX >> 8);
  local_5 = 0;
  bVar1 = false;
  if (*(char *)((int)*(undefined4 *)0x4418 + 0xe6) == '\0') {
    local_5 = 2;
    *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c1) = 2;
  }
  else {
    while ((uVar2 = (undefined1)((uint)in_AX >> 8), local_5 < 5 && (!bVar1))) {
      uVar3 = 0xd1;
      in_AX = FUN_0000_0d3a(unaff_CS,CONCAT11(uVar2,param_1),CONCAT11(uVar2,param_2),
                            CONCAT11(uVar2,param_3));
      unaff_CS = uVar3;
      if ((char)in_AX == '\0') {
        local_5 = local_5 + 1;
        in_AX = CONCAT11((char)((uint)in_AX >> 8),param_1);
        if (param_1 == '\0') {
          param_2 = param_2 + -1;
        }
        else if (param_1 == '\x02') {
          param_3 = param_3 + '\x01';
        }
        else if (param_1 == '\x04') {
          param_2 = param_2 + '\x01';
        }
        else if (param_1 == '\x06') {
          param_3 = param_3 + -1;
        }
      }
      else {
        bVar1 = true;
      }
    }
  }
  return CONCAT11(uVar2,local_5);
}


