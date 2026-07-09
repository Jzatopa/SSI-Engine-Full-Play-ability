/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1b6f:003b
 * Ghidra name: FUN_1b6f_003b
 * Linear address: 0x1B72B
 * Body addresses: 204
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined1 __stdcall16far FUN_1b6f_003b(byte param_1)

{
  char cVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_c;
  int local_b;
  int local_9;
  uint local_7;
  uint local_5;
  undefined1 local_3;
  
  local_3 = 8;
  if ((*(char *)0x8db8 != '\0') &&
     (cVar1 = FUN_1b6f_060d(&local_c,unaff_SS,&local_7,unaff_SS,&local_5,unaff_SS,param_1),
     cVar1 != '\0')) {
    local_9 = 0;
    *(undefined1 *)0x7817 = 1;
    while( true ) {
      if (*(uint *)((uint)param_1 * 0x1c + *(char *)0x7817 * 2 + -0x729c) < local_5) {
        local_9 = (int)*(char *)0x7817;
      }
      if (*(char *)0x7817 == '\x05') break;
      *(char *)0x7817 = *(char *)0x7817 + '\x01';
    }
    local_b = 0;
    *(undefined1 *)0x7817 = 1;
    while( true ) {
      if (*(uint *)((uint)param_1 * 0x1c + *(char *)0x7817 * 2 + -0x728e) < local_7) {
        local_b = (int)*(char *)0x7817;
      }
      if (*(char *)0x7817 == '\x05') break;
      *(char *)0x7817 = *(char *)0x7817 + '\x01';
    }
    local_3 = *(undefined1 *)(local_b * 6 + local_9 + 0x3814);
  }
  return local_3;
}


