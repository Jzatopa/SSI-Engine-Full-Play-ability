/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:4a49
 * Ghidra name: FUN_0000_4a49
 * Linear address: 0x04A49
 * Original GAME.OVR file offset: 19025
 * Body addresses: 70
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Instruction at (ram,0x00004aaa) overlaps instruction at (ram,0x00004aa9)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00004a76) */
/* WARNING: Removing unreachable block (ram,0x00004a84) */
/* WARNING: Removing unreachable block (ram,0x00004a87) */
/* WARNING: Removing unreachable block (ram,0x00004aaa) */
/* WARNING: Removing unreachable block (ram,0x00004a8a) */
/* WARNING: Removing unreachable block (ram,0x00004aa6) */
/* WARNING: Removing unreachable block (ram,0x00004ab1) */
/* WARNING: Removing unreachable block (ram,0x00004abf) */
/* WARNING: Removing unreachable block (ram,0x00004acc) */
/* WARNING: Removing unreachable block (ram,0x00004ad5) */
/* WARNING: Removing unreachable block (ram,0x00004ad2) */
/* WARNING: Removing unreachable block (ram,0x00004abc) */
/* WARNING: Removing unreachable block (ram,0x00004c8e) */
/* WARNING: Removing unreachable block (ram,0x00004aae) */
/* WARNING: Removing unreachable block (ram,0x00004afa) */
/* WARNING: Removing unreachable block (ram,0x00004aed) */

void __stdcall16far
FUN_0000_4a49(undefined2 param_1,undefined2 param_2,int param_3,undefined2 param_4,uint param_5,
             undefined2 param_6,int param_7,undefined2 param_8,int param_9,undefined2 param_10,
             int param_11,undefined2 param_12,undefined2 param_13)

{
  byte *pbVar1;
  uint *puVar2;
  undefined2 uVar3;
  int iVar4;
  char cVar5;
  undefined2 in_AX;
  undefined2 in_CX;
  undefined4 in_EDX;
  int in_BX;
  uint uVar6;
  int unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_FS;
  long in_GS_OFFSET;
  int in_stack_00000000;
  int in_stack_00000002;
  
  *(byte *)(in_BX + 0x66) = *(byte *)(in_BX + 0x66) & (byte)((uint)in_CX >> 8);
  *(byte *)(unaff_SI + 0x61) = *(byte *)(unaff_SI + 0x61) & (byte)((uint)in_AX >> 8);
  uVar3 = in((int)in_EDX);
  *unaff_DI = uVar3;
  puVar2 = (uint *)(in_GS_OFFSET + CONCAT22((int)((ulong)in_EDX >> 0x10),param_4));
  *puVar2 = *puVar2 & param_5;
  pbVar1 = (byte *)(param_3 + in_stack_00000000 + 0x73);
  *pbVar1 = *pbVar1 & (byte)(param_5 >> 8);
  *(byte *)(in_stack_00000002 + 0x65) =
       *(byte *)(in_stack_00000002 + 0x65) & (byte)((uint)param_6 >> 8);
  *(uint *)(param_11 + param_7) = *(uint *)(param_11 + param_7) & (uint)&stack0x0020;
  uVar6 = *(int *)(param_9 + 0x67) * 0x1021;
  pbVar1 = (byte *)(param_11 + param_7 + 0x73);
  *pbVar1 = *pbVar1 & (byte)((uint)param_13 >> 8);
  *(byte *)(param_7 + 0x6e) = *(byte *)(param_7 + 0x6e) & (byte)((uint)param_12 >> 8);
  puVar2 = (uint *)(param_11 + 0x6e);
  iVar4 = (uVar6 & 3) - (*puVar2 & 3);
  *puVar2 = *puVar2 + (uint)(0 < iVar4) * iVar4;
  if (0 < iVar4) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  cVar5 = FUN_0000_0963();
  if (((cVar5 != '\0') && (*(char *)(uVar6 + 8) == '\0')) && (*(byte *)(uVar6 + 10) < 100)) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2();
  }
  if (*(char *)(uVar6 + 8) == '\0') {
    cVar5 = FUN_0000_09ba();
    *(char *)(uVar6 - 5) = cVar5 + '\x01';
  }
  else {
    *(char *)(uVar6 - 5) = (char)*(undefined2 *)((int)*(undefined4 *)(uVar6 - 4) + 0x45) + '\x1e';
  }
  FUN_0000_e390();
  FUN_0000_0a0f();
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2();
}


