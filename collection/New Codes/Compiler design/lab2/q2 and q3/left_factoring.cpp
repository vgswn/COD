#include <bits/stdc++.h>
using namespace std;
int pref(string a,string b)
{
    int i,l;
    string t="";
    for(i=0;i<b.size();i++)
    {
        t=t+b[i];
        if(t.compare(a)==0)
        {
            return i+1;
        }
    }
    return 0;
}
int cmpprefix(string a,string b)
{
    int i,l,flag=0,pos=0;
    for(i=0;i<a.size();i++)
    {
        if(a.substr(0,i+1).compare(b.substr(0,i+1))==0)
        {
            pos=i+1;
            flag=1;
        }
    }
    if(flag==0)
    {
        return 0;
    }
    return pos;
}
string remove_left_factor(string lhs,string rhs)
{

}
int main()
{
    ifstream fp("C:/Users/RAGHAV SABOO/Desktop/Studies/Cod lab/inp_left_factoring.txt");
    string s;
    int flag=0;
    int i,j;
    vector <string> ans,tv;
    while(fp>>s)
    {
        cout<<s<<endl;
        tv.push_back(s);
    }
    for(int k=0;k<tv.size();k++)
    {
        s=tv[k];
        string lhs="";
        vector <string> rhs;
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
        int lf=0;
        vector < pair < int, vector<string > > > mp;
        map <string,int> inds;
        int mark[105];
        for(i=0;i<100;i++)
        {
            mark[i]=0;
        }
        for(i=0;i<rhs.size();i++)
        {
            vector <string> pref;
            if(mark[i])
            {
                continue;
            }
            int mn=100;
            vector <int> pv;
            for(j=i+1;j<rhs.size();j++)
            {
                if(mark[j])
                {
                    continue;
                }
                int rr=cmpprefix(rhs[i],rhs[j]);
                if(rr)
                {
                    pv.push_back(j);
                    mn=min(mn,rr);
                }
            }
            if(mn!=100)
            {
                lf=1;
                mark[i]++;
                pref.push_back(rhs[i]);
                inds[rhs[i]]=mn;
                for(j=0;j<pv.size();j++)
                {
                    mark[pv[j]]++;
                    inds[rhs[pv[j]]]=mn;
                    pref.push_back(rhs[pv[j]]);
                }
                mp.push_back(make_pair(mn,pref));
            }
        }
        if(lf==1)
        {
            /*for(i=0;i<mp.size();i++)
            {
                cout<<mp[i].first<<"   ";
                vector <string> vs1=mp[i].second;
                for(j=0;j<vs1.size();j++)
                {
                    cout<<vs1[j]<<" ";
                }
                cout<<endl;
            }*/
            map <string,int> fs;
            for(i=0;i<mp.size();i++)
            {
                vector <string> vs1=mp[i].second;
                string vs2="";
                vs2=lhs;
                for(j=0;j<=i;j++)
                {
                    vs2+="'";
                }
                vs2+="->";
                for(j=0;j<vs1.size();j++)
                {
                    fs[vs1[j]]=i+1;
                    string temps1=vs1[j].substr(mp[i].first);
                    vs2+=(temps1.size()==0?"epsilon":temps1);
                    if(j!=vs1.size()-1)
                    {
                        vs2+="|";
                    }
                }
                ans.push_back(vs2);
            }
            string temps2="";
            temps2+=lhs+"->";
            for(i=0;i<rhs.size();i++)
            {
                if(mark[i])
                {
                    temps2+=rhs[i].substr(0,inds[rhs[i]])+lhs;
                    for(j=0;j<fs[rhs[i]];j++)
                    {
                        temps2+="'";
                    }
                }
                else
                {
                    temps2+=rhs[i];
                }
                if(i!=rhs.size()-1)
                {
                    temps2+="|";
                }
            }
            ans.push_back(temps2);
        }
        else
        {
            ans.push_back(s);
        }
    }
    if(flag)
    {
        cout<<"Left factoring was present!!\n";
    }
    else
    {
        cout<<"No left factoring!!\n";
    }
    cout<<"Converted grammar -:\n";
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

