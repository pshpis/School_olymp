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

string test(string s){
    int n = s.size();

    string nw = "";
    for (int i = 0; i < n; i ++){
        nw += s[i];
        if (i != n - 1) nw += "*";
    }

    s = nw;
//    watch(s);
    n = s.size();

    int r = -1;
    deque<pii> a;

    for (int i = 1; i < n; i += 2){
            int f;
//        cout << i << endl;
//        watch(r);
        int j;
        for (j = i + 1; j < n && 2 * i - j > r; j ++){
            if (s[j] != s[2 * i - j]){
                f = j - 1;
//                watch(j);
                if (f != i){
                    a.pb(mp(2 * i - j + 1, j - 1));
                    r = f;
                }
                i = f;
                break;
            }
        }
        if (2 * i - j == r || j == n){
            r = j;
            if (r != i) a.pb(mp(2 * i - j + 1, j - 1));
            i = r;
//            cout << "fucking if" << endl;
        }

    }

//    cout << "here" << endl;

    string ans = "";
    for (int i = 0; i < n; i ++){
        if (!a.empty() && i == a[0].fi){
            i = a[0].se ;
            a.pop_front();
        }

        else {
            ans += s[i];
        }
    }

    string res = "";

    for (char v: ans) if (v != '*') res += v;

    return res;
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
    for (int i = 0; i < 50; i ++) s = test(s);

    cout << s;

}
/*




*/

