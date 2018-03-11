#include<bits/stdc++.h>
using namespace std;
struct tabletype
{
	int type;
	int num;
	tabletype(int x,int y)
    {
		type = x;
		num =y;
	}
    tabletype()
    {

    }
};

struct tabletype table[25][25];
map <char,int> r;
map <int,char> p;
int red[]={3,1,3,1,3,1};


int parse(string s)
{
    stack <int> st;
    st.push(0);
    int id,i,l,j;
    char ch;
    id=0;
    while(id<s.size())
    {
        if(st.empty())
        {
            return 0;
        }
        int top=st.top();
        tabletype ty=table[top][r[s[id]]];
        if(ty.num==-1)
        {
            return 0;
        }
        if(ty.type==0)
        {
            st.push(ty.num);
            id++;
        }
        else if(ty.type==1)
        {   
            for(i=1;i<=red[ty.num-1];i++)
            {
                if(st.empty())
                {
                    return 0;
                }
                st.pop();
            }    
            if(st.empty())
            {
                return 0;
            }
            tabletype temp=table[st.top()][r[p[ty.num]]];
            st.push(temp.num);
        }   
        else if(ty.type==3&&ty.num==0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
	int token;
	for(int i=0;i<25;i++)
    {
		for(int j=0;j<25;j++)
        {
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
	

    r['i']=0;
    r['+']=1;
    r['*']=2;
    r['(']=3;
    r[')']=4;
    r['$']=5;
    r['E']=6;
    r['T']=7;
    r['F']=8;

    p[1]='E';
    p[2]='E';
    p[3]='T';
    p[4]='T';
    p[5]='F';
    p[6]='F';


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