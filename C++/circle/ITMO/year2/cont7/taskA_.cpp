#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mp make_pair
#define pw2(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()

#define fi first
#define se second
#define th third

#define ins insert
#define pb push_back
#define eb emplace_back

#define fr(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define wrvec(a) for (int i = 0; i < (a).size(); i ++) cout << (a)[i] << " "; cout << endl;
#define revfr(i, n) for(int (i) = int(n) - 1; (i) >= 0; i --)

//#define int int64_t // int -> long long

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
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int> > vii;
typedef set<int> si;
typedef set<pii> sii;

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

int logn = 1;

template<typename type>

type next()
{type x; cin >> x; return x;}

ll next()
{ll x; cin >> x; return x;}

int n, k;
vector<vector<int>> g, new_g, rev_g;
vector<int> p;
vector<bool> used;
vector<int> h;
vector<int> cnt;
vector<pii> rib;
map<pii, int> rib_id;
vector<int> ans;

void make_logn(int n){
    int p = 1;
    for (int i = 1; i <= 21; i ++){
        p *= 2;
        if (n > p){
            logn = i;
        }
    }
}

int fast_pow(int a, int k){
    if (k == 0) return 1;
    if (k == 1) return a;
    if (k % 2 == 0) return pw2(fast_pow(a, k / 2));
    else return a * pw2(fast_pow(a, k / 2));
}

void dfs(int st = 0, int from = -1, int level = 0){
    h[st] = level;
    used[st] = true;
    for (int v: g[st]){
        if (!used[v]){
            new_g[st].pb(v);
            rev_g[v].pb(st);
            p[v] = st;
            dfs(v, st, level + 1);
        }
    }
}

inline void inzializate(int n){
    g.resize(n);
    new_g.resize(n);
    rev_g.resize(n);
    h.resize(n);
    p.resize(n);
    used.resize(n, false);
    cnt.resize(n);
    ans.resize(n);
}

int ans_dfs(int st = 0, int from = -1){
    int d = 0;
    for (int v: g[st]){
        d += ans_dfs(v, st);
    }
    d += cnt[st];
    if (from != - 1 && d != 0){
        int id = rib_id[mp(st, from)];
        ans[id] = d;
    }
    return d;
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

    cin >> n;
    make_logn(n);
    inzializate(n);

    for (int i = 0; i < n - 1; i ++){
        int u = next() - 1, v = next() - 1;
        g[u].pb(v);
        g[v].pb(u);
        rib_id[mp(u, v)] = i;
        rib_id[mp(v, u)] = i;
        rib.pb(mp(u, v));
    }

    dfs();
    g = new_g;
    used.clear();
    used.resize(n, false);

    vector<vector<int> > help(logn + 1, vector<int>(n, 0 )); // 2 up method

    for (int i = 0; i < n; i ++){
        help[0][i] = p[i];
    }

    for (int j = 1; j <= logn; j ++){
        for (int i = 0; i < n; i ++){
            help[j][i] = help[j - 1][help[j - 1][i]];
        }
    }

    cin >> k;
    for (int i = 0; i < k; i ++){
        int u = next() - 1, v = next() - 1;
        int a = u, b = v;

        cnt[u] ++;
        cnt[v] ++;
        int lca;

        if (h[u] < h[v]) swap(u, v);
        int len = h[u] - h[v];

        for (int j = logn; j >= 0; j --){
            if (len >= fast_pow(2, j)){
                len -= fast_pow(2, j);
                u = help[j][u];
            }
        }

        if (u == v){
            lca = u;
        }
        else {
            for (int j = logn; j >= 0; j --){
                if (help[j][u] != help[j][v]){
                    u = help[j][u];
                    v = help[j][v];
                }
            }
            u = p[u];
            v = p[v];
            lca = u;
        }

//        watch(a);
//        watch(b);
//        watch(lca);
        cnt[lca] -= 2;

    }

    ans_dfs();
    for (int i = 0; i < n - 1; i ++){
        cout << ans[i] << " ";
    }
}
/*




*/

