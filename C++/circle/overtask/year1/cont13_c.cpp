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

lint c2(lint k)
{
    return k*(k-1)/2;
}

int main()
{
    ios::sync_with_stdio(false);
    lint n=lnext(), m=lnext();
    lint mn, mx;
    lint L=0, R=n;
    if (m==0)
    {
        cout<<n<<" "<<n<<"\n";
        return 0;
    }
    while (R-L>1)
    {
        lint mid=(R+L)/2;
        if (c2(mid)>m) R=mid;
        if (c2(mid)<m) L=mid;
        if (c2(mid)==m)
        {
            R=mid;
            L=mid-1;
            break;
        }
    }
    mx=n-R;
    mn=max(n-m*2, (lint)0);
    cout<<mn<<" "<<mx<<"\n";

}
