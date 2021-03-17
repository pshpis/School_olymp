#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mp make_pair
#define pw2(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

#define ins insert
#define pb push_back
#define eb emplace_back

//#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[] = "input.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "output.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

template<typename type>

type next()
{type x; cin >> x; return x;}

int next()
{ll x; cin >> x; return x;}

inline void fast_wrie(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out
}

int perebor(multiset<pii>& b, int d){
    set<pii> :: iterator it = b.end();
    it --;
    set<pii> :: iterator fsh = b.begin();
    fsh --;
    int ans = 0;
    int sum = 0;
    while (it != fsh & sum < d){
        auto p = *it;
        sum += p.fi;
        ans ++;
    }
    return ans;
}

void solve(){
    int n = next();
    vi num;
    vi pl;

    vi b_cnt(2);
    for (int i = 0; i < n; i ++){
        int x = next();
        num.pb(x);
        if (x != 0){
            pl.pb(x);
            b_cnt[x % 2] ++;
        }
    }

    vector<pii> a;
    vi cnt(3);
    for (int i = 0; i < pl.size(); i ++){
        if (i == 0){
            if (pl[i] == 0) continue;
            a.pb(mp(pl[i], num[pl[i]] % 2));
            cnt[num[pl[i]] % 2] += pl[i];
            continue;
        }
        if (num[pl[i]] % 2 == num[pl[i - 1]] % 2){
            if (pl[i] - pl[i - 1] - 1 == 0) continue;
            a.pb(mp(pl[i] - pl[i - 1] - 1, num[pl[i]] % 2));
            cnt[num[pl[i]] % 2] += pl[i] - pl[i - 1] - 1;
        }
        else{
            if (pl[i] - pl[i - 1] - 1 == 0) continue;
            a.pb(mp(pl[i] - pl[i - 1] - 1, 2));
            cnt[2] += pl[i] - pl[i - 1] - 1;
        }
    }

    if (n - pl.back() - 1 != 0 ){
        a.eb(n - pl.back() - 1, num[pl.back()] % 2);
        cnt[num[pl.back()] % 2] += n - pl.back() - 1;
    }
    int zn = cnt[1] - cnt[0] + b_cnt[1] - b_cnt[0];
    watch(zn);
    watch(cnt[1]);
    watch(cnt[0]);
    watch(b_cnt[1]);
    watch(b_cnt[0]);
    int d = abs(zn);
    watch(d);
    int ans = 0;
    int sum2 = 0;
    for (auto el: a){
        if (el.se == 2){
            sum2 += el.fi;
            ans ++;
            watch(el.fi);
        }
    }

    watch(sum2);
    watch(d);

    if (sum2 >= d){
        cout << ans << '\n';
        return;
    }
    d -= sum2;
    int need = 0;
    if (zn > 0) need = 1;

    cout << "HERE" << endl;
    multiset<pii> b;
    for (int i = 0; i < a.size(); i ++){
        if (a[i].se == need) b.insert(a[i]);
    }

    bool fl = (a[0].se == need), fl_ = ((a.back()).se == need);
    cout << "HERRREEE" << endl;
    int d_ans = 2 * perebor(b, d);
    if (!fl && !fl_){
        ans += d_ans;
        cout << ans << '\n';
        return;
    }
    if (fl && !fl_){
        int d_ans2 = 1;
        b.erase(b.find(a[0]));
        d -= a[0].fi;
        d_ans2 += 2 * perebor(b, d);
        d += a[0].fi;
        b.insert(a[0]);
        ans += min(d_ans, d_ans2);
        cout << ans << '\n';
        return;
    }
    if (!fl && fl_){
        int d_ans2 = 1;
        b.erase(b.find(a.back()));
        d -= (a.back()).fi;
        d_ans2 += 2 * perebor(b, d);
        d += (a.back()).fi;
        b.insert(a.back());
        ans += min(d_ans, d_ans2);
        cout << ans << '\n';
        return;
    }
    if (fl && fl_){
        int d_ans2 = 1;
        b.erase(b.find(a[0]));
        d -= a[0].fi;
        d_ans2 += 2 * perebor(b, d);
        d += a[0].fi;
        b.insert(a[0]);

        d_ans = min(d_ans, d_ans2);

        int d_ans3 = 1;
        b.erase(b.find(a.back()));
        d -= (a.back()).fi;
        d_ans3 += 2 * perebor(b, d);
        d += (a.back()).fi;
        b.insert(a.back());

        d_ans = min(d_ans, d_ans3);

        int d_ans4 = 2;
        b.erase(b.find(a.back()));
        b.erase(b.find(a[0]));
        d -= (a.back()).fi;
        d -= a[0].fi;
        d_ans4 += 2 * perebor(b, d);
        d_ans = min(d_ans, d_ans4);
        ans += d_ans;
        cout << ans << '\n';
    }
}

int32_t main()
{
    fast_wrie();
    solve();
}
/*




*/

