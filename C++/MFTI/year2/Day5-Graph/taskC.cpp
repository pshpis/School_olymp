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
vector<vector<int> > gr;
vector<int> tin, tout, fup;
vector<bool> used;
set<int> ans;
int timer = 0;

void dfs(int st, int from = -1){
    used[st] = true;
    tin[st] = fup[st] = timer ++;
    int children = 0;
    for (int to: gr[st]){
        if (to == from) continue;
        if (used[to]){
            fup[st] = min(fup[st], tin[to]);
        }
        else{
            dfs(to, st);
            fup[st] = min(fup[st], fup[to]);
            if (fup[to] >= tin[st] && from != -1){
                ans.ins(st);
            }
            children ++;
        }
    }
    if (from == -1 && children > 1) ans.ins(st);
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
    tin.resize(n);
    tout.resize(n);
    fup.resize(n);
    used.assign(n, false);

    for (int i = 0; i < m; i ++){
        int a = next() - 1, b = next() - 1;
        gr[a].pb(b);
        gr[b].pb(a);
    }

    for (int i = 0; i < n; i ++){
        if (!used[i]) dfs(i);
    }

    cout << ans.size() << "\n";
    for (int x: ans) cout << x + 1 << " ";

}
/*




*/

