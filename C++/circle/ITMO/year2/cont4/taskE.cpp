#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)
#define fi first
#define se second

//#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;

const int INF=2e9;
const ll INF64=1e18;
const double PI=3.14159265359;
const double EPS=1e-9;
const int MOD=1e9+7;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

ll lnext()
{ll x;cin>>x;return x;}

vector<unordered_set<int> > gr;
vector<int> help;
vector<int> child;
vector<bool> used;
vector<int> comp;
vector<pii> rib;
vector<int> comp_size;

int n, m;

void read_gr(){
    cin >> n >> m;
    gr = vector<unordered_set<int> >(n);
    comp = vector<int>(n);
    used = vector<bool>(n, false);
    child = vector<int>(n, 0);

    for (int i = 0; i < m; ++ i){
        int x = next() - 1, y = next() - 1;
        rib.pb(mp(x, y));
        gr[x].insert(y);
        gr[y].insert(x);
    }
}

void dfs(int st){
    used[st] = true;
    help.pb(st);
    for (int v: gr[st]){
        if (used[v]) continue;
        dfs(v);
        child[st] += child[v] + 1;
        gr[v].erase(st);
    }
}

void test(){
    int e = next() - 1;
    int x = rib[e].fi, y = rib[e].se;
    if (gr[x].count(y) == 0) swap(x, y);
    int c = comp[y];
    int sz = comp_size[c];
//    watch(x);
//    watch(y);
//    watch(c);
//    watch(sz);
//    watch(child[y]);
    ll ans = (ll)(child[y] + 1) * (sz - child[y] - 1);
    cout << ans << endl;

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

    read_gr();

    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        if (used[i]) continue;
        help.clear();
        dfs(i);

        int sz = 0;
        for (int v: help){
            comp[v] = cnt;
            ++ sz;
        }

        comp_size.pb(sz);
        ++ cnt;
    }

    int q = next();
    for (int i = 0; i < q; ++ i){
        test();
    }
}
/*




*/

