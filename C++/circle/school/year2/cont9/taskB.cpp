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

struct Point{
    int x, y;

    Point(int x_, int y_): x(x_), y(y_){}

    Point() = default;
};

ostream& operator << (ostream& s, const Point n){
    s << n.x << " " << n.y;
}

istream& operator>>(istream& s, Point& n)
{
    n.x = next();
    n.y = next();
    return s;
}

bool operator < (Point f, Point s){
    return (f.x < s.x || (f.x == s.x && f.y < s.y));
}

bool operator == (Point f, Point s){
    return (f.x == s.x && f.y == s.y);
}


struct Line{
    int a, b;
    double c;

    Line(int a_, int b_, int c_): a(a_), b(b_), c(c_){}

    Line(Point A, Point B): a(A.y - B.y), b(B.x - A.x), c(A.x * B.y - B.x * A.y){
        if (a < 0){
            a = -a;
            b = -b;
            c = -c;
        }

        int gcd = __gcd(a, b);
        a /= gcd;
        b /= gcd;
        c /= gcd;
    }


};

bool paral(Line s1, Line s2){
    return (s1.a == s2.a && s1.b == s2.b);
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

    vector<Point> p;
    int n = next();
    for (int i = 0; i < n; i ++){
        Point x;
        cin >> x;
        p.pb(x);
    }

    map<pii, set<pair<Point, Point> > > ln_point;
    for (int i = 0; i < n; i ++){
        for (int j = i + 1; j < n; j ++){
            Line f(p[i], p[j]);
            ln_point[mp(f.a, f.b)].insert(mp(p[i], p[j]));
        }
    }

    int cnt = 0;

    set<pair<Point, Point> > :: iterator it1, it2;
    for (auto v: ln_point){
        for (it1 = ln_point[v.fi].begin(); it1 != ln_point[v.fi].end(); it1 ++){
            auto p1 = *it1;
            it2 = it1;
            it2 ++;
            for (;it2 != ln_point[v.fi].end(); it2 ++){
                auto p2 = *it2;
                if (p1 == p2) continue;

                Line s1(p1.fi, p2.fi);
                Line s2(p1.se, p2.se);

                Line k1(p1.fi, p2.se);
                Line k2(p1.se, p2.fi);

                if (paral(s1, s2)){
                    cnt ++;
                    ln_point[mp(s1.a, s1.b)].erase(mp(p1.fi, p2.fi));
                    ln_point[mp(s1.a, s1.b)].erase(mp(p1.se, p2.se));
                }
                else if (paral(k1, k2)){
                    cnt ++;
                    ln_point[mp(s1.a, s1.b)].erase(mp(p1.fi, p2.se));
                    ln_point[mp(s1.a, s1.b)].erase(mp(p1.se, p2.fi));
                }
            }
        }
    }
    cout << cnt << '\n';

}
/*




*/

