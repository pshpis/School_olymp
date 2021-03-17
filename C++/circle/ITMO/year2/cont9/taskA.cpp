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

    int n = next(), m = next(), k = next();
    vector<int> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i ++) cin >> b[i];

    vector<bool> used(n, false);

    for (int i = 0; i < m; i ++){
        int need = b[i];
        int left_up = -1;
        int left_eq = -1;
        for (int j = k - 1; j >= 0; j --){
            if (used[j]) continue;
            if (a[j] > need) left_up = max(left_up, j);
            if (a[j] == need) left_eq = max(left_eq, j);
        }
        int right_up = 1e9 + 7;
        int right_eq = 1e9 + 7;
        for (int j = k; j < n; j ++){
            if (used[j]) continue;
            if (a[j] > need) right_up = min(right_up, j);
            if (a[j] == need) right_eq = min(right_eq, j);
        }

        int ans = 0;
        if (right_eq == 1e9 + 7 && left_eq == -1){
            if (right_up == 1e9 + 7) ans = left_up;
            else if (left_up == -1) ans = right_up;
            else {
                int d_left = k - 1 - left_up;
                int d_right = right_up - k;
                if (d_right < d_left) ans = right_up;
                else ans = left_up;
            }
        }
        else {
            if (right_eq == 1e9 + 7) ans = left_eq;
            else if (left_eq == -1) ans = right_eq;
            else {
                int d_left = k - 1 - left_eq;
                int d_right = right_eq - k;
                if (d_right < d_left) ans = right_eq;
                else ans = left_eq;
            }
        }
        if (ans == 1e9 + 7) ans = -2;
        if (ans == -1) ans = -2;
        cout << ans + 1 << " ";
        if (ans != -2) used[ans] = true;
    }

}
/*




*/

