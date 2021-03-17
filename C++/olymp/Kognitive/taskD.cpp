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
const int MOD = 1e9 + 7;

template<typename type>

type next()
{type x; cin >> x; return x;}

int next()
{int x; cin >> x; return x;}

ll lnext()
{ll x; cin >> x; return x;}

int n, k;

vector<int> a;
int sum = 0;
int ans = 0;

void rec(){
    if (!(k - sum <= 15 * (n - a.size()) && k - sum >= 0 && a.size() <= n)){
        return;
    }
    if (a.size() == n){
        if (sum == k){
            ans = (ans + 1) % MOD;
//            for (int i = 0; i < a.size(); i ++)
//                cout << a[i] << " ";
//            cout << "\n";
        }
        return;
    }
    for (int i = 0; i <= min(15, k - sum); i ++){
        if (i == 0 && a.size() == 0) continue;
        a.push_back(i);
        sum += i;
        if (sum > k){
            sum -= i;
            a.pop_back();
            break;
        }
        rec();
        sum -= i;
        a.pop_back();
    }
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
    rec();
    cout << ans;
}
/*




*/

