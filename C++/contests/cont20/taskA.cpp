#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mp make_pair
#define pw2(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()

#define fi first
#define se second
#define th third

#define ins insert
#define pb push_back
#define eb emplace_back

#define fr(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define wrvec(a) for (int i = 0; i < (a).size(); i ++) cout << (a)[i] << " "; cout << endl;
#define revfr(i, n) for(int (i) = int(n) - 1; (i) >= 0; i --)

#define int int64_t // int -> long long

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[] = "input.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "output.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int> > vii;
typedef set<int> si;
typedef set<pii> sii;

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

template<typename type>

type next()
{type x; cin >> x; return x;}

ll next()
{ll x; cin >> x; return x;}

int n, k;

string get_new(string per){
    string nw = "";
    while (nw.size() + k <= n){
        nw += per;
    }

    int cnt = 0;
    while (nw.size() < n){
        nw += per[cnt];
        cnt ++;
    }

    return nw;

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

    n = next(); k = next();
    string s;
    cin >> s;
    string up = "";
    while (up.size() < n + 1){
        if (up.size() % k == 0) up += "1";
        else up += "0";
    }

    string per = "";
    for (int i = 0; i < k; i ++) per += s[i];

    string nw = get_new(per);
    if (nw >= s){
        cout << nw.size() << endl;
        cout << nw << endl;
        return 0;
    }

    bool is_upd = false;
    for (int i = k - 1; i >= 0; i --){
        if (per[i] != '9'){
            per[i] ++;
            is_upd = true;
            break;
        }
        else {
            per[i] = '0';
        }
    }


    if (is_upd){
        string ans = get_new(per);
        cout << ans.size() << endl;
        cout << ans << endl;
        return 0;
    }
    else {
        cout << up.size() << endl;
        cout << up << endl;
        return 0;
    }


}
/*




*/

