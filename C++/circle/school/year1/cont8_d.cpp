#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

typedef long long lint;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

void step(string& x)
{
    string ans="";
    for (int i=1; i<x.size(); i++)
        ans+=x[i];
    ans+=x[0];
    x=ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int n=next();
    vector<string> str;
    for (int i=0; i<n; i++)
    {
        string x;
        cin>>x;
        str.pb(x);
    }
    vector<string> save_str=str;
    int global_ans=1e9+7;
    for (int i=0; i<n; i++)
    {
        int ans=0;
        bool fl=false;
        for (int j=0; j<n; j++)
        {
            int ans_=0;
            while (str[j]!=str[i])
            {
                ans_++;
                step(str[j]);
                if (ans_>str[j].size())
                {
                    cout<<-1;
                    return 0;
                }
            }
            ans+=ans_;
        }
        str=save_str;
        global_ans=min(global_ans, ans);
    }
    cout<<global_ans;
}

