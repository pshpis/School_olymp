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
const int max_pw = 20;

const int logn = 20;

template<typename type>

type next()
{type x; cin >> x; return x;}

ll next()
{ll x; cin >> x; return x;}

int fast_pow(int a, int k){
    if (k == 0) return 1;
    if (k == 1) return a;
    if (k % 2 == 0) return pw2(fast_pow(a, k / 2));
    else return pw2(fast_pow(a, k / 2)) * a;
}

int n;
vector<vector<int> > g, gr;
vector<vector<int> > lca;
vector<bool> used;
vector<int> d;
vector<int> p;
vector<pii> rib;
map<pii, int> rib_id;

vector<bool> start, finish;

void dfs(int st, int level = 0, int from = -1){
    used[st] = true;
    d[st] = level;
    p[st] = from;
    for (int v: g[st]){
        if (!used[v]){
            gr[st].pb(v);
            dfs(v, level + 1, st);
        }
    }
}

bool is_cnt = false;

void dfs(int st){
    if (is_cnt && finish[st]) is_cnt = false;
    if (!is_cnt && s)
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
    g.resize(n);
    gr.resize(n);
    p.resize(n);
    used.assign(n, false);
    start.assign(n, false);
    finish.assign(n, false);
    d.resize(n);
    lca.resize(max_pw + 1, vector<int>(n));

    for (int i = 0; i < n - 1; i ++){
        int u = next() - 1, v  = next() - 1;
        rib.pb(mp(u, v));
        g[u].pb(v);
        g[v].pb(u);
        rib_id[mp(u, v)] = i;
        rib_id[mp(v, u)] = i;
    }

    dfs(0);
    g = gr;

    for (int i = 0; i < n; i ++)
        lca[0][i] = p[i];

    for (int i = 1; i <= max_pw; i ++){
        for (int j = 0; j < n; j ++){
            lca[i][j] = lca[i - 1][lca[i - 1][j]];
        }
    }


    int k = next();
    for (int i = 0; i < k; i ++){
        int a = next() - 1, b = next() - 1;
        finish[a] = true;
        finish[b] = true;

        if (d[a] < d[b]) swap(a, b);

        int len = d[a] - d[b];
        for (int j = max_pw; j >= 0; j --){
            if (len >= fast_pow(2, j)){
                len -= fast_pow(2, j);
                a = lca[j][a];
            }
        }

        if (a == b){
            start[a] = true;
            continue;
        }

        for (int j = max_pw; j >= 0; j --){
            if (lca[j][a] != lca[j][b]){
                a = lca[j][a];
                b = lca[j][b];
            }
        }

        start[p[a]] = true;
    }

}
/*




*/

