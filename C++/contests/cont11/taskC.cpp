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

void solve(){
    int n = next();
    int last, cnt = 0;
    int g = 0, s = 0, b = 0;
    bool g_ok = false, b_ok = false;
    for (int i = 0; i < n; i ++){
        if (g + s + b > n / 2){
            cout << "0 0 0 \n";
            return;
        }
        int x = next();
        if (i == 0){
            last = x;
            cnt = 1;
            continue;
        }
        if (last == x){
            cnt ++;
            continue;
        }
        else {
            last = x;
            if (!g_ok){
                g = cnt;
                g_ok = true;
                cnt = 1;
                continue;
            }
            if (s <= g){
                s += cnt;
                cnt = 1;
                continue;
            }
            if (b <= g){
                b += cnt;
//                watch(b);
//                watch(cnt);
                cnt = 1;
                continue;
            }
            if (!b_ok && g + s + b + cnt <= n / 2) b += cnt;
            else b_ok = true;
//            watch(b);
//            watch(cnt);
            cnt = 1;

        }
    }
    if (g + s + b > n / 2 || g == 0 || s == 0 || b == 0 || g >= s || g >= b){
        cout << "0 0 0 \n";
        return;
    }
    else cout << g << " " << s << " " << b << "\n";
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
    for (int i = 0; i < n; i ++){
        solve();
    }
}
/*
1
16
5 5
4 3 3
2 2 2
1 1 1 1 1 1 1 1 1 1

*/

