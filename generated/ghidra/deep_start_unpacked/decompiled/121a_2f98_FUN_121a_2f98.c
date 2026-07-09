
void __stdcall16far FUN_121a_2f98(undefined1 param_1)

{
  undefined2 in_AX;
  byte bVar1;
  byte extraout_AH;
  undefined1 extraout_AH_00;
  byte extraout_AH_01;
  
  bVar1 = (byte)((uint)in_AX >> 8);
  FUN_121a_2dea((uint)bVar1 << 8,(uint)bVar1 << 8,(uint)bVar1 << 8,CONCAT11(bVar1,param_1));
  FUN_121a_2dea(CONCAT11(extraout_AH,1),CONCAT11(extraout_AH,1),(uint)extraout_AH << 8,
                CONCAT11(extraout_AH,param_1));
  FUN_121a_2dea(CONCAT11(extraout_AH_00,1),CONCAT11(extraout_AH_00,2),CONCAT11(extraout_AH_00,1),
                CONCAT11(extraout_AH_00,param_1));
  FUN_121a_2dea((uint)extraout_AH_01 << 8,CONCAT11(extraout_AH_01,3),CONCAT11(extraout_AH_01,1),
                CONCAT11(extraout_AH_01,param_1));
  return;
}


