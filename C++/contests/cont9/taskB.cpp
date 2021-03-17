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

    int n= next();

    vector<int> num;
    vector<int> days;
    unordered_map<int, int> in;
    unordered_map<int, int> d;
    bool fl = true;
    unordered_set<int> not_out;

    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        int x = next();
        cnt ++;
        num.pb(x);
        if (x > 0){
            if (in[x] > 0){
                cout << -1 << endl;
                return 0;
            }
            ++ in[x];
            ++ d[x];
            not_out.insert(x);
        }
        if (x < 0){
            x = -x;
            if (d[x] == 0){
                cout << -1 << endl;
                return 0;
            }
            -- d[x];
            not_out.erase(x);
            if (not_out.empty()){
                days.pb(cnt);
                in.clear();
                d.clear();
                cnt = 0;
            }
        }
    }
    if (!not_out.empty()){
        cout << -1 << endl;
        return 0;
    }
    cout << days.size() << endl;
    for (int i = 0; i < days.size(); ++ i){
        cout << days[i] << " ";
    }
    cout << endl;

}
/*




*/

