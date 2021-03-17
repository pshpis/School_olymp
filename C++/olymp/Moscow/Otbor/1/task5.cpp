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

    vector<pii> event;
    int t; cin >> t;
    int n; cin >> n;
    for (int i = 0; i < n; i ++){
        int a, b; cin >> a >> b;
        pii e = {a, 1};
        pii e_ = {b + t - 1, 4};
        event.pb(e);
        event.pb(e_);
    }
    int m; cin >> m;
    for (int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        pii e = {a, 2};
        pii e_ = {b + t - 1, 3};
        event.pb(e);
        event.pb(e_);
    }

    sort(event.begin(), event.end());

    int p1 = 0, p2 = 0;
    int ans = 0;
    for (int i = 0; i < event.size(); i ++){
        int type = event[i].se;
        int time = event[i].fi;
//        watch(time);
//        watch(type);
        if (type == 1){
            if (p1 == 0) ans ++;
            else p1 --;
        }
        if (type == 2){
            if (p2 == 0) ans ++;
            else p2 --;
        }
        if (type == 3) p1 ++;
        if (type == 4) p2 ++;
    }

    cout << ans << endl;
}
/*
4
2
3
8
5
10
1
11
15
----
3

1
2
15
18
7
9
2
11
14
1
3
----
2




*/

