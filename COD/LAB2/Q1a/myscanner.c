#include<stdio.h>
#include"scan.h"

extern int yylex();
extern char* yytext;

int main(){
	int n;
	n=yylex();
	while(n){
		printf("found variable %s\n",yytext);
		n=yylex();
	}
	return 0;
}
