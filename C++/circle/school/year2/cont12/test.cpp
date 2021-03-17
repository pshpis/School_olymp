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

int fast_pow(int a, int k){
    if (k == 0) return 1;
    if (k == 1) return a;
    if (k % 2 == 0) return pw2(fast_pow(a, k / 2));
    else return pw2(fast_pow(a, k / 2)) * a;
}

const int max_pw = 4;

vector<vector<int> > g;
vector<int> d;
vector<bool> used;

void dfs(int st, int level = 0){
    d[st] = level;
    used[st] = true;
    for (int v: g[st]){
        if (!used[v])
            dfs(v, level + 1);
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

    int n, m;
    cin >> n >> m;
    g.resize(n);
    d.resize(n);
    used.assign(n, false);
    vector<int> p(n, 0);
    for (int i = 1; i < n; i ++){
        int x = next();
        p[i] = x;
        g[x].pb(i);
    }

    dfs(0);

    vector<vector<int> > lca(max_pw + 1, vector<int>(n, 0));

    for (int i = 0; i < n; i ++)
        lca[0][i] = p[i];

    for (int i = 1; i <= max_pw; i ++){
        for (int j = 0; j < n; j ++){
            lca[i][j] = lca[i - 1][lca[i - 1][j]];
        }
    }

    int a = next(), b = next();
    int x = next(), y = next(), z = next();
    int last_ans = 0;

    int sum = 0;

    for (int i = 0; i < m; i ++){
        int a_ = a;
        int b_ = b;

        if (i > 0){
            a_ = (a * x + b * y + z) % n;
            b_ = (b * x + a_ * y + z) % n;
            a = a_;
            b = b_;
            a_ = (a_ + last_ans) % n;
        }

        if (d[a_] < d[b_]) swap(a_, b_);
//        cout << "HERE" << endl;
        int len = d[a_] - d[b_];
        for (int j = max_pw; j >= 0; j --){
            if (len >= fast_pow(2, j)){
                len -= fast_pow(2, j);
                a_ = lca[j][a_];
            }
        }

        if (a_ == b_){
            sum += a_;
            last_ans = a_;
            continue;
        }

        for (int j = max_pw; j >= 0; j --){
            if (lca[j][a_] != lca[j][b_]){
                a_ = lca[j][a_];
                b_ = lca[j][b_];
            }
        }
        sum += p[a_];
        last_ans = p[a_];
    }

    cout << sum << "\n";
}
/*




*/

