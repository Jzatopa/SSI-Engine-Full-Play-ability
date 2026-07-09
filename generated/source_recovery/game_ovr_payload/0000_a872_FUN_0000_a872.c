/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:a872
 * Ghidra name: FUN_0000_a872
 * Linear address: 0x0A872
 * Original GAME.OVR file offset: 43130
 * Body addresses: 274
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_a872(void)

{
  uint *puVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  bool bVar5;
  uint local_a;
  uint uStack_8;
  
  while (*(int *)0x7489 != 0 || *(int *)0x748b != 0) {
    puVar4 = (undefined2 *)*(undefined4 *)0x7489;
    uVar2 = *puVar4;
    uVar3 = ((undefined2 *)puVar4)[1];
    FUN_0000_ce54(unaff_CS,0x1a,*(undefined2 *)0x7489,*(undefined2 *)0x748b);
    *(undefined2 *)0x7489 = uVar2;
    *(undefined2 *)0x748b = uVar3;
    unaff_CS = 0xcc0;
  }
  uStack_8 = *(uint *)0x5801;
  local_a = *(uint *)0x57ff;
  while( true ) {
    bVar5 = (local_a | uStack_8) == 0;
    if (bVar5) break;
    FUN_0000_d977(unaff_CS,0,unaff_CS,
                  CONCAT11((char)((local_a | uStack_8) >> 8),*(undefined1 *)(local_a + 0xd4)));
    if (!bVar5) {
      *(undefined1 *)(local_a + 0xd4) = 1;
    }
    func_0x0000094f(0xcc0,0,0,CONCAT11(extraout_AH,0xd),local_a,uStack_8);
    func_0x0000094f(0x92,0,0,CONCAT11(extraout_AH_00,1),local_a,uStack_8);
    unaff_CS = 0x92;
    func_0x0000094f(0x92,0,0,CONCAT11(extraout_AH_01,0xe),local_a,uStack_8);
    puVar1 = (uint *)(local_a + 0xff);
    uStack_8 = *(uint *)(local_a + 0x101);
    local_a = *puVar1;
  }
  FUN_0000_ce54(unaff_CS,0x4e9,*(undefined2 *)0x71dc,*(undefined2 *)0x71de);
  *(undefined2 *)0x71dc = 0;
  *(undefined2 *)0x71de = 0;
  FUN_0000_453c(0x7507);
  FUN_0000_453c(0x68bc);
  func_0x00000df3(0x21a);
  *(undefined1 *)&DAT_0000_750f = 0;
  *(undefined2 *)*(undefined4 *)0x44ca = 200;
  *(undefined2 *)((int)*(undefined4 *)0x44ca + 2) = 0x28;
  return;
}


