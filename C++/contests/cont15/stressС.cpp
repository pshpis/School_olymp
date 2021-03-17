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

vector<int> num;

pair<int, int> get_ans(int l, int r){
    if (l == r){
        return mp(num[l], 1);
    }
    int m = (l + r) / 2;

    auto ans1 = get_ans(l, m), ans2 = get_ans(m + 1, r);

    pii ans = {ans1.fi * ans2.se, ans1.se * ans2.fi};

    if (ans.fi < ans.se) swap(ans.fi, ans.se);

    return ans;

}

pair<int, int> solve(int x){
    map<int, int> fact;

    for (int i = 2; i <= sqrt(x); i ++){
        while (x % i == 0){
            fact[i] ++;
            x /= i;
        }
    }

    if (x != 1)
        fact[x] ++;

    int a = 1, b = 1;

    vector<int> num;

    for (auto v: fact){
        int x = v.fi, k = v.se;
        num.pb(fast_pow(x, k));
    }

    sort(all(num));
    reverse(all(num));

    return get_ans(0, num.size() - 1);
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

    for (int i = 3; ; i ++){
        auto ans = solve(i);
        int a = ans.fi, b = ans.se;
        int lcd = (a * b) / __gcd(a, b);
        if (lcd != i){
            watch(a);
            watch(b);
            cout << " ----------------- " << endl;
        }
        watch(i);
    }
}
/*




*/


