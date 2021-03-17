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

lint nod(lint x, lint y)
{
	if (y==0 || x == 0)
		return x + y;
	return nod(y, x%y);
}

lint nok(lint x, lint y)
{
    lint ans=x*y/nod(x, y);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int n=next();
    for (int i=0; i<n; i++)
    {
        int ang=next();
        int g=nod(180, ang);
        int res=180/g;
        if (ang/g==res-1) res*=2;
        cout<<res<<"\n";

    }
}

