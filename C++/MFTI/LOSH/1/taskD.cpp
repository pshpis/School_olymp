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

const lint mod = 1e9+7;

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

lint c(lint n, lint k, vector<lint>& fact, vector<lint>& rev_fact){
    if (k>n) return 0;
    lint ans=(((fact[n]*rev_fact[k])%mod)*rev_fact[n-k])%mod;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    lint n=lnext(), m=lnext(), l=lnext();
    vector<lint> fact(n+1, 0), rev_fact(n+1, 0);
    fact[0]=1;
    rev_fact[0]=1;
    for (int i=1; i<=n; i++){
        fact[i]=(fact[i-1]*i)%mod;
        rev_fact[i]=binpow(fact[i], mod-2);
    }
    lint ans=0;
    for (lint k=1; k<=l; k++){
        ans+=c(n, m*k, fact, rev_fact);
        ans%=mod;
    }
    cout<<ans;
}

