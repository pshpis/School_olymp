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

const int MAX_N = 1e6 + 10;

int n, root;
vector<vector<int> > gr(MAX_N);
vector<int> color(MAX_N);

void read_gr(){
    cin >> n;
    for (int i = 0; i < n; ++ i){
        int p = next() - 1, c = next();
        color[i] = c;
        if (p == -1){
            root = i;
            continue;
        }
        gr[p].pb(i);

    }
}

vector<unordered_set<int> > subtree(MAX_N);
vector<int> ans(MAX_N, 0);
unordered_set<int> empt;

void dfs(int st){
    subtree[st].insert(color[st]);
    for (int to: gr[st]){
        dfs(to);
        for (int c: subtree[to]) subtree[st].insert(c);
        subtree[to] = empt;
    }
    ans[st] = subtree[st].size();
}

void print_ans(){
    for (int i = 0; i < n; ++ i){
        cout << ans[i] << ' ';
    }
    cout << endl;
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
    dfs(root);
    print_ans();

}

