
void __cdecl16far FUN_1000_6712(void)

{
  undefined1 extraout_AH;
  undefined2 unaff_DS;
  char local_5;
  char local_4;
  
  func_0x0000b5d1();
  func_0x0000077a(0xb58);
  *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xf0) =
       *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xc3);
  *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xf1) =
       *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xc4);
  local_4 = *(char *)((int)*(undefined4 *)0x4418 + 0xc3) +
            ((undefined *)&DAT_0000_26ca)[*(byte *)0x736b];
  local_5 = *(char *)((int)*(undefined4 *)0x4418 + 0xc4) +
            ((undefined *)&DAT_0000_26d3)[*(byte *)0x736b];
  if (local_4 < '\0') {
    local_4 = '\0';
  }
  if ('%' < local_4) {
    local_4 = '%';
  }
  if (local_5 < '\0') {
    local_5 = '\0';
  }
  if ('\x0e' < local_5) {
    local_5 = '\x0e';
  }
  *(char *)((int)*(undefined4 *)0x4418 + 0xc3) = local_4;
  *(char *)((int)*(undefined4 *)0x4418 + 0xc4) = local_5;
  FUN_0000_0775(0x75);
  FUN_0000_b5b0(0x75);
  FUN_0000_08c5(0xb58,CONCAT11(extraout_AH,3),CONCAT11(extraout_AH,0xc));
  return;
}


