#include <stdio.h>
#include <string.h>
#include "myscanner.h"
extern int yylex();
extern int yylineno;
extern char* yytext;
int main()
{
	int n;
	n=yylex();
	//printf("%d\n",n);
	while(n)
	{
		if(n==VALID)
		{
			printf("Valid %s\n",yytext);
		}
		n=yylex();
	}
	return 0;
}

//[ ]+{id}{opid}[;]
/*
smt ("if".*[\n\t].*[\{][.*{smt1}][\}])|("if".*[\n].*[\{]([.*{smt1}])[\}]"else".*[\{]([.*{smt1}])[\}])
smt1 (("if".*[\n].*[\{]({smt1})[\}])|("if".*[\n].*[\{]({smt1})[\}]"else".*[\{]({smt1})[\}])|{fun})*
exp ([eE][\+\-]?([0-9]+([\.][0-9]+)?))?

*/
