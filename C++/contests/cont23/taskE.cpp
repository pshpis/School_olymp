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

    int n = next();
    vector<int> used(n + 5, 0);
    for (int i = 0; i < n; i ++) used[next()] ++;

    vector<pii> otr;
    bool fl = false;

    for (int i = 0; i < n + 2; i ++){
        if (used[i] != 0 && !fl){
            fl = true;
            otr.pb({i, i});
        }

        if (fl){
            if (used[i] == 0) fl = false;
            else {
                otr[otr.size() - 1].se = i;
            }
        }
    }

    vector<int> long_used = used;

    for (auto el: otr){
        int sum = 0;
        for (int i = el.fi; i <= el.se; i ++){
            sum += long_used[i];
        }

        int len = el.se - el.fi + 1;
        if (sum >= len + 2){
            long_used[el.fi - 1] ++;
            long_used[el.se + 1] ++;
        }
        if (sum == len + 1){
            if (long_used[el.fi - 1] == 0) long_used[el.fi - 1] ++;
            else long_used[el.se + 1] ++;
        }
    }

    int mx = 0;
    for (int i = 0; i < n + 2; i ++) if (long_used[i] > 0) mx ++;

    int now = 0;
    for (int i = 0; i < n + 2; i ++) if (used[i] > 0) now ++;

    int mn = 0;
    for (int i = 0; i < n + 2; i ++){
        if (used[i] > 0){
            mn ++;
            i += 2;
        }
    }

    cout << mn << endl << mx << endl;



}
/*



give me tests;
*/



