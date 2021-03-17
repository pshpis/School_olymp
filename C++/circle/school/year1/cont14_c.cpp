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
#define fr(i, n) for (int (i)=0; i<int(n); i++)

const bool isDbg=false;

typedef long long lint;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    lint n=lnext();
    map<lint, lint> x, y;
    set<pair<lint, lint> > pl;
    for (lint i=0; i<n; ++i){
        lint f=lnext() ,s=lnext();
        x[s]++;
        y[f]++;
        pl.insert({f, s});
    }
    lint ans=0;
    for (auto val: x)
        ans+=val.second*(val.second-1)/2;
    for (auto val: y)
        ans+=val.second*(val.second-1)/2;
    lint m=n-pl.size();
    ans-=m*(m-1)/2;
    cout<<ans;
}
