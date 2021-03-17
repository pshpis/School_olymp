#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pw2(x) ((x)*(x))
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
    lint n=next(), k1=next(), k2=next();
    vector<lint> a, b;
    multiset<lint> raz;
    for (int i=0; i<n; i++)
        a.pb(next());
    for (int i=0; i<n; i++)
        b.pb(next());
    for (int i=0; i<n; i++)
        raz.insert(abs(a[i]-b[i]));
    lint sum=k1+k2;
    //watch(sum);
    while (sum>0)
    {
        auto it=raz.end();
        it--;
        //if (*it==0) break;
        raz.erase(it);
        raz.insert(abs(*it-1));
        sum--;
    }
    lint ans=0;
    for (lint x: raz)
        ans+=x*x;
    cout<<ans;
}

