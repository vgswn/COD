%{
	#include "scan.h"
%}


type    (char|float|int|double)
opid    ([ ]*[\,][ ]*(id))*
ter     [\;]
var 	({type}[ ]+(id){opid}{ter})

%%

{var}   return VAR;
[ \n\t] ;

%%

int yywrap(){

	return 1;
}
