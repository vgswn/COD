%{
	#include "y.tab.h"
	#include <string.h>
%}


%%


[\+\*\(\)]				   	{return yytext[0];}
"id"			   	{strcpy(yylval.iden,yytext); return id;}
[ \t\n]             {;}
.                  	{ECHO; yyerror ("unexpected character");}

%%
int yywrap (void) 
{
	return 1;
}
