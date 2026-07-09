
void __cdecl16far FUN_187b_0f94(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  uint uVar2;
  
  uVar2 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
          (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
          (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1);
  iRam00010a3c = 0;
  do {
    iVar1 = *(int *)(iRam00010a3c * 2 + 0x9f8);
    if (*(int *)(iRam00010a3c * 4 + 0x9b8) != 0 || *(int *)(iRam00010a3c * 4 + 0x9ba) != 0) {
      if (iVar1 != -1) {
        FUN_187b_1094(iVar1,uVar2);
      }
      FUN_187b_13fc(iRam00010a3c,param_1,param_2);
    }
    iRam00010a3c = iRam00010a3c + 1;
  } while (iRam00010a3c != 0x10);
  FUN_187b_10d8();
                    /* WARNING: Call to offcut address within same function */
  func_0x0001979e(0x1000);
  return;
}


