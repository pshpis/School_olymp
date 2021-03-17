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

bool solve(string& s){
    int n = s.size();
    if (n == 0){
        if (s[0] == '?') s[0] = 'a';
        return true;
    }
    for (int i = 0; i < n; i ++){
        if (s[i] == '?'){
            if (i == 0 && s[i + 1] == '?'){
                s[i] = 'a';
                continue;
            }
            if (i == 0){
                s[i] = (s[i + 1] - 'a' + 1) % 3 + 'a';
                continue;
            }
            if (i == n - 1 || s[i + 1] == '?'){
                s[i] = (s[i - 1] - 'a' + 1) % 3 + 'a';
                continue;
            }
            if (s[i + 1] == s[i - 1]){
                s[i] = (s[i + 1] - 'a' + 1) % 3 + 'a';
                continue;
            }
            s[i] = 'a' + 'b' + 'c' - s[i - 1] - s[i + 1];
        }
    }
    for (int i = 0; i < n - 1; i ++){
        if (s[i] == '?' || s[i + 1] == '?' || s[i] == s[i + 1]){
            return false;
        }
    }
    return true;
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

    int q = next();
    for (int i = 0; i < q; i ++){
        string s;
        cin >> s;
        if (solve(s)) cout << s << '\n';
        else cout << -1 << '\n';
    }
}
/*




*/

