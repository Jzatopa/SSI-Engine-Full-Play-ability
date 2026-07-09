
void __cdecl16far FUN_187b_0e1d(undefined2 param_1)

{
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  
  out(0x43,0x36);
  uRam000109b6 = param_1;
  out(0x40,(char)param_1);
  out(0x40,(char)((uint)param_1 >> 8));
                    /* WARNING: Call to offcut address within same function */
  func_0x000195eb(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 |
                         (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                         (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
                         (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1));
  return;
}


