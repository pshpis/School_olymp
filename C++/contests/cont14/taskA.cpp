#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mp make_pair
#define pw2(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

#define ins insert
#define pb push_back
#define eb emplace_back

//#define int int64_t

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

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

template<typename type>

type next()
{type x; cin >> x; return x;}

int next()
{ll x; cin >> x; return x;}

inline void fast_wrie(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out
}

void solve(){
    int n = next();
//    watch(n);
    vi a;
    string s;
    cin >> s;
//    watch(s);
    for (int i = 0; i < n; i ++){
        char c = s[i];
        if (c == 'A') a.pb(i);
//        if (fl) s += c;
    }
//    for (int i = 0; i < a.size(); i ++) cout << a[i] << endl;
    a.pb(n);

    int mx = 0;
    for (int i = 1; i < a.size(); i ++) mx = max(mx, a[i] - a[i - 1] - 1);

    cout << mx << '\n';

}

int32_t main()
{
    fast_wrie();
    int t = next();
    for (int i = 0; i < t; i ++) solve();
}
/*




*/

