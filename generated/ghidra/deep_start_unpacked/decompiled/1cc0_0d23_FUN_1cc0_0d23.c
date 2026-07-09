
void __stdcall16far FUN_1cc0_0d23(byte param_1,byte param_2,undefined4 param_3)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  bool bVar5;
  
  if (param_2 <= param_1) {
    cVar3 = (param_1 - param_2) + '\x01';
    uVar4 = (uint)(param_2 >> 3);
    bVar2 = '\x01' << (param_2 & 7);
    do {
      pbVar1 = (byte *)(uVar4 + (int)param_3);
      *pbVar1 = *pbVar1 | bVar2;
      bVar5 = (char)bVar2 < '\0';
      bVar2 = bVar2 << 1 | bVar5;
      uVar4 = uVar4 + bVar5;
      cVar3 = cVar3 + -1;
    } while (cVar3 != '\0');
  }
  return;
}


