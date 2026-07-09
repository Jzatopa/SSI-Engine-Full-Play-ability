
void __cdecl16far FUN_1000_0202(void)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  undefined1 *local_b;
  
  *(undefined1 *)0x747f = 0xd;
  *(undefined1 *)0x7480 = 10;
  *(undefined1 *)0x7481 = 0xf;
  *(undefined1 *)0x8c2d = 0;
  *(undefined1 *)0x8c2e = 0;
  *(undefined2 *)0x7489 = 0;
  *(undefined2 *)0x748b = 0;
  *(undefined1 *)&DAT_0000_750f = 0;
  *(undefined1 *)0x7510 = 0;
  *(undefined1 *)0x74b0 = 0;
  *(undefined1 *)0x7485 = 0;
  *(undefined1 *)0x687e = 0;
  uVar2 = *(undefined1 *)0x50d2;
  *(undefined1 *)0x50d2 = 1;
  *(undefined1 *)((int)*(undefined4 *)0x441c + 0x312) = *(undefined1 *)0x50d2;
  uVar3 = *(undefined4 *)0x4418;
  iVar1 = (int)uVar3 + 0x200;
  *(int *)0x534a = iVar1;
  *(undefined2 *)0x534c = (int)((ulong)uVar3 >> 0x10);
  FUN_0000_07d7(CONCAT11((char)((uint)iVar1 >> 8),10),*(undefined2 *)0x534a,*(undefined2 *)0x534c);
  *(undefined1 *)0x50d2 = uVar2;
  *(undefined2 *)0x5360 = 0;
  *(undefined2 *)0x5362 = 0;
  uVar3 = *(undefined4 *)0x4418;
  *(int *)0x5360 = (int)uVar3 + 0x85;
  *(undefined2 *)0x5362 = (int)((ulong)uVar3 >> 0x10);
  uVar5 = (undefined2)((ulong)*(undefined4 *)0x5360 >> 0x10);
  iVar4 = (int)*(undefined4 *)0x5360;
  *(undefined1 *)(iVar4 + 0x36) = 0;
  *(undefined1 *)(iVar4 + 0x34) = 0;
  iVar1 = ((uint)*(byte *)0x26aa + (uint)*(byte *)0x2698) * 3;
  _local_b = (undefined1 *)CONCAT22(unaff_DS,(undefined1 *)(iVar1 + 0x25e8));
  *(undefined1 *)(iVar4 + 0x39) = *_local_b;
  *(undefined1 *)(iVar4 + 0x3a) = *(undefined1 *)(iVar1 + 0x25e9);
  *(undefined1 *)(iVar4 + 0x38) = 0x57;
  return;
}


