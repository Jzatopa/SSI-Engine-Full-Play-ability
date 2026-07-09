
void FUN_0000_d62d(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined2 in_AX;
  int unaff_BP;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  do {
    uVar2 = *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP);
    *(undefined2 *)((undefined *)&DAT_0000_ffec + unaff_BP) = in_AX;
    *(undefined2 *)((undefined *)&DAT_0000_ffee + unaff_BP) = uVar2;
    while( true ) {
      do {
        while( true ) {
          while( true ) {
            uVar5 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -0x10) >> 0x10);
            iVar4 = (int)*(undefined4 *)(unaff_BP + -0x10);
            uVar2 = *(undefined2 *)(iVar4 + 0x2c);
            *(undefined2 *)(unaff_BP + -0x10) = *(undefined2 *)(iVar4 + 0x2a);
            *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP) = uVar2;
            if (*(int *)(unaff_BP + -0x10) == 0 &&
                *(int *)((undefined *)&DAT_0000_fff2 + unaff_BP) == 0) {
              FUN_0000_d64a();
              return;
            }
            *(undefined2 *)(unaff_BP + -0x21) =
                 (undefined *)&DAT_0000_536e +
                 (uint)*(byte *)((int)*(undefined4 *)(unaff_BP + -0x10) + 0x2e) * 9;
            *(undefined2 *)(unaff_BP + -0x1f) = unaff_DS;
            cVar1 = *(char *)*(undefined4 *)(unaff_BP + -0x21);
            if (cVar1 != '\0') break;
            uVar3 = FUN_0000_d18e(unaff_BP);
            ((undefined *)&DAT_0000_ffdd)[unaff_BP] = uVar3;
            cVar1 = *(char *)((int)*(undefined4 *)(unaff_BP + -0x21) + 2);
            if (cVar1 == '\x02') {
              ((undefined *)&DAT_0000_ffdd)[unaff_BP] =
                   (byte)((undefined *)&DAT_0000_ffdd)[unaff_BP] >>
                   (((undefined *)&DAT_0000_ffd1)[unaff_BP] & 0x1f);
            }
            else if (cVar1 == '\x03') {
              ((undefined *)&DAT_0000_ffdd)[unaff_BP] =
                   (byte)((undefined *)&DAT_0000_ffdd)[unaff_BP] >>
                   (((undefined *)&DAT_0000_ffd3)[unaff_BP] & 0x1f);
            }
            else if (cVar1 == '\x04') {
              ((undefined *)&DAT_0000_ffdd)[unaff_BP] =
                   (byte)((undefined *)&DAT_0000_ffdd)[unaff_BP] >>
                   (((undefined *)&DAT_0000_ffd2)[unaff_BP] & 0x1f);
            }
            if ((byte)((undefined *)&DAT_0000_ffde)[unaff_BP] <
                (byte)((undefined *)&DAT_0000_ffdd)[unaff_BP]) {
              ((undefined *)&DAT_0000_ffde)[unaff_BP] = ((undefined *)&DAT_0000_ffdd)[unaff_BP];
              uVar2 = *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP);
              *(undefined2 *)(unaff_BP + -8) = *(undefined2 *)(unaff_BP + -0x10);
              *(undefined2 *)((undefined *)&DAT_0000_fffa + unaff_BP) = uVar2;
            }
          }
          if (cVar1 != '\x01') break;
          if ((*(int *)((undefined *)&DAT_0000_ffe8 + unaff_BP) == 0 &&
               *(int *)((undefined *)&DAT_0000_ffea + unaff_BP) == 0) ||
             ((int)((uint)(byte)((undefined *)&DAT_0000_5370)
                                [(uint)*(byte *)((int)*(undefined4 *)
                                                       ((undefined *)&DAT_0000_ffe8 + unaff_BP) +
                                                0x2e) * 9] +
                   (int)*(char *)((int)*(undefined4 *)((undefined *)&DAT_0000_ffe8 + unaff_BP) +
                                 0x32)) <
              (int)((uint)*(byte *)((int)*(undefined4 *)(unaff_BP + -0x21) + 2) +
                   (int)*(char *)((int)*(undefined4 *)(unaff_BP + -0x10) + 0x32)))) {
            uVar2 = *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP);
            *(undefined2 *)((undefined *)&DAT_0000_ffe8 + unaff_BP) =
                 *(undefined2 *)(unaff_BP + -0x10);
            *(undefined2 *)((undefined *)&DAT_0000_ffea + unaff_BP) = uVar2;
          }
        }
      } while (cVar1 != '\x06');
      if ((*(byte *)((int)*(undefined4 *)(unaff_BP + -0x10) + 0x34) & 0x80) == 0) break;
      *(undefined1 *)(unaff_BP + -0x1d) = 1;
    }
    in_AX = *(undefined2 *)(unaff_BP + -0x10);
  } while( true );
}


