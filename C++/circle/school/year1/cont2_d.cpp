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

int mx_num(int x)
{
    int mx=-1;
    while (x>0)
    {
        mx=max(mx, x%10);
        x/=10;
    }
    return mx;
}
int main()
{
    ios::sync_with_stdio(false);
    int x=next();
    int ans=0;
    while (x>0)
    {
        //watch(x);
        x-=mx_num(x);
        //watch(mx_num(x));
        //watch(x);
        ans++;
    }
    cout<<ans;
}

