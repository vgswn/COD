#include <bits/stdc++.h>
using namespace std;
map <string , vector <string> > mp;
map <string,string> smp,fmp;
map <string,vector <string> > first_nt,follow_nt;
string start;
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
    if(mp.find(a)==mp.end())
    {
        return "";
    }
    if(fmp.find(a)!=fmp.end())
    {
        return fmp[a];
    }
    for(map <string , vector <string> > :: iterator it=mp.begin();it!=mp.end();it++)
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
    ifstream fp("first_grammar.txt");
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
    start=gm[0].first;
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
        vector <string> tv;
        for(set <string> :: iterator it2=s2.begin();it2!=s2.end();it2++)
        {
            cout<<*it2<<" ";
            tv.push_back(*it2);
        }
        first_nt[it->first]=tv;
        cout<<endl;
    }
    for(map <string , vector <string> > :: iterator it=mp.begin();it!=mp.end();it++)
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
    return 0;
}
