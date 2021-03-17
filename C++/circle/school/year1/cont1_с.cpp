#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

#define watch(x) cout << (#x) << " is " << (x) << endl

typedef long long lint;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

const int inf=1e9+1;
string s;
set<int> str;
int n;
vector<int> pl;

void fill_set()
{
    for (int i=0; i<n; i++)
        str.insert(i);
}

void del_2m(string s)
{
    for (int i=0; i<n-1; i++)
    {
        if (s[i]=='-' && s[i+1]=='-')
        {
            pl.push_back(i);
            str.erase(i);
            str.erase(i+1);
            i++;
        }
    }
}

string watch_set()
{
    string ans="";
    for (auto a:str)
        ans+=s[a];
    //watch(ans);
    return ans;
}

string count_no2(string f)
{
    string ans="";
    for (int i=0; i<f.size(); i++)
    {
        if (f[i]=='.') ans+="0";
        else
        {
            ans+="1";
            i++;
        }
    }
    //watch(ans);
    return ans;
}

string comb(string f)
{
    string ans="";
    pl.push_back(inf);
    int dist=0, j=0;
    for (int i=0; i<f.size(); i++)
    {
        while (dist==pl[j])
        {
            dist+=2;
            ans+="2";
            j++;
            //pl_set.erase(pl[j]);
        }

        int d=1;
        if (f[i]=='1') d++;
        ans+=f[i];
        dist+=d;
    }
    if (dist<s.size())
        for (int i=0; i<(s.size()-dist)/2; i++)
            ans+="2";
    return ans;
}

int main()
{
    cin>>s;
    n=s.size();
    fill_set();
    del_2m(s);
    cout<<comb(count_no2(watch_set()));
}

