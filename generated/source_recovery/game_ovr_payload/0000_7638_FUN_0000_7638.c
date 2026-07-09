/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:7638
 * Ghidra name: FUN_0000_7638
 * Linear address: 0x07638
 * Original GAME.OVR file offset: 30272
 * Body addresses: 163
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_7638(void)

{
  undefined1 uVar1;
  byte bVar3;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (*(char *)(unaff_BP + -0x107) != '\x1b') {
    FUN_0000_7105();
    do {
      bVar3 = (byte)((uint)*(int *)(unaff_BP + -4) >> 8);
      if ((*(int *)(unaff_BP + -2) == *(int *)0x5354) && (*(int *)(unaff_BP + -4) == *(int *)0x5352)
         ) {
        iVar2 = (uint)bVar3 << 8;
      }
      else {
        iVar2 = CONCAT11(bVar3,1);
      }
      uVar1 = FUN_0000_4758(*(undefined2 *)(unaff_BP + 6),iVar2,*(undefined2 *)0x534a,
                            *(undefined2 *)0x534c);
      ((undefined *)&DAT_0000_fff4)[*(int *)(unaff_BP + 6)] = uVar1;
      if (-1 < (char)((undefined *)&DAT_0000_fff4)[*(int *)(unaff_BP + 6)]) {
        FUN_0000_538f(0x602,*(undefined2 *)(unaff_BP + 6),*(undefined1 *)(unaff_BP + -0x114),
                      *(undefined2 *)(unaff_BP + -4),*(undefined2 *)(unaff_BP + -2),
                      ((undefined *)&DAT_0000_fff4)[*(int *)(unaff_BP + 6)],*(undefined2 *)0x534e,
                      *(undefined2 *)0x5350,*(undefined2 *)0x534a,*(undefined2 *)0x534c);
      }
    } while ((((-1 < (char)((undefined *)&DAT_0000_fff4)[*(int *)(unaff_BP + 6)]) &&
              (((undefined *)&DAT_0000_fffa)[*(int *)(unaff_BP + 6)] == '\0')) &&
             (*(int *)(unaff_BP + -2) == *(int *)0x5354)) &&
            (*(int *)(unaff_BP + -4) == *(int *)0x5352));
    *(undefined1 *)(unaff_BP + -0x105) = 1;
  }
  FUN_0000_790f();
  return;
}


