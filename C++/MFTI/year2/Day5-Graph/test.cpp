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

int n, m;
vector<vector<int> > g;
vector<int> tin, tout;
vector<bool> used;
vector<int> color;
int timer = 0;

void dfs(int st){
    used[st] = true;
    tin[st] = timer ++;
    for (int v: g[st]){
        if (used[v]) continue;
        dfs(v);
    }
    tout[st] = timer ++;
}

bool cmp(int i, int j){
    return tout[i] < tout[j];
}

bool is_cycle(int st){
    color[st] = 1;
    for (int v: g[st]){
        if (color[v] == 1) return false;
        if (color[v] == 0) dfs(v);
    }
    color[st] = 2;
    return true;
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
    g.resize(n);
    tin.assign(n, -1);
    tout.assign(n , -1);
    used.assign(n, false);
    color.assign(n, 0);
    for (int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        a --; b --;
        g[a].pb(b);
    }

    bool is_ans = true;
    for (int i = 0; i < n; i ++)
    if (color[i] == 0){
        if (is_cycle(i)) is_ans = false;
    }

    if (is_ans){
        for (int i = 0; i < n ; i ++){
            if (!used[i]) dfs(i);
        }
        vector<int> v;
        for (int i = 0; i < n; i  ++) v.pb(i);
        sort(all(v), cmp);;
        reverse(all(v));
        for (int i = 0; i < n; i ++) cout << i + 1 << " ";
    }
    else cout << -1;


}
/*




*/

