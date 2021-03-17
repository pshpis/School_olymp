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
    int n=next();
    vector<int> a;
    lint sum=0;
    int mn=1e9+1;
    for (int i=0; i<n; i++)
    {
        int x=next();
        if (x>=0) sum+=x;
        if (abs(x%2)==1) mn=min(mn, abs(x));
        a.pb(x);
    }
    if (sum%2==0)
    {
        sum-=mn;
    }
    cout<<sum;
}

