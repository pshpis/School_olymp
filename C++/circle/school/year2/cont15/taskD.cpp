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
vector<int> a, c;

bool can(int k){
    vector<int> day(m + 1, -1);
    day[0] = 0;
    for (int i = 0; i < k; i ++){
        if (a[i] != 0){
            day[a[i]] = i;
        }
    }
    for (int i = 0; i < m + 1; i ++){
        if (day[i] == -1){
            return false;
        }
    }

    vector<int> b(k, 0);
    for (int i = 1; i < m + 1; i ++){
        b[day[i]] = i;
    }

    int cnt = 0;
    for (int i = 0; i < k; i ++){
        if (b[i] == 0) cnt ++;
        else cnt -= c[b[i] - 1];
        if (cnt < 0) return false;
    }
    return true;
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
    a.resize(n);
    c.resize(m);
    fr(i, n) cin >> a[i];
    fr(i, m) cin >> c[i];

//    for (int i = 0; i < n; i ++){
//        cout << can(i);
//    }

//    cout << endl;

    int l = 0, r = n;
    while (r - l > 1){
        int m = (r + l) / 2;
        if (!can(m)) l = m;
        else r = m;
    }
    if (!can(r)) cout << -1;
    else cout << r;
}
/*




*/

