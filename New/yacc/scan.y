%{
#include<stdio.h>
%}
%token id
%start S
%%
S : id S
  |
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
