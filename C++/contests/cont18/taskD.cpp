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

int fast_pow(int a, int k){
    if (k == 0) return 1;
    if (k == 1) return a;
    if (k % 2 == 0) return pw2(fast_pow(a, k / 2));
    else return a * pw2(fast_pow(a, k / 2));

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

    int n = next();
    vector<int> num;
    vector<bitset<31> > a;
    vector<int> st_sum(31, 0);
    for (int i = 0; i < n ; i ++) num.pb(next());
    sort(all(num));
    reverse(all(num));
    for (int i = 0; i < n; i ++){
        int x = num[i];
        bitset<31> b(x);
        a.pb(b);
        for (int j = 0; j < 31; j ++){
            if (b[j]) st_sum[j] ++;
        }
    }

    vector<int> res(n, 0);
    for (int i = 0; i < n ; i ++){
        auto b = a[i];
        for (int j = 0; j < 31; j ++){
            if (b[j]){
                if (st_sum[j] == 1) res[i] += fast_pow(2, j);
            }
        }
    }

//    cout << "This is st_sum" << endl;
//    wrvec(st_sum);
//
//    cout << "This is num" << endl;
//    wrvec(num);
//
//    cout << "This is res" << endl;
//    wrvec(res);

    int mx = -1;
    int pl = -1;
    for (int i = 0; i < n; i ++){
        if (res[i] > mx){
            mx = res[i];
            pl = i;
        }
    }

    cout << num[pl] << " ";
    for (int i = 0; i < n; i ++){
        if (i == pl) continue;
        cout << num[i] << " ";
    }

}
/*




*/

