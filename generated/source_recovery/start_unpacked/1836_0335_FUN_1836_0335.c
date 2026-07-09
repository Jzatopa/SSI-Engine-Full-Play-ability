/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1836:0335
 * Ghidra name: FUN_1836_0335
 * Linear address: 0x18695
 * Body addresses: 154
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined1 __cdecl16far FUN_1836_0335(void)

{
  char cVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte local_6;
  int local_5;
  undefined1 local_3;
  
  local_3 = FUN_1bdc_02fb();
  if ((*(char *)0x8db8 != '\0') || (*(char *)0x8d70 != '\0')) {
    if (*(char *)0x8d70 == '\0') {
      FUN_1b6f_018d(&local_6,unaff_SS,&local_5,unaff_SS);
      cVar1 = FUN_1bdc_02fb();
      if (((cVar1 == '\0') && (local_5 < 1)) && (7 < local_6)) {
        local_3 = 0;
      }
      else {
        local_3 = 1;
      }
    }
    else {
      FUN_1b58_0072(0x8d75,unaff_DS,0x8d73,unaff_DS,&local_5,unaff_SS);
      cVar1 = FUN_1bdc_02fb();
      if ((cVar1 == '\0') && (local_5 == 0)) {
        local_3 = 0;
      }
      else {
        local_3 = 1;
      }
    }
  }
  return local_3;
}


