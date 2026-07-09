
void __cdecl16far FUN_1000_e9c9(void)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_DS;
  
  cVar1 = *" at sensor operation!\x0eShip Character\x01";
  if (cVar1 == '\0') {
    if (*"\x15 at sensor operation!\x0eShip Character\x01" < '\x01') {
      *(undefined1 *)0x736a = 0xf;
    }
    else {
      *"\x15 at sensor operation!\x0eShip Character\x01" =
           *"\x15 at sensor operation!\x0eShip Character\x01" + -1;
    }
  }
  else if (cVar1 == '\x02') {
    if (*"s\x15 at sensor operation!\x0eShip Character\x01" < '\x0f') {
      *"s\x15 at sensor operation!\x0eShip Character\x01" =
           *"s\x15 at sensor operation!\x0eShip Character\x01" + '\x01';
    }
    else {
      *(undefined1 *)0x7369 = 0;
    }
  }
  else if (cVar1 == '\x04') {
    if (*"\x15 at sensor operation!\x0eShip Character\x01" < '\x0f') {
      *"\x15 at sensor operation!\x0eShip Character\x01" =
           *"\x15 at sensor operation!\x0eShip Character\x01" + '\x01';
    }
    else {
      *(undefined1 *)0x736a = 0;
    }
  }
  else if (cVar1 == '\x06') {
    if (*"s\x15 at sensor operation!\x0eShip Character\x01" < '\x01') {
      *(undefined1 *)0x7369 = 0xf;
    }
    else {
      *"s\x15 at sensor operation!\x0eShip Character\x01" =
           *"s\x15 at sensor operation!\x0eShip Character\x01" + -1;
    }
  }
  uVar3 = (uint)*(byte *)0x7369;
  uVar4 = (uint)*(byte *)0x736a;
  uVar2 = func_0x00000d44();
  *(undefined1 *)0x736d = uVar2;
  uVar2 = FUN_0000_0d3a(0xd1,*(undefined1 *)0x736b,*(undefined1 *)0x736a,*(undefined1 *)0x7369,uVar4
                        ,uVar3);
  *(undefined1 *)0x736c = uVar2;
  *(undefined1 *)0x8c38 = 1;
  return;
}


