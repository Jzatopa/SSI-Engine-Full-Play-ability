
void __stdcall16far FUN_2000_780a(undefined4 param_1,char param_2)

{
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  undefined1 extraout_AH_03;
  undefined1 extraout_AH_04;
  undefined1 extraout_AH_05;
  undefined1 extraout_AH_06;
  undefined1 extraout_AH_07;
  undefined1 extraout_AH_08;
  undefined1 extraout_AH_09;
  undefined1 extraout_AH_10;
  undefined1 extraout_AH_11;
  undefined1 extraout_AH_12;
  undefined1 extraout_AH_13;
  undefined1 extraout_AH_14;
  undefined1 extraout_AH_15;
  undefined1 extraout_AH_16;
  undefined2 uVar1;
  undefined2 uVar2;
  
  if (((param_2 != '\0') && (param_2 != '\x01')) && (param_2 != '\x02')) {
    uVar1 = (undefined2)param_1;
    uVar2 = (undefined2)((ulong)param_1 >> 0x10);
    if (param_2 == '\x03') {
      FUN_2000_77a7(0x1c,uVar1,uVar2);
      FUN_2000_77a7(CONCAT11(extraout_AH,0x1e),uVar1,uVar2);
    }
    else if (param_2 != '\x04') {
      if (param_2 == '\x05') {
        FUN_2000_77a7(0x14,uVar1,uVar2);
        FUN_2000_77a7(CONCAT11(extraout_AH_00,0x19),uVar1,uVar2);
        FUN_2000_77a7(CONCAT11(extraout_AH_01,0x12),uVar1,uVar2);
        FUN_2000_77a7(CONCAT11(extraout_AH_02,0x17),uVar1,uVar2);
        FUN_2000_77a7(CONCAT11(extraout_AH_03,0x18),uVar1,uVar2);
        FUN_2000_77a7(CONCAT11(extraout_AH_04,0x1a),uVar1,uVar2);
        FUN_2000_77a7(CONCAT11(extraout_AH_05,0x1b),uVar1,uVar2);
        FUN_2000_77a7(CONCAT11(extraout_AH_06,3),uVar1,uVar2);
      }
      else if (param_2 == '\x06') {
        FUN_2000_77a7(0x17,uVar1,uVar2);
        FUN_2000_77a7(CONCAT11(extraout_AH_07,3),uVar1,uVar2);
      }
      else if (param_2 == '\a') {
        FUN_2000_77a7(1,uVar1,uVar2);
        FUN_2000_77a7(CONCAT11(extraout_AH_08,2),uVar1,uVar2);
        FUN_2000_77a7(CONCAT11(extraout_AH_09,0xe),uVar1,uVar2);
      }
      else if (param_2 != '\b') {
        if (param_2 == '\t') {
          FUN_2000_77a7(0x16,uVar1,uVar2);
          FUN_2000_77a7(CONCAT11(extraout_AH_10,0x15),uVar1,uVar2);
          FUN_2000_77a7(CONCAT11(extraout_AH_11,0x13),uVar1,uVar2);
          FUN_2000_77a7(CONCAT11(extraout_AH_12,0x10),uVar1,uVar2);
          FUN_2000_77a7(CONCAT11(extraout_AH_13,3),uVar1,uVar2);
        }
        else if (param_2 == '\n') {
          FUN_2000_77a7(0xd,uVar1,uVar2);
        }
        else if (param_2 == '\v') {
          FUN_2000_77a7(0xd,uVar1,uVar2);
        }
        else if (param_2 == '\f') {
          FUN_2000_77a7(0xd,uVar1,uVar2);
        }
        else if (param_2 != '\r') {
          if (param_2 == '\x0e') {
            FUN_2000_77a7(0x20,uVar1,uVar2);
            FUN_2000_77a7(CONCAT11(extraout_AH_14,0x1f),uVar1,uVar2);
            FUN_2000_77a7(CONCAT11(extraout_AH_15,0x11),uVar1,uVar2);
          }
          else if (param_2 == '\x0f') {
            FUN_2000_77a7(0xe,uVar1,uVar2);
            FUN_2000_77a7(CONCAT11(extraout_AH_16,2),uVar1,uVar2);
          }
          else if ((param_2 != '\x10') && (param_2 != '\x11')) {
            if (param_2 == '\x12') {
              FUN_2000_77a7(0x1d,uVar1,uVar2);
            }
            else if (((param_2 != '\x13') && (param_2 != '\x14')) &&
                    ((param_2 != '\x15' && (param_2 == '\x16')))) {
              FUN_2000_77a7(0x1d,uVar1,uVar2);
            }
          }
        }
      }
    }
  }
  return;
}


