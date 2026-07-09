
void __cdecl16far FUN_1cc0_0000(void)

{
  code *pcVar1;
  int iVar2;
  undefined2 in_BX;
  undefined2 *puVar3;
  undefined2 unaff_ES;
  int unaff_SS;
  
  DAT_1e87_3d9c = ((uint)&stack0x0013 >> 4) + unaff_SS;
  DAT_1e87_3da0 = DAT_1e87_3d9c + DAT_1e87_3d96;
  DAT_1e87_3db2 = *(undefined2 *)0x2;
  DAT_1e87_3dbc = 0xa9;
  DAT_1e87_3dbe = 0x1cc0;
  puVar3 = (undefined2 *)0xa14e;
  iVar2 = 0x13;
  DAT_1e87_3d9e = DAT_1e87_3d9c;
  DAT_1e87_3daa = DAT_1e87_3da0;
  DAT_1e87_3dae = DAT_1e87_3da0;
  DAT_1e87_3db6 = DAT_1e87_3da0;
  DAT_1e87_3dca = unaff_ES;
  do {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    *puVar3 = in_BX;
    puVar3[1] = unaff_ES;
    puVar3 = puVar3 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  FUN_1cc0_04f5();
  FUN_1cc0_0565();
  FUN_1cc0_04f5();
  FUN_1cc0_056a();
  return;
}


