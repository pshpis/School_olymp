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

void test(){
    string s;
    cin >> s;

    int l = 0, r = 0, d = 0, u = 0;
    for (int i = 0; i < s.size(); i ++){
        if (s[i] == 'L') l ++;
        if (s[i] == 'R') r ++;
        if (s[i] == 'D') d ++;
        if (s[i] == 'U') u ++;
    }
    int k1 = min(l, r), k2 = min(u, d);
    if (k1 == 0 || k2 == 0){
        if (!(k1 + k2 == 0)){
            if (k1 == 0) cout << "2\nUD\n";
            if (k2 == 0) cout << "2\nLR\n";
            return;
        }
    }
    cout << k1 * 2 + k2 * 2 << "\n";
    for (int i = 0; i < k2; i ++) cout << 'U';
    for (int i = 0; i < k1; i ++) cout << 'R';
    for (int i = 0; i < k2; i ++) cout << 'D';
    for (int i = 0; i < k1; i ++) cout << 'L';
    cout << '\n';
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
        test();
    }

}
/*




*/

