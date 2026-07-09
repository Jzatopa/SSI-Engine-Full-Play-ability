/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:7afb
 * Ghidra name: FUN_0000_7afb
 * Linear address: 0x07AFB
 * Original GAME.OVR file offset: 31491
 * Body addresses: 3
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_7afb(void)

{
  char *pcVar1;
  undefined1 uVar2;
  byte extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  int unaff_BP;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar8;
  undefined2 uVar9;
  
  if (*(int *)((undefined *)&DAT_0000_ffb3 + unaff_BP) != 0 ||
      *(int *)((undefined *)&DAT_0000_ffb5 + unaff_BP) != 0) {
    uVar9 = 0x12;
    uVar8 = FUN_0000_ce3f();
    uVar5 = (undefined2)((ulong)*(undefined4 *)((undefined *)&DAT_0000_ffb3 + unaff_BP) >> 0x10);
    iVar3 = (int)*(undefined4 *)((undefined *)&DAT_0000_ffb3 + unaff_BP);
    *(undefined2 *)(iVar3 + 0xf3) = (int)uVar8;
    *(undefined2 *)(iVar3 + 0xf5) = (int)((ulong)uVar8 >> 0x10);
    uVar8 = *(undefined4 *)((int)*(undefined4 *)((undefined *)&DAT_0000_ffb3 + unaff_BP) + 0xf3);
    uVar6 = (undefined2)((ulong)uVar8 >> 0x10);
    uVar4 = (undefined2)uVar8;
    FUN_0000_e6d2(0);
    uVar7 = (undefined2)((ulong)*(undefined4 *)((undefined *)&DAT_0000_ffb3 + unaff_BP) >> 0x10);
    iVar3 = (int)*(undefined4 *)((undefined *)&DAT_0000_ffb3 + unaff_BP);
    uVar5 = *(undefined2 *)(iVar3 + 0x101);
    *(undefined2 *)((undefined *)&DAT_0000_ffb3 + unaff_BP) = *(undefined2 *)(iVar3 + 0xff);
    *(undefined2 *)((undefined *)&DAT_0000_ffb5 + unaff_BP) = uVar5;
    FUN_0000_7afb(uVar4,uVar6,uVar9);
    return;
  }
  ((undefined *)&DAT_0000_fffa)[unaff_BP] = 0;
  ((undefined *)&DAT_0000_ffb7)[unaff_BP] = 0;
  *(undefined1 *)0x5359 = 8;
  *(undefined1 *)(unaff_BP + -0x47) = 8;
  FUN_0000_0a2d();
  func_0x00007133(0x99,(uint)extraout_AH << 8,CONCAT11(extraout_AH,0x15),CONCAT11(extraout_AH,0x26),
                  CONCAT11(extraout_AH,0x13),CONCAT11(extraout_AH,1));
  uVar2 = FUN_0000_45fc(unaff_BP);
  *(undefined1 *)(unaff_BP + -0x48) = uVar2;
  do {
    FUN_0000_e6d2(0);
    FUN_0000_e6d2(0);
    if (*(char *)(unaff_BP + -0x48) == '\0') {
      func_0x000073af(0xcc0);
    }
    func_0x000069e7(0xcc0);
    uVar2 = extraout_AH_00;
    if (*(char *)(unaff_BP + -0x48) == '\x01') {
      func_0x000073af(0xcc0);
      uVar2 = extraout_AH_01;
    }
    if (((undefined *)&DAT_0000_fffa)[unaff_BP] == '\0') {
      if (*(char *)(unaff_BP + -0x47) < '\0') {
        *(undefined1 *)(unaff_BP + -0x47) = 0;
      }
      else if (*(char *)(unaff_BP + -0x47) < '\x04') {
        *(undefined1 *)(unaff_BP + -0x4e) = 1;
      }
      else if ('\b' < *(char *)(unaff_BP + -0x47)) {
                    /* WARNING: Subroutine does not return */
        FUN_0000_d6c2(0x35fc,0xcc0,unaff_BP + -0x78,unaff_SS,CONCAT11(uVar2,0xe));
      }
    }
    FUN_0000_0a82();
    *(undefined1 *)0x5359 = *(undefined1 *)(unaff_BP + -0x47);
    func_0x00000a5a(0x99);
  } while (((undefined *)&DAT_0000_fffa)[unaff_BP] == '\0');
  FUN_0000_4525(unaff_BP);
  *(undefined1 *)((int)*(undefined4 *)0x4418 + 0x80) = 0;
  if (*(char *)((int)*(undefined4 *)0x4418 + 0x27c) == '\0') {
    *(undefined1 *)0x8c2e = 1;
    *(undefined1 *)0x8c2d = 1;
  }
  if (*(int *)0x67e3 == 0) {
    FUN_0000_e6d2(0);
    FUN_0000_e6d2(0);
  }
  else {
    FUN_0000_e6af(0xc);
    *(undefined1 *)((int)*(undefined4 *)0x4418 + 0x278) =
         *(undefined1 *)((int)*(undefined4 *)0x534e + 0x39);
    *(undefined1 *)((int)*(undefined4 *)0x4418 + 0x27a) =
         *(undefined1 *)((int)*(undefined4 *)0x534e + 0x31);
    *(undefined1 *)((int)*(undefined4 *)0x4418 + 0x279) =
         *(undefined1 *)((int)*(undefined4 *)0x534e + 0x30);
    *(undefined1 *)((int)*(undefined4 *)0x4418 + 0x27b) =
         *(undefined1 *)((int)*(undefined4 *)0x534e + 0x35);
    *(undefined1 *)((int)*(undefined4 *)0x4418 + 0x281) = 0;
    *(undefined1 *)0x7817 = 0;
    while (pcVar1 = (char *)((int)*(undefined4 *)0x4418 + 0x281),
          *pcVar1 = *pcVar1 + *(char *)((int)*(undefined4 *)0x534e + *(char *)0x7817 * 6 + 0x3e),
          *(char *)0x7817 != '\a') {
      *(char *)0x7817 = *(char *)0x7817 + '\x01';
    }
    *(undefined1 *)((int)*(undefined4 *)0x4418 + 0x282) = 0;
  }
  FUN_0000_453c(0x744a);
  func_0x00000ad9(0x21a);
  func_0x000003e5(0xaa);
  FUN_0000_ce54(0x3c,0x6c,*(undefined2 *)0x534e,*(undefined2 *)0x5350);
  *(undefined2 *)0x534e = 0;
  *(undefined2 *)0x5350 = 0;
  *(undefined1 *)0x4438 = ((undefined *)&DAT_0000_ffba)[unaff_BP];
  FUN_0000_0a2d(0xcc0);
  return;
}


