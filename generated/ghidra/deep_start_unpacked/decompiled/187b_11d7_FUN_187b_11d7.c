
void __cdecl16far FUN_187b_11d7(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 uVar1;
  undefined2 in_DX;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  
  uVar1 = FUN_187b_0e70(0x4240,0xf,param_2,param_3,
                        (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 |
                        (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                        (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
                        (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1));
  FUN_187b_1182(param_1,uVar1,in_DX);
                    /* WARNING: Call to offcut address within same function */
  func_0x000199bd(0x187b);
  return;
}


