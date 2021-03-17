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

int n;
vector<pii> rib;

vector<int> old, nw;
int mx;

inline void comp(){
    for (int i = 0; i < old.size(); i ++){
        int k = (int)old.size() - i;
        if (k == 4 || k == 2){
            pii r = mp(mx + 1, old[i]);
            pii r_ = mp(mx + 1, old[i + 1]);
            rib.pb(r);
            rib.pb(r_);
            nw.pb(mx + 1);
            mx ++;
            i ++;
            continue;
        }
        pii r = mp(mx + 1, old[i]);
        pii r_ = mp(mx + 1, old[i + 1]);
        pii r__ = mp(mx + 1, old[i + 2]);
        rib.pb(r);
        rib.pb(r_);
        rib.pb(r__);
        nw.pb(mx + 1);
        mx ++;
        i += 2;
    }
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

    cin >> n;
    for (int i = 1; i <= n; i ++) old.pb(i);
    mx = n;

    for (;;){
        comp();
        old = nw;
        nw.clear();
        if (old.size() <= 1) break;
    }

    cout << mx << "\n";

    for (auto v: rib){
        if (v.fi == 1) v.fi = mx;
        else if (v.fi == mx) v.fi = 1;

        if (v.se == 1) v.se = mx;
        else if (v.se == mx) v.se = 1;
        cout << v.fi << " " << v.se << "\n";
    }

}
/*




*/

