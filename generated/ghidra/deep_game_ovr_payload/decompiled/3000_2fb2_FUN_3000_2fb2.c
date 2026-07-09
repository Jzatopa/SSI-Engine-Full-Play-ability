
undefined2 __stdcall16far FUN_3000_2fb2(uint param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 local_5;
  undefined1 local_4;
  
  uVar3 = (int)(param_2 - param_4) >> 0xf;
  iVar1 = (param_2 - param_4 ^ uVar3) - uVar3;
  uVar4 = (int)(param_1 - param_3) >> 0xf;
  uVar4 = (param_1 - param_3 ^ uVar4) - uVar4;
  local_4 = '\0';
  local_5 = '\0';
  uVar3 = uVar4;
  while (uVar2 = (undefined1)(uVar3 >> 8), local_5 == '\0') {
    uVar3 = CONCAT11(uVar2,local_4);
    if (local_4 == '\x01') {
      uVar3 = param_1;
      if (((((int)param_1 < param_3) && (uVar3 = param_2, param_4 < (int)param_2)) &&
          (uVar3 = (iVar1 * 0x26a) / 0x100, (int)uVar4 <= (int)uVar3)) &&
         (uVar3 = (iVar1 * 0x6a) / 0x100, (int)uVar3 <= (int)uVar4)) {
        uVar3 = CONCAT11((char)(uVar3 >> 8),1);
      }
      else {
        uVar3 = uVar3 & 0xff00;
      }
      local_5 = (char)uVar3;
    }
    else if (local_4 == '\x03') {
      uVar3 = param_1;
      if (((param_3 < (int)param_1) && (uVar3 = param_2, param_4 < (int)param_2)) &&
         ((uVar3 = (iVar1 * 0x26a) / 0x100, (int)uVar4 <= (int)uVar3 &&
          (uVar3 = (iVar1 * 0x6a) / 0x100, (int)uVar3 <= (int)uVar4)))) {
        uVar3 = CONCAT11((char)(uVar3 >> 8),1);
      }
      else {
        uVar3 = uVar3 & 0xff00;
      }
      local_5 = (char)uVar3;
    }
    else if (local_4 == '\x05') {
      uVar3 = param_1;
      if (((param_3 < (int)param_1) && (uVar3 = param_2, (int)param_2 < param_4)) &&
         ((uVar3 = (iVar1 * 0x26a) / 0x100, (int)uVar4 <= (int)uVar3 &&
          (uVar3 = (iVar1 * 0x6a) / 0x100, (int)uVar3 <= (int)uVar4)))) {
        uVar3 = CONCAT11((char)(uVar3 >> 8),1);
      }
      else {
        uVar3 = uVar3 & 0xff00;
      }
      local_5 = (char)uVar3;
    }
    else if (local_4 == '\a') {
      uVar3 = param_1;
      if (((((int)param_1 < param_3) && (uVar3 = param_2, (int)param_2 < param_4)) &&
          (uVar3 = (iVar1 * 0x26a) / 0x100, (int)uVar4 <= (int)uVar3)) &&
         (uVar3 = (iVar1 * 0x6a) / 0x100, (int)uVar3 <= (int)uVar4)) {
        uVar3 = CONCAT11((char)(uVar3 >> 8),1);
      }
      else {
        uVar3 = uVar3 & 0xff00;
      }
      local_5 = (char)uVar3;
    }
    else if (local_4 == '\0') {
      uVar3 = param_1;
      if ((param_3 < (int)param_1) || (uVar3 = (iVar1 * 0x26a) / 0x100, (int)uVar4 < (int)uVar3)) {
        uVar3 = uVar3 & 0xff00;
      }
      else {
        uVar3 = CONCAT11((char)(uVar3 >> 8),1);
      }
      local_5 = (char)uVar3;
    }
    else if (local_4 == '\x02') {
      uVar3 = param_2;
      if (((int)param_2 < param_4) || (uVar3 = (iVar1 * 0x6a) / 0x100, (int)uVar3 < (int)uVar4)) {
        uVar3 = uVar3 & 0xff00;
      }
      else {
        uVar3 = CONCAT11((char)(uVar3 >> 8),1);
      }
      local_5 = (char)uVar3;
    }
    else if (local_4 == '\x04') {
      uVar3 = param_1;
      if (((int)param_1 < param_3) || (uVar3 = (iVar1 * 0x26a) / 0x100, (int)uVar4 < (int)uVar3)) {
        uVar3 = uVar3 & 0xff00;
      }
      else {
        uVar3 = CONCAT11((char)(uVar3 >> 8),1);
      }
      local_5 = (char)uVar3;
    }
    else if (local_4 == '\x06') {
      uVar3 = param_2;
      if ((param_4 < (int)param_2) || (uVar3 = (iVar1 * 0x6a) / 0x100, (int)uVar3 < (int)uVar4)) {
        uVar3 = uVar3 & 0xff00;
      }
      else {
        uVar3 = CONCAT11((char)(uVar3 >> 8),1);
      }
      local_5 = (char)uVar3;
    }
    if (local_5 == '\0') {
      local_4 = local_4 + '\x01';
    }
  }
  return CONCAT11(uVar2,local_4);
}


