
int __stdcall16far FUN_121a_0e41(uint param_1)

{
  undefined2 unaff_DS;
  
  return (param_1 & *(uint *)0x22e9) * 0x4000 + (param_1 & *(uint *)0x22e7) * 0x400 +
         (param_1 & *(uint *)0x22e5) * 0x40 + (param_1 & *(uint *)0x22e3) * 4 +
         ((param_1 & *(uint *)0x22e1) >> 2) + ((param_1 & *(uint *)0x22df) >> 6) +
         ((param_1 & *(uint *)0x22dd) >> 10) + ((param_1 & *(uint *)0x22db) >> 0xe);
}


