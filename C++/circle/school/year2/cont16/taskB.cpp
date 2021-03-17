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

const ll INF = 2e4;
const ll INF64 = 1e18;
const long double PI = 3.14159265359;
const long double EPS = 1e-10;
const int MOD = 1e9+7;

template<typename type>

type next()
{type x; cin >> x; return x;}

ll next()
{ll x; cin >> x; return x;}

typedef long double coord;

bool eq (coord x, coord y){
    return abs(x - y) < EPS;
}

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

    coord norm(){
        return pw2(x) + pw2(y);
    }

    void make_need_length(coord length){
        coord ln = len();
        x /= ln;
        y /= ln;
        x *= length;
        y *= length;
    }
};

point nullpoint(-INF, -INF);

coord dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

typedef point vec;

point operator -(point a){
    return point(-a.x, -a.y);
}

point operator + (point a, point b){
    return point(a.x + b.x, a.y + b.y);
}

point operator - (point a, point b){
    return a + (-b);
}

bool operator == (point a, point b){
    return (eq(a.x, b.x) && eq(a.y, b.y));
}

bool operator < (point a, point b){
    if (a.x < b.x) return true;
    if (a.x == b.x && a.y < b.y) return true;
    return false;
}

ostream& operator <<(ostream& s, const point a)
{
    s << a.x << " " << a.y;
    return s;
}

istream& operator>>(istream& s, point& a)
{
    s >> a.x;
    s >> a.y;
    return s;
}

struct line{
    int a, b, c;

    line(point p1, point p2){
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = p1.y * p2.x - p1.x * p2.y;
    }

    line (int a_, int b_, int c_){
        a = a_;
        b = b_;
        c = c_;
    }

    line() = default;

    double zn(point p){
        return a * p.x + b * p.y + c;
    }

    bool is_on(point p){
        return eq(zn(p), 0);
    }
};

struct circle{
    point O;
    coord r;

    circle(point O_, coord r_){
        O = O_;
        r = r_;
    }
};

point intersect(line s1, line s2){
    point ans;
    ans.x = -(s1.c * s2.b - s2.c * s1.b) / (s1.a * s2.b - s2.a *  s1.b);
    ans.y = -(s1.a * s2.c - s2.a * s1.c) / (s1.a * s2.b - s2.a *  s1.b);
    return ans;
}

coord dist(line s, point p){
    return abs(s.zn(p)) / hypot(s.a, s.b);
}

pair<point, point> intersect(line s, circle c){
    s.c = s.zn(c.O);
    c.O = point(0, 0);
    coord h = dist(s, c.O);
    point p = nullpoint;
    point d_(s.a, s.b);
    d_.make_need_length(h);
    point p1 = c.O - d_;
    point p2 = c.O + d_;
    if (s.is_on(p1)) p = p1;
    if (s.is_on(p2)) p = p2;
    if (eq(h, c.r)){
        return mp(p, nullpoint);
    }
    if (h > c.r) return mp(nullpoint, nullpoint);
    coord d = sqrt(pw2(c.r) - pw2(h));
    point d__(-s.b, s.a);
    d__.make_need_length(d);

    return mp(p + d__, p - d__);
}

pair<point, point> intersect(circle c1, circle c2){
    c2.O = c2.O - c1.O;
    c1.O = point(0, 0);

    line s;
    s.a = -2 * (c2.O).x;
    s.b = -2 * (c2.O).y;
    s.c = pw2((c2.O).x) + pw2((c2.O).y) + pw2(c1.r) - pw2(c2.r);

    return intersect(s, c1);
}

point o;

inline coord dp(point p1, point p2){
    return p1.x * p2.x + p1.y * p2.y;
}

inline coord cp(point p1, point p2){
    return p1.x * p2.y - p1.y * p2.x;
}

bool cmp(point p1, point p2){
    coord cr = cp(p1 - o, p2 - o);
    return (cr > 0 || (cr == 0 && (p1 - o).len() < (p2 - o).len()));
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    cout << fixed;

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out

    int n = next();
    vector<point> p;
    int pos = 0;

    for (int i = 0; i < n; i ++){
        point x;
        cin >> x;
        p.pb(x);
        if (p[i].x < p[pos].x || (p[i].x == p[pos].x && p[i].y < p[pos].y))
            pos = i;
    }

    swap(p[0], p[pos]);
    o = p[0];
    sort(p.begin() + 1, p.end(), cmp);
    vector<point> ans;
    ans.pb(p[0]);
    ans.pb(p[1]);
    int sz = 2;
    for (int i = 2; i < n; i ++){
        while(sz > 1 && cp(ans[sz - 1] - ans[sz - 2], p[i] - ans[sz - 1]) <= 0) {
            ans.pop_back();
            sz--;
        }
        ans.push_back(p[i]);
        sz++;
    }

    coord res = 0;
    for (int i = 0; i < ans.size() - 1; i ++){
        res += dist(ans[i], ans[i + 1]);
    }

    res += dist(ans[0], ans.back());

//    cout << res;
//    if (n == ans.size()) cout << "YES" << endl;
//    else cout << "NO" << endl;
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i ++)
        cout << ans[i] << "\n";
}
/*




*/
