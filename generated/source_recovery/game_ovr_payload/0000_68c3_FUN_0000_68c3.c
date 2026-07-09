/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:68c3
 * Ghidra name: FUN_0000_68c3
 * Linear address: 0x068C3
 * Original GAME.OVR file offset: 26827
 * Body addresses: 258
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Removing unreachable block (ram,0x000069a8) */

undefined2 __stdcall16far FUN_0000_68c3(int param_1)

{
  char cVar1;
  char cVar2;
  uint in_AX;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  long lVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined1 local_3;
  
  cVar1 = FUN_0000_4758(*(undefined2 *)(param_1 + 6),in_AX & 0xff00,*(undefined2 *)0x534e,
                        *(undefined2 *)0x5350);
  iVar3 = (int)cVar1;
  if (iVar3 < 0) {
    local_3 = 0;
  }
  else {
    uVar9 = *(undefined2 *)0x5350;
    uVar8 = *(undefined2 *)0x534e;
    cVar2 = func_0x00000a87();
    iVar3 = *(int *)0x534a;
    cVar2 = func_0x00000a87(0x99,iVar3,*(undefined2 *)0x534c,(int)cVar2,uVar8,uVar9);
    iVar5 = (cVar2 - iVar3) * 10;
    iVar3 = CONCAT11((char)((uint)iVar5 >> 8),0x33);
    uVar4 = FUN_0000_0a6e(0x99,iVar3,*(undefined2 *)0x5352,*(undefined2 *)0x5354,iVar5);
    iVar3 = (uVar4 & 0xff) + iVar3;
    if (iVar3 < 0x5a) {
      cVar2 = FUN_0000_6833(&stack0xfffe);
      iVar5 = (int)cVar2 / 10;
      cVar1 = FUN_0000_51b3(*(undefined2 *)(param_1 + 6),0,0,
                            CONCAT11((char)((uint)iVar5 >> 8),cVar1),*(undefined2 *)0x534a,
                            *(undefined2 *)0x534c,*(undefined2 *)0x534e,*(undefined2 *)0x5350);
      iVar5 = (0x15 - cVar1) * 5 * iVar5;
      iVar6 = iVar5 >> 0xf;
      lVar7 = func_0x0000d612(0x99);
      iVar3 = (int)lVar7;
      if (lVar7 < CONCAT22(iVar6,iVar5)) {
        local_3 = 1;
      }
      else {
        local_3 = 0;
      }
    }
    else {
      local_3 = 1;
    }
  }
  return CONCAT11((char)((uint)iVar3 >> 8),local_3);
}


