/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:38e0
 * Ghidra name: FUN_0000_38e0
 * Linear address: 0x038E0
 * Original GAME.OVR file offset: 14568
 * Body addresses: 214
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_38e0(void)

{
  char cVar1;
  undefined2 unaff_DS;
  
  cVar1 = *(char *)0x764f;
  if (cVar1 == '\0') {
    func_0x00000a86();
  }
  else if (cVar1 == '\x01') {
    FUN_0000_0b10();
  }
  else if (cVar1 == '\x02') {
    FUN_0000_0b2d();
  }
  else if (cVar1 == '\x03') {
    FUN_0000_0b42();
  }
  else if ((((cVar1 == '\x04') || (cVar1 == '\x05')) || (cVar1 == '\x06')) || (cVar1 == '\a')) {
    FUN_0000_0bcb();
  }
  else if (cVar1 == '\b') {
    FUN_0000_0ccf();
  }
  else if (cVar1 == '\t') {
    FUN_0000_0d34();
  }
  else if (cVar1 == '\n') {
    FUN_0000_0d8c();
  }
  else if (cVar1 == '\v') {
    FUN_0000_0f11();
  }
  else if (cVar1 == '\f') {
    FUN_0000_0e6c();
  }
  else if (cVar1 == '\r') {
    FUN_0000_1348();
  }
  else if (cVar1 == '\x0e') {
    FUN_0000_144e();
  }
  else if (cVar1 == '\x0f') {
    FUN_0000_1468();
  }
  else if (cVar1 == '\x10') {
    FUN_0000_14b8();
  }
  else if ((cVar1 == '\x11') || (cVar1 == '\x12')) {
    FUN_0000_1530();
  }
  else if (cVar1 == '\x13') {
    FUN_0000_1631();
  }
  else if (cVar1 == '\x14') {
    FUN_0000_1685();
  }
  else if (cVar1 == '\x15') {
    FUN_0000_1aee();
  }
  else if (((cVar1 == '\x16') || (cVar1 == '\x17')) ||
          ((cVar1 == '\x18' || (((cVar1 == '\x19' || (cVar1 == '\x1a')) || (cVar1 == '\x1b')))))) {
    FUN_0000_1701();
  }
  else if (cVar1 == '\x1c') {
    FUN_0000_1e10();
  }
  else if (cVar1 == '\x1d') {
    FUN_0000_1e79();
  }
  else if (cVar1 == '\x1e') {
    FUN_0000_1f29();
  }
  else if (cVar1 == '\x1f') {
    FUN_0000_0385();
  }
  else if (cVar1 == ' ') {
    FUN_0000_1777();
  }
  else if ((cVar1 == '!') || (cVar1 == '7')) {
    FUN_0000_180b();
  }
  else if (cVar1 == '\"') {
    FUN_0000_2120();
  }
  else if (cVar1 == '#') {
    FUN_0000_2120();
  }
  else if (cVar1 == '$') {
    FUN_0000_2453();
  }
  else if ((cVar1 == '%') || (cVar1 == '&')) {
    FUN_0000_2575();
  }
  else if (cVar1 == '\'') {
    FUN_0000_260a();
  }
  else if (cVar1 == '(') {
    FUN_0000_2725();
  }
  else if (cVar1 == ')') {
    FUN_0000_2810();
  }
  else if (cVar1 == '*') {
    FUN_0000_1a30();
  }
  else if (cVar1 == '+') {
    FUN_0000_1c91();
  }
  else if (cVar1 == ',') {
    FUN_0000_2847();
  }
  else if (cVar1 == '-') {
    FUN_0000_2e04();
  }
  else if (cVar1 == '.') {
    FUN_0000_296c();
  }
  else if ((cVar1 == '/') || (cVar1 == '0')) {
    FUN_0000_19b4();
  }
  else if (cVar1 == '1') {
    FUN_0000_1c91();
  }
  else if (cVar1 == '2') {
    FUN_0000_288d();
  }
  else if (cVar1 == '3') {
    FUN_0000_2ced();
  }
  else if (cVar1 == '4') {
    FUN_0000_2cb8();
  }
  else if (cVar1 == '5') {
    FUN_0000_1a9a();
  }
  else if (cVar1 == '6') {
    FUN_0000_2d9b();
  }
  else if (cVar1 == '8') {
    FUN_0000_2ed1();
  }
  else if (cVar1 == '9') {
    FUN_0000_2d2a();
  }
  else if (cVar1 == ':') {
    FUN_0000_2942();
  }
  else if (cVar1 != ';') {
    if (cVar1 == '<') {
      FUN_0000_2f47();
    }
    else if (cVar1 == '=') {
      FUN_0000_2d00();
    }
    else if (cVar1 == '>') {
      FUN_0000_2f4c();
    }
    else if (cVar1 == '?') {
      FUN_0000_2fa7();
    }
    else if (cVar1 == '@') {
      FUN_0000_3065();
    }
    else if (cVar1 == 'A') {
      FUN_0000_3215();
    }
    else if (cVar1 == 'B') {
      FUN_0000_3338();
    }
    else if (cVar1 == 'C') {
      FUN_0000_335f();
    }
    else if (cVar1 == 'D') {
      FUN_0000_33a2();
    }
    else if (cVar1 == 'E') {
      FUN_0000_33ab();
    }
    else if (cVar1 == 'F') {
      FUN_0000_340b();
    }
    else if (cVar1 == 'G') {
      FUN_0000_3440();
    }
    else if (cVar1 == 'H') {
      FUN_0000_346c();
    }
    else if (cVar1 == 'I') {
      FUN_0000_35af();
    }
    else if (cVar1 == 'J') {
      FUN_0000_36d5();
    }
    else if (cVar1 == 'K') {
      FUN_0000_36e3();
    }
    else if (cVar1 == 'L') {
      FUN_0000_384b();
    }
  }
  return;
}


