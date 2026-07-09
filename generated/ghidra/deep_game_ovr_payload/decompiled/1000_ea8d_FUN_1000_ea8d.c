
void __stdcall16far FUN_1000_ea8d(undefined4 param_1,byte param_2)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_CS;
  undefined2 uVar5;
  undefined1 local_c;
  uint local_b;
  uint local_9;
  uint local_7;
  uint uStack_5;
  byte local_3;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uStack_5 = *(uint *)(iVar3 + 0xf9);
  local_7 = *(uint *)(iVar3 + 0xf7);
  while (uVar1 = local_7 | uStack_5, uVar1 != 0) {
    if (*(uint *)(local_7 + 0x36) < 0x100) {
      if (0x18 < *(uint *)(local_7 + 0x36)) {
        if (param_2 < 0x33) {
          param_2 = 0;
        }
        else {
          uVar1 = param_2 - 0x32;
          param_2 = (byte)uVar1;
        }
      }
    }
    else if (param_2 < 0x5b) {
      param_2 = 0;
    }
    else {
      uVar1 = param_2 - 0x5a;
      param_2 = (byte)uVar1;
    }
    uVar2 = (undefined1)(uVar1 >> 8);
    uVar5 = 0x99;
    local_3 = FUN_0000_09ba(unaff_CS,CONCAT11(uVar2,100),CONCAT11(uVar2,1));
    local_b = *(uint *)(local_7 + 0x2a);
    local_9 = *(uint *)(local_7 + 0x2c);
    if (local_3 <= param_2) {
      if ((*(byte *)(local_7 + 0x34) & 0x80) != 0) {
        uVar5 = 0x7e;
        func_0x0000083c(0x99,&local_c);
      }
      func_0x000009e7(uVar5,local_7,uStack_5,iVar3,uVar4);
    }
    unaff_CS = 0x99;
    uStack_5 = local_9;
    local_7 = local_b;
  }
  return;
}


