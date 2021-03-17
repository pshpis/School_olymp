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

int fastpow(int x, int k){
    if (k == 0) return 1;
    if (k == 1) return x;
    if (k % 2 == 0) return pw2(fastpow(x, k / 2));
    else return pw2(fastpow(x, k / 2)) * x;
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

    int n = next();
    set<int> num;
    vector<ll> cost(n);
    vector<int> a(n);
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        cin >> cost[i];
        num.insert(a[i]);
    }

    int m = next();
    vector<ll> kit_cost(m);
    vector<vector<int> > kit(m);
    for (int i = 0; i < m; i ++){
        int k = next();
        cin >> kit_cost[i];
        for (int j = 0; j < k; j ++){
            int x = next();
            if (num.count(x) > 0) kit[i].pb(x);
        }
    }

    int pw_m_2 = fastpow(2, m);

    ll min_c = 1e15;
    set<int> el;
    for (size_t i = 0; i < pw_m_2; ++ i){
        bitset<20> b(i);
        ll c = 0;
        for (size_t j = 0; j < m; ++ j){
            if (b[j]){
                c += kit_cost[j];
                for (size_t k = 0; k < kit[j].size(); ++ k) el.insert(kit[j][k]);
            }
        }
        for (size_t j = 0; j < n; ++ j){
            if (el.count(a[j]) == 0) c += cost[j];
        }
//        watch(c);
        min_c = min(min_c, c);
        el.clear();
    }
    cout << min_c;


}
/*




*/

