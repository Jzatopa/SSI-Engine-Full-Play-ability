
void FUN_0000_b25b(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined4 in_stack_0000000c;
  undefined1 local_204 [258];
  undefined1 local_102 [256];
  
  uVar2 = 0x18;
  func_0x00001140();
  local_102[0] = 0;
  uVar1 = *(undefined4 *)((int)in_stack_0000000c + 0xf3);
  if (*(char *)((int)uVar1 + 3) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(local_102,unaff_SS,local_204,unaff_SS,uVar2);
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(local_102,unaff_SS,local_204,unaff_SS,uVar2);
}


