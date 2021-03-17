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

const int MAX_N = 1e5 + 100, MAX_M = 1e5 + 100;

int n, m;
vector<unordered_set<int> > g(MAX_N);
vector<bool> used(MAX_N, false);
vector<int> tin(MAX_N), fup(MAX_N);
map<pii, vector<int> > rib;

vector<int> ans;

int timer;

void read_gr(){
    cin >> n >> m;
    for (int i = 0; i < m; ++ i){
        int x = next() - 1, y = next() - 1, z = next() - 1;

        g[x].insert(y);
        g[y].insert(x);
        rib[mp(x, y)].pb(i);
        rib[mp(y, x)].pb(i);

        g[x].insert(z);
        g[z].insert(x);
        rib[mp(x, z)].pb(i);
        rib[mp(z, x)].pb(i);

        g[z].insert(y);
        g[y].insert(z);
        rib[mp(z, y)].pb(i);
        rib[mp(y, z)].pb(i);
    }
}

void IS_BRIDGE(int x, int y){
    if (rib[mp(x, y)].size() == 1)
        ans.pb(rib[mp(x, y)][0]);
}

void dfs (int v, int p = -1){
	used[v] = true;
	tin[v] = fup[v] = timer ++;
	for (int to: g[v]){
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v])
				IS_BRIDGE(v, to);
		}
	}
}

void find_bridges(){
	timer = 0;
	for (int i = 0; i < n; ++ i)
		used[i] = false;
	for (int i = 0; i < n; ++ i)
		if (!used[i])
			dfs(i);
}

void print_ans(){
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++ i)
        cout << ans[i] + 1 << " ";
    cout<<endl;
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
    find_bridges();
    print_ans();

}

