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

struct SNM{
    vector<int> parent;
    vector<int> sz;

    SNM(int n){
        parent.resize(n);
        sz.resize(n);
    }

    void make_set(int a){
        parent[a] = a;
        sz[a] = 1;
    }

    int find_set(int a){
        if (parent[a] == a) return a;
        return parent[a] = find_set(parent[a]);
    }

    void merge_set(int a, int b){
        a = find_set(a);
        b = find_set(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        parent[b] = a;
    }

    int set_size(int a){
        return sz[find_set(a)];
    }

    bool together(int a, int b){
        return (find_set(a) == find_set(b));
    }

};

int n, m, k;
vector<unordered_set<int> > g;

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

    cin >> n >> m >> k;
    g.resize(n);
    SNM rail(n);
    for (int i = 0; i < n; i ++){
        rail.make_set(i);
    }

    for (int i = 0; i < m; i ++){
        int u = next() - 1, v = next() - 1;
        g[u].insert(v);
        g[v].insert(u);
    }

    vector<int> ans(n, 0);

    for (int i = 0; i < k; i ++){
        int u = next() - 1, v = next() - 1;
        if (!rail.together(u, v)){
            rail.merge_set(u, v);
            if (g[u].count(v) > 0){
                ans[u] ++;
                ans[v] ++;
            }
        }
    }

    int q = next();
    for (int i = 0; i <  q; i ++){
        char c;
        cin >> c;
        if (c == 'T'){
            int u = next() - 1, v = next() - 1;
            if (!rail.together(u, v)){
                rail.merge_set(u, v);
                if (g[u].count(v) > 0){
                    ans[u] ++;
                    ans[v] ++;
                }
            }
        }
        if (c == 'F'){
            int u = next() - 1, v = next() - 1;
            if (rail.together(u, v)){
                ans[u] ++;
                ans[v] ++;
            }
            g[u].insert(v);
            g[v].insert(u);
        }
        if (c == '?'){
            int u = next() - 1;
            cout << ans[u] << "\n";
        }
    }

}
/*




*/

