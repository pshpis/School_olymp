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
#define double long double

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

const int MAXQ = 6;

int fast_pow(int a, int k){
    if (k == 0) return 1;
    if (k == 1) return a;
    if (k % 2 == 0) return pw2(fast_pow(a, k / 2));
    else return a * pw2(fast_pow(a, k / 2));
}

double to(string x){
    bool more_0 = true;
    if (x[0] == '-') more_0 = false;
    int st = 0;
    if (!more_0) st ++;
    double ans = 0;
    int pl = x.size() + 1;
    for (int i = st; i < x.size(); i ++){
        if  (x[i] == '.'){
            pl = i;
            break;

        }
        ans *= 10;
        ans += (x[i] - '0') % 10;
    }
//    watch(ans);

    double d = 0;
    for (int i = pl + 1; i < x.size(); i ++){
        d *= 10;
        d += x[i] - '0';
    }
//    watch(d);
    int len = x.size() - pl - 1;
//    watch(len);
    d = d / (double) fast_pow(10, len);
//    watch(d);
    ans += d;

    if (!more_0) ans = -ans;
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    srand(time(0));

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out

//    string x;
//    cin >> x;
//    double a = to(x);
//    cout << a << endl;

    int n = next();

    vector<set<pair<double, pair<double, double> > > > ans(n);

    for (int i = 0; i < MAXQ; i ++){
        int a = rand() % 100;
        int b = rand() % 100;
        int c = rand() % 100;
        int d = rand() % 100;

        cout << a << " " << b << " " << c << " " << d << endl;

        for (int i = 0; i < n; i ++){
            string s;
            cin >> s;
//            watch(s);
            if (s[0] == 'p') continue;
            pair<double, pair<double, double> > d;
            d.fi = to(s);
//            watch(d.fi);
            cin >> d.se.fi;
//            watch(d.se.fi);
            cin >> d.se.se;
//            watch(d.se.se);
            ans[i].insert(d);
        }
    }

    cout << "answer:" << endl;

    for (int i = 0; i < n; i ++){
        int cnt = 0;
        for (pair<double, pair<double, double> > v: ans[i]){
            if (cnt >= 2) break;
            cnt ++;
            cout << v.fi << " " << v.se.fi << " " << v.se.se << " ";
        }
        cout << endl;
    }

}
/*
00012.1230456



*/

