%{
    #include "y.tab.h"
%}

%%

[0-9]+ {return num;};

"id" {return id;};
[ \t] {;};
[\n] {return 0;};
[\+\*\(\)] {return yytext[0];};
.   {yyerror();};
%%

int yywrap()
{
    return 1;
}