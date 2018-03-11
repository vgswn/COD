#include<bits/stdc++.h>
using namespace std;
extern int yylex();
extern int yylineno;
extern char* yytext;
map <string , set <string> > mp;
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
struct dott_string
{
    string lhs;
    string s;
    int ind;
    
};
inline bool operator<(const dott_string &x,const dott_string &y){
        if(x.s.compare(y.s)==0&&x.lhs.compare(y.lhs)==0){
            return x.ind < y.ind;
        }
        else if(x.lhs.compare(y.lhs)==0){
            return x.s.compare(y.s)<0;
        }
        else{
            return x.lhs.compare(y.lhs)<0   ;
        }
    } 
struct itemset
{
    int type;
    set <dott_string> v;
    map <char,int> next;
};
vector < itemset > arr;
map <char,int> cpc;
int processed;
int equal_set(set <dott_string> s1,set <dott_string> s2)
{
    int flag=0;
    set <dott_string> :: iterator it1=s2.begin();
    for(set <dott_string> :: iterator it=s1.begin();it!=s1.end()&&it1!=s2.end();it++,it1++)
    {
        //cout<<(*it).s<<" "<<(*it).ind<<" "<<(*it1).s<<" "<<(*it1).ind<<endl;
        if((*it).lhs.compare((*it1).lhs)!=0||(*it).s.compare((*it1).s)!=0||(*it).ind!=(*it1).ind)
        {
            //cout<<"Return 0\n";
            return 0;
        }
    }
    //cout<<"Return 1\n";
    return 1;
}
set <dott_string> closure(struct dott_string s)
{
    set <dott_string> v;
    v.insert(s);
    //cout<<s.s<<" "<<s.ind<<"**\n";
    if(s.ind==s.s.size())
    {
        return v;
    }
    else
    {
        if(cpc.find(s.s[s.ind])!=cpc.end())
        {
            set <dott_string> v1;
            v1.clear();
            return v1;
        }
        string ts="";
        ts=ts+s.s[s.ind];
        cpc[s.s[s.ind]]++;
        //cout<<s.s[s.ind]<<"((((\n";
        /*for(map <char,int> :: iterator it=cpc.begin();it!=cpc.end();it++)
            {
                cout<<it->first<<" ";
            }
            cout<<endl;*/
        if(mp.find(ts)!=mp.end())
        {
            set <string> pr=mp[ts];
            dott_string tmp;
            
            
            
            for(set <string> :: iterator it=pr.begin();it!=pr.end();it++)
            {
                tmp.lhs=ts;
                tmp.s=*it;
                tmp.ind=0;
                v.insert(tmp);
                set <dott_string> rc=closure(tmp);
                v.insert(rc.begin(),rc.end());
            }
        }
        else
        {
            //printf("***************\n");
        }
    }
    return v;
}

void make_itemset(string start)
{
    struct itemset ini;
    struct dott_string tmp;
    set <dott_string> s;
    tmp.s=start;
    tmp.ind=0;
    map <char,int> mci;
    s=closure(tmp);
    for(set <dott_string> :: iterator it=s.begin();it!=s.end();it++)
    {
      //  cout<<(*it).s<<" ";
    }
    //cout<<endl;
    int i;
    ini.v=s;
    ini.type=0;
    set <string> fp;
    string tss;
    ini.v=s;
    arr.push_back(ini);
    processed=0;
    while(processed<arr.size())
    {
        s=arr[processed].v;
        mci=arr[processed].next;
        fp.clear();
        for(set <dott_string> :: iterator it=s.begin();it!=s.end();it++)
        {
            tmp=*it;
            tss="";
            if(tmp.ind<tmp.s.size())
            {
                tss=tss+tmp.s[tmp.ind];
                fp.insert(tss);
            }
        }
        //cout<<processed<<endl;
        for(set <string> :: iterator it=fp.begin();it!=fp.end();it++)
        {
            set <dott_string> same_type;
            for(set <dott_string> :: iterator it1=s.begin();it1!=s.end();it1++)
            {
                tmp=*it1;
                if(tmp.s[tmp.ind]==(*it)[0])
                {
                    dott_string tmp2=tmp;
                    if(tmp2.ind<tmp2.s.size())
                    {
                        tmp2.ind++;
                    }   
                    same_type.insert(tmp2);
                }
            }
            set <dott_string> clos;
            for(set <dott_string> :: iterator it1=same_type.begin();it1!=same_type.end();it1++)
            {
                cpc.clear();
                set <dott_string> rc=closure(*it1);
                clos.insert(rc.begin(),rc.end());
            }
            int flag=0;
            for(i=0;i<arr.size();i++)
            {
                if(equal_set(arr[i].v,clos))
                {   
                    flag=1;
                    mci[(*it)[0]]=i;
                   // cout<<(*it)[0]<<" "<<i<<"((((\n";
                    break;
                }
            }   
            if(!flag)
            {
                struct itemset newi;
                newi.v=clos;
                arr.push_back(newi);
                mci[(*it)[0]]=i;
            }
        }
        arr[processed].next=mci;
        processed++;
    }
}

int main()
{    
    map< pair <string,string> ,int > map_ind;
    ifstream fp("inp.txt");
    string s="";
    int flag=0;
    int i,j;
    vector <string> ans;
    set <string> rhs;
    int count=1;
    vector < pair < string, set <string> > > gm;
    while(fp>>s)
    {
        string lhs="";
        for(i=0;i<s.size()&&s[i]!='-';i++)
        {
            lhs=lhs+s[i];
        }
        i+=2;
        string temp_string="";
        for(;i<s.size();i++)
        {
            if(s[i]=='|')
            {
                map_ind[make_pair(lhs,temp_string)]=count++;
                rhs.insert(temp_string);
                temp_string="";
            }
            else
            {
                temp_string+=s[i];
            }
        }
        map_ind[make_pair(lhs,temp_string)]=count++;
        rhs.insert(temp_string);
        gm.push_back(make_pair(lhs,rhs));
        rhs.clear();
    }
    for(i=0;i<gm.size();i++)
    {
        mp[gm[i].first]=gm[i].second;
    }

    make_itemset(gm[0].first);
    
    for(i=0;i<arr.size();i++)
    {
        cout<<"State "<<i<<" contains items - ";
        for(set <dott_string> :: iterator it=arr[i].v.begin();it!=arr[i].v.end();it++)
        {
            for(int ui=0;ui<(*it).s.size();ui++)
            {
            	if((*it).ind==ui)
            	{
            		cout<<".";
            	}
            	cout<<(*it).s[ui];	
            }
            cout<<"   ";
        }
        cout<<endl;
    }
    tabletype table[25][25];
    map <int,int> index;
    index['i']=0;
    index['+']=1;
    index['*']=2;
    index['(']=3;
    index[')']=4;
    index['$']=5;
    index['E']=6;
    index['T']=7;
    index['F']=8;
    for(i=0;i<12;i++){
        for(int j=0;j<9;j++){
            table[i][j]= tabletype(3,-1);
        }
    }
    
    int k=0;
   
    for(i=0;i<arr.size();i++)
    {
        map <char,int> nx=arr[i].next; 
        int type=0;
        int red=-1;
        int fs=0;
        for(set<dott_string>::iterator it=arr[i].v.begin();it!=arr[i].v.end();it++)
        {
            
            dott_string x=*it;

            if(x.s.size()==x.ind)
            {
               // cout<<i<<" "<<x.s<<"****\n";
                if(x.s.compare(gm[0].first)==0)
                {
                    fs=1;
                }
                red=map_ind[make_pair(x.lhs,x.s)];
                break;
            }
            
        }
        if(red!=-1&&fs==0)
        {
            for(int j=0;j<6;j++)
            {
                dott_string a;
                table[i][j]=tabletype(1,red);
            }
        }
        else
        {
            if(fs==1)
            {
                table[i][index['$']]=tabletype(3,1);
            }
            for(map<char,int> :: iterator it=nx.begin();it!=nx.end();it++)
            {
                if(it->first>=65&&it->first<=90)
                {
                    table[i][index[it->first]]=tabletype(2,it->second);
                }
                else
                {
                    table[i][index[it->first]]=tabletype(0,it->second);
                }
            }
        }
    }

    for(i=0;i<arr.size();i++)
    {
    //    cout<<i<<"  ";
        for(map <char,int> :: iterator it=arr[i].next.begin();it!=arr[i].next.end();it++)
        {
      //      cout<<it->first<<" "<<it->second<<"   ";
        }
       // cout<<endl;
    }
    cout<<"\n\nTable for SLR Parser - \n";
    cout<<"           i       +      *       (       )       $       E       T      F\n";
    for(i=0;i<12;i++)
    {
    	cout<<"State "<<i<<"   ";
        for(j=0;j<9;j++)
        {
        	if(table[i][j].type==0)
        	{
        		cout<<"s "; 
        	}
        	else if(table[i][j].type==1)
        	{
        		cout<<"r ";
        	}
        	else if(table[i][j].type==2)
        	{
        		cout<<"gt ";
        	}
            cout<<table[i][j].num<<"     ";
        }
        cout<<endl;
    }
    /*int token;
    token=yylex();
    stack<int> st1;
    st1.push(0);
    
    int reduce[]={0,6,2,6,2,6,2};
    int got[]={0,6,6,7,7,8,8};
    while(token){
        
        tabletype temp=table[st1.top()][token-1];
        printf("top yytext %d %s\n", st1.top(),yytext);
        printf("type num %d %d\n",temp.type,temp.num);
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
    }*/

    return 0;
}