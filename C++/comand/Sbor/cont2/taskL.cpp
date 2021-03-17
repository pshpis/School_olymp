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

ll solve1(ll n , ll k){
//    ll n, k;
//    cin >> n >> k;

    if (k ==  1){
        return 2;
        //return 0;
    }
    vector<ll> dp;

    for (int i = 0; i <= k && i <= n; ++ i){
        dp.pb(fast_pow(2, i));
    }

    for (int i = k + 1; i <= n; ++ i){
        dp.pb( (2 * dp[i - 1] - 2 * dp[i - k - 1]) % MOD ) ;
    }

    return dp.back();
}

ll solve2(ll n , ll k){
    vector <ll> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i ++){
        dp[i] = dp[i - 1];
        if (i - k >= 0) dp[i] -= dp[i - k];

        dp[i] += dp[i - 1];
        dp[i] %= MOD;
    }

    return dp[n - 1]*2 % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int n = 1; n < 10; n ++){
        for (int k = 1; k < 10; k ++){
            if (solve1(n , k) != solve2(n ,k)){
                cout << n << ' ' << k << '\n';
                cout << solve1(n , k) << ' ' << solve2(n ,k) << "\n------------\n";
            }
        }
    }
}
/*



*/

