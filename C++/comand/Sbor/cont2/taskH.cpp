#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

const ll MOD = 1e9 +7;

ll fast_pow(ll x, ll y){
    if (y == 0) return 1;
    if (y % 2 == 0) return pw2(fast_pow(x, y / 2)) % MOD;
    return (( pw2(fast_pow(x, y / 2)) % MOD) * x) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    cout << fast_pow(3, n) + 1;
}
/*



*/

