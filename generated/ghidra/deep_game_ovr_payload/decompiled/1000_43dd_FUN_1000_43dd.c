
void __stdcall16far
FUN_1000_43dd(undefined4 param_1,char param_2,char param_3,char param_4,char param_5)

{
  char cVar1;
  byte bVar2;
  byte extraout_AH;
  byte extraout_AH_00;
  undefined2 uVar3;
  undefined2 unaff_CS;
  undefined2 uVar4;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  cVar1 = *(char *)((int)param_1 + 0x2e);
  if ((cVar1 == '\x05') || (cVar1 == '\a')) {
    unaff_CS = 0x784;
    FUN_0000_7840();
  }
  else if (cVar1 == '\x06') {
    unaff_CS = 0x784;
    FUN_0000_7840();
  }
  else if ((cVar1 == '\t') || (cVar1 == '\r')) {
    unaff_CS = 0x784;
    FUN_0000_7840();
  }
  else if ((cVar1 == '\n') || (cVar1 == '\v')) {
    unaff_CS = 0x784;
    FUN_0000_7840();
  }
  else if (cVar1 == '\f') {
    unaff_CS = 0x784;
    FUN_0000_7840();
  }
  else if (cVar1 == '\x0e') {
    unaff_CS = 0x784;
    FUN_0000_7840();
  }
  else if (cVar1 == '\x0f') {
    unaff_CS = 0x784;
    FUN_0000_7840();
  }
  else if (((cVar1 == '\x10') || (cVar1 == '\x11')) || (cVar1 == '\x12')) {
    unaff_CS = 0x784;
    FUN_0000_7840();
  }
  uVar4 = 0xdb;
  func_0x00000dda(unaff_CS,(int)param_2,(int)param_3,(int)param_4,(int)param_5);
  local_3 = 1;
  cVar1 = *(char *)((int)param_1 + 0x2e);
  bVar2 = (byte)((uint)*(undefined2 *)((int)*(undefined4 *)0x7507 + 0x12) >> 8);
  if (cVar1 == '\x11') {
    FUN_1000_4340(&stack0xfffe,CONCAT11(bVar2,0xd));
  }
  else if (cVar1 == '\x0e') {
    FUN_1000_4340(&stack0xfffe,CONCAT11(bVar2,0xd));
  }
  else if ((cVar1 == '\t') || (cVar1 == '\r')) {
    FUN_1000_4340(&stack0xfffe,CONCAT11(bVar2,0x10));
  }
  else if (cVar1 == '\x05') {
    FUN_1000_4340(&stack0xfffe,CONCAT11(bVar2,0x13));
  }
  else if ((cVar1 == '\a') || (cVar1 == '\x06')) {
    FUN_1000_4340(&stack0xfffe,CONCAT11(bVar2,0x16));
  }
  else if ((cVar1 == '\x12') || ((cVar1 == '\n' || (cVar1 == '\v')))) {
    FUN_1000_4340(&stack0xfffe,CONCAT11(bVar2,0x19));
  }
  else if ((cVar1 == '\f') || (cVar1 == '\x0f')) {
    FUN_0000_4f8a(0xdb,(uint)bVar2 << 8,(uint)bVar2 << 8,(uint)bVar2 << 8,CONCAT11(bVar2,0x1e));
    uVar4 = 0x21a;
    FUN_0000_4f8a(0x21a,(uint)extraout_AH << 8,CONCAT11(extraout_AH,1),CONCAT11(extraout_AH,1),
                  CONCAT11(extraout_AH,0x1e));
    local_3 = 2;
  }
  else {
    FUN_0000_4f8a(0xdb,(uint)bVar2 << 8,(uint)bVar2 << 8,(uint)bVar2 << 8,CONCAT11(bVar2,0x25));
    uVar4 = 0x21a;
    FUN_0000_4f8a(0x21a,(uint)extraout_AH_00 << 8,CONCAT11(extraout_AH_00,1),
                  CONCAT11(extraout_AH_00,1),CONCAT11(extraout_AH_00,0x25));
    local_3 = 2;
  }
  func_0x00000a00(uVar4,CONCAT11(param_2 >> 7,10),CONCAT11(param_2 >> 7,local_3),(int)param_2,
                  (int)param_3,(int)param_4,(int)param_5);
  return;
}


