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

#define int int64_t // int -> long long

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

int n, m;
vector<vector<int> > gr, rev_gr;
vector<bool> used;
vector<int> order;
vector<int> component;

void dfs1(int st){
    used[st] = true;
    for (int to: gr[st]){
        if (!used[to]) dfs1(to);
    }
    order.pb(st);
}

void dfs2(int st){
    used[st] = true;
    component.pb(st);
    for (int to: rev_gr[st]){
        if (!used[to]) dfs2(to);
    }
}

vector<int> parent, r;

void make_set(int v){
    parent[v] = v;
    r[v] = 0;
}

int find_set(int v){
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
}

void merge_set(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if (a == b) return;
    if (r[a] < r[b]) swap(a, b);
    if (r[a] == r[b]) r[a] ++;
    parent[b] = a;
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

    cin >> n >> m;
    gr.resize(n);
    rev_gr.resize(n);
    used.assign(n, false);

    vector<pair<int, int> > rib;

    parent.resize(n);
    r.resize(n);

    for (int i = 0; i < n; i ++) make_set(i);

    for (int i = 0; i < m; i ++){
        int  a = next() - 1, b = next() - 1;
        gr[a].pb(b);
        rev_gr[b].pb(a);
        rib.pb(mp(a, b));
    }

    for (int i = 0; i < n; i ++){
        if (!used[i]) dfs1(i);
    }

    used.assign(n, false);
    reverse(all(order));

    int sum_sz = 0;

    for (int v: order){
        if (!used[v]){
            dfs2(v);
            if (component.size() == 0) continue;
            int a = component[0];
            for (int i = 1; i < component.size(); i ++) merge_set(a, component[i]);
            component.clear();
        }
    }

    set<pii> need_rib;

    for (auto v: rib){
        int a = v.fi, b = v.se;
        a = find_set(a);
        b = find_set(b);
        if (a < b) swap(a, b);
        if (a != b) need_rib.ins(mp(a, b));
    }

    cout << need_rib.size() << "\n";


}
/*
3 2
1 2
2 3




*/

