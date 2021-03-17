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

typedef long double coord;

struct point{
    coord x, y;

    point(coord x_, coord y_){
        x = x_;
        y = y_;
    }

    point() = default;

    coord len(){
        return hypot(x, y);
    }
};

point operator + (point p1, point p2){
    return point (p1.x + p2.x, p1.y + p2.y);
}

point operator - (point p){
    return point (-p.x, -p.y);
}

point operator - (point p1, point p2){
    return p1 + (- p2);
}

inline coord dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

inline coord dp(point p1, point p2){
    return p1.x * p2.x + p1.y * p2.y;
}

inline coord cp(point p1, point p2){
    return p1.x * p2.y - p1.y * p2.x;
}

point o;

inline bool cmp(point p1, point p2){
    coord cr = cp(p1 - o, p2 - o);
    return (cr < 0 || (cr == 0 && (p1 - o).len() < (p2 - o).len()));
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out

    int n;
    cin >> n;
    vector<point> p(n);

    int pos = 0;
    for (int i = 0; i < n; i ++){
        cin >> p[i].x >> p[i].x;
        if (p[i].x < p[pos].x || (p[i].x == p[pos].x && p[i].y < p[pos].y)) pos = i;
    }

    o = p[pos];
    swap(p[0], p[pos]);

    sort(p.begin() + 1, p.end(), cmp);

    vector<point> ans;
    ans.pb(p[0]); ans.pb(p[1]);

    int sz = 2;
    for (int i = 2; i < n; i ++){
        while (sz > 1 && cp(ans[sz - 1] - ans[sz - 2], p[i] - ans[sz - 1]) <= 0){
            ans.pop_back();
            sz --;
        }
        ans.pb(p[i]);
        sz ++;
    }

    coord res = 0;
    for (int i = 0; i < ans.size(); i ++){
        res += dist(ans[i], ans[i + 1]);
    }

    res += dist(*ans.begin(), *(ans.end() - 1));

    cout << res;

}
/*




*/

