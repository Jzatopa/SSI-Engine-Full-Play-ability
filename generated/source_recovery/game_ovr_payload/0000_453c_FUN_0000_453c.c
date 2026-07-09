/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:453c
 * Ghidra name: FUN_0000_453c
 * Linear address: 0x0453C
 * Original GAME.OVR file offset: 17732
 * Body addresses: 191
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Instruction at (ram,0x0000453e) overlaps instruction at (ram,0x0000453d)
    */

void __stdcall16far FUN_0000_453c(void)

{
  int *piVar1;
  char *pcVar2;
  char in_AL;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  while( true ) {
    unaff_SI = unaff_SI + 1;
    *(int *)((undefined *)&DAT_0000_ff46 + unaff_BP + unaff_SI) =
         *(int *)((undefined *)&DAT_0000_ff46 + unaff_BP + unaff_SI) + -1;
    if (*(int *)((undefined *)&DAT_0000_ffdb + *(int *)(unaff_BP + 6) + *(char *)(unaff_BP + -1) * 2
                ) < *(int *)((int)*(undefined4 *)(unaff_BP + -5) + in_AL * 2 + 0x16)) {
      piVar1 = (int *)((int)*(undefined4 *)(unaff_BP + -5) + *(char *)(unaff_BP + -1) * 2 + 0x16);
      *piVar1 = *piVar1 - *(int *)((undefined *)&DAT_0000_ffdb +
                                  *(int *)(unaff_BP + 6) + *(char *)(unaff_BP + -1) * 2);
    }
    if (*(char *)(unaff_BP + -1) == '\x05') break;
    *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
    in_AL = *(char *)(unaff_BP + -1);
  }
  *(undefined1 *)0x7817 = 0;
  while( true ) {
    if (*(byte *)((int)*(undefined4 *)(unaff_BP + -5) + *(char *)0x7817 * 6 + 0x3e) <
        (byte)((undefined *)&DAT_0000_ffcb)[*(int *)(unaff_BP + 6) + (int)*(char *)0x7817]) {
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -5) + *(char *)0x7817 * 6 + 0x3e) = 0;
    }
    else {
      pcVar2 = (char *)((int)*(undefined4 *)(unaff_BP + -5) + *(char *)0x7817 * 6 + 0x3e);
      *pcVar2 = *pcVar2 - ((undefined *)&DAT_0000_ffcb)
                          [*(int *)(unaff_BP + 6) + (int)*(char *)0x7817];
    }
    if (*(char *)0x7817 == '\a') break;
    *(char *)0x7817 = *(char *)0x7817 + '\x01';
  }
  return;
}


