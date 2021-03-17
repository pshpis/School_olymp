#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

//#define int int64_t

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    int n , k;
    cin >> n >> k;
    vector <ll> a(n) , c(n);
    unordered_map<int , vector <int> > p;

    for (int i = 0; i < n;  i ++){
        cin >> a[i] >> c[i];
        p[a[i]].pb(i);
    }

    ll ans = 0;

    for (int i = 0; i < n; i ++){
        if (p[a[i]].size() <= 1) continue;
        vector <int> cur = p[a[i]];
        p[a[i]].clear();


        vector <ll> cost(cur.size());
        for (int j = 0; j < cur.size(); j ++){
            cost[j] = c[cur[j]];
            if (j > 0) cost[j] += cost[j - 1];
        }

        vector < vector <ll> > dp(cur.size() , vector <ll> (2 , 4e18));
        dp[0][0] = 0;
        dp[0][1] = cost[0];
        for (int j = 1; j < cur.size(); j ++){
            dp[j][1] = min(dp[j - 1][0] , dp[j - 1][1]) + cost[j] - cost[j - 1];

            int pos = lower_bound(cur.begin() , cur.end() , cur[j] - k + 1) - cur.begin();
            pos--;
            if (pos < 0){
                dp[j][0] = cost[j - 1];
                continue;
            }

            dp[j][0] = min(dp[pos][0] , dp[pos][1]) + cost[j - 1] - cost[pos];
        }
        ans += min(dp[cur.size() - 1][0] , dp[cur.size() - 1][1]);
    }

    cout << ans << '\n';

}
/*
3 2
1 1
2 12
1 3



5 3
1 1
2 12
1 3
2 8
1 4


3 3
1 1
2 2
1 3


5 3
1 1
2 12
1 7
2 8
1 4


*/
