
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_187b_0ebb(void)

{
  undefined2 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  
  uRam000109b2 = 0xffff;
  uRam000109b4 = 0xffff;
  uVar5 = 0;
  do {
    if (*(int *)(uVar5 * 2 + 0x8fe) != 0) {
      uVar2 = *(uint *)(uVar5 * 4 + 0x964);
      uVar3 = *(uint *)(uVar5 * 4 + 0x966);
      if ((uVar3 < uRam000109b4) || ((uVar3 == uRam000109b4 && (uVar2 < uRam000109b2)))) {
        uRam000109b2 = uVar2;
        uRam000109b4 = uVar3;
      }
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x11);
  if ((uRam000109b2 != uRam000109a8) || (uRam000109b4 != uRam000109aa)) {
    _LAB_1099_001f_1 = 0xffff;
    uRam000109a8 = uRam000109b2;
    uRam000109aa = uRam000109b4;
    FUN_187b_0e46(uRam000109b2,
                  (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200
                  | (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40
                  | (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1));
    puVar6 = (undefined2 *)0x920;
    for (iVar4 = 0x22; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar1 = 0;
    }
  }
                    /* WARNING: Call to offcut address within same function */
  func_0x000196f6(0x1000);
  return;
}


