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
    int n = next();
    vector<int> a, b;
    for (int i = 0; i < n; ++ i)
        a.pb(next());
    for (int i = 0; i < n; ++ i)
        b.pb(next());

    bool fl = false;
    bool ln = false;
    bool ans = true;
    int d = -1e9;
    for (int i = 0; i < n; ++ i){
        if (a[i] != b[i] && ln){
            ans = false;
//            cout<<"1"<<endl;
//            watch(i);
            break;
        }
        if (a[i] != b[i] && !ln){
            if (fl){
                int d_ = a[i] - b[i];
//                watch(d_);
                if (d_ != d){
                    ans = false;
//                    watch(i);
                    break;
                }
            }
            if (!fl){
                d = a[i] - b[i];
            }
            fl = true;
        }
        else if (fl) ln = true;
    }
    if (ans && d > 0) ans = false;
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
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
    for (int i = 0; i < q; ++ i){
        test();
    }

}
/*




*/

