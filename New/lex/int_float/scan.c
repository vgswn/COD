#include <stdio.h>
#include "header.h"
extern int yylex();
extern int yylineno;
extern char* yytext;
int main() {
  int x;
   while(x=yylex()){
  if(x==integer)
  {
    printf("Integer Returned %s\n",yytext);
  }
  else if(x==float)
  {
    printf("Float Returned %s\n",yytext);
  }
}
  return 1;
}
