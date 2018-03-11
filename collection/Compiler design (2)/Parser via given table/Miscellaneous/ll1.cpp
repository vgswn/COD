#include <bits/stdc++.h>
using namespace std;
int table[100][100];
map <int,string> prod;
map <char,int> r,c;
int parse(string s)
{
  stack <char> st;
  st.push('$');
  st.push('E');
  int i,j,l,id=0;
  char ch;
  while(id<s.size())
  {
    if(st.empty())
    {
      return 0;
    }
    if(st.top()=='$'&&s[id]=='$')
    {
      return 1;
    }
    char top;
    top=st.top();
    //cout<<top<<" "<<id<<endl;
    if(top>=65&&top<=90)
    {
      if(table[r[top]][c[s[id]]]==0)
      {
        return 0;
      }
      string pr=prod[table[r[top]][c[s[id]]]];
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
      if(top==s[id])
      {
        st.pop();
        id++;
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

  cout<<"Enter parsing table"<<endl;
  int m,n,i,j;
  cin>>m>>n;
  for(i=0;i<m;i++)
  {
    for (j=0;j<n;j++)
    {
      cin>>table[i][j];
    }
  }
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      //cout<<table[i][j]<<" ";
    }
    //cout<<endl;
  }
  int no;
  cout<<"Enter no of  String to be processed"<<endl;
  cin>>no;
  while(no--)
  {
    string s;
    cin>>s;
    if(parse(s+"$"))
    {
      
      cout<<"Valid String\n";
    }
    else
    {
      cout<<"Not a Valid String\n";
    }
  }
  return 0;
}








/*5 6
1 0 0 1 0 0
0 2 0 0 3 3
4 0 0 4 0 0
0 6 5 0 6 6
8 0 0 7 0 0*/
