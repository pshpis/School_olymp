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

vector<int> parent;
vector<int> r;

inline void make_set(int v){
    parent[v] = v;
    r[v] = 0;
}

int find_set(int v){
    if (parent[v] == v) return v;
    else return parent[v] = find_set(parent[v]);
}

inline void merge_set(int a, int b){
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

    vector<pair<int, pair<int, int> > > edges;
    int n = next();
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++){
            int w = next();
            if (i >= j) continue;
            edges.pb(mp(w, mp(i, j)));
        }

    for (int i = 0; i < n; i ++){
        int w = next();
        edges.pb(mp(w, mp(i, n)));
    }

    sort(all(edges));

    parent.resize(n + 1);
    r.resize(n + 1);

    for (int i = 0; i < n + 1; i ++){
        make_set(i);
    }

    int sum = 0;
    for (auto v: edges){
        int w = v.fi;
        int a = v.se.fi, b = v.se.se;
        if (find_set(a) == find_set(b)) continue;
        merge_set(a, b);
        sum += w;
    }

    cout << sum;
}
/*




*/

