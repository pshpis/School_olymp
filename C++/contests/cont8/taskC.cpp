#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)
#define fi first
#define se second

#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;

const int INF=2e9;
const ll INF64=1e18;
const double PI=3.14159265359;
const double EPS=1e-9;
const int MOD=1e9+7;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

ll lnext()
{ll x;cin>>x;return x;}

const ll MAX_N = 1e12+1;

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

    int n = lnext(), k = sqrt(MAX_N);
//    vector<bool> prime(k + 1, true);
//    prime[0] = false;
//    prime[1] = false;
//    for (int i = 2; i <= k; ++ i){
//        if (prime[i])
//        if (i * 1ll * i <= n)
//            for (int j = i * i; j <= n; j += i)
//                prime[j] = false;
//    }
    int fi = -1;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0){
            fi = i;
            break;
        }
    if (fi == -1){
        cout<<n;
        return 0;
    }
    while (n % fi == 0){
        n /= fi;
    }
    if (n == 1){
        cout<<fi;
    }
    else cout<<1;
}

