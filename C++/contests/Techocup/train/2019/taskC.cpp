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

    int n = next(), k = next();
    deque<int> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i];
    deque<pair<int, int>> buff;

    for (int i = 0; i < min(k, n); i ++){
        buff.pb(mp(a[i], 0));
    }

    k = buff.size();

    sort(all(buff));

//    cout << "this is buff" << endl;
//    for (auto v: buff) cout << v.fi << " " << v.se << " -- ";
//    cout << endl;
    int cnt = 0;
    int timer = 0;
    int ans = 0;
    for (int i = k; i < n; i ++){
        cnt ++;
        timer = buff[0].fi;
        buff.pop_front();
        int pc = round(double(cnt) / double(n) * 100);
        for (int i = 0; i < k - 1; i ++){
            int cnt_test = timer - buff[i].se;
            if (cnt_test + 1 >= pc) ans ++;
        }
        buff.push_back(mp(a[i] + timer, timer));
        sort(all(buff));
    }

    for (int i = 0; i < k; i ++){
        cnt ++;
        timer = buff[0].fi;
        buff.pop_front();
        int pc = round(double(cnt) / double(n) * 100);
        for (auto v: buff){
            int cnt_test = timer - v.se;
            if (cnt_test + 1 == pc) ans ++;
        }
    }

    cout << ans;

}
/*




*/

