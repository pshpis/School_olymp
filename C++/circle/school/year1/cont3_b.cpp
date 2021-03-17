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
    int a=next(), b=next(), c=next();
    int ans=min3(a, b, c);
    a-=ans;
    b-=ans;
    c-=ans;
    if ( (a>0 && b>0) || (a>0 && c>0) || (c>0 && b>0))
    {
        ans+=min(((a+b+c)/3), min(a, b));
    }
    cout<<ans;
}

