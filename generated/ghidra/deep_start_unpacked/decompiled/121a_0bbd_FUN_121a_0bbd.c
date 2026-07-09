
void __stdcall16far
FUN_121a_0bbd(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined1 param_4,
             undefined1 param_5,undefined2 param_6,undefined2 param_7)

{
  char cVar1;
  bool bVar2;
  undefined2 in_AX;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 unaff_DS;
  
  uVar3 = CONCAT11((char)((uint)in_AX >> 8),param_4) & 0xff01;
  iVar6 = (int)param_3;
  uVar7 = (undefined2)((ulong)param_3 >> 0x10);
  if (((char)uVar3 == '\0') ||
     ((uVar4 = *(uint *)(iVar6 + 0x17) | *(uint *)(iVar6 + 0x19), uVar4 == 0 &&
      (uVar3 = 0, *(char *)0x44c8 != '\x03')))) {
    uVar5 = (undefined1)(uVar3 >> 8);
    bVar2 = false;
  }
  else {
    uVar5 = (undefined1)(uVar4 >> 8);
    bVar2 = true;
  }
  cVar1 = *(char *)0x44c8;
  if (cVar1 == '\0') {
    if (bVar2) {
      FUN_121a_306f(param_1,param_2,iVar6,uVar7,CONCAT11(uVar5,param_5),param_6,param_7);
    }
    else {
      FUN_121a_2fe8(param_1,param_2,iVar6,uVar7,CONCAT11(uVar5,param_5),param_6,param_7);
    }
  }
  else if (cVar1 == '\x01') {
    if (bVar2) {
      FUN_121a_32f7(param_1,param_2,iVar6,uVar7,CONCAT11(uVar5,param_5),param_6,param_7);
    }
    else {
      FUN_121a_3268(param_1,param_2,iVar6,uVar7,CONCAT11(uVar5,param_5),param_6,param_7);
    }
  }
  else if (cVar1 == '\x02') {
    if (bVar2) {
      FUN_121a_35a4(param_1,param_2,iVar6,uVar7,CONCAT11(uVar5,param_5),param_6,param_7);
    }
    else {
      FUN_121a_350f(param_1,param_2,iVar6,uVar7,CONCAT11(uVar5,param_5),param_6,param_7);
    }
  }
  else if (cVar1 == '\x03') {
    if (bVar2) {
      FUN_121a_3953(param_1,param_2,iVar6,uVar7,CONCAT11(uVar5,param_5),
                    CONCAT11(uVar5,*(undefined1 *)(iVar6 + 0x16)),param_6,param_7);
    }
    else {
      FUN_121a_38b0(param_1,param_2,iVar6,uVar7,CONCAT11(uVar5,param_5),param_6,param_7);
    }
  }
  return;
}


