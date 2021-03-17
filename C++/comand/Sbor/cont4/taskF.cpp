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

ll n, p, w, d;

ll fast_pow(ll a, ll pw){
    if (pw == 0) return 1;
    if (pw % 2 == 0){
        ll ans = fast_pow(a, pw/2);
        return ans * ans % d;
    }
    if (pw % 2 == 1){
        ll ans = fast_pow(a, pw/2);
        return ((ans * ans) % d) * a % d;
    }
}

vector<ll> ans;

bool solve(){
    ans.clear();
    ll gcd_pwd = __gcd(p, __gcd(w, d));
    p/= gcd_pwd;
    w/= gcd_pwd;
    d/= gcd_pwd;

    if (d == 1){
        ll x0 = p / w;
        ll y0 = p - x0 * w;
        if (x0 + y0 > n ) return false;
        else{
            ans.pb(x0);
            ans.pb(y0);
            ans.pb(n - x0 - y0);
            return true;
        }
    }

    if (__gcd(w, d) > 1){
        return false;
    }

    ll eul_d = 0;
    for (ll i = 1; i < d; i++)
        if (__gcd(d, i) == 1) eul_d++;

    ll x0 = 0, mn = p / 1e12, step = fast_pow(w, eul_d - 1);
    for (ll i = 0; i < mn; i++){
        x0 = (((ll)1e12 % d) * step % d + x0) % d;
    }
    x0 = (((p % (ll)1e12) % d) * step % d + x0) % d;
    ll y0 = (p - w * x0) / d;

    if (x0 + y0 <= n){
        ans.pb(x0);
        ans.pb(y0);
        ans.pb(n - y0 - x0);
        return true;
    }

    ll k = y0 / w, l = (x0 + y0 - n - d - 1 + w) / (w - d);

    if (l > k){
        return false;
    }
    else{
        ll x = x0 + k * d, y = y0 - k * w;
        ans.pb(x);
        ans.pb(y);
        ans.pb(n - x - y);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

//    w = 3;
//    d = 1;
//
//    for (n = 0; n <= 10000; n ++){
//        for (p = 0; p <= n * w; p ++){
//            if (solve()){
//                ll cnt = ans[0] * w + ans[1] * d;
//                if (ans[0] < 0 || ans[1] < 0 || ans[2] < 0){
//                    cout << "EXT-------EXT" << endl;
//                    watch(ans[0]);
//                    watch(ans[1]);
//                    watch(ans[2]);
//                    cout << "EXT-------EXT" << endl;
//                }
//                if (cnt != p){
//                    watch(n);
//                    watch(p);
//                    watch(w);
//                    watch(d);
//                    cout << "--------" << endl;
//                    watch(cnt);
//                    cout << "---------------------------" << endl << endl;
//                }
//            }
//        }
//    }
    cin >> n >> p >> w >> d;
    if (solve()){
        cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    }
    else cout << -1 << "\n";
}
/*



*/
