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
    multiset<lint> a;
    lint n=next();
    for (int i=0; i<n; i++)
    {
        lint x=next();
        a.insert(x);
    }
    while (*a.begin()!=*(--a.end()))
    {
        lint mn=*a.begin(), mx=*(--a.end());
        a.erase(a.begin());
        a.erase(--a.end());
        a.insert(mx-mn);
    }
    cout<<*a.begin();
}
