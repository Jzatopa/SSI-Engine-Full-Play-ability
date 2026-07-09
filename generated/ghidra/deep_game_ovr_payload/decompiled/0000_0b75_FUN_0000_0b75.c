
void FUN_0000_0b75(void)

{
  char in_CH;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  bool in_SF;
  
  if (in_SF) {
    func_0x0000d6dc();
    return;
  }
  *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) + in_CH;
  return;
}


