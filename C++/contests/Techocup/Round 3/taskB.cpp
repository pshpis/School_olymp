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

void solve(){
    int n = next();
    vector<int> p(n, 0);
    vector<int> mx(n, 0);
    set<int> num;
    for (int i = 1; i <= n; i ++) num.insert(i);
    vector<pii> mx_ind;
    for (int i = 0; i < n; i ++){
        cin >> mx[i];
        if (i == 0) p[i] = mx[i], mx_ind.eb(mx[i], i);
        else if (mx[i] != mx[i - 1]) p[i] = mx[i], mx_ind.eb(mx[i], i);
        num.erase(p[i]);
    }
    sort(mx_ind.begin(), mx_ind.end());
    for (int i = 0; i < mx_ind.size(); i ++){
        for (int j = mx_ind[i].second + 1; p[j] == 0; j++){
            p[j] = *num.begin();
            num.erase(*num.begin());
        }
    }


    for (int i = 0; i < n; i ++)
        if (p[i] > mx[i] ){
            cout << "-1" << endl;
            return;
        }
    for (int i = 0; i < n; i ++)
        cout << p[i] << " ";
    cout << endl;
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
        solve();
    }
}
/*




*/

