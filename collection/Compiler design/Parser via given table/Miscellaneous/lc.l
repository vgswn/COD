%{
	#include"scan.h"
	#include <string.h>
%}


%%


[\+]				   	{return plus;}
[\*]                    {return star;}
[\(]                    {return op;}
[\)]                    {return cp;}
"$"                     {return dollar;}
"id"			   	{ return id;}
[\n]				{return newline;}
[ \t]             {;}
.                  	{ECHO; printf ("unexpected character");}

%%
int yywrap (void) 
{
	return 1;
}
