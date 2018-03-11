#include <bits/stdc++.h>
using namespace std;
map <string , vector <string> > mp;
map <string,string> smp;
string rec(string a)
{
    int i,j,l;
    string s="";
    vector <string> rhs;
    if(mp.find(a)==mp.end())
    {
        return "";
    }
    if(smp.find(a)!=smp.end())
    {
        return smp[a];
    }
    rhs=mp[a];
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
int main()
{
    ifstream fp("C:/Users/RAGHAV SABOO/Desktop/Studies/Cod lab/inp3_grammar.txt");
    string s="";
    int flag=0;
    int i,j;
    vector <string> ans;
    vector <string> rhs;
    vector < pair < string, vector <string> > > gm;
    while(fp>>s)
    {
       // cout<<s<<endl;
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
                rhs.push_back(temp_string);
                temp_string="";
            }
            else
            {
                temp_string+=s[i];
            }
        }
        rhs.push_back(temp_string);
        gm.push_back(make_pair(lhs,rhs));
        rhs.clear();
    }
    for(i=0;i<gm.size();i++)
    {
        mp[gm[i].first]=gm[i].second;
    }
    for(map <string , vector <string> > :: iterator it=mp.begin();it!=mp.end();it++)
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
        for(set <string> :: iterator it=s2.begin();it!=s2.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    return 0;
}
