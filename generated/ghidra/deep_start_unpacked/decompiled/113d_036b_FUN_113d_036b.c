
void __cdecl16far FUN_113d_036b(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  undefined1 extraout_AH_03;
  undefined1 extraout_AH_04;
  undefined1 extraout_AH_05;
  undefined1 extraout_AH_06;
  undefined1 extraout_AH_07;
  undefined1 extraout_AH_08;
  undefined1 extraout_AH_09;
  undefined1 extraout_AH_10;
  uint uVar3;
  uint uVar4;
  int extraout_DX;
  int extraout_DX_00;
  int extraout_DX_01;
  int extraout_DX_02;
  int iVar5;
  int extraout_DX_03;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined2 uVar11;
  undefined1 local_108 [6];
  undefined1 local_102 [247];
  undefined1 local_b [3];
  undefined1 local_8 [5];
  char local_3;
  
  *(undefined1 *)0x9f34 = 0;
  FUN_178b_01ff();
  puVar9 = local_b;
  uVar7 = unaff_SS;
  FUN_1cc0_0ac2(0x8f,0x178b);
  FUN_1c6a_0012(puVar9,uVar7);
  uVar7 = *(undefined2 *)0x9f4c;
  *(undefined2 *)0x8c49 = *(undefined2 *)0x9f4a;
  *(undefined2 *)0x8c4b = uVar7;
  *(undefined2 *)0x9f4a = 0x405;
  *(undefined2 *)0x9f4c = 0x1836;
  puVar10 = local_108;
  puVar9 = local_8;
  uVar7 = unaff_SS;
  uVar11 = unaff_SS;
  FUN_1cc0_0ac2(0x98,0x1c6a);
  FUN_1c3e_018d(puVar9,uVar7);
  FUN_1c3e_0256(0x431a,unaff_DS,0x4311,unaff_DS,0x4370,unaff_DS,puVar10,uVar11);
  if (*(byte *)0x4371 < 0x43) {
    if (*(char *)0x4371 == 'A') {
      FUN_1cc0_0adc(0x4f,0x43c0,unaff_DS,0x9e,0x1c3e);
    }
    else {
      FUN_1cc0_0adc(0x4f,0x43c0,unaff_DS,0xa2,0x1c3e);
    }
  }
  else {
    FUN_1cc0_0adc(0x4f,0x43c0,unaff_DS,0x4370,unaff_DS);
  }
  *(undefined1 *)0x4410 = *(undefined1 *)0x43c1;
  cVar1 = FUN_178b_051b(0x1059,unaff_DS);
  if (cVar1 == '\0') {
    FUN_1cc0_04f5(0x1059,unaff_DS,0x413e,unaff_DS);
    FUN_1cc0_056a(0x1cc0,0x413e);
    uVar2 = FUN_1cc0_04a2();
    *(undefined1 *)0x42be = uVar2;
    if (*(char *)0x42be != '\0') {
      FUN_1bdc_01c0();
      uVar11 = 0xa04e;
      uVar7 = unaff_DS;
      FUN_1cc0_0917(0,0xa6,0x1bdc);
      FUN_1cc0_0848(uVar11,uVar7);
      FUN_1cc0_0848(0xa04e,unaff_DS);
      uVar11 = 0xa04e;
      uVar7 = unaff_DS;
      FUN_1cc0_0917(0,0xce,0x1cc0);
      FUN_1cc0_0848(uVar11,uVar7);
      FUN_1cc0_00e9();
    }
    FUN_1bdc_01c0();
    uVar11 = 0xa04e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x10a,0x1bdc);
    FUN_1cc0_086c(uVar11,uVar7);
    uVar2 = func_0x000113f0(0x1cc0,CONCAT11(extraout_AH,3),CONCAT11(extraout_AH,1));
    *(undefined1 *)0x413d = uVar2;
    cVar1 = *(char *)0x413d;
    if (cVar1 == '\x01') {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_08b5(0,0x45);
      FUN_1cc0_0848(uVar11,uVar7);
    }
    else if (cVar1 == '\x02') {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_08b5(0,0x54);
      FUN_1cc0_0848(uVar11,uVar7);
    }
    else if (cVar1 == '\x03') {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_08b5(0,0x56);
      FUN_1cc0_0848(uVar11,uVar7);
    }
    FUN_1bdc_01c0();
    uVar11 = 0xa04e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x13f,0x1bdc);
    FUN_1cc0_0848(uVar11,uVar7);
    uVar11 = 0xa04e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x15b,0x1cc0);
    FUN_1cc0_0848(uVar11,uVar7);
    uVar11 = 0xa04e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x17a,0x1cc0);
    FUN_1cc0_0848(uVar11,uVar7);
    uVar11 = 0xa04e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x191,0x1cc0);
    FUN_1cc0_0848(uVar11,uVar7);
    uVar11 = 0xa04e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x1ae,0x1cc0);
    FUN_1cc0_0848(uVar11,uVar7);
    uVar11 = 0xa04e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x1ca,0x1cc0);
    FUN_1cc0_0848(uVar11,uVar7);
    uVar2 = func_0x000113f0(0x1cc0,CONCAT11(extraout_AH_00,6),CONCAT11(extraout_AH_00,1));
    *(undefined1 *)0x413d = uVar2;
    cVar1 = *(char *)0x413d;
    if (cVar1 == '\x01') {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_08b5(0,0x50);
      FUN_1cc0_0848(uVar11,uVar7);
    }
    else if (cVar1 == '\x02') {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_08b5(0,0x53);
      FUN_1cc0_0848(uVar11,uVar7);
    }
    else if (cVar1 == '\x03') {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_08b5(0,0x41);
      FUN_1cc0_0848(uVar11,uVar7);
    }
    else if (cVar1 == '\x04') {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_08b5(0,0x52);
      FUN_1cc0_0848(uVar11,uVar7);
    }
    else if (cVar1 == '\x05') {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_08b5(0,0x54);
      FUN_1cc0_0848(uVar11,uVar7);
    }
    else if (cVar1 == '\x06') {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_08b5(0,0x51);
      FUN_1cc0_0848(uVar11,uVar7);
    }
    *(undefined1 *)0x8db8 = 0;
    FUN_1bdc_01c0();
    uVar11 = 0xa04e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x1e2,0x1bdc);
    FUN_1cc0_086c(uVar11,uVar7);
    uVar2 = func_0x000113f0(0x1cc0,CONCAT11(extraout_AH_01,3),CONCAT11(extraout_AH_01,1));
    *(undefined1 *)0x413d = uVar2;
    cVar1 = *(char *)0x413d;
    if (cVar1 == '\x01') {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_08b5(0,0x4a);
      FUN_1cc0_0848(uVar11,uVar7);
      *(undefined1 *)0x8db8 = 1;
    }
    else if (cVar1 == '\x02') {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_08b5(0,0x4d);
      FUN_1cc0_0848(uVar11,uVar7);
    }
    else if (cVar1 == '\x03') {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_08b5(0,0x4e);
      FUN_1cc0_0848(uVar11,uVar7);
    }
    FUN_1bdc_01c0();
    puVar9 = local_102;
    uVar7 = unaff_SS;
    FUN_1cc0_0ac2(0x43c0,unaff_DS);
    FUN_1cc0_0b4f(0x220,0x1cc0);
    FUN_1cc0_0adc(0x4f,0x431f,unaff_DS,puVar9,uVar7);
    uVar8 = 0xa04e;
    puVar9 = local_102;
    uVar7 = unaff_SS;
    uVar11 = unaff_DS;
    FUN_1cc0_0ac2(0x225,0x1cc0);
    FUN_1cc0_0b4f(0x431f,unaff_DS);
    FUN_1cc0_0b4f(0x243,0x1cc0);
    FUN_1cc0_0917(0,puVar9,uVar7);
    FUN_1cc0_086c(uVar8,uVar11);
    uVar11 = 0x9f4e;
    uVar7 = unaff_DS;
    FUN_1cc0_08df(0x50,0x42c0,unaff_DS);
    FUN_1cc0_081a(uVar11,uVar7);
    uVar2 = FUN_1cc0_1c54(CONCAT11(extraout_AH_02,*(undefined1 *)0x42c1));
    *(undefined1 *)0x42c1 = uVar2;
    if ((((*(byte *)0x42c0 < 4) || (uVar2 = *(char *)0x42c2 == ':', !(bool)uVar2)) ||
        ((FUN_1cc0_0d77(0x248,0x1cc0,*(undefined1 *)0x42c1), !(bool)uVar2 &&
         (uVar2 = 0, *(char *)0x42c1 == *(char *)0x4371)))) ||
       (FUN_1cc0_0d77(0x268,0x1cc0,CONCAT11(extraout_AH_03,*(undefined1 *)0x42c1)), (bool)uVar2)) {
      FUN_1cc0_0adc(0x50,0x42c0,unaff_DS,0x431f,unaff_DS);
      uVar8 = 0xa04e;
      puVar9 = local_102;
      uVar7 = unaff_SS;
      uVar11 = unaff_DS;
      FUN_1cc0_0ac2(0x288,0x1cc0);
      FUN_1cc0_0b4f(0x42c0,unaff_DS);
      FUN_1cc0_0917(0,puVar9,uVar7);
      FUN_1cc0_0848(uVar8,uVar11);
      FUN_1bdc_029c(2000);
    }
    local_3 = *(char *)0x42c0;
    if (local_3 != '\0') {
      *(undefined1 *)0x42bf = 1;
      while( true ) {
        uVar2 = FUN_1cc0_1c54(*(undefined1 *)(*(byte *)0x42bf + 0x42c0));
        *(undefined1 *)(*(byte *)0x42bf + 0x42c0) = uVar2;
        if (*(char *)0x42bf == local_3) break;
        *(char *)0x42bf = *(char *)0x42bf + '\x01';
      }
    }
    if (*(char *)(*(byte *)0x42c0 + 0x42c0) != '\\') {
      puVar9 = local_102;
      uVar7 = unaff_SS;
      FUN_1cc0_0ac2(0x42c0,unaff_DS);
      FUN_1cc0_0b4f(0x29d,0x1cc0);
      FUN_1cc0_0adc(0x50,0x42c0,unaff_DS,puVar9,uVar7);
    }
    uVar11 = 0x413e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x42c0,unaff_DS);
    FUN_1cc0_0848(uVar11,uVar7);
    FUN_1bdc_01c0();
    *(undefined1 *)0x42c0 = 0;
    if (*(byte *)0x43c1 < 0x43) {
      puVar9 = local_102;
      uVar7 = unaff_SS;
      FUN_1cc0_0bf2(CONCAT11(extraout_AH_04,*(undefined1 *)0x43c1));
      FUN_1cc0_0b4f(0x29f,0x1cc0);
      FUN_1cc0_0adc(0x4f,0x431f,unaff_DS,puVar9,uVar7);
    }
    else {
      puVar9 = local_102;
      uVar7 = unaff_SS;
      FUN_1cc0_0bf2(CONCAT11(extraout_AH_04,*(undefined1 *)0x43c1));
      FUN_1cc0_0b4f(0x2a6,0x1cc0);
      FUN_1cc0_0adc(0x4f,0x431f,unaff_DS,puVar9,uVar7);
    }
    uVar11 = 0xa04e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x2b2,0x1cc0);
    FUN_1cc0_0848(uVar11,uVar7);
    uVar8 = 0xa04e;
    puVar9 = local_102;
    uVar7 = unaff_SS;
    uVar11 = unaff_DS;
    FUN_1cc0_0ac2(0x2de,0x1cc0);
    FUN_1cc0_0b4f(0x431f,unaff_DS);
    FUN_1cc0_0b4f(0x243,0x1cc0);
    FUN_1cc0_0917(0,puVar9,uVar7);
    FUN_1cc0_086c(uVar8,uVar11);
    uVar11 = 0x9f4e;
    uVar7 = unaff_DS;
    FUN_1cc0_08df(0x50,0x42c0,unaff_DS);
    FUN_1cc0_081a(uVar11,uVar7);
    uVar2 = FUN_1cc0_1c54(CONCAT11(extraout_AH_05,*(undefined1 *)0x42c1));
    *(undefined1 *)0x42c1 = uVar2;
    if (((*(byte *)0x42c0 < 4) || (uVar2 = *(char *)0x42c2 == ':', !(bool)uVar2)) ||
       (((FUN_1cc0_0d77(0x248,0x1cc0,*(undefined1 *)0x42c1), !(bool)uVar2 &&
         (uVar2 = 0, *(char *)0x42c1 == *(char *)0x4371)) ||
        (FUN_1cc0_0d77(0x268,0x1cc0,CONCAT11(extraout_AH_06,*(undefined1 *)0x42c1)), (bool)uVar2))))
    {
      FUN_1cc0_0adc(0x50,0x42c0,unaff_DS,0x431f,unaff_DS);
      uVar8 = 0xa04e;
      puVar9 = local_102;
      uVar7 = unaff_SS;
      uVar11 = unaff_DS;
      FUN_1cc0_0ac2(0x288,0x1cc0);
      FUN_1cc0_0b4f(0x42c0,unaff_DS);
      FUN_1cc0_0917(0,puVar9,uVar7);
      FUN_1cc0_0848(uVar8,uVar11);
      FUN_1bdc_029c(2000);
    }
    local_3 = *(char *)0x42c0;
    if (local_3 != '\0') {
      *(undefined1 *)0x42bf = 1;
      while( true ) {
        uVar2 = FUN_1cc0_1c54(*(undefined1 *)(*(byte *)0x42bf + 0x42c0));
        *(undefined1 *)(*(byte *)0x42bf + 0x42c0) = uVar2;
        if (*(char *)0x42bf == local_3) break;
        *(char *)0x42bf = *(char *)0x42bf + '\x01';
      }
    }
    if (*(char *)(*(byte *)0x42c0 + 0x42c0) != '\\') {
      puVar9 = local_102;
      FUN_1cc0_0ac2(0x42c0,unaff_DS);
      FUN_1cc0_0b4f(0x29d,0x1cc0);
      FUN_1cc0_0adc(0x50,0x42c0,unaff_DS,puVar9,unaff_SS);
    }
    uVar11 = 0x413e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x42c0,unaff_DS);
    FUN_1cc0_0848(uVar11,uVar7);
    uVar11 = 0x413e;
    uVar7 = unaff_DS;
    FUN_1cc0_08b5(0,CONCAT11(extraout_AH_07,0x46));
    FUN_1cc0_0848(uVar11,uVar7);
    FUN_1b6f_029d();
    *(undefined1 *)0x42bf = 0;
    while( true ) {
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_09ad(0,*(undefined2 *)((uint)*(byte *)0x42bf * 2 + -0x7280),0);
      FUN_1cc0_0848(uVar11,uVar7);
      uVar11 = 0x413e;
      uVar7 = unaff_DS;
      FUN_1cc0_09ad(0,*(undefined2 *)((uint)*(byte *)0x42bf * 2 + -0x7272),0);
      FUN_1cc0_0848(uVar11,uVar7);
      if (*(char *)0x42bf == '\x06') break;
      *(char *)0x42bf = *(char *)0x42bf + '\x01';
    }
    FUN_1cc0_05bf(0x413e,unaff_DS);
  }
  FUN_1bdc_01c0();
  uVar11 = 0xa04e;
  uVar7 = unaff_DS;
  FUN_1cc0_0917(0,0x2ea,0x1bdc);
  FUN_1cc0_0848(uVar11,uVar7);
  FUN_1bdc_029c(2000);
  FUN_1cc0_04f5(0x1059,unaff_DS,0x413e,unaff_DS);
  FUN_1cc0_0565(0x1cc0,0x413e);
  uVar11 = 0x413e;
  uVar7 = unaff_DS;
  uVar2 = FUN_1cc0_0896(0x413e);
  *(undefined1 *)0x413c = uVar2;
  FUN_1cc0_081a(uVar11,uVar7);
  *(undefined1 *)0x44ad = 0xf;
  iVar5 = extraout_DX;
  FUN_1c3e_000b(0x44ac);
  *(undefined1 *)0x44c6 = *(undefined1 *)0x44ac;
  *(undefined1 *)0x44c7 = *(undefined1 *)0x44c6;
  cVar1 = *(char *)0x413c;
  if (cVar1 == 'E') {
    *(undefined1 *)0x44c8 = 1;
    FUN_121a_00ad(CONCAT11(extraout_AH_08,0xd));
    *(undefined1 *)0x44c5 = 0;
    *(undefined1 *)0x44c4 = 0;
    FUN_1602_00f5(CONCAT11(extraout_AH_09,*(undefined1 *)0x44c5));
    FUN_1602_0124(CONCAT11(extraout_AH_10,*(undefined1 *)0x44c4));
    iVar5 = extraout_DX_00;
  }
  else if (cVar1 == 'T') {
    *(undefined1 *)0x44c8 = 2;
    iVar5 = *(int *)0x3db2;
    *(undefined2 *)0x4138 = *(undefined2 *)0x3db0;
    *(int *)0x413a = iVar5 + -0x400;
    uVar7 = *(undefined2 *)0x4138;
    uVar11 = *(undefined2 *)0x413a;
    *(undefined2 *)0x3db0 = uVar7;
    *(undefined2 *)0x3db2 = uVar11;
    FUN_121a_00ad(CONCAT11((char)((uint)uVar7 >> 8),9));
    iVar5 = extraout_DX_01;
  }
  else if (cVar1 == 'V') {
    *(undefined1 *)0x44c8 = 3;
    FUN_121a_00ad(CONCAT11(extraout_AH_08,0x13));
    iVar5 = extraout_DX_02;
  }
  uVar3 = FUN_1cc0_029c();
  iVar6 = iVar5;
  uVar4 = FUN_1c6a_01f2();
  iVar5 = (1 - iVar5) - (uint)(0xe000 < uVar4);
  if ((iVar5 < iVar6) || ((iVar5 <= iVar6 && (0xe000 - uVar4 <= uVar3)))) {
    FUN_1c6a_01a3(0xe000,1);
  }
  else {
    FUN_121a_00dd();
    uVar11 = 0xa04e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x316,0x121a);
    iVar5 = extraout_DX_03;
    uVar3 = FUN_1cc0_029c(uVar11);
    iVar6 = iVar5;
    uVar4 = FUN_1c6a_01f2(uVar3,iVar5);
    FUN_1cc0_09ad(0,(0xe000 - uVar4) - uVar3,
                  (((1 - iVar5) - (uint)(0xe000 < uVar4)) - iVar6) - (uint)(0xe000 - uVar4 < uVar3))
    ;
    FUN_1cc0_0917(0,0x340,0x1cc0);
    FUN_1cc0_0848(uVar11,uVar7);
    FUN_1cc0_00e9();
  }
  if (*(int *)0x3d84 != 0) {
    FUN_121a_00dd();
    uVar11 = 0xa04e;
    uVar7 = unaff_DS;
    FUN_1cc0_0917(0,0x34d,0x121a);
    FUN_1cc0_0848(uVar11,uVar7);
    FUN_1cc0_00e9();
  }
  uVar11 = 0x413e;
  uVar7 = unaff_DS;
  uVar2 = FUN_1cc0_0896(0x413e);
  *(undefined1 *)0x413c = uVar2;
  FUN_1cc0_081a(uVar11,uVar7);
  cVar1 = *(char *)0x413c;
  if (cVar1 == 'P') {
    *(undefined1 *)0x50cc = 1;
  }
  else if (cVar1 == 'S') {
    *(undefined1 *)0x50cc = 2;
  }
  else if (cVar1 == 'A') {
    *(undefined1 *)0x50cc = 3;
  }
  else if (cVar1 == 'R') {
    *(undefined1 *)0x50cc = 4;
  }
  else if (cVar1 == 'T') {
    *(undefined1 *)0x50cc = 5;
  }
  else if (cVar1 == 'Q') {
    *(undefined1 *)0x50cc = 0;
  }
  else {
    *(undefined1 *)0x50cc = 0;
  }
  uVar11 = 0x413e;
  uVar7 = unaff_DS;
  uVar2 = FUN_1cc0_0896(0x413e);
  *(undefined1 *)0x413c = uVar2;
  FUN_1cc0_081a(uVar11,uVar7);
  cVar1 = *(char *)0x413c;
  if (cVar1 == 'J') {
    *(undefined1 *)0x8db8 = 1;
    *(undefined1 *)0x8d70 = 0;
  }
  else if (cVar1 == 'M') {
    *(undefined1 *)0x8d70 = 1;
    *(undefined1 *)0x8db8 = 0;
  }
  else if (cVar1 == 'N') {
    *(undefined1 *)0x8d70 = 0;
    *(undefined1 *)0x8db8 = 0;
  }
  uVar11 = 0x413e;
  uVar7 = unaff_DS;
  FUN_1cc0_08df(0xff,0x50d4,unaff_DS);
  FUN_1cc0_081a(uVar11,uVar7);
  uVar11 = 0x413e;
  uVar7 = unaff_DS;
  FUN_1cc0_08df(0xff,0x51d4,unaff_DS);
  FUN_1cc0_081a(uVar11,uVar7);
  uVar11 = 0x413e;
  uVar7 = unaff_DS;
  uVar2 = FUN_1cc0_0896(0x413e);
  *(undefined1 *)0x413c = uVar2;
  FUN_1cc0_081a(uVar11,uVar7);
  if (*(char *)0x413c == 'F') {
    *(undefined1 *)0x4416 = 1;
  }
  else {
    *(undefined1 *)0x4416 = 0;
  }
  FUN_1b6f_0000();
  if (*(char *)0x8db8 != '\0') {
    *(undefined1 *)0x42bf = 0;
    while( true ) {
      uVar8 = 0x413e;
      uVar7 = unaff_DS;
      uVar11 = FUN_1cc0_0955(0x413e);
      *(undefined2 *)((uint)*(byte *)0x42bf * 2 + -0x7280) = uVar11;
      FUN_1cc0_081a(uVar8,uVar7);
      uVar8 = 0x413e;
      uVar7 = unaff_DS;
      uVar11 = FUN_1cc0_0955(0x413e);
      *(undefined2 *)((uint)*(byte *)0x42bf * 2 + -0x7272) = uVar11;
      FUN_1cc0_081a(uVar8,uVar7);
      if (*(char *)0x42bf == '\x06') break;
      *(char *)0x42bf = *(char *)0x42bf + '\x01';
    }
  }
  FUN_1cc0_05bf(0x413e,unaff_DS);
  return;
}


