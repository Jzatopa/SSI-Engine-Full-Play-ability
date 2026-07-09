
undefined2 __stdcall16far FUN_1836_0405(undefined2 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  uVar2 = 0x1836;
  while( true ) {
    iVar1 = (*(code *)*(undefined2 *)0x8c49)(uVar2,param_1);
    if (iVar1 == 0) break;
    FUN_1bdc_02c7(4000);
    FUN_1bdc_029c(0x14);
    uVar2 = 0x1bdc;
    FUN_1bdc_02f4();
  }
  return 0;
}


