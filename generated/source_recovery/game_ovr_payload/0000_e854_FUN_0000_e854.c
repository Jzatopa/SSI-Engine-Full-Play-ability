/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:e854
 * Ghidra name: FUN_0000_e854
 * Linear address: 0x0E854
 * Original GAME.OVR file offset: 59484
 * Body addresses: 30
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_e854(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  int in_AX;
  uint in_CX;
  undefined1 in_BL;
  int unaff_BP;
  undefined2 uVar4;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  do {
    *(undefined1 *)((int)*(undefined4 *)0x71dc + in_AX + in_CX + 7) = in_BL;
    do {
      if (*(char *)(unaff_BP + -2) == '\x18') {
        if (*(char *)(unaff_BP + -1) == '1') {
          return;
        }
        *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
        *(undefined1 *)(unaff_BP + -2) = 0;
      }
      else {
        *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
      }
      iVar1 = (uint)*(byte *)(unaff_BP + -2) * 0x32;
    } while (*(char *)((int)*(undefined4 *)0x71dc + iVar1 + (uint)*(byte *)(unaff_BP + -1) + 7) !=
             '\x06');
    uVar3 = (undefined1)((uint)iVar1 >> 8);
    *(undefined1 *)(unaff_BP + -3) = *(undefined1 *)(unaff_BP + 8);
    uVar4 = unaff_CS;
    if (*(char *)(unaff_BP + 6) != '\0') {
      uVar4 = 0x99;
      cVar2 = FUN_0000_09ba(unaff_CS,CONCAT11(uVar3,*(undefined1 *)(unaff_BP + 6)),CONCAT11(uVar3,1)
                           );
      *(char *)(unaff_BP + -3) = *(char *)(unaff_BP + -3) + cVar2 + -1;
    }
    in_BL = *(undefined1 *)(unaff_BP + -3);
    in_CX = (uint)*(byte *)(unaff_BP + -1);
    in_AX = (uint)*(byte *)(unaff_BP + -2) * 0x32;
    unaff_CS = uVar4;
  } while( true );
}


