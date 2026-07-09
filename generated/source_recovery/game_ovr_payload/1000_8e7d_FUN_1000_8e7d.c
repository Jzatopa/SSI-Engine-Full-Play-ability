/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:8e7d
 * Ghidra name: FUN_1000_8e7d
 * Linear address: 0x18E7D
 * Original GAME.OVR file offset: 102021
 * Body addresses: 151
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - character_creation (character_creation), next candidate, distance 2512 byte(s), source offset 99509
 */

void __stdcall16far FUN_1000_8e7d(int param_1)

{
  char cVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte local_3;
  
  if ((((undefined *)&DAT_0000_ffcc)[param_1] == '\a') && (1 < *(byte *)*(undefined4 *)0x57fb)) {
    if (*(char *)(param_1 + -0x3d) == *(char *)*(undefined4 *)0x57fb) {
      *(char *)*(undefined4 *)0x57fb = *(char *)*(undefined4 *)0x57fb + -1;
      *(undefined1 *)(param_1 + -0x3d) = *(undefined1 *)*(undefined4 *)0x57fb;
    }
    else {
      cVar1 = *(char *)*(undefined4 *)0x57fb;
      local_3 = *(byte *)(param_1 + -0x3d);
      if (local_3 <= (byte)(cVar1 - 1U)) {
        for (; *(undefined1 *)((int)*(undefined4 *)0x57fb + (uint)local_3) =
                    *(undefined1 *)((int)*(undefined4 *)0x57fb + local_3 + 1),
            local_3 != (byte)(cVar1 - 1U); local_3 = local_3 + 1) {
        }
      }
      *(char *)*(undefined4 *)0x57fb = *(char *)*(undefined4 *)0x57fb + -1;
    }
  }
  return;
}


