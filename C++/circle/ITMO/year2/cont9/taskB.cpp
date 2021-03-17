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

int n, k;
vector<int> a;

int check1(int x){
    int ans = 0;
    for (int i = 0; i < n; i ++){
        if (i % 2 == 1) x += k;
        ans += abs(a[i] - x);
        if (i % 2 == 1) x -= k;
    }
    return ans;
}

int check2(int x){
    int ans = 0;
    for (int i = 0; i < n; i ++){
        if (i % 2 == 0) x += k;
        ans += abs(a[i] - x);
        if (i % 2 == 0) x -= k;
    }
    return ans;
}

int check(int x){
    return min(check1(x), check2(x));
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

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i ++) cin >> a[i];

    int left = -1e3, right = 1e3;
    while (right - left > 1){
        int mid1 = (right + 2 * left);
        if (mid1 > 0) mid1 += 2;
        mid1 /= 3;
        int mid2 = (2 * right + left );
        if (mid2 < 0) mid2 -= 2;
        mid2 /= 3;
        int ans1 = check(mid1);
        int ans2 = check(mid2);

        watch(left);
        watch(right);

        if (ans1 > ans2) left = mid1;
        else right = mid2;

        watch(mid1);
        watch(mid2);
        watch(ans1);
        watch(ans2);
        watch(left);
        watch(right);
        cout << "----------" << endl;
    }

    watch(right);
    watch(left);

    cout << min(check(right), check(left));

}
/*




*/

