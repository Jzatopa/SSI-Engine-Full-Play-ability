
undefined1 __stdcall16far FUN_0000_c05c(void)

{
  char *pcVar1;
  char in_AL;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  char in_DL;
  int unaff_BP;
  undefined2 uVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  
  ((undefined *)&DAT_0000_ffd8)[unaff_BP] = in_AL - in_DL;
  ((undefined *)&DAT_0000_ffda)[unaff_BP] = *(char *)(unaff_BP + -0x11) + *(char *)(unaff_BP + -8);
  ((undefined *)&DAT_0000_ffd9)[unaff_BP] =
       ((undefined *)&DAT_0000_ffee)[unaff_BP] - *(char *)(unaff_BP + -8);
  ((undefined *)&DAT_0000_ffdb)[unaff_BP] =
       ((undefined *)&DAT_0000_ffee)[unaff_BP] + *(char *)(unaff_BP + -8);
  uVar13 = 0x169;
  uVar11 = FUN_0000_ce3f();
  *(undefined2 *)(unaff_BP + -5) = (int)uVar11;
  *(undefined2 *)(unaff_BP + -3) = (int)((ulong)uVar11 >> 0x10);
  uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -5) >> 0x10);
  uVar5 = (undefined2)*(undefined4 *)(unaff_BP + -5);
  uVar12 = 0x169;
  uVar9 = 0xcc0;
  FUN_0000_e6d2(0x100);
  uVar10 = *(undefined2 *)0x5801;
  *(undefined2 *)(unaff_BP + -0x10) = *(undefined2 *)0x57ff;
  *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP) = uVar10;
  while (*(int *)(unaff_BP + -0x10) != 0 || *(int *)((undefined *)&DAT_0000_fff2 + unaff_BP) != 0) {
    uVar2 = FUN_0000_0e20(uVar9,*(undefined2 *)(unaff_BP + -0x10),
                          *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP),uVar12,uVar5,uVar7
                          ,uVar13);
    ((undefined *)&DAT_0000_ffed)[unaff_BP] = uVar2;
    uVar5 = *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP);
    uVar12 = *(undefined2 *)(unaff_BP + -0x10);
    uVar9 = 0xdb;
    uVar2 = FUN_0000_0e25();
    ((undefined *)&DAT_0000_ffec)[unaff_BP] = uVar2;
    if ((((*(char *)((int)*(undefined4 *)(unaff_BP + -0x10) + 0xd5) != '\0') &&
         ((char)((undefined *)&DAT_0000_ffdc)[unaff_BP] <=
          (char)((undefined *)&DAT_0000_ffed)[unaff_BP])) &&
        ((char)((undefined *)&DAT_0000_ffed)[unaff_BP] <=
         (char)((undefined *)&DAT_0000_ffde)[unaff_BP])) &&
       (((char)((undefined *)&DAT_0000_ffdd)[unaff_BP] <=
         (char)((undefined *)&DAT_0000_ffec)[unaff_BP] &&
        ((char)((undefined *)&DAT_0000_ffec)[unaff_BP] <= *(char *)(unaff_BP + -0x21))))) {
      *(undefined1 *)(unaff_BP + -0x1f) =
           ((undefined *)&DAT_0000_ffd1)
           [unaff_BP + *(char *)((int)*(undefined4 *)(unaff_BP + -0x10) + 0xd6)];
      cVar3 = *(char *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) + 0x2e);
      if ((cVar3 == '%') || (cVar3 == '&')) {
        uVar9 = 0xdb;
        func_0x00000e02(0xdb,(undefined *)&DAT_0000_ffd3 + unaff_BP);
        if ((((undefined *)&DAT_0000_ffd3)[unaff_BP] == '\x01') ||
           (((undefined *)&DAT_0000_ffd3)[unaff_BP] == '\x04')) {
          *(undefined1 *)(unaff_BP + -0x1f) = 0xff;
        }
      }
      else if (cVar3 == '#') {
        cVar3 = func_0x00000a96(0xdb,unaff_BP + -0x33);
        if ((cVar3 != '\0') ||
           (cVar3 = func_0x000009ce(0x99,*(undefined2 *)(unaff_BP + -0x10),
                                    *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP)),
           cVar3 != '\0')) {
          *(undefined1 *)(unaff_BP + -0x1f) = 0;
        }
        uVar9 = 0x99;
      }
      else if (cVar3 == '\"') {
        uVar9 = 0x99;
        cVar3 = func_0x000009ce(0xdb,*(undefined2 *)(unaff_BP + -0x10),
                                *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP));
        if (cVar3 != '\0') {
          *(undefined1 *)(unaff_BP + -0x1f) = 0;
        }
      }
      *(char *)(unaff_BP + -0x1d) = -((undefined *)&DAT_0000_fffa)[unaff_BP];
      ((undefined *)&DAT_0000_ffe2)[unaff_BP] = ((undefined *)&DAT_0000_fffa)[unaff_BP];
      if ((int)*(char *)(unaff_BP + -0x1d) + (int)(char)((undefined *)&DAT_0000_ffec)[unaff_BP] <
          (int)(char)((undefined *)&DAT_0000_ffd9)[unaff_BP]) {
        *(char *)(unaff_BP + -0x1d) =
             ((undefined *)&DAT_0000_ffd9)[unaff_BP] - ((undefined *)&DAT_0000_ffec)[unaff_BP];
      }
      if ((int)(char)((undefined *)&DAT_0000_ffdb)[unaff_BP] <
          (int)(char)((undefined *)&DAT_0000_ffe2)[unaff_BP] +
          (int)(char)((undefined *)&DAT_0000_ffec)[unaff_BP]) {
        ((undefined *)&DAT_0000_ffe2)[unaff_BP] =
             ((undefined *)&DAT_0000_ffdb)[unaff_BP] - ((undefined *)&DAT_0000_ffec)[unaff_BP];
      }
      ((undefined *)&DAT_0000_ffca)[unaff_BP] = ((undefined *)&DAT_0000_ffe2)[unaff_BP];
      if (*(char *)(unaff_BP + -0x1d) <= (char)((undefined *)&DAT_0000_ffca)[unaff_BP]) {
        ((undefined *)&DAT_0000_ffe6)[unaff_BP] = *(char *)(unaff_BP + -0x1d);
        while( true ) {
          ((undefined *)&DAT_0000_ffe5)[unaff_BP] =
               ((undefined *)&DAT_0000_ffed)[unaff_BP] -
               *(char *)((char)((undefined *)&DAT_0000_ffe6)[unaff_BP] * 3 +
                         (uint)(byte)((undefined *)&DAT_0000_fffa)[unaff_BP] + 0x6dc);
          ((undefined *)&DAT_0000_ffe4)[unaff_BP] =
               ((undefined *)&DAT_0000_ffed)[unaff_BP] +
               *(char *)((char)((undefined *)&DAT_0000_ffe6)[unaff_BP] * 3 +
                         (uint)(byte)((undefined *)&DAT_0000_fffa)[unaff_BP] + 0x6dc);
          if ((char)((undefined *)&DAT_0000_ffe5)[unaff_BP] <
              (char)((undefined *)&DAT_0000_ffd8)[unaff_BP]) {
            ((undefined *)&DAT_0000_ffe5)[unaff_BP] = ((undefined *)&DAT_0000_ffd8)[unaff_BP];
          }
          if ((char)((undefined *)&DAT_0000_ffda)[unaff_BP] <
              (char)((undefined *)&DAT_0000_ffe4)[unaff_BP]) {
            ((undefined *)&DAT_0000_ffe4)[unaff_BP] = ((undefined *)&DAT_0000_ffda)[unaff_BP];
          }
          ((undefined *)&DAT_0000_ffc9)[unaff_BP] = ((undefined *)&DAT_0000_ffe4)[unaff_BP];
          if ((char)((undefined *)&DAT_0000_ffe5)[unaff_BP] <=
              (char)((undefined *)&DAT_0000_ffc9)[unaff_BP]) {
            *(char *)(unaff_BP + -0x19) = ((undefined *)&DAT_0000_ffe5)[unaff_BP];
            while (pcVar1 = (char *)((int)*(undefined4 *)(unaff_BP + -5) +
                                     ((int)*(char *)(unaff_BP + -0x19) -
                                     (int)*(char *)(unaff_BP + -0x11)) * 0x13 +
                                     (((int)(char)((undefined *)&DAT_0000_ffe6)[unaff_BP] +
                                      (int)(char)((undefined *)&DAT_0000_ffec)[unaff_BP]) -
                                     (int)(char)((undefined *)&DAT_0000_ffee)[unaff_BP]) + 0xb4),
                  *pcVar1 = *pcVar1 + *(char *)(unaff_BP + -0x1f),
                  *(char *)(unaff_BP + -0x19) != ((undefined *)&DAT_0000_ffc9)[unaff_BP]) {
              *(char *)(unaff_BP + -0x19) = *(char *)(unaff_BP + -0x19) + '\x01';
            }
          }
          if (((undefined *)&DAT_0000_ffe6)[unaff_BP] == ((undefined *)&DAT_0000_ffca)[unaff_BP])
          break;
          ((undefined *)&DAT_0000_ffe6)[unaff_BP] = ((undefined *)&DAT_0000_ffe6)[unaff_BP] + '\x01'
          ;
        }
      }
    }
    uVar8 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -0x10) >> 0x10);
    iVar6 = (int)*(undefined4 *)(unaff_BP + -0x10);
    uVar10 = *(undefined2 *)(iVar6 + 0x101);
    *(undefined2 *)(unaff_BP + -0x10) = *(undefined2 *)(iVar6 + 0xff);
    *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP) = uVar10;
  }
  uVar2 = FUN_0000_0e20(uVar9,*(undefined2 *)(unaff_BP + 0xc),*(undefined2 *)(unaff_BP + 0xe),uVar12
                        ,uVar5,uVar7,uVar13);
  ((undefined *)&DAT_0000_ffe9)[unaff_BP] = uVar2;
  uVar10 = 0xdb;
  uVar2 = FUN_0000_0e25(*(undefined2 *)(unaff_BP + 0xc),*(undefined2 *)(unaff_BP + 0xe));
  ((undefined *)&DAT_0000_ffe8)[unaff_BP] = uVar2;
  *(undefined1 *)(unaff_BP + -0x20) = 0;
  ((undefined *)&DAT_0000_ffca)[unaff_BP] = *(undefined1 *)(unaff_BP + -8);
  if (-*(char *)(unaff_BP + -8) <= (char)((undefined *)&DAT_0000_ffca)[unaff_BP]) {
    *(char *)(unaff_BP + -0x19) = -*(char *)(unaff_BP + -8);
    do {
      ((undefined *)&DAT_0000_ffc9)[unaff_BP] = *(undefined1 *)(unaff_BP + -8);
      if (-*(char *)(unaff_BP + -8) <= (char)((undefined *)&DAT_0000_ffc9)[unaff_BP]) {
        ((undefined *)&DAT_0000_ffe6)[unaff_BP] = -*(char *)(unaff_BP + -8);
        do {
          iVar6 = *(char *)(unaff_BP + -0x19) * 0x13;
          *(undefined1 *)(unaff_BP + -0x1f) =
               *(undefined1 *)
                ((int)*(undefined4 *)(unaff_BP + -5) + iVar6 +
                 (int)(char)((undefined *)&DAT_0000_ffe6)[unaff_BP] + 0xb4);
          uVar5 = uVar10;
          if (*(char *)(unaff_BP + -0x20) < *(char *)(unaff_BP + -0x1f)) {
LAB_0000_c3a1:
            ((undefined *)&DAT_0000_ffed)[unaff_BP] = ((undefined *)&DAT_0000_ffe9)[unaff_BP];
            ((undefined *)&DAT_0000_ffec)[unaff_BP] = ((undefined *)&DAT_0000_ffe8)[unaff_BP];
            uVar10 = 0x7e;
            uVar4 = func_0x00000814(uVar5,*(undefined2 *)(unaff_BP + 0xc),
                                    *(undefined2 *)(unaff_BP + 0xe));
            *(uint *)((undefined *)&DAT_0000_ffd5 + unaff_BP) = uVar4 & 0xff;
            *(undefined1 *)0x4137 = 1;
            if ((((-1 < (int)*(char *)(unaff_BP + -0x11) + (int)*(char *)(unaff_BP + -0x19)) &&
                 ((int)*(char *)(unaff_BP + -0x11) + (int)*(char *)(unaff_BP + -0x19) < 0x32)) &&
                (-1 < (int)(char)((undefined *)&DAT_0000_ffee)[unaff_BP] +
                      (int)(char)((undefined *)&DAT_0000_ffe6)[unaff_BP])) &&
               ((int)(char)((undefined *)&DAT_0000_ffee)[unaff_BP] +
                (int)(char)((undefined *)&DAT_0000_ffe6)[unaff_BP] < 0x18)) {
              uVar10 = 0xd7;
              cVar3 = FUN_0000_0da4(0x7e,(undefined *)&DAT_0000_ffd5 + unaff_BP);
              if ((cVar3 != '\0') && (*(char *)0x4134 == '\0')) {
                ((undefined *)&DAT_0000_ffeb)[unaff_BP] = *(undefined1 *)(unaff_BP + -0x19);
                ((undefined *)&DAT_0000_ffea)[unaff_BP] = ((undefined *)&DAT_0000_ffe6)[unaff_BP];
                *(undefined1 *)(unaff_BP + -0x20) = *(undefined1 *)(unaff_BP + -0x1f);
              }
            }
          }
          else if ((*(char *)(unaff_BP + -0x1f) == *(char *)(unaff_BP + -0x20)) &&
                  ('\0' < *(char *)(unaff_BP + -0x1f))) {
            uVar10 = 0x99;
            cVar3 = FUN_0000_09b5(CONCAT11((char)((uint)iVar6 >> 8),0x19));
            uVar5 = uVar10;
            if (cVar3 != '\0') goto LAB_0000_c3a1;
          }
          if (((undefined *)&DAT_0000_ffe6)[unaff_BP] == ((undefined *)&DAT_0000_ffc9)[unaff_BP])
          break;
          ((undefined *)&DAT_0000_ffe6)[unaff_BP] = ((undefined *)&DAT_0000_ffe6)[unaff_BP] + '\x01'
          ;
        } while( true );
      }
      if (*(char *)(unaff_BP + -0x19) == ((undefined *)&DAT_0000_ffca)[unaff_BP]) break;
      *(char *)(unaff_BP + -0x19) = *(char *)(unaff_BP + -0x19) + '\x01';
    } while( true );
  }
  uVar5 = 0xcc0;
  FUN_0000_ce54(uVar10,0x169,*(undefined2 *)(unaff_BP + -5),*(undefined2 *)(unaff_BP + -3));
  if (*(char *)(unaff_BP + 10) == '\0') {
    if ('\0' < *(char *)(unaff_BP + -0x20)) {
      cVar3 = *(char *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) + 0x2e);
      if (cVar3 == '%') {
        uVar5 = 0x99;
        uVar4 = FUN_0000_09ba(0xcc0,6,1);
        *(uint *)((undefined *)&DAT_0000_ffcb + unaff_BP) = (uVar4 & 0xff) + 1;
      }
      else if (cVar3 == '&') {
        uVar5 = 0x99;
        uVar4 = FUN_0000_09ba(0xcc0,6,1);
        *(uint *)((undefined *)&DAT_0000_ffcb + unaff_BP) = uVar4 & 0xff;
      }
      else if (cVar3 == '!') {
        *(undefined2 *)((undefined *)&DAT_0000_ffcb + unaff_BP) = 0x28;
      }
      else if (cVar3 == '\"') {
        *(undefined2 *)((undefined *)&DAT_0000_ffcb + unaff_BP) = 5;
      }
      else if (cVar3 == '$') {
        uVar5 = 0x99;
        uVar4 = FUN_0000_09ba(0xcc0,10,1);
        *(uint *)((undefined *)&DAT_0000_ffcb + unaff_BP) = (uVar4 & 0xff) + 10;
      }
      else if (cVar3 == '#') {
        uVar5 = 0x99;
        uVar4 = FUN_0000_09ba(0xcc0,10,1);
        *(uint *)((undefined *)&DAT_0000_ffcb + unaff_BP) = (uVar4 & 0xff) + 5;
      }
      else if (cVar3 == '\x11') {
        *(undefined2 *)((undefined *)&DAT_0000_ffcb + unaff_BP) = 0x19;
      }
      else if (cVar3 == '\x12') {
        *(undefined2 *)((undefined *)&DAT_0000_ffcb + unaff_BP) = 0x1e;
      }
      uVar10 = func_0x0000d612(uVar5);
      *(undefined2 *)((undefined *)&DAT_0000_ffcb + unaff_BP) = uVar10;
      if (*(uint *)((undefined *)&DAT_0000_ffcb + unaff_BP) < 0x81) {
        *(undefined *)*(undefined4 *)(unaff_BP + 6) = ((undefined *)&DAT_0000_ffcb)[unaff_BP];
      }
      else {
        *(char *)*(undefined4 *)(unaff_BP + 6) =
             (char)(*(uint *)((undefined *)&DAT_0000_ffcb + unaff_BP) >> 4) + 'x';
      }
    }
  }
  else if (*(char *)(unaff_BP + -0x20) < '\x01') {
    FUN_0000_d3bf(0xcc0,(undefined *)&DAT_0000_ffd7 + unaff_BP);
    *(undefined1 *)(unaff_BP + -1) = ((undefined *)&DAT_0000_ffd7)[unaff_BP];
  }
  else {
    FUN_0000_0585(0xcc0,(undefined *)&DAT_0000_ffd7 + unaff_BP);
    uVar2 = FUN_0000_0a28(0x56,*(undefined2 *)(unaff_BP + 0xc),*(undefined2 *)(unaff_BP + 0xe));
    *(undefined1 *)(unaff_BP + -1) = uVar2;
  }
  return *(undefined1 *)(unaff_BP + -1);
}


