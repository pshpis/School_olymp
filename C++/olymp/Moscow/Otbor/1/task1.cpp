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

    vector<int> t(2);
    cin >> t[0] >> t[1];
    vector<int> cnt(2);
    cin >> cnt[0] >> cnt[1];
    vector<int> mn(2), mx(2);
    for (int i = 0; i < 2; i ++){
        mx[i] = cnt[i] * (t[i] + 1) + t[i];
        mn[i] = cnt[i] * (t[i] + 1) - t[i];
    }

    for (int i = 0; i < 2; i ++){
        if (mn[i] > mx[1 - i]){
            cout << -1;
            return 0;
        }
    }

    int ans_mx = min(mx[0], mx[1]);
    int ans_mn = max(mn[0], mn[1]);
    cout << ans_mn << " " << ans_mx;

}
/*




*/

