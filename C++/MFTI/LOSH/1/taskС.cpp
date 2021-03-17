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

const lint mod=1e9+9;

lint binpow(lint a, lint n){
    if (n == 0)
		return 1;
	if (n % 2 == 1)
		return (binpow (a, n-1) * a)%mod;
	else {
		lint b = binpow (a, n/2);
		return (b * b)%mod;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    lint n=lnext();
    lint e_f=mod-1;
//    watch(e_f);
    for (int i=0; i<n; i++){
        lint a=lnext();
        cout<<(lint)binpow(a, e_f-1)<<endl;
    }
}
