
void __stdcall16far FUN_2000_cfc8(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (((*(char *)(param_1 + -0x212) == '\0') && ((int)*(char *)0x7477 <= *(int *)(param_1 + -0x20e))
      ) && (*(int *)(param_1 + -0x20e) <= (int)*(char *)0x7478)) {
    *(undefined1 *)(param_1 + -0x211) = 1;
    while ((*(byte *)(param_1 + -0x211) < 0x1a && (*(char *)(param_1 + -0x212) == '\0'))) {
      if (((int)(uint)(byte)((undefined *)&DAT_0000_745d)[*(byte *)(param_1 + -0x211)] <=
           *(int *)(param_1 + -0x210)) &&
         (((undefined *)&DAT_0000_745d)[*(byte *)(param_1 + -0x211)] != -1)) {
        *(undefined1 *)(param_1 + -0x212) = 1;
        *(undefined1 *)0x7483 =
             *(undefined1 *)
              (param_1 + (uint)*(byte *)(param_1 + (uint)*(byte *)0x7457 * 2 + -0x23e) + -0x200);
      }
      *(char *)(param_1 + -0x211) = *(char *)(param_1 + -0x211) + '\x01';
    }
  }
  return;
}


