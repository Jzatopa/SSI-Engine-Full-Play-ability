/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:1817
 * Ghidra name: FUN_121a_1817
 * Linear address: 0x139B7
 * Body addresses: 921
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_121a_1817(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined2 unaff_DS;
  undefined1 *local_8;
  uint local_6;
  int local_4;
  
  FUN_1b58_0051();
  cVar1 = *(char *)0x44c8;
  if (cVar1 == '\0') {
    local_4 = 0;
    while( true ) {
      if (*(char *)(local_4 + 0x44e2) != '\0') {
        FUN_1cc0_1aaf((*(int *)(local_4 * 2 + 0x482a) - *(int *)(local_4 * 2 + 0x46da)) + 1,
                      *(int *)(local_4 * 2 + 0x458a) + 2,*(undefined2 *)((local_4 + 8) * 2 + 0x4c1a)
                      ,(int)*(undefined4 *)0x44ca + *(int *)(local_4 * 2 + 0x46da) + 0x1b,
                      (int)((ulong)*(undefined4 *)0x44ca >> 0x10));
      }
      if (local_4 == 0xa7) break;
      local_4 = local_4 + 1;
    }
  }
  else if (cVar1 == '\x01') {
    out(0x3c4,2);
    local_4 = 0;
    while( true ) {
      if (*(char *)(local_4 + 0x44e2) != '\0') {
        puVar4 = (undefined1 *)
                 (*(int *)((local_4 + 8) * 2 + 0x4daa) + *(int *)(local_4 * 2 + 0x458a) + 1);
        out(0x3c5,*(undefined1 *)0x22ec);
        local_6 = *(uint *)(local_4 * 2 + 0x46da);
        local_8 = puVar4;
        do {
          *local_8 = *(undefined1 *)((int)*(undefined4 *)0x44ca + local_6 + 0x1b);
          local_6 = local_6 + 4;
          local_8 = local_8 + 1;
        } while (local_6 <= *(uint *)(local_4 * 2 + 0x482a));
        out(0x3c5,*(undefined1 *)0x22ed);
        local_6 = *(int *)(local_4 * 2 + 0x46da) + 1;
        local_8 = puVar4;
        do {
          *local_8 = *(undefined1 *)((int)*(undefined4 *)0x44ca + local_6 + 0x1b);
          local_6 = local_6 + 4;
          local_8 = local_8 + 1;
        } while (local_6 <= *(uint *)(local_4 * 2 + 0x482a));
        out(0x3c5,*(undefined1 *)0x22ee);
        local_6 = *(int *)(local_4 * 2 + 0x46da) + 2;
        local_8 = puVar4;
        do {
          *local_8 = *(undefined1 *)((int)*(undefined4 *)0x44ca + local_6 + 0x1b);
          local_6 = local_6 + 4;
          local_8 = local_8 + 1;
        } while (local_6 <= *(uint *)(local_4 * 2 + 0x482a));
        out(0x3c5,*(undefined1 *)0x22ef);
        local_6 = *(int *)(local_4 * 2 + 0x46da) + 3;
        local_8 = puVar4;
        do {
          *local_8 = *(undefined1 *)((int)*(undefined4 *)0x44ca + local_6 + 0x1b);
          local_6 = local_6 + 4;
          local_8 = local_8 + 1;
        } while (local_6 <= *(uint *)(local_4 * 2 + 0x482a));
      }
      if (local_4 == 0xa7) break;
      local_4 = local_4 + 1;
    }
    out(0x3c5,0xf);
    local_8 = (undefined1 *)(*(int *)0x4dba + 1);
    out(0x3ce,5);
    out(0x3cf,1);
    local_4 = 0;
    while( true ) {
      if (*(char *)(local_4 + 0x44e2) != '\0') {
        FUN_1cc0_1aaf(((uint)(*(int *)(local_4 * 2 + 0x482a) - *(int *)(local_4 * 2 + 0x46da)) >> 2)
                      + 1,(int)local_8 + *(int *)(local_4 * 2 + 0x458a),0xa000,
                      (int)local_8 + *(int *)(local_4 * 2 + 0x458a),0xa200);
      }
      local_8 = (undefined1 *)((int)local_8 + 0x28);
      if (local_4 == 0xa7) break;
      local_4 = local_4 + 1;
    }
    out(0x3cf,0);
  }
  else if (cVar1 == '\x02') {
    local_4 = 0;
    while( true ) {
      if (*(char *)(local_4 + 0x44e2) != '\0') {
        FUN_1cc0_1aaf((*(int *)(local_4 * 2 + 0x482a) - *(int *)(local_4 * 2 + 0x46da)) + 1,
                      *(int *)(local_4 * 2 + 0x458a) + 4,*(undefined2 *)((local_4 + 8) * 2 + 0x4f3a)
                      ,(int)*(undefined4 *)0x44ca + *(int *)(local_4 * 2 + 0x46da) + 0x1b,
                      (int)((ulong)*(undefined4 *)0x44ca >> 0x10));
      }
      if (local_4 == 0xa7) break;
      local_4 = local_4 + 1;
    }
  }
  else if (cVar1 == '\x03') {
    local_4 = 0;
    while( true ) {
      if (*(char *)(local_4 + 0x44e2) != '\0') {
        uVar2 = *(uint *)(local_4 * 2 + 0x458a);
        uVar3 = (local_4 + 8) * 0x140;
        uVar5 = uVar3 + uVar2;
        FUN_1cc0_1aaf((*(int *)(local_4 * 2 + 0x482a) - *(int *)(local_4 * 2 + 0x46da)) + 1,
                      uVar5 + 8,CARRY2(uVar3,uVar2) + 0xa000 + (uint)(0xfff7 < uVar5),
                      (int)*(undefined4 *)0x44ca + *(int *)(local_4 * 2 + 0x46da) + 0x1b,
                      (int)((ulong)*(undefined4 *)0x44ca >> 0x10));
      }
      if (local_4 == 0xa7) break;
      local_4 = local_4 + 1;
    }
  }
  FUN_1cc0_1ad2(0,0xa8,0x44e2,unaff_DS);
  FUN_1cc0_1ad2(0x1ff,0x150,0x46da,unaff_DS);
  FUN_1cc0_1ad2(0x100,0x150,0x482a,unaff_DS);
  FUN_1b58_0030();
  return;
}


