
undefined1 __stdcall16far
FUN_3000_11b4(byte param_1,char param_2,char param_3,char param_4,char param_5)

{
  char cVar1;
  char cVar2;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  if (((((param_5 < '\0') || ('1' < param_5)) || (param_4 < '\0')) ||
      (('\x18' < param_4 || (param_3 < '\0')))) ||
     (('1' < param_3 || ((param_2 < '\0' || ('\x18' < param_2)))))) {
    local_3 = 0;
  }
  else {
    if (param_1 == 0xff) {
      param_1 = 8;
    }
    cVar1 = param_5 + ((undefined *)&DAT_0000_26ca)[param_1];
    cVar2 = param_4 + ((undefined *)&DAT_0000_26d3)[param_1];
    if (((param_5 == param_3) && (param_4 == param_2)) || ((cVar1 == param_3 && (cVar2 == param_2)))
       ) {
      local_3 = 1;
    }
    else if (param_1 == 0) {
      if (((param_3 < cVar1) || (((int)cVar1 - (int)param_3) + (int)cVar2 < (int)param_2)) &&
         ((cVar1 < param_3 || (((int)param_3 - (int)cVar1) + (int)cVar2 < (int)param_2)))) {
        local_3 = 0;
      }
      else {
        local_3 = 1;
      }
    }
    else if (param_1 == 1) {
      if (((param_3 < cVar1) || (((int)cVar1 - (int)param_3) + (int)cVar2 < (int)param_2)) &&
         (((int)param_3 < ((int)cVar1 + (int)cVar2) - (int)param_2 || (cVar2 < param_2)))) {
        local_3 = 0;
      }
      else {
        local_3 = 1;
      }
    }
    else if (param_1 == 2) {
      if ((((int)param_3 < ((int)cVar1 + (int)cVar2) - (int)param_2) || (cVar2 < param_2)) &&
         (((int)param_3 < ((int)cVar1 + (int)param_2) - (int)cVar2 || (param_2 < cVar2)))) {
        local_3 = 0;
      }
      else {
        local_3 = 1;
      }
    }
    else if (param_1 == 3) {
      if ((((int)param_3 < ((int)cVar1 + (int)param_2) - (int)cVar2) || (param_2 < cVar2)) &&
         ((param_3 < cVar1 || ((int)param_2 < ((int)param_3 - (int)cVar1) + (int)cVar2)))) {
        local_3 = 0;
      }
      else {
        local_3 = 1;
      }
    }
    else if (param_1 == 4) {
      if (((param_3 < cVar1) || ((int)param_2 < ((int)param_3 - (int)cVar1) + (int)cVar2)) &&
         ((cVar1 < param_3 || ((int)param_2 < ((int)cVar1 - (int)param_3) + (int)cVar2)))) {
        local_3 = 0;
      }
      else {
        local_3 = 1;
      }
    }
    else if (param_1 == 5) {
      if (((cVar1 < param_3) || ((int)param_2 < ((int)cVar1 - (int)param_3) + (int)cVar2)) &&
         ((((int)cVar1 + (int)cVar2) - (int)param_2 < (int)param_3 || (param_2 < cVar2)))) {
        local_3 = 0;
      }
      else {
        local_3 = 1;
      }
    }
    else if (param_1 == 6) {
      if (((((int)cVar1 + (int)cVar2) - (int)param_2 < (int)param_3) || (param_2 < cVar2)) &&
         ((((int)cVar1 + (int)param_2) - (int)cVar2 < (int)param_3 || (cVar2 < param_2)))) {
        local_3 = 0;
      }
      else {
        local_3 = 1;
      }
    }
    else if (param_1 == 7) {
      if (((((int)cVar1 + (int)param_2) - (int)cVar2 < (int)param_3) || (cVar2 < param_2)) &&
         ((cVar1 < param_3 || (((int)param_3 - (int)cVar1) + (int)cVar2 < (int)param_2)))) {
        local_3 = 0;
      }
      else {
        local_3 = 1;
      }
    }
    else if (param_1 == 8) {
      local_3 = 1;
    }
  }
  return local_3;
}


