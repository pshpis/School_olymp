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
    lint n=lnext(), m=lnext();
    if (m>=n)
    {
        cout<<n;
        return 0;
    }
    n=n-m;
    lint left=0, right=2e9;
    while (left<right)
    {
        lint mid=(right+left)/2;
        if (mid*(mid+1)/2>=n)
        {
            right=mid;
        }
        else left=mid+1;
    }
    cout<<left+m;
}
