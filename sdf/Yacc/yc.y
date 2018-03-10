%{
	#include <stdio.h>
	#include <stdlib.h>
	void yyerror(char *s);	
	extern char * yytext;
%}

%union {int num;char iden[105];}
%start E
%token <iden> id
%type <iden> E T F 

%%

E : E '+' T {;}
	| T {;}
	;

T : T '*' F  {;}
	| F   {;}
	;


F : '(' E ')' {;}
	| id {;}
	;

%%

int main()
{
	return yyparse();
}

void yyerror (char *s) 
{
	fprintf (stderr, "%s %s\n", s,yytext);
} 



