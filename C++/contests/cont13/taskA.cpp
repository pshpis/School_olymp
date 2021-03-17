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
    int n = s.size();
    vector<int> let(26, 0);
    for (int i = 0; i < n; i ++){
        let[(int)(s[i] - 'a')] ++;
    }
    string pass;
    cin >> pass;
    int m = pass.size();
    if (m < n){
        cout << "NO\n";
        return;
    }

//    cout << "HERE" << endl;

    vector<vector<int> > pref(26, vector<int>(m + 1, 0));
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < 26; j ++){
            pref[j][i + 1] = pref[j][i];
        }
        pref[(int)(pass[i] - 'a')][i + 1] ++;
    }

//    cout << "THERE" << endl;
//    for (int i = 0; i <= m; i ++){
//        cout << i << " " << pref[0][i] << endl;
//    }
    for (int i = n; i <= m; i ++){
        bool fl = true;
        for (int j = 0; j < 26; j ++){
            int k = pref[j][i] - pref[j][i - n];
            if (k != let[j]) fl = false;
        }
        if (fl) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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

    int t; cin >> t;

    for (int i = 0; i < t; i ++){
        test();
    }

}
/*




*/

