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

vector<double> a = {5,2,4,7,1,8,3,0,9,6};

double solve(double z){
    double g = 10, f = 1, r = 0;
    while (g > 1 || f == 1){
        g = max(1, int(g / z));
        f = 0;
        double i = 0;
        while (i < 10 - g){
            if (a[i] > a[i + g]){
                double t = a[i];
                a[i] = a[i + g];
                a[i + g] = t;
                f = 1;
                r = r + 1;
            }
            i = i + 1;
        }
    }
    return r;
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



    double mn = 1e9;
    double d = 0.0001;
    double z = 1;
    while (z < 10){
        z += d;
        mn = min(mn, solve(z));
    }
    watch(mn);
}
/*




*/

