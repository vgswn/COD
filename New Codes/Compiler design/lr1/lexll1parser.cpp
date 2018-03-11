#include <bits/stdc++.h>
#include "slrlc.h"
using namespace std;
extern int yylex();
extern char* yytext;
int table[5][6]={{1,0,0, 0, 0},
{0, 2, 0 ,0 ,3, 3,},
{4 ,0 ,0 ,4 ,0, 0},
{0 ,6 ,5, 0, 6 ,6},
{8 ,0 ,0 ,7 ,0 ,0}};
map <int,string> prod;
map <char,int> r,c;
int parse(string s)
{
  //cout<<s<<" ";
  stack <char> st;
  st.push('$');
  st.push('E');
  int i,j,l,ind=0;
  char ch;
  while(ind<s.size())
  {
    if(st.empty())
    {
      return 0;
    }
    if(st.top()=='$'&&s[ind]=='$')
    {
      return 1;
    }
    char top;
    top=st.top();
    //cout<<top<<" "<<id<<endl;
    if(top>=65&&top<=90)
    {
      if(table[r[top]][c[s[ind]]]==0)
      {
        return 0;
      }
      string pr=prod[table[r[top]][c[s[ind]]]];
      if(pr.size()==4&&pr[3]=='@')
      {
        st.pop();
      }
      else
      {
        st.pop();
        for(i=pr.size()-1;i>=0;i--)
        {
          if(pr[i]=='>')
          {
            break;
          }
          st.push(pr[i]);
        }
      }
    }
    else
    {
      if(top==s[ind])
      {
        st.pop();
        ind++;
      }
      else
      {
        return 0;
      }
    }
  }
  return 0;
}
int main()
{

  r['E']=0;
  r['K']=1;
  r['T']=2;
  r['M']=3;
  r['F']=4;


  c['i']=0;
  c['+']=1;
  c['*']=2;
  c['(']=3;
  c[')']=4;
  c['$']=5;



  prod[1]="E->TK";
  prod[2]="K->+TK";
  prod[3]="K->@";
  prod[4]="T->FM";
  prod[5]="M->*FM";
  prod[6]="M->@";
  prod[7]="F->(E)";
  prod[8]="F->i";

  int m,n,i,j;
  /*cin>>m>>n;
  for(i=0;i<m;i++)
  {
    for (j=0;j<n;j++)
    {
      cin>>table[i][j];
    }
  }*/

  m=5;n=6;
  

  int no=yylex();
    string s="",os="";
    while(no)
    {
        if(no==nl)
        {
            if(parse(s+"$"))
            {
            cout<<os<<" is a Valid String\n";
            }
            else
            {
            cout<<os<<" is Not a Valid String\n";
            }
            os="";
            s="";
        }
        else if(no==id)
        {
            s=s+"i";
            for(int i=0;i<strlen(yytext);i++)
            {
                os=os+yytext[i];
            }            
        }
        else
        {
            for(int i=0;i<strlen(yytext);i++)
            {
                s=s+yytext[i];
                os=os+yytext[i];
            }
        }
        no=yylex();
    }
  return 0;
}








/*5 6
1 0 0 1 0 0
0 2 0 0 3 3
4 0 0 4 0 0
0 6 5 0 6 6
8 0 0 7 0 0*/
