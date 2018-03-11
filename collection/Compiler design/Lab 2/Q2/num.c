#include <stdio.h>
#include "mynumber.h"
extern int yylex();
extern int yylineno;
extern char* yytext;
int main()
{
	int ntoken;
	int cnt_uns=0,cnt_sig=0;
	ntoken=yylex();
	while(ntoken)
	{
		if(ntoken==UNSIGNED)
		{
			cnt_uns++;
			printf("Unsigned no %s at line no %d\n",yytext,yylineno);
		}
		else if(ntoken==SIGNED)
		{
			cnt_sig++;
			printf("Signed no %s at line no %d\n",yytext,yylineno);
		}
		ntoken=yylex();
	}
	printf("Total Unsigned no are - %d\n",cnt_uns);
	printf("Total Signed no are - %d\n",cnt_sig);
	return  0;
}