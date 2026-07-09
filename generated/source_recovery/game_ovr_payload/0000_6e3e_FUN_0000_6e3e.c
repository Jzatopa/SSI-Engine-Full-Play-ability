/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:6e3e
 * Ghidra name: FUN_0000_6e3e
 * Linear address: 0x06E3E
 * Original GAME.OVR file offset: 28230
 * Body addresses: 246
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Instruction at (ram,0x00006ef4) overlaps instruction at (ram,0x00006ef3)
    */
/* WARNING: Removing unreachable block (ram,0x00006e7c) */
/* WARNING: Removing unreachable block (ram,0x00006e7e) */
/* WARNING: Removing unreachable block (ram,0x00006e8d) */
/* WARNING: Removing unreachable block (ram,0x00006e94) */

void FUN_0000_6e3e(void)

{
  byte *pbVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  long lVar4;
  int in_AX;
  byte in_CL;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  undefined2 *in_ESI;
  undefined1 *unaff_DI;
  undefined1 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_FS;
  bool in_CF;
  undefined1 *in_stack_00000000;
  undefined2 in_stack_00000008;
  undefined2 in_stack_0000000c;
  undefined2 *in_stack_0000000e;
  undefined2 in_stack_00000018;
  byte in_stack_0000001c;
  undefined2 *in_stack_0000001e;
  undefined2 *in_stack_00000020;
  int in_stack_00000026;
  undefined2 in_stack_00000028;
  byte in_stack_0000002a;
  undefined1 *in_stack_0000002e;
  undefined1 *in_stack_00000030;
  undefined2 in_stack_00000038;
  int in_stack_0000003a;
  undefined2 in_stack_0000003c;
  
  uVar2 = in(in_DX);
  *unaff_DI = uVar2;
  out(*(undefined2 *)in_ESI,in_DX);
  if (in_CF) {
    pbVar1 = unaff_DI + 1 + in_BX;
    *pbVar1 = *pbVar1 & in_CL;
    lVar4 = (long)(int)((undefined2 *)in_ESI)[0x35] * 0x7264;
    puVar5 = unaff_DI + 1;
    if ((int)lVar4 == lVar4 && *pbVar1 != 0) {
LAB_0000_6e6d:
      puVar5[0x6e] = puVar5[0x6e] & (byte)((uint)in_stack_0000000c >> 8);
      puVar5[*(int *)((undefined1 *)CONCAT22((int)((ulong)in_ESI >> 0x10),in_stack_00000000) + 0x65)
             * 0x2073 + 0x65] =
           puVar5[*(int *)((undefined1 *)CONCAT22((int)((ulong)in_ESI >> 0x10),in_stack_00000000) +
                          0x65) * 0x2073 + 0x65] | (byte)in_stack_00000008;
      out(*in_stack_00000000,in_stack_00000008);
      func_0x0000d74f();
      FUN_0000_715c();
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2(0x2ac3,0x602);
    }
    uVar3 = in(in_stack_00000018);
    *in_stack_0000000e = uVar3;
    *(byte *)0x6f42 = *(byte *)0x6f42 & in_stack_0000001c;
    *(byte *)(in_stack_00000026 + (int)in_stack_00000020) =
         *(byte *)(in_stack_00000026 + (int)in_stack_00000020) & in_stack_0000002a;
    out(*in_stack_00000020,in_stack_00000028);
    uVar3 = in(in_stack_00000028);
    *in_stack_0000001e = uVar3;
    uVar3 = in(in_stack_00000028);
    in_stack_0000001e[1] = uVar3;
    out(*in_stack_00000030,in_stack_00000038);
    pbVar1 = in_stack_00000030 + 1;
    *pbVar1 = *pbVar1 & (byte)in_stack_0000003c;
    out(*(undefined2 *)(in_stack_00000030 + 1),in_stack_00000038);
    in_stack_00000000 = in_stack_00000030 + 5;
    out(*(undefined2 *)(in_stack_00000030 + 3),in_stack_00000038);
    in_stack_0000000c = in_stack_0000003c;
    in_stack_00000008 = in_stack_00000038;
    puVar5 = in_stack_0000002e;
    if ((long)(int)&stack0xfff6 != (long)*(int *)(in_stack_00000030 + 0x21) * 0x420e)
    goto LAB_0000_6e6d;
    if (in_stack_0000003a + 1 < 0) goto code_r0x00006ee3;
  }
  else {
    if (in_AX == *(int *)0x5352) {
      if (*(char *)0x5358 != '\0') {
        func_0x00007263();
      }
      unaff_CS = 0x602;
      FUN_0000_7105();
    }
    if ((*(int *)(*(int *)(unaff_BP + 6) + -2) != *(int *)0x5354) ||
       (*(int *)(*(int *)(unaff_BP + 6) + -4) != *(int *)0x5352)) {
      if (0x14 < *(byte *)0x5357) {
                    /* WARNING: Subroutine does not return */
        FUN_0000_d6c2(0x2ac4,unaff_CS);
      }
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2(0x2ac3,unaff_CS);
    }
    in_stack_0000002e = (undefined1 *)*(undefined2 *)(unaff_BP + 6);
  }
  unaff_ES = (undefined2)((ulong)*(undefined1 **)(in_stack_0000002e + -4) >> 0x10);
  in_stack_0000002e = (undefined1 *)*(undefined1 **)(in_stack_0000002e + -4);
code_r0x00006ee3:
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(in_stack_0000002e,unaff_ES);
}


