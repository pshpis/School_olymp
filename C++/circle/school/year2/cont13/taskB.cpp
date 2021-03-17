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

const int maxN = 1e5 + 100;
set<int> prime;

void make_prime(){
    vector<bool> a(maxN + 100, true);
    a[0] = false;
    a[1] = false;
    for (int i = 2; i < maxN; i ++){
        if (a[i]){
            for (int j = i * i; j < maxN; j += i){
                a[j] = false;
            }
        }
    }
//    cout << "I finish" << endl;

    for (int i = 0; i < maxN; i ++){
        if (a[i]) prime.insert(i);
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

    make_prime();

//    cout << "I start" << endl;

    int n = next(), m = next();
    vector<vector<int> > a(n, vector<int>(m,  0));
    set<int> :: iterator it;

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            int x = next();
            it = prime.lower_bound(x);
            a[i][j] = (*it) - x;
        }
    }

    vector<int> ln_sum(n, 0);
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            ln_sum[i] += a[i][j];
        }
    }

    vector<int> st_sum(m, 0);
    for  (int j = 0; j < m; j ++){
        for (int i = 0; i < n; i ++){
            st_sum[j] += a[i][j];
        }
    }

    int mn_ln = INF64;
    for (int i = 0; i < n; i ++){
        mn_ln = min(mn_ln, ln_sum[i]);
    }

    int mn_st = INF64;
    for (int j = 0; j < m; j ++){
        mn_st = min(mn_st, st_sum[j]);
    }

    cout << min(mn_st, mn_ln);



}
/*




*/

