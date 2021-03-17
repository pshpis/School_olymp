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
    char file_in[] = "input.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "output.txt";
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

int n, m, k;
vector<int> a;
vector<int> el;

inline void test(){
    int l, r;
    cin >> l >> r;
    l --; r --;

    for (int i = l; i <= r; i ++) el.pb(a[i]);

    sort(el.begin(), el.end());
    int cnt = 1;
    for (int i = 1; i < el.size(); i ++) if (el[i] - el[i - 1] > k) cnt ++;
    el.clear();
    cout << cnt << " ";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < m; i ++) test();
}
/*




*/

