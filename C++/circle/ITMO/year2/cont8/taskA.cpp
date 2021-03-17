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

vector<int> parent;
vector<int> r;

vector<pii> a;

double dist(pii a, pii b){
    return sqrt(double(pw2(a.fi - b.fi) + pw2(a.se - b.se)));
}

double dist(int i, int j){
    return dist(a[i], a[j]);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(10);

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out

    int n = next();
    a.resize(n);
    for (int i = 0; i < n; i ++){
        cin >> a[i].fi >> a[i].se;
    }

    vector<bool> used(n, false);
    vector<double> min_e(n, INF);
    vector<int> end_e(n, - 1);
    min_e[0] = 0;
    double w = 0;
    for (int i = 0; i < n; i ++){
        int v = -1;
        for (int j = 0; j < n; j ++){
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        }

        w += min_e[v];
        used[v] = true;

        for (int j = 0; j < n ; j ++){
            if (dist(v, j) < min_e[j]){
                min_e[j] = dist(v, j);
                end_e[j] = v;
            }
        }
    }

    cout << w;

}
/*




*/
