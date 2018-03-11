#include <stdio.h>
extern int yylex();
extern int yylineno;
extern char* yytext;
int main() {
  int x;
   while(x=yylex()){
  if(x==1)
  {
    printf("String Returned %s\n",yytext);
  }
}
  return 1;
}
