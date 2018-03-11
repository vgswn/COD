%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%token id num
%start E

%%

E : E '+' T 
	| T 
	;

T : T '*' F  
	| F   
	;

 
F : '(' E ')'
	| id 
	;

%%


int main()
{
	yyparse();
	printf("Valid\n");
	exit(0);
}

void yyerror() 
{
	printf("Error\n");
	exit(0);
} 



