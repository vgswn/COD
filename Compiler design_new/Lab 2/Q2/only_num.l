%{
	#include "mynumber.h"
%}

digit [0-9]
exp ([E|e][\+\-]?{digit}+)?
frac ([\.]{digit}*)?
num [1-9]{digit}*{frac}{exp}
%%

{num}  { return UNSIGNED; }
[\+\-]{num} {return SIGNED; }
[\n]      {yylineno++; return OTHER;}
.    {return OTHER; }

%%

int yywrap()
{
	return 1;
}