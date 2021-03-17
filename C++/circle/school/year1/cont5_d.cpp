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
    vector<bool> a;
    for (int i=0; i<n; i++)
    {
       bool x;
       cin>>x;
       a.pb(x);
    }
    int last_bad=-100;
    int ans=0;
    for (int i=0; i<n; i++)
    {
        if (i>0 && i<n-1)
        {
            if (a[i-1] && a[i+1] && !a[i])
            {
                a[i+1]=false;
                ans++;
            }
        }
    }
    //watch(last_bad);
    cout<<ans;
}
