%{
	#include "slrlc.h"
%}

%%

"id" {return id;}
[\(] {return op;}	
[\)] {return cp;}
[\+] {return plus;}
[\*] {return mult;}
[\n] {return nl;}
[ \t]	{;}
.          {return oth;}


%%

int yywrap()
{
	return 1;
}