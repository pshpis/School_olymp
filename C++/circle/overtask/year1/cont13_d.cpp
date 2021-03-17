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

int main()
{
    ios::sync_with_stdio(false);
    int n=next();
    vector<int> el;
    vector<lint> pref(n, 0);
    map<lint, int> suf;
    for (int i=0; i<n; i++)
    {
        int x=next();
        el.pb(x);
    }
    pref[0]=el[0];
    for (int i=1;i<n; i++)
        pref[i]=pref[i-1]+el[i];
    lint obr_sum=0;
    for (int i=n-1; i>=0; i--)
    {
        obr_sum+=el[i];
        suf[obr_sum]=i+1;
    }
    lint ans=0;
    for (int i=0; i<n; i++)
    {
        lint key=pref[i];
        if (suf[key]==0) continue;
        lint suf_i=suf[key]-1;
        if (suf_i>i) ans=max(ans, key);
    }
    cout<<ans;
}

