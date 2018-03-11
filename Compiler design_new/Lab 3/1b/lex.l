%{
	#include "myscanner.h"
%}

letter_ [a-zA-Z_]
digit [0-9]
intver ("short int"|"long int"|"int")
realtype ("float"|"double"|"long double")
inttype (("unsigned "{intver})|{intver})
type ("char"|{inttype}|{realtype})
id {letter_}({letter_}|{digit})*
opast ([=]({digit}+|{id}))
opid ({id}{opast}?[,][ ]*)*
vardec {type}[ ]+{opid}({id}{opast}?[ ]*)[;]




%%
{vardec}	return VALID;

[ \n\t] ;
. ;

%%
int yywrap(void)
{
	return 1;
}



