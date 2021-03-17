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
    int n=next(), Max_p=next();
    vector<int> p(Max_p+1);
    for (int i=0; i<n; i++)
    {
        int x=next()-1;
        p[x]++;
    }
    int m=next();
    for (int i=0; i<m; i++)
    {
        char q;
        cin>>q;
        int x=next()-1;
        if (q=='?')
            cout<<p[x]<<endl;
        else
        {
            p[x+1]+=p[x];
            p[x]=0;
        }
    }
}
