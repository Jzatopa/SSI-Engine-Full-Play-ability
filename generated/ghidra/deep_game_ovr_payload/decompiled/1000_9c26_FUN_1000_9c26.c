
void __cdecl16far FUN_1000_9c26(void)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  uVar3 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
  iVar1 = (int)*(undefined4 *)0x57fb;
  if (*(char *)(iVar1 + 0x27) == '\x05') {
    *(undefined1 *)(iVar1 + 0xb8) = 0x11;
  }
  else if (*(char *)(iVar1 + 0x27) == '\x06') {
    cVar2 = FUN_0000_09ba();
    if (cVar2 == '\x01') {
      *(undefined1 *)(iVar1 + 0xb8) = 0x10;
    }
    else if (cVar2 == '\x02') {
      *(undefined1 *)(iVar1 + 0xb8) = 0x17;
    }
    else if (cVar2 == '\x03') {
      *(undefined1 *)(iVar1 + 0xb8) = 0x18;
    }
    else if (cVar2 == '\x04') {
      *(undefined1 *)(iVar1 + 0xb8) = 0x1f;
    }
  }
  else {
    *(undefined1 *)(iVar1 + 0xb8) =
         *(undefined1 *)(*(char *)(iVar1 + 0x26) * 5 + (int)*(char *)(iVar1 + 0x28) + 0xd77);
  }
  return;
}


