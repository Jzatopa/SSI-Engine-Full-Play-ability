
/* WARNING: Removing unreachable block (ram,0x0000013e) */
/* WARNING: Removing unreachable block (ram,0x00000119) */
/* WARNING: Removing unreachable block (ram,0x0000014f) */

bool __stdcall16far FUN_0000_00d2(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  FUN_0000_872f();
  lVar3 = FUN_0000_6c93(0x836);
  lVar3 = lVar3 + (ulong)(uint)(param_1 * 100);
  lVar4 = FUN_0000_6c93(0x602);
  do {
    lVar5 = FUN_0000_6c93(0x602);
    if (99 < lVar5 - lVar4) {
      lVar4 = FUN_0000_6c93(0x602);
    }
    uVar2 = 0x836;
    cVar1 = FUN_0000_8695(0x602);
    if (cVar1 != '\0') break;
    uVar2 = 0x602;
    lVar5 = FUN_0000_6c93(0x836);
  } while (lVar5 < lVar3);
  lVar4 = FUN_0000_6c93(uVar2);
  FUN_0000_872f();
  return lVar4 < lVar3;
}


