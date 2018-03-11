%{
  #include "header.h"
%}
%%
[+-]*[0-9]* return integer;
[+-]*[0-9]*[.]*[0-9]+ return float;
%%
int yywrap(void)
{
  return 1;
}
