#include <stdio.h>
#include <string.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
int check_keyword(char *s)
{
	int i;
	for(i=0;i<32;i++)
	{
		if(strcmp(keywords[i],s)==0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int retvalue,count=1;
	retvalue=yylex();
	//printf("%d\n",retvalue);
	while(retvalue)
	{
		if (retvalue==IF)
		{
				printf("If Block  \"%s\" starts  from line number %d\n\n",yytext,count);

		}
		else if(retvalue==ELSE){
				printf(" Else Block \"%s\" starts from line number %d\n\n",yytext,count);
		}

			else if(retvalue==IDENTIFIER)
		{
			if(check_keyword(yytext))
			{
				printf("Keyword \"%s\" at line number %d\n\n",yytext,count);
			}
			else
			{
				printf("Identifier \"%s\" at line number %d\n\n",yytext,count);
			}

		}
		else if(retvalue==NUMBER)
		{
			printf("Unsigned Number \"%s\" at line number %d\n\n",yytext,count);
		}
		else if(retvalue==NEWLINE){
			count++;
		}
		else if(retvalue==FOR){
			printf("Loop : For ->  \"%s\" at line number %d\n\n",yytext,count);
		}
		else if(retvalue==WHILE){
			printf("Loop : While -> \"%s\" at line number %d\n\n",yytext,count);
		}
		retvalue=yylex();
	}
	return 0;
}

/*
smt ("if".*[\n\t].*[\{][.*{smt1}][\}])|("if".*[\n].*[\{]([.*{smt1}])[\}]"else".*[\{]([.*{smt1}])[\}])
smt1 (("if".*[\n].*[\{]({smt1})[\}])|("if".*[\n].*[\{]({smt1})[\}]"else".*[\{]({smt1})[\}])|{fun})*

*/
