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
int main()
{
    ifstream fp("C:/Users/RAGHAV SABOO/Desktop/Studies/Cod lab/inp_left_recursion.txt");
    string s;
    int flag=0;
    int i,j;
    vector <string> ans;
    while(fp>>s)
    {
        cout<<s<<endl;
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
        /*cout<<lhs<<" =  ";
        for(i=0;i<rhs.size();i++)
        {
            cout<<rhs[i]<<" ";
        }
        cout<<endl;*/
        int lf=0;
        vector <string> alpha,beta;
        for(i=0;i<rhs.size();i++)
        {
            int p=pref(lhs,rhs[i]);
            if(p)
            {
                lf=1;
                flag=1;
                alpha.push_back(rhs[i].substr(p));
            }
            else
            {
                beta.push_back(rhs[i]);
            }
        }
        if(lf==1)
        {
            string final_string="";
            final_string=final_string+lhs+"->";
            for(i=0;i<beta.size();i++)
            {
                final_string+=beta[i]+lhs+"'";
                if(i!=beta.size()-1)
                {
                    final_string+="|";
                }
            }
            ans.push_back(final_string);
            final_string="";
            final_string=final_string+lhs+"'->";
            for(i=0;i<alpha.size();i++)
            {
                final_string+=alpha[i]+lhs+"'";
                if(i!=alpha.size()-1)
                {
                    final_string+="|";
                }
            }
            ans.push_back(final_string+"|epsilon");
        }
        else
        {
            ans.push_back(s);
        }
    }
    if(flag)
    {
        cout<<"Left recursion was present!!\n";
    }
    else
    {
        cout<<"No left recursion!!\n";
    }
    cout<<"Converted grammar -:\n";
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
