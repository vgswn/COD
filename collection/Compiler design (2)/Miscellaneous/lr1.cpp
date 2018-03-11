#include<bits/stdc++.h>
#include"scan.h"
using namespace std;
extern int yylex();
extern int yylineno;
extern char* yytext;
struct tabletype{
	int type;
	int num;
	tabletype(int x,int y){
		type = x;
		num =y;
	}
	tabletype(){

	}
};
struct tabletype table[25][25];
 
int main(){
	int token;
	for(int i=0;i<12;i++){
		for(int j=0;j<9;j++){
			table[i][j]= tabletype(3,-1);
		}
	}
	table[0][0]= tabletype(0,5);
	table[0][4]= tabletype(0,4);
    table[0][6]= tabletype(2,1);
    table[0][7]= tabletype(2,2);
    table[0][8]= tabletype(2,3);
    table[1][1]= tabletype(0,6);
    table[1][5]= tabletype(3,0);
    table[2][1]= tabletype(1,2);
    table[2][2]= tabletype(0,7);
    table[2][4]= tabletype(1,2);
    table[2][5]= tabletype(1,2);
    table[3][1]= tabletype(1,4);
    table[3][2]= tabletype(1,4);
    table[3][4]= tabletype(1,4);
    table[3][5]= tabletype(1,4);
    table[4][0]= tabletype(0,5);
    table[4][3]= tabletype(0,4);
    table[4][6]= tabletype(2,8);
    table[4][7]= tabletype(2,2);
    table[4][8]= tabletype(2,3);
    table[5][1]= tabletype(1,6);
    table[5][2]= tabletype(1,6);
    table[5][4]= tabletype(1,6);
    table[5][5]= tabletype(1,6);
    table[6][0]= tabletype(0,5);
    table[6][3]= tabletype(0,4);
    table[6][7]= tabletype(2,9);
    table[6][8]= tabletype(2,3);
    table[7][0]= tabletype(0,5);
    table[7][3]= tabletype(0,4);
    table[7][8]= tabletype(2,10);
    table[8][1]= tabletype(0,6);
    table[8][4]= tabletype(0,11);
    table[9][1]= tabletype(1,1);
    table[9][2]= tabletype(0,7);
    table[9][4]= tabletype(1,1);
    table[9][5]= tabletype(1,1);
    table[10][1]= tabletype(1,3);
    table[10][2]= tabletype(1,3);
    table[10][4]= tabletype(1,3);
    table[10][5]= tabletype(1,3);
    table[11][1]= tabletype(1,5);
    table[11][2]= tabletype(1,5);
    table[11][4]= tabletype(1,5);
    table[11][5]= tabletype(1,5);
	token=yylex();
	stack<int> st1;
	st1.push(0);
	
	int reduce[]={0,6,2,6,2,6,2};
	int got[]={0,6,6,7,7,8,8};
	while(token){
		
		tabletype temp=table[st1.top()][token-1];
		//printf("top yytext %d %s\n", st1.top(),yytext);
		//printf("type num %d %d\n",temp.type,temp.num);
		if(temp.type==0){
			st1.push(token);
			st1.push(temp.num);
			//st1.pop();
			token=yylex();
		}
		else if(temp.type==1){
			for(int i=0;i<reduce[temp.num];i++){
				st1.pop();
			}
			temp=table[st1.top()][got[temp.num]];
			st1.push(got[temp.num]-5);
			st1.push(temp.num);
		}
		else if(temp.type==3){
			if(temp.num==0){
				printf("valid syntax!!\n");
				token=yylex();
				if(token==newline){
					while(st1.empty()==false){
						st1.pop();
					}
				}
				st1.push(0);
				token=yylex();
			}
			else{
				printf("error\n");
				while(token!=newline){
					token=yylex();
				}
				while(st1.empty()==false){
					st1.pop();
				}
				st1.push(0);
				token=yylex();
			}
		}
	}
	return 0;
}
