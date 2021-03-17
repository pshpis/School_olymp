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
#define fr(i, n) for (int (i)=0; i<int(n); i++)

typedef long long lint;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

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
    lint n=lnext();
    vector<int> is_prime(n+1, 0);
    for(int i=2; i<=n; i++)
        if (is_prime[i]==0)
            for (int j=0; j*i<=n; j++)
                is_prime[i*j]++;
    for (int i=2; i<=n; i++)
        if (is_prime[i]>=3) cout<<i<<' ';


}

