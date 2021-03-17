#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

#define watch(x) cout << (#x) << " is " << (x) << endl

typedef long long lint;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    cout.precision(10);
    int n=next(), s=next();
    map<int, int> circ;
    for (int i=0; i<n; i++)
    {
        int x=next(), y=next(), dist=x*x+y*y, k=next();
        circ[dist]+=k;
    }
    int ans=-1;
    for (auto a: circ)
    {
        int dist=a.first, p=a.second;
        s+=p;
        if (s>=1e6)
        {
            ans=dist;
            cout<<sqrt(ans);
            return 0;
        }
    }
    cout<<ans;
}

