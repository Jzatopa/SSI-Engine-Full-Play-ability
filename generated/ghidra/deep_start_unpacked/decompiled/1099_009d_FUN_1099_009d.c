
void FUN_1099_009d(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x3f);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x3f);
  (*pcVar1)();
  return;
}


