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

int to_10(string& s){
    int ans = 0;
    for (int i = 0; i < s.size(); i ++){
        ans *= 2;
        ans += s[i] - '0';
    }
    return ans;

}

string to_2(int x){
    if (x == 0) return "0";
    string ans = "";
    while (x > 0){
        ans += x % 2 + '0';
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
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

//    while (true) cout << to_2(next()) << endl;
//    return 0;

    int n = next();
    vector<int> a;
    for (int i = 0; i < n; i ++){
        string x;
        cin >> x;
        a.pb(to_10(x));
    }
    string x;
    cin >> x;
    int b = to_10(x);

    int up = 1e8;

    for (int i = 0; i < up; i ++){
        int res = 0;
        for (int j = 0; j < n; j ++){
            res = res ^ (a[j] + i);
        }
        if (res == b){
            cout << to_2(i) << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
/*




*/

