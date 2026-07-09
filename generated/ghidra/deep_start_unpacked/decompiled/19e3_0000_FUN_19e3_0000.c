
void __stdcall16far FUN_19e3_0000(uint param_1)

{
  undefined2 unaff_DS;
  
  if (param_1 == 0) {
    if (*(char *)0x50cc != '\0') {
      FUN_19e3_16c6(0);
      FUN_19e3_165a(0);
    }
  }
  else if (param_1 == 1) {
    if (*(char *)0x50cc != '\0') {
      FUN_19e3_1732(1);
    }
  }
  else if (param_1 == 0xff) {
    if ((*(char *)0x50cc != '\0') && (*(char *)0x50d0 == '\x01')) {
      *(undefined1 *)0x50d0 = 0;
      FUN_19e3_16c6(0);
      FUN_19e3_165a(0);
      FUN_19e3_12c9();
    }
  }
  else if ((param_1 < 2) || (0x14 < param_1)) {
    if (param_1 == 0x15) {
      *(undefined2 *)*(undefined4 *)0x4412 = 5000;
    }
  }
  else if (*(char *)0x50cc != '\0') {
    if (*(char *)0x50cc == '\x05') {
      FUN_19e3_16c6(param_1 - 1);
    }
    else {
      FUN_19e3_165a(param_1 - 1);
    }
  }
  return;
}


