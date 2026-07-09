/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:006f
 * Ghidra name: FUN_3000_006f
 * Linear address: 0x3006F
 * Original GAME.OVR file offset: 196727
 * Body addresses: 1976
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - wall_loader_wall_def_1 (wall_loader), previous candidate, distance 2118 byte(s), source offset 198845
 *   - wall_loader_wall_def_2 (wall_loader), previous candidate, distance 2153 byte(s), source offset 198880
 *   - load3dmap_geo (map_loader), previous candidate, distance 2607 byte(s), source offset 199334
 *   - load3dmap_error (map_loader), previous candidate, distance 2638 byte(s), source offset 199365
 */

void __stdcall16far FUN_3000_006f(void)

{
  char cVar1;
  char cVar2;
  undefined2 unaff_DS;
  char local_19;
  char local_15;
  byte local_12;
  
  if (*"ls\x15 at sensor operation!\x0eShip Character\x01" == '\0') {
    func_0x0003fb8c();
    local_15 = '\x02';
    do {
      if (local_15 == '\x02') {
        local_19 = '\0';
        for (local_12 = 0; local_12 < 4; local_12 = local_12 + 1) {
          cVar2 = func_0x0003fef1();
          cVar1 = func_0x0003fd91();
          if ((cVar1 == '\0') && (cVar1 = func_0x0003fef1(), cVar1 == '\0')) {
            local_19 = '\0';
          }
          if (cVar2 == '\0') {
            if ((local_19 != '\0') && (cVar2 = func_0x0003fef1(), cVar2 != '\0')) {
              func_0x0003fc83();
            }
            local_19 = '\0';
          }
          else {
            if (local_19 != '\0') {
              func_0x0003fc83();
            }
            func_0x0003fc83();
            local_19 = cVar2;
          }
        }
        local_19 = '\0';
        for (local_12 = 0; local_12 < 4; local_12 = local_12 + 1) {
          cVar2 = func_0x0003fef1();
          cVar1 = func_0x0003fd91();
          if ((cVar1 == '\0') && (cVar1 = func_0x0003fef1(), cVar1 == '\0')) {
            local_19 = '\0';
          }
          if (cVar2 == '\0') {
            if ((local_19 != '\0') && (cVar2 = func_0x0003fef1(), cVar2 != '\0')) {
              func_0x0003fc83();
            }
            local_19 = '\0';
          }
          else {
            if (local_19 != '\0') {
              func_0x0003fc83();
            }
            func_0x0003fc83();
            local_19 = cVar2;
          }
        }
        for (local_12 = 0; local_12 < 3; local_12 = local_12 + 1) {
          cVar2 = func_0x0003fef1();
          if (cVar2 != '\0') {
            if (local_12 == 0) {
              func_0x0003fc83();
            }
            else {
              func_0x0003fc83();
            }
          }
        }
        for (local_12 = 0; local_12 < 3; local_12 = local_12 + 1) {
          cVar2 = func_0x0003fef1();
          if (cVar2 != '\0') {
            if (local_12 == 0) {
              func_0x0003fc83();
            }
            else {
              func_0x0003fc83();
            }
          }
        }
      }
      else if (local_15 == '\x01') {
        for (local_12 = 0; local_12 < 3; local_12 = local_12 + 1) {
          cVar2 = func_0x0003fef1();
          if (cVar2 != '\0') {
            func_0x0003fc83();
          }
          cVar2 = func_0x0003fef1();
          if (cVar2 != '\0') {
            func_0x0003fc83();
          }
        }
        for (local_12 = 0; local_12 < 3; local_12 = local_12 + 1) {
          cVar2 = func_0x0003fef1();
          if (cVar2 != '\0') {
            func_0x0003fc83();
          }
          cVar2 = func_0x0003fef1();
          if (cVar2 != '\0') {
            func_0x0003fc83();
          }
        }
      }
      else if (local_15 == '\0') {
        for (local_12 = 0; local_12 < 2; local_12 = local_12 + 1) {
          cVar2 = func_0x0003fef1();
          if (cVar2 != '\0') {
            func_0x0003fc83();
          }
          cVar2 = func_0x0003fef1();
          if (cVar2 != '\0') {
            func_0x0003fc83();
          }
        }
        for (local_12 = 0; local_12 < 2; local_12 = local_12 + 1) {
          cVar2 = func_0x0003fef1();
          if (cVar2 != '\0') {
            func_0x0003fc83();
          }
          cVar2 = func_0x0003fef1();
          if (cVar2 != '\0') {
            func_0x0003fc83();
          }
        }
      }
      local_15 = local_15 + -1;
    } while (local_15 != -1);
    FUN_0000_39b7();
  }
  else {
    func_0x0003fa17();
  }
  return;
}


