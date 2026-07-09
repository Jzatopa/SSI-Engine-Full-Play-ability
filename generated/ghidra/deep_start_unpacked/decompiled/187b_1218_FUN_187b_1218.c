
void __cdecl16far FUN_187b_1218(undefined2 param_1,uint param_2)

{
  undefined2 uVar1;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  
  if (param_2 == 0) {
    uVar1 = 0xd68d;
  }
  else {
    uVar1 = (undefined2)(((ulong)param_2 * 10000) / 0x2e9c);
  }
  FUN_187b_1182(param_1,uVar1,0,
                (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
                (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
                (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1));
                    /* WARNING: Call to offcut address within same function */
  func_0x000199f9(0x187b);
  return;
}


