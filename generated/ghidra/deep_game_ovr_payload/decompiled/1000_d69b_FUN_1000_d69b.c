
undefined2 __stdcall16far FUN_1000_d69b(byte param_1)

{
  undefined2 in_AX;
  int iVar1;
  undefined1 local_3;
  
  if (param_1 < 0x20) {
    iVar1 = param_1 + 0x40;
    local_3 = (byte)iVar1;
  }
  else {
    iVar1 = CONCAT11((char)((uint)in_AX >> 8),param_1);
    local_3 = param_1;
  }
  return CONCAT11((char)((uint)iVar1 >> 8),local_3);
}


