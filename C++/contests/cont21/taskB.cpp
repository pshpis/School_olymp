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

    int n = next(), m = next(), k = next();

    set<int> del_k;
    for (int i = 1; i * i <= k; i ++){
        if (k % i == 0){
            del_k.insert(i);
            del_k.insert(k / i);
        }
    }

//    vector<int> del;
//    map<int, int> id_del;
//    for (int v: del_k){
//        del.pb(v);
////        cout << v << " ";
//        id_del[del.back()] = del.size() - 1;
//    }

//    cout << endl;

    vector<int> null_x, null_y;
    for (int i = 0; i < n; i ++){
        int x = next();
        if (x == 0) null_x.pb(i);
    }

    for (int i = 0; i < m; i ++){
        int x = next();
        if (x == 0) null_y.pb(i);
    }

    null_x.pb(n);
    null_y.pb(m);

    n = null_x.size();
    m = null_y.size();

    int ans = 0;

    set<int>::iterator it1, it2;

    sort(all(null_x));
    sort(all(null_y));

    for (int i = 0; i < n; i ++){
        int left;
        if (i == 0) left = 0;
        else left = null_x[i - 1] + 1;
        for (int j = 0; j < m; j ++){
            int up;
            if (j == 0) up = 0;
            else up = null_y[j - 1] + 1;

            int a = null_x[i] - left, b = null_y[j] - up;
//            watch(a);
//            watch(b);
            if (a < b) swap(a, b);
            if (a * b < k) continue;
            if (a * b == k){
                ans ++;
                continue;
            }

            it1 = del_k.upper_bound(b);
//            it1 --;
            it2 = del_k.lower_bound(k / a);

            for(; it2 != it1; it2 ++){
                int v = *it2;
                ans += (b - v + 1) * (a - (k / v) + 1);
            }
        }
    }

    cout << ans << endl;;
}
/*




*/

