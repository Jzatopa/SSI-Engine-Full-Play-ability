
char __stdcall16far FUN_121a_0dbc(byte param_1)

{
  return (param_1 * -0x80 + (param_1 & 2) * ' ' + (param_1 & 4) * '\b' + (param_1 & 8) * '\x02' +
          ((param_1 & 0x10) >> 1) + ((param_1 & 0x20) >> 3) + ((param_1 & 0x40) >> 5)) -
         ((char)param_1 >> 7);
}


