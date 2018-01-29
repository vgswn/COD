%{
	#include "scan.h"
%}
intver   (short[ ]int|long[ ]int|int)
realtype (float|double|long[ ]double)
inttype  (((unsigned)[ ]+{intver})|{intver})
type     ((char)|{inttype}|{realtype})
opid     ([ ]*[\,][ ]*(id){opast})*
ter      [\;]
opast    (([ ]*(=)[ ]*(val))|([ ]*(=)[ ]*(id)))*
var 	 ({type}[ ]+(id){opast}{opid}[ ]*{ter})

%%

{var}   return VAR;
[ \n\t] ;

%%

int yywrap(){

	return 1;
}
