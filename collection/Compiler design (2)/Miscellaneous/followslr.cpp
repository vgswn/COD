#include <bits/stdc++.h>
using namespace std;
map <string , vector <string> > mp1;
map <string,string> smp,fmp;
map <string,vector <string> > first_nt,follow_nt;
string start;
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
string rec_follow(string a)
{
    if(!(a[0]>=65&&a[0]<=90))
    {
        return "";
    }
    int i,j,l;
    string s="";
    if(a.compare(start)==0)
    {
        s=s+"$ ";
    }
    vector <string> rhs;
    if(mp1.find(a)==mp1.end())
    {
        return "";
    }
    if(fmp.find(a)!=fmp.end())
    {
        return fmp[a];
    }
    for(map <string , vector <string> > :: iterator it=mp1.begin();it!=mp1.end();it++)
    {
        string lhs=it->first;
        rhs=it->second;
        int flag;
        for(i=0;i<rhs.size();i++)
        {
            flag=0;
            for(j=0;j<rhs[i].size();j++)
            {
                if(rhs[i][j]==a[0])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                continue;
            }
            if(j==rhs[i].size()-1)
            {
                    if(lhs.compare(a)!=0)
                    {
                        s=s+" "+rec_follow(lhs);
                    }
            }
            else
            {
                j++;
                for(;j<rhs[i].size();j++)
                {
                    if(!(rhs[i][j]>=65&&rhs[i][j]<=90))
                    {
                        s=s+rhs[i][j]+" ";
                        break;
                    }
                    string s22="";
                    s22=s22+rhs[i][j];
                    vector <string> v=first_nt[s22];
                    int ifl=0;
                    for(int li=0;li<v.size();li++)
                    {
                        if(v[li].compare("@")==0)
                        {
                            ifl=1;
                        }
                        else
                        {
                            s=s+v[li]+" ";
                        }
                    }
                    if(ifl==0)
                    {
                        break;
                    }
                }
                if(j==rhs[i].size())
                {
                    if(lhs.compare(a)!=0)
                    {
                        s=s+" "+rec_follow(lhs);
                    }
                }
            }
        }
    }
    return fmp[a]=s;
}

string rec(string a)
{
    int i,j,l;
    string s="";
    vector <string> rhs;
    if(mp1.find(a)==mp1.end())
    {
        return "";
    }
    if(smp.find(a)!=smp.end())
    {
        return smp[a];
    }
    rhs=mp1[a];
    int flag=0;
    for(i=0;i<rhs.size();i++)
    {
        if(!(rhs[i][0]>=65&&rhs[i][0]<=90))
        {
            if(rhs[i].compare("@")==0)
            {
                s=s+"@ ";
            }
            else
            {
                s=s+rhs[i][0]+" ";
            }
        }
        else
        {
            for(j=0;j<rhs[i].size();j++)
            {
                flag=0;
                if(rhs[i][j]>=65&&rhs[i][j]<=90)
                {
                    string s22="";
                    s22=s22+rhs[i][j];
                    string rs=rec(s22);
                    string s2="";
                    s=s+rs;
                    for(int k=0;k<rs.size();k++)
                    {
                        if(rs[k]==' '&&s2.size()>0)
                        {
                            if(s2.compare("@")==0)
                            {
                                flag=1;
                            }
                            s2="";
                        }
                        else if(rs[k]!=' ')
                        {
                            s2=s2+rs[k];
                        }
                    }
                }
                else
                {
                    s=s+rhs[i][j]+" ";
                    break;
                }
                if(flag==0)
                {
                    break;
                }
            }
        }
    }
    return smp[a]=s;
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
        cout<<(*it).s<<" ";
    }
    cout<<endl;
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
        cout<<processed<<endl;
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
                    cout<<(*it)[0]<<" "<<i<<"((((\n";
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
    cout<<flag<<endl;
    int i,j;
    vector <string> ans,rhs1;
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
                rhs1.push_back(temp_string);
                temp_string="";
            }
            else
            {
                temp_string+=s[i];
            }
        }
        map_ind[make_pair(lhs,temp_string)]=count++;
        rhs.insert(temp_string);
        rhs1.push_back(temp_string);
        cout<<rhs1[0]<<endl;
        mp1[gm[i].first]=rhs1;
        gm.push_back(make_pair(lhs,rhs));
        rhs.clear();
        rhs1.clear();
    }

    cout<<"***\n";

    start=gm[0].first;
    for(i=0;i<gm.size();i++)
    {
        mp[gm[i].first]=gm[i].second;
    }
    for(map <string , vector <string> > :: iterator it=mp1.begin();it!=mp1.end();it++)
    {
        string s1=rec(it->first);
        cout<<"First of Non terminal "<<it->first<<" is = ";
        set <string> s2;
        string s3="";
        for(i=0;i<s1.size();i++)
        {
            if(s1[i]==' '&&s3.size()>0)
            {
                s2.insert(s3);
                s3="";
            }
            else if(s1[i]!=' ')
            {
                s3=s3+s1[i];
            }
        }
        vector <string> tv;
        for(set <string> :: iterator it2=s2.begin();it2!=s2.end();it2++)
        {
            cout<<*it2<<" ";
            tv.push_back(*it2);
        }
        first_nt[it->first]=tv;
        cout<<endl;
    }
    for(map <string , vector <string> > :: iterator it=mp1.begin();it!=mp1.end();it++)
    {
        string s1=rec_follow(it->first);
        cout<<"Follow of Non terminal "<<it->first<<" is = ";
        set <string> s2;
        string s3="";
        for(i=0;i<s1.size();i++)
        {
            if(s1[i]==' '&&s3.size()>0)
            {
                s2.insert(s3);
                s3="";
            }
            else if(s1[i]!=' ')
            {
                s3=s3+s1[i];
            }
        }
        vector <string> tv;
        for(set <string> :: iterator it2=s2.begin();it2!=s2.end();it2++)
        {
            cout<<*it2<<" ";
            tv.push_back(*it2);
        }
        follow_nt[it->first]=tv;
        cout<<endl;
    }





    make_itemset(gm[0].first);
    
    for(i=0;i<arr.size();i++)
    {
        cout<<"State "<<i<<"        ";
        for(set <dott_string> :: iterator it=arr[i].v.begin();it!=arr[i].v.end();it++)
        {
            cout<<(*it).s<<"  "<<(*it).ind<<endl;
        }
        cout<<endl;
    }
    tabletype table[25][25];
    map <char,int> index;
    map <int,char> rindex;
    index['i']=0;rindex[0]='i';
    index['+']=1;rindex[1]='+';
    index['*']=2;rindex[2]='*';
    index['(']=3;rindex[3]='(';
    index[')']=4;rindex[4]=')';
    index['$']=5;rindex[5]='$';
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
        string fllhs;
        for(set<dott_string>::iterator it=arr[i].v.begin();it!=arr[i].v.end();it++)
        {
            
            dott_string x=*it;

            if(x.s.size()==x.ind)
            {
                cout<<i<<" "<<x.s<<"****\n";
                if(x.s.compare(gm[0].first)==0)
                {
                    fs=1;
                }
                red=map_ind[make_pair(x.lhs,x.s)];
                fllhs=x.lhs;
                break;
            }
            
        }
        if(red!=-1&&fs==0)
        {
            dott_string a;
            vector <string> rhs3=follow_nt[fllhs];
            int flag3=0;
            for(int jj=0;jj<rhs3.size();jj++)
            {
                if(index.find(rhs3[jj][0])!=index.end())
                {
                    table[i][index[rhs3[jj][0]]]=tabletype(1,red);
                }
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
        cout<<i<<"  ";
        for(map <char,int> :: iterator it=arr[i].next.begin();it!=arr[i].next.end();it++)
        {
            cout<<it->first<<" "<<it->second<<"   ";
        }
        cout<<endl;
    }
    cout<<"i   +   *   (   )   $   E   T   F\n";
    for(i=0;i<12;i++)
    {
        for(j=0;j<9;j++)
        {
            cout<<table[i][j].type<<" "<<table[i][j].num<<"   ";
        }
        cout<<endl;
    }
    return 0;
}