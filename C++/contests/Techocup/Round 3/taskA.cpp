#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++ i)
#define fi first
#define se second
#define ins insert

//#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

template<typename type>

type next()
{type x; cin >> x; return x;}

int next()
{int x; cin >> x; return x;}

ll lnext()
{ll x; cin >> x; return x;}

int solve1(const vector<pii>& a){
    int n = a.size();
    pii ans;
    int d = 0;
    for (int i = 0; i < n - 1; i ++){
        if (i == 0){
            int l = a[i].fi, r = a[i].se;
            int l_ = a[i + 1].fi, r_ = a[i + 1].se;
            if (l == l_) ans = mp(min(r, r_), min(r, r_));
            else if (r == r_) ans = mp(r, r_);
            else if (l <= l_ && r >= r_) ans = mp(r_, r_);
            else if (l_ >= r) ans = mp(r, l_);
            else ans = mp(r, r);
            d = ans.second - ans.first;
            continue;
        }
        int l = a[i + 1].fi;
        int r = a[i + 1].se;
        if ( (l <= ans.second && l >= ans.first) || (r <= ans.second && r >= ans.first)) continue;
        if (l < ans.first && r > ans.second) continue;
        if (l > ans.second) ans.second = l;
        else if (r < ans.first) ans.first = r;
        d = ans.second - ans.first;
    }
    return d;
}

int solve2(const vector<pii>& a){
    int n = a.size();
    pii ans;
    int d = 0;
    for (int i = 0; i < n - 1; i ++){
        if (i == 0){
            int l = a[i].se;
            int r = a[i + 1].fi;
            if (l >= r) ans = mp(r, r);
            else ans = mp(l, r), d = r - l;
            continue;
        }
        int l = a[i + 1].fi;
        int r = a[i + 1].se;
        if ( (l <= ans.second && l >= ans.first) || (r <= ans.second && r >= ans.first)) continue;
        if (l < ans.first && r > ans.second) continue;
        if (l > ans.second) ans.second = l;
        else if (r < ans.first) ans.first = r;
        d = ans.second - ans.first;
    }
    return d;
}

int solve3(const vector<pii>& a){
    int n = a.size();
    pii ans;
    int d = 0;
    for (int i = 0; i < n - 1; i ++){
        if (i == 0){
            int l = a[i].se;
            int r = a[i + 1].fi;
            if (l >= r) ans = mp(a[i + 1].se, a[i + 1].se);
            else ans = mp(l, r), d = r - l;
            continue;
        }
        int l = a[i + 1].fi;
        int r = a[i + 1].se;
        if ( (l <= ans.second && l >= ans.first) || (r <= ans.second && r >= ans.first)) continue;
        if (l < ans.first && r > ans.second) continue;
        if (l > ans.second) ans.second = l;
        else if (r < ans.first) ans.first = r;
        d = ans.second - ans.first;
    }
    return d;
}

void solve(){
    int n = next();
    vector<pii> a;
    for (int i = 0; i < n; i ++){
        int l = next(), r = next();
        a.pb(mp(l, r));
    }
    sort(a.begin(), a.end());

    cout << solve1(a) << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out

    int q = next();
    for (int i = 0; i < q; i ++)
        solve();


}
/*

4
1 20
2 19
3 18
4 17


*/

