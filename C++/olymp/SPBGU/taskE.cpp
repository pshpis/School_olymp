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

#define int int64_t

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

    int a, b, c, d, n, k; // n - max, k - need value of answers
    cin >> a >> b >> c >> d >> n >> k;

    int cnt = 0;
    vector<pii> ans;

    for (int f = 1; f <= n; f ++){
        int e_min = a * f / b + 1;
        if (e_min > n) break;
        int e_max = c * f / d;
        if (c * f % d == 0) e_max --;
        e_max = min(e_max, n)
        for (int e = e_min; e <= e_max; e ++){
            if (__gcd(e, f) == 1){
                if (ans.size() < k) ans.pb(mp(e, f));
            }
        }
    }


    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i ++) cout << ans[i].fi << " " << ans[i].se << "\n";

}

/*




*/

