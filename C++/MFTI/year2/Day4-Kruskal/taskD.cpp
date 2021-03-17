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

template<typename type>

type next()
{type x; cin >> x; return x;}

ll next()
{ll x; cin >> x; return x;}

vector<vector<pii> > g;

vector<int> parent, r;

void make_set(int v){
    r[v] = 0;
    parent[v] = v;
}

int find_set(int v){
    if (parent[v] == v) return v;
    else return parent[v] = find_set(parent[v]);
}

void merge_set(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if (a == b) return;
    if (r[b] > r[a]) swap(a, b);
    if (r[a] == r[b]) r[a] ++;
    parent[b] = a;
}

vector<pii> p;
vector<bool> used;

void dfs(int st){
    used[st] = true;
    for (pii v: g[st]){
        if (used[v.fi]) continue;
        p[v.fi] = mp(st, v.se);
        dfs(v.fi);
    }
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

    int n = next(), m = next(), k = next();
    vector< pair<int, pii> > edge;

    for (int i = 0; i < m; i ++){
        int a = next() - 1, b = next() - 1, w = -next();
        edge.pb(mp(w, mp(a, b)));
    }

    parent.resize(n + 1);
    r.resize(n + 1);
    g.resize(n);

    for  (int i = 0; i < n; i ++) make_set(i);

//    cout << "HERE" << endl;
    sort(all(edge));

    for (int i = 0; i < m; i ++){
        int w = edge[i].fi, a = edge[i].se.fi, b = edge[i].se.se;
        if (find_set(a) == find_set(b)) continue;
        g[a].pb(mp(b, w));
        g[b].pb(mp(a, w));
        merge_set(a, b);
    }

//    cout << "HERE" << endl;
    for (int i = 0; i < k; i ++){
        int a = next() - 1, b = next() - 1;
        used.assign(n, false);
        p.clear();
        p.resize(n);
        dfs(a);
        int min_w = -1e9;
        while (p[b].fi != a){
            min_w = max(min_w, p[b].se);
            b = p[b].fi;
        }
        min_w = max(min_w, p[b].se);
        cout << -min_w << "\n";
    }
}
/*




*/

