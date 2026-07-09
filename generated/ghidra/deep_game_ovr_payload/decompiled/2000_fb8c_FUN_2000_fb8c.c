
void __cdecl16far FUN_2000_fb8c(void)

{
  undefined2 unaff_DS;
  
  func_0x000045b0();
  func_0x000045b0(0x21a,*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,0x2300);
  func_0x000045b0(0x21a,*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,0x2300);
  if ((*(byte *)0x736d & 0x80) == 0) {
    if (*(int *)0x8dc2 != 0 || *(int *)0x8dc4 != 0) {
      FUN_0000_2e9a(*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,*(undefined2 *)0x8dc2,
                    *(undefined2 *)0x8dc4,0,0,2,2);
    }
  }
  else if (*(int *)0x8dbe != 0 || *(int *)0x8dc0 != 0) {
    FUN_0000_2e9a(*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,*(undefined2 *)0x8dbe,
                  *(undefined2 *)0x8dc0,0,0,2,2);
  }
  return;
}


