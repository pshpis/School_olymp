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
vector<unordered_set<int> > g;
vector<bool> used;
vector<int> mt;

bool kuhn(int st){
    if (used[st]) return false;
    used[st] = true;

    for (int to: g[st]){
        if (mt[to] == -1 || kuhn(mt[to])){
            mt[to] = st;
            return true;
        }
    }

    return false;
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

    cin >> n;
    g.resize(n);

    string s;
    cin >> s;

    m = s.size();
    mt.assign(m, -1);

    map<char, vector<int>> pl;
    for (int i = 0; i < s.size(); i ++){
        pl[s[i]].pb(i);
    }

    for (int i = 0; i < n; i ++){
        string x;
        cin >> x;

        for (char v: x){
            for (int j = 0; j < pl[v].size(); j ++){
                g[i].insert(pl[v][j]);
            }
        }
    }

    for (int i = 0; i < n; i ++){
        used.assign(n, false);
        kuhn(i);
    }

    vector<int> ans;
    for(int i = 0; i < s.size(); i ++){
        if (mt[i] == -1){
            cout << "NO";
            return 0;
        }

        ans.pb(mt[i]);
    }

    cout << "YES" << endl;

    for (int r: ans){
        cout << r + 1 << " ";
    }

}
/*




*/

