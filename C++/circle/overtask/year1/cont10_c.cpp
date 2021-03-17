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

lint res1=0, res2=0;

int main()
{
    ios::sync_with_stdio(false);
    int n=next(), m=next();
    res1+=min(n/2*2, m/2*2)-1;
    res2+=min(n/2*2, m/2*2);
    int n1=n, m1=m;
    n-=min(n1/2*2, m1/2*2);
    m-=min(n1/2*2, m1/2*2);
    res1+=max(n, m);
    if (min(n, m)==1) res2+=1;
    cout<<res1<<" "<<res2;

}

