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

int get_num(string s){
    if (s.size() == 2) return 10;
    if (s[0] > '0' && s[0] <= '9') return s[0] - '0';
    if (s[0] == 'J') return 11;
    if (s[0] == 'Q') return 12;
    if (s[0] == 'K') return 13;
    if (s[0] == 'A') return 14;
    return -1;
}

string get_name(int k){
    if (k < 10){
        string x = "";
        x += '0' + k;
        return x;
    }
    if (k == 10) return "10";
    if (k == 11) return "J";
    if (k == 12) return "Q";
    if (k == 13) return "K";
    if (k == 14) return "A";
    return "0";
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

    string s;
    cin >> s;
    vector<int> a;
    for (int i = 0; i < s.size(); i ++){
        string x = "";
        if (s[i] == '1'){
            x += s[i];
            x += s[i + 1];
            a.pb(get_num(x));
            i ++;
        }
        else{
            x += s[i];
            a.pb(get_num(x));
        }
    }
    sort(a.begin(), a.end());
    for (int i = (int)(a.size() - 1); i >= 0; i --){
        cout << get_name(a[i]);
    }
}
/*




*/

