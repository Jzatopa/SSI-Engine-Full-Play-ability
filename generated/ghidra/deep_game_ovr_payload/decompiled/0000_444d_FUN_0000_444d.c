
/* WARNING: Instruction at (ram,0x00004462) overlaps instruction at (ram,0x00004461)
    */

undefined2 FUN_0000_444d(void)

{
  byte *pbVar1;
  undefined1 uVar2;
  int in_AX;
  undefined1 *puVar3;
  undefined2 uVar4;
  undefined2 in_DX;
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  pbVar1 = unaff_SI;
  *pbVar1 = *pbVar1 >> 3 | *pbVar1 << 5;
  puVar3 = &stack0x0000 + in_AX + ((char)*pbVar1 < '\0');
  if (puVar3 != (undefined1 *)0x0 &&
      (SCARRY2(in_AX,(int)&stack0x0000) !=
      SCARRY2((int)(&stack0x0000 + in_AX),(uint)((char)*pbVar1 < '\0'))) == (int)puVar3 < 0) {
    uVar4 = func_0x0000d6dc();
    return uVar4;
  }
  pbVar1 = unaff_SI;
  *pbVar1 = *pbVar1 >> 1 | *pbVar1 << 7;
  uVar2 = in(in_DX);
  return CONCAT11((char)((uint)puVar3 >> 8),uVar2);
}


