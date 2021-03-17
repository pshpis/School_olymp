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
    char file_in[] = "input.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "output.txt";
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

int n, k;
vector<vector<pii> > a;
vector<vector<int> > gr;
vector<vector<pii> > obj;
vector<bool> used;
bool ok = true;
int ans = 1e9;

inline vector<pii> intersect(vector<pii>& a, vector<pii>& b){
    ok = true;
    vector<pii> ans(a.size());
    if (a.size() != b.size()) return ans;
    for (int i = 0; i < a.size(); i ++){
        ans[i].fi = max(a[i].fi, b[i].fi);
        ans[i].se = min(a[i].se, b[i].se);
        if (ans[i].fi > ans[i].se) ok = false;
    }
    return ans;
}

void dfs(int st, int level){
    used[st] = true;
    for (int v: gr[st]){
        if (used[v]) continue;
        obj[v] = intersect(obj[st], a[v]);
        if (!ok){
            ans = min(ans, level + 1);
            ok = true;
        }
        else dfs(v, level + 1);
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

    cin >> n >> k;
    a = vector<vector<pii> >(n, vector<pii>(k));
    gr.resize(n);

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < k; j ++)
            cin >> a[i][j].fi;
        for (int j = 0; j < k; j ++)
            cin >> a[i][j].se;
    }

    for (int i = 0; i < n - 1; i ++){
        int v = next() - 1, u = next() - 1;
        gr[v].pb(u);
        gr[u].pb(v);
    }

    int res = 1e9;
    for (int i = 0; i < n; i ++){
//        watch(i);
        used = vector<bool>(n, false);
        obj = vector<vector<pii> >(n, vector<pii>(k));
        obj[i] = a[i];
        ans = 1e9;
        ok = true;
        dfs(i, 0);
//        watch(ans);
        res = min(res, ans);
    }

    if (res == 1e9) cout << -1;
    else cout << res;
}
/*




*/

