/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1b6f:060d
 * Ghidra name: FUN_1b6f_060d
 * Linear address: 0x1BCFD
 * Body addresses: 171
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined1 __stdcall16far FUN_1b6f_060d(byte *param_1,uint *param_2,uint *param_3,char param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  
  if ((param_4 != '\x01') && (param_4 != '\x02')) {
    return 0;
  }
  bVar3 = 1;
  if (param_4 == '\x02') {
    bVar3 = 4;
  }
  uVar5 = 1;
  iVar4 = 0;
  out(0x201,0xff);
  do {
    bVar1 = in(0x201);
    if ((bVar3 & ~bVar1) != 0) {
      iVar4 = 0x1fff - uVar5;
      if (uVar5 < 0x2000) {
        do {
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      do {
        bVar1 = bVar3;
        *param_3 = uVar5;
        bVar3 = bVar1 << 1;
        iVar4 = 0;
        while (bVar2 = in(0x201), (bVar3 & ~bVar2) == 0) {
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) {
            return 0;
          }
        }
        uVar5 = 1;
        iVar4 = 0;
        out(0x201,0xff);
        while (bVar2 = in(0x201), (bVar3 & ~bVar2) == 0) {
          uVar5 = uVar5 + 1;
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) {
            return 0;
          }
        }
        iVar4 = 0x1fff - uVar5;
        if (uVar5 < 0x2000) {
          do {
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
          *param_2 = uVar5;
          iVar4 = 0;
          do {
            bVar3 = in(0x201);
            if ((bVar1 & 0x7f & ~bVar3) != 0) {
              *param_1 = (byte)~bVar3 >> 4;
              return 1;
            }
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
          return 0;
        }
      } while( true );
    }
    uVar5 = uVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return 0;
}


