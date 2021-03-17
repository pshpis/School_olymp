#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n , k;
    cin >> n >> k;
    vector <ll> dp(n);
    dp[0] = 1;
    if (n == 1){
        cout << 2;
        return 0;
    }

    for (int i = 1; i < k && i < n; i ++){
        dp[i] = dp[i - 1]*2 % MOD;
    }

    for (int i = 1; i < k && i < n; i ++){
        dp[i] += dp[i - 1];
        dp[i] %= MOD;
    }


    for (int i = k; i < n; i ++){
        dp[i] = dp[i - 1];
        if (i - k - 1 >= 0) dp[i] -= dp[i - k - 1];
        while(dp[i] < 0) dp[i] += MOD;

        dp[i] += dp[i - 1];
        dp[i] %= MOD;
    }

    /*cout << dp[0]*2 << ' ';
    for (int i = 1; i <n; i ++){
        cout << 2*(dp[i] - dp[i - 1]) << ' ';
    } cout << '\n';*/

    ll ans = dp[n - 1] - dp[n - 2];
    while(ans < 0) ans += MOD;
    cout << (ans)*2 % MOD;
}
/*



*/
