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

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    int n; cin >> n;
    ll m; cin >> m;
    vector <ll> a(n);
    set<ll> p;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        if (i > 0) a[i] += a[i - 1];
        a[i] %= m;
    }
    ll ans = 0;

    for (int i = 0; i < n; i ++){
        auto it = p.upper_bound(a[i]);
        ans = max(ans , a[i]);
        if (it != p.end()){
            ll d = *it;
            ll cur = (a[i] - d) % m;
            while(cur < 0) cur += m;
            ans = max(ans , cur);
        }
        p.insert(a[i]);
    }
    cout << ans;


}
/*
4 3
3 4 5 3

4 3
4 4 4 4



*/
