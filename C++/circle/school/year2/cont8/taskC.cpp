#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
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

const int MAX_N = 1e6 + 100;

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

    int a, b, k;
    cin >> a >> b >> k;
    vector<bool> prime(MAX_N, true);
    vector<int> s;

    prime[0] = false;
    prime[1] = false;

    bool fl = false;
    for (int i = 2; i < MAX_N; ++ i){
        if (prime[i]){

            if (i >= a && i <= b){
                s.pb(i);
                fl = true;
            }
//            else if (fl){
//                s.pb(i);
//                fl = false;
//            }


            for (int j = i * i; j < MAX_N; j += i){
                prime[j] = false;
            }
        }
    }
//
//    watch(true);
//    watch(fl);
//
//    for (int i = 0; i < s.size(); ++ i){
//        watch(i);
//        watch(s[i]);
//    }

    int d = -1e9;
//    s.pb(b + 1);
    for (int i = 0; i < s.size() - k; ++ i){
        d = max(d, s[i + k] - s[i]);
    }
//    if (s.size() == k){
//        cout << b - a + 1 << endl;
//        return 0;
//    }

    if (s.size() < k){
        cout << -1 << endl;
        return 0;
    }

    d = max(d, b - s[s.size() - k] + 1);
    d = max(d, s[k - 1] - a + 1);

    cout << d << endl;
    return 0;
}
/*




*/

