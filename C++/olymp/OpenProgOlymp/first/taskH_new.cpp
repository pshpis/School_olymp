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

#define int int64_t

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

int p, q, a, b, n;

int fast_pow(int a, int k){
    if (k == 0) return 1;
    if (k == 1) return a;
    if (k % 2 == 0) return pw2(fast_pow(a, k / 2));
    else return a * pw2(fast_pow(a, k / 2));
}

inline bool solve1(int pw, int a, int n, int q){
    if (a == n){
        return true;
    }
    if (pw == 0){
        return false;
    }

    int k = n % q + n / q;
    if (k > a) return false;
    else if ((a - k) % (q - 1) == 0) return true;
    else return false;

}

bool solve(int pw, int a, int n, int q){
    int k = fast_pow(q, pw);
    if (pw <= 1) return solve1(pw, a, n, q);

    for (int i = 0; i * k <= n && i < a; i ++){
        if (i * k == n) return true;
        if (solve(pw - 1, a - i, n - i * k, q)) return true;
    }
//    return false;
}

inline void test(){

    cin >> p >> q >> a >> b >> n;
    if (p * a == n){
        cout << "Yes\n";
        return;
    }
    if (a * p > n){
        cout << "No\n";
        return;
    }

    if (b == 0){
        cout << "No\n";
        return;
    }
    if (n % p != 0){
        cout << "No\n";
        return;
    }
    n /= p;
    b = min(b, (int)61);
//    watch(b);

    int sum = 0;
    int cnt = 0;
    while (n > 0 && cnt < b){
        sum += n % q;
        n /= q;
        cnt ++;
    }
    sum += n;
//    watch(sum);
//    watch(n);

    if (a >= sum && (a - sum) % (q - 1) == 0) cout << "Yes\n";
    else cout << "No\n";
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

//    cout << fast_pow(3, 5);
//    return 0;

    int t = next();
    for (int i = 0; i < t; i ++) test();
}
/*

1
1 3 5 1 3 2

1
1 2
6 200
5

1
1 2
2 3
17

Yes
*/

