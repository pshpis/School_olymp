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

    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n, 0);

    for (int i = 0; i < n; i ++) cin >> a[i];

    int cnt = 0;

    for (int i = 0; i < n; i ++){
        if (i == 0){
            if (a[i] > l) cnt ++;
            continue;
        }
        if (a[i] > l && a[i - 1] <= l) cnt ++;
    }

    for (int i = 0; i < m; i ++){
        int t = next();
        if (t == 0){
            cout << cnt << '\n';
        }
        if (t == 1){
            int p = next() - 1, d = next();
            if (a[p] > l){
                a[p] += d;
                continue;
            }
            a[p] += d;
            if (a[p] <= l) continue;

            if (p == 0){
                if (n == 1){
                    cnt  ++;
                    continue;
                }
                if (a[p + 1] <= l) cnt ++;
                continue;
            }

            if (p == n - 1){
                if (a[p - 1] <= l) cnt ++;
                continue;
            }

            if (a[p - 1] > l && a[p + 1] > l) cnt --;
            else if (a[p - 1] <= l && a[p + 1] <= l) cnt ++;

        }
    }

}
/*




*/
