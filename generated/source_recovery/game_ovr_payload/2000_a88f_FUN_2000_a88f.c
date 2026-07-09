/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:a88f
 * Ghidra name: FUN_2000_a88f
 * Linear address: 0x2A88F
 * Original GAME.OVR file offset: 174231
 * Body addresses: 132
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_2000_a88f(void)

{
  uint uVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  uVar2 = 0xb58;
  func_0x0000b5d1();
  if (*(int *)0x534e == 0 && *(int *)0x5350 == 0) {
    FUN_2000_b876(0xb58,1,*(undefined2 *)0x534a,*(undefined2 *)0x534c);
  }
  else {
    uVar1 = (uint)(byte)(*(char *)0x253f >> 7);
    FUN_0000_2e9a(*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,*(undefined2 *)0x52d6,
                  *(undefined2 *)0x52d8,uVar1 << 8,uVar1 << 8,(int)*(char *)0x253f,
                  (int)*(char *)0x253e);
    FUN_0000_2e9a(*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,*(undefined2 *)0x744a,
                  *(undefined2 *)0x744c,0,0,0,0);
    uVar2 = 0x21a;
    FUN_0000_39b7();
    FUN_2000_a819(0x21a);
    FUN_2000_a680(*(undefined2 *)0x534e,*(undefined2 *)0x5350);
  }
  FUN_0000_b5b0(uVar2);
  return;
}


