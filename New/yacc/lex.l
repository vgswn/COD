%{
#include "y.tab.h"
%}
%%
"i" {return id;};
"+" {return yytext[0];};
[\n] {return 0;};
.   {yyerror();};
%%
int yywrap()
{
  return 1;
}
