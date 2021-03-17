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

    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n, 0);
    for (int i = 0; i < n; i ++){
        if (s[i] < 'a') a[i] = 1;
    }

    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i ++)
        pref[i + 1] = pref[i] + a[i];

    int sum = pref[n];
    int mn = 1e9 + 7;
    int id = -1;
    for (int i = 0; i < n + 1; i ++){
        int k1 = i - pref[i], k2 = sum - pref[i];

        mn = min(mn, k1 + k2);
        if (mn == k1 + k2) id = i;

//        if (i == 10){
//            watch(k1);
//            watch(k2);
//        }
    }

//    wrvec(a);
//
//    watch(id);
    cout << mn << endl;

}
/*




*/

