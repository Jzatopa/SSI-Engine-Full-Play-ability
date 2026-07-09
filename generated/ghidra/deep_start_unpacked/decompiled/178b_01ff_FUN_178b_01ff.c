
void __cdecl16far FUN_178b_01ff(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar3;
  undefined2 uVar4;
  undefined1 local_d [9];
  char local_4;
  undefined1 local_3;
  
  uVar1 = 0x178b;
  do {
    puVar3 = local_d;
    uVar2 = 0x1cc0;
    uVar4 = unaff_SS;
    FUN_1cc0_0ac2(0x1da,uVar1);
    local_4 = FUN_178b_051b(puVar3,uVar4);
    if (local_4 == '\0') {
      uVar4 = 0xa04e;
      uVar1 = unaff_DS;
      FUN_1cc0_0917(0,0x1e3,0x1cc0);
      FUN_1cc0_0848(uVar4,uVar1);
      uVar2 = 0x1836;
      local_3 = FUN_1836_01c7();
    }
    uVar1 = uVar2;
  } while (local_4 == '\0');
  return;
}


