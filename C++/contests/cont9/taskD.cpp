#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
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
    char file_in[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
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

int n, m;
vector< vector<int> > gr;
vector<bool> used;
vector< set<int> > comp;
vector<int> cl;

void read(){
    cin >> n >> m;

    gr = vector<vector<int> >(n);
    used = vector<bool>(n, false);
    cl = vector<int>(n);

    for (int i = 0; i < m; ++ i){
        int x = next() - 1, y = next() - 1;
        gr[x].pb(y);
        gr[y].pb(x);
    }
}

void dfs(int st, int cnt){
    used[st] = true;
    cl[st] = cnt;
    comp[cnt].insert(st);

    for (int v: gr[st]){
        if (!used[v]) dfs(v, cnt);
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

    read();
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        if (!used[i]){
            set<int> fake;
            comp.pb(fake);
            dfs(i, cnt);
            ++ cnt;
        }
    }

    int ans = 0;
    bool fl = false;
    set<int> :: iterator it;
    int fsh = -1;
    int c = -1;
    for (int i = 0; i < n; ++ i){
        if (!fl){
            c = cl[i];
            it = comp[c].end();
            it --;
            fsh = *it;
            fl = comp[c].size() != 1;
            continue;
        }
        if (cl[i] != c){
            ++ ans;
//            watch(i);
//            watch(cl[i]);
//            watch(c);
            for (int v: comp[cl[i]]){
                cl[v] = c;
                fsh = max(fsh, v);
            }
        }
        if (i == fsh) fl = false;
    }

    cout << ans << endl;

}
/*




*/

