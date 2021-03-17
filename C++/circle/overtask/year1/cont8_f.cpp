#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

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

int main()
{
    ios::sync_with_stdio(false);
    int n=next(), m=next(), q=next();
    string s;
    cin>>s;
    string t;
    cin>>t;
    set<int> into;
    for (int i=0; i<n-m+1; i++)
    {
        string x="";
        for (int j=0; j<m; j++)
        {
            x+=s[i+j];
        }
        if (x==t) into.insert(i);
    }
    vector<int> mask;
    int ev=0;
    for (int i=0; i<n; i++)
    {
        if (into.count(i)>0) ev++;
        mask.pb(ev);
    }

    for (int i=0; i<q; i++)
    {
        int l=next()-1, r=next()-1;
        int ans=0;
        int last=-1;
        for (int j=l; j<=r-m+1; j++)
            if (j!=0 && mask[j]!=mask[j-1]) ans++;
            else
            if (j==0 && mask[j]==1) ans++;
        cout<<ans<<"\n";
    }
}
