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

vector<pii> rib;

bool test(int n, int m){
    vector<int> level(n, 0);
    for (int i = 0; i < m; i ++){
        int u = rib[i].fi, v = rib[i].fi;
        level[v] ++; // see look
    }

    int root = -1;
    int cnt_root = 0;

    for (int i = 0; i < n; i ++){
        if (level[i] == 0){
            root = i;
            cnt_root ++;
        }
    }
//    watch(cnt_root);

    if (cnt_root == 0 || cnt_root > 1){
        return false;
    }

    vector<int> p(n, 0);
    p[root] = -1;

    for (int i = 0; i < m; i ++){
        int u = rib[i].fi;
        int v = rib[i].se;
        if (level[u] <= level[v]){
            return false;
        }
        if (level[u] == level[v] + 1){
            p[u] = v;
        }
    }

    cout << "Yes" << "\n";
    for (int i = 0; i < n; i ++){
        cout << p[i] + 1 << " ";
    }

    cout << "\n";
    return true;

}

int fast_pow(int x, int k){
    if (k == 0) return 1;
    if (k == 1) return x;
    if (k % 2 == 0) return pw2(fast_pow(x, k / 2));
    else return x * pw2(fast_pow(x, k / 2));
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

    int t = next();
    for (int i = 0; i < t; i ++){
        rib.clear();
        int n = next(), m = next();
        for (int i = 0; i < m; i ++){
            pii r;
            r.fi = next() - 1;
            r.se = next() - 1;
            rib.pb(r);
        }

        bool is_ans = false;

//        if (i == 2){
//            watch(i);
//            test(n, m);
//            cout << endl;
//        }

        for (int i = 0; i < pow(2, m); i ++){
            bitset<10> a(i);
            for (int i = 0; i < 10; i ++){
                if (a[i]){
                    swap(rib[i].fi, rib[i].se);
                }
            }
            if (test(n, m)) is_ans = true;
            for (int i = 0; i < 10; i ++){
                if (a[i]){
                    swap(rib[i].fi, rib[i].se);
                }
            }
            if (is_ans) break;
        }

        if (!is_ans) cout << "No\n";

        if
    }
}
/*




*/

