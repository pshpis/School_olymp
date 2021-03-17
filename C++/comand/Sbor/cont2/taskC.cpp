#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll x , y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }

/*    vector < vector <ll> > dp(n , vector <ll> (2));
    dp[n - 1][0] = abs(a[n - 1] - y);
    dp[n - 1][1] = abs(a[n - 1] - x);

    for (int i = n - 2; i >= 0; i --){
        dp[i][0] = -1 , dp[i][1] = 1e18;
        for (int j = i + 1; j < n; j ++){
            dp[i][0] = max(dp[i][0] , min(dp[j][1] , abs(a[j - 1] - a.back())));
            dp[i][1] = min(dp[i][0] , max(dp[j][1] , abs(a[j - 1] - a.back())));
        }
    }

    cout << dp[0][0] << '\n';

    cout << max(dp[0][0] , abs(y - a.back()));
*/

    if (n == 1) cout << abs(y - a.back());
    else cout << max(abs(y - a.back()) , abs(a[n - 1] - a[n - 2]));
}
/*
3 3 3
1 10 1


2 7 10
5 1

3 3 2
4 6 10


*/
