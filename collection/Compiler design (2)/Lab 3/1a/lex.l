%{
	#include "myscanner.h"
%}

type ("int"|"char"|"float"|"double")
letter_ [a-zA-Z_]
digit [0-9]
id {letter_}({letter_}|{digit})*[^{type}]
opid ({id}[,][ ]*)*
vardec {type}[ ]+{opid}{id}[;]



%%

{vardec}	return VALID;
[ \n\t] ;
. ;

%%
int yywrap(void)
{
	return 1;
}

