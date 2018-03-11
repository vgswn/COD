#include <bits/stdc++.h>
using namespace std;
map <string,int> r,c;
set <string> nont;
int table[105][105];
map <int,string> prod;
map <string,int> rprod;
map <string , vector <string> > mp;
map <string,string> smp,fmp;
map <string,vector <string> > first_nt,follow_nt;
string start;
int parse(string s)
{
  stack <char> st;
  st.push('$');
  st.push(start[0]);
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
    string stop="",tss="";
    stop=stop+top;
    tss=tss+s[id];
    //cout<<top<<" "<<id<<endl;
    if(top>=65&&top<=90)
    {
      if(table[r[stop]][c[tss]]==0)
      {
        return 0;
      }
      string pr=prod[table[r[stop]][c[tss]]];
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


    int cnt=0;
    for(i=0;i<gm.size();i++)
    {
        int ifl=0;
        r[gm[i].first]=i;    
        for(j=0;j<gm[i].second.size();j++)
        {
            if(gm[i].second[j].compare("@")==0)
            {
                ifl=1;
            }
            prod[++cnt]=gm[i].first+"->"+gm[i].second[j];
            rprod[gm[i].first+"->"+gm[i].second[j]]=cnt;
            for(int li=0;li<gm[i].second[j].size();li++)
            {
                if(!(gm[i].second[j][li]>=65&&gm[i].second[j][li]<=90))
                {
                    string sdd="";
                    sdd=sdd+gm[i].second[j][li];
                    nont.insert(sdd);
                }
            }
        }
        for(j=0;j<first_nt[gm[i].first].size();j++)
        {
            if(first_nt[gm[i].first][j].compare("@")==0&&ifl==0)
            {
                prod[++cnt]=gm[i].first+"->@";
                rprod[gm[i].first+"->@"]=cnt;
                break;
            }
        }
    }
    
    for(map <string,int> :: iterator it=rprod.begin();it!=rprod.end();it++)
    {
       // cout<<it->first<<" "<<it->second<<endl;
    }

    i=0;
    nont.insert("$");
    //cout<<"   ";
    cout<<setw(8);
    for(set<string> :: iterator it=nont.begin();it!=nont.end();it++)
    {
        c[*it]=i++;
        cout<<*it<<setw(7);
    }
    cout<<endl;
    int m,n;
    m=gm.size();
    n=i;
    
    
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            table[i][j]=0;
        }
    }

    for(i=0;i<gm.size();i++)
    {   
        int gifl=0;
        for(j=0;j<gm[i].second.size();j++)
        {
            for(int li=0;li<gm[i].second[j].size();li++)
            {
                if(!(gm[i].second[j][li]>=65&&gm[i].second[j][li]<=90))
                {
                    string sdd="";
                    sdd=sdd+gm[i].second[j][li];
                    if(sdd.compare("@")==0)
                    {
                        gifl=1;
                        break;
                    }
                    table[r[gm[i].first]][c[sdd]]=rprod[gm[i].first+"->"+gm[i].second[j]];
                    break;
                }
                else
                {
                    int ifl=0;
                    string sdd="";
                    sdd=sdd+gm[i].second[j][li];
                    vector <string> tfirst=first_nt[sdd];
                    for(int li1=0;li1<tfirst.size();li1++)
                    {
                        //cout<<gm[i].first<<" "<<gm[i].second[j]<<" "<<tfirst[li1]<<endl;
                        if(tfirst[li1].compare("@")==0)
                        {
                            ifl=1;
                            gifl=1;
                            continue;    
                        }
                        table[r[gm[i].first]][c[tfirst[li1]]]=rprod[gm[i].first+"->"+gm[i].second[j]];
                    }
                    if(ifl==0)
                    {
                        break;
                    }
                }
            }
        }
        if(gifl==1)
        {
            vector <string> tfirst=follow_nt[gm[i].first];
            for(int li1=0;li1<tfirst.size();li1++)
            {
                table[r[gm[i].first]][c[tfirst[li1]]]=rprod[gm[i].first+"->@"];
            }
        }
    }
    for(i=0;i<m;i++)
    {
        cout<<std::left<<gm[i].first<<setw(7);
        for(j=0;j<n;j++)
        {
            if(table[i][j]==0)
            {
                cout<<"0"<<setw(7);
            }
            else
            {
                cout<<prod[table[i][j]]<<setw(7);
            }
        }
        cout<<endl;
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
