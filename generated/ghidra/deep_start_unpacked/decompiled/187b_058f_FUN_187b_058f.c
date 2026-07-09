
void __stdcall16far FUN_187b_058f(byte param_1)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined2 uVar6;
  undefined1 local_300 [256];
  undefined1 local_200 [256];
  undefined1 local_100 [33];
  undefined1 local_df [128];
  undefined4 local_5f;
  undefined2 local_5b;
  undefined2 local_59;
  uint local_57;
  undefined1 local_55 [81];
  char local_4;
  char local_3;
  
  local_4 = 0;
  if (*(char *)0x50cc != '\0') {
    if (*(char *)0x50d0 == '\x02') {
      local_4 = '\x01';
    }
    else {
      *(undefined1 *)0x50cf = *(undefined1 *)0x50d0;
      local_4 = FUN_187b_049f(*(char *)0x50cc * 0x100 + 0x3783,unaff_DS);
      if (local_4 != '\0') {
        *(undefined1 *)0x50d0 = 2;
      }
    }
    if (local_4 != '\0') {
      local_57 = 0;
      while( true ) {
        if (*(int *)(local_57 * 4 + -0x60f8) != 0 || *(int *)(local_57 * 4 + -0x60f6) != 0) {
          FUN_1cc0_0254(*(undefined2 *)0x9f2c,*(undefined2 *)(local_57 * 4 + -0x60f8),
                        *(undefined2 *)(local_57 * 4 + -0x60f6));
          *(undefined2 *)(local_57 * 4 + -0x60f8) = 0;
          *(undefined2 *)(local_57 * 4 + -0x60f6) = 0;
        }
        if (local_57 == 8) break;
        local_57 = local_57 + 1;
      }
      uVar2 = FUN_187b_15bb(*(undefined2 *)0x9eea);
      *(undefined2 *)0x9f2c = uVar2;
      *(undefined2 *)0x9f2e = 0;
      puVar5 = local_200;
      uVar2 = unaff_SS;
      FUN_1cc0_0ac2(*(char *)0x50cc * 9 + 0x384d,unaff_DS);
      FUN_1cc0_0b4f(0x583,0x1cc0);
      cVar1 = FUN_187b_0361(puVar5,uVar2);
      if (cVar1 == '\0') {
        FUN_187b_02c3();
      }
      else {
        FUN_1cc0_1aaf(4,local_55,unaff_SS,(int)*(undefined4 *)0x9eec + 4,
                      (int)((ulong)*(undefined4 *)0x9eec >> 0x10));
        puVar5 = local_300;
        uVar6 = unaff_SS;
        FUN_1cc0_0ac2(0x588,0x1cc0);
        puVar4 = local_200;
        uVar2 = unaff_SS;
        FUN_187b_040f(local_55,unaff_SS);
        FUN_1cc0_0b4f(puVar4,uVar2);
        FUN_1cc0_0adc(0x20,local_100,unaff_SS,puVar5,uVar6);
        if (*(int *)0x9ef2 != 0 || *(int *)0x9ef4 != 0) {
          FUN_1cc0_0254(*(undefined2 *)0x9ef0,*(undefined2 *)0x9ef2,*(undefined2 *)0x9ef4);
          *(undefined2 *)0x9ef2 = 0;
          *(undefined2 *)0x9ef4 = 0;
        }
        uVar2 = FUN_187b_15cc(*(undefined2 *)0x9eea);
        *(undefined2 *)0x9ef0 = uVar2;
        if (*(int *)0x9ef0 != 0) {
          uVar3 = FUN_1cc0_023f(*(undefined2 *)0x9ef0);
          *(undefined2 *)0x9ef2 = (int)uVar3;
          *(undefined2 *)0x9ef4 = (int)((ulong)uVar3 >> 0x10);
          FUN_187b_15dd(*(undefined2 *)0x9ef0,*(undefined2 *)0x9ef2,*(undefined2 *)0x9ef4,
                        *(undefined2 *)0x9eea);
        }
        local_57 = 0;
        local_3 = '\0';
        while ((local_57 < 8 && (local_3 == '\0'))) {
          uVar3 = FUN_1cc0_023f(*(undefined2 *)0x9f2c);
          *(undefined2 *)(local_57 * 4 + -0x60f8) = (int)uVar3;
          *(undefined2 *)(local_57 * 4 + -0x60f6) = (int)((ulong)uVar3 >> 0x10);
          uVar2 = FUN_187b_15f7(0,0,*(undefined2 *)(local_57 * 4 + -0x60f8),
                                *(undefined2 *)(local_57 * 4 + -0x60f6),local_57,
                                *(undefined2 *)0x9ee2,*(undefined2 *)0x9ee4,*(undefined2 *)0x9eea);
          *(undefined2 *)(local_57 * 2 + -0x610a) = uVar2;
          if (*(int *)(local_57 * 2 + -0x610a) == -1) {
            FUN_1cc0_0254(*(undefined2 *)0x9f2c,*(undefined2 *)(local_57 * 4 + -0x60f8),
                          *(undefined2 *)(local_57 * 4 + -0x60f6));
            *(undefined2 *)(local_57 * 4 + -0x60f8) = 0;
            *(undefined2 *)(local_57 * 4 + -0x60f6) = 0;
            local_3 = '\x01';
          }
          if (local_3 == '\0') {
            local_59 = FUN_187b_161d(*(undefined2 *)(local_57 * 2 + -0x610a),*(undefined2 *)0x9eea);
            FUN_1cc0_1aaf(2,&local_5b,unaff_SS,&local_59,unaff_SS);
            while (local_5b._1_1_ != -1) {
              local_5f = (undefined2 *)FUN_187b_0000(local_5b,local_100,unaff_SS,local_df,unaff_SS);
              if (local_5f == (undefined2 *)0x0) {
                FUN_187b_02c3();
                return;
              }
              FUN_187b_1631(local_5f,local_5b & 0xff,local_5b >> 8,*(undefined2 *)0x9eea);
              FUN_1cc0_0254(*local_5f,(undefined2 *)local_5f,local_5f._2_2_);
              local_59 = FUN_187b_161d(*(undefined2 *)(local_57 * 2 + -0x610a),*(undefined2 *)0x9eea
                                      );
              FUN_1cc0_1aaf(2,&local_5b,unaff_SS,&local_59,unaff_SS);
            }
            local_57 = local_57 + 1;
          }
        }
        *(uint *)0x9ee8 = (uint)param_1;
        FUN_187b_164e(*(undefined2 *)(*(int *)0x9ee8 * 2 + -0x610a),*(undefined2 *)0x9eea);
      }
    }
  }
  return;
}


