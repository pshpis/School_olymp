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


typedef double coord;

struct point{
    coord x, y;

    point() = default;

    point(coord x_, coord y_){
        x = x_;
        y = y_;
    }

    point operator - (point& other){
        return point(x - other.x, y - other.y);
    }

    point operator -(){
        return point(-x, -y);
    }

    point operator +(point& other){
        return point(x + other.x, y + other.y);
    }

    coord len(){
        return sqrt(x * x + y * y);
    }
};

coord cp(point a, point b){
    return a.x * b.y - a.y * b.x;
}

point o;

bool cmp(point& a, point& b){
    coord __cp = cp(a - o, b - o);
    return (__cp > 0 || (__cp == 0 && (a - o).len() > (b - o).len()));
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out

    int n = next();
    vector<point> p(n);
    int pos = -1;
    point min_p(1e9, 1e9);
    for (int i = 0; i < n; i ++){
        cin >> p[i].x >> p[i].y;
        if (p[i].y < min_p.y){
            pos = i;
            min_p = p[i];
        }
        if (p[i].y == min_p.y && p[i].x < min_p.y){
            pos = i;
            min_p = p[i];
        }
    }
    swap(p[0], p[pos]);
    o = p[0];
    sort(p.begin() + 1, p.end(), cmp);

    int sz = 2;
    vector<point> ans = {p[0], p[1]};

    for (int i = 2; i < n; i ++){
        while (sz > 1 && (cp(ans[sz - 1] - ans[sz - 2], p[i] - ans[sz - 1]) <= 0)){
            ans.pop_back();
            sz --;
        }
        ans.push_back(p[i]);
        sz ++;
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i ++){
        cout << ans[i].x << " " << ans[i].y << "\n";
    }
}
/*




*/

