#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mp make_pair
#define pw2(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

#define ins insert
#define pb push_back
#define eb emplace_back

#define fr(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define wrvec(a) for (int i = 0; i < (a).size(); i ++) cout << (a)[i] << " "; cout << endl;
#define revfr(i, n) for(int (i) = int(n) - 1; (i) >= 0; i --)

//#define int int64_t // int -> long long

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
typedef vector<pair<int, int> > vii;
typedef set<int> si;
typedef set<pii> sii;

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

//cout for pair
template <typename T1, typename T2>

ostream& operator <<(ostream& s, const pair<T1, T2> x)
{
    s << x.fi << " " << x.se;
    return s;
}

//cin for pair
template <typename T1, typename T2>

istream& operator>>(istream& s, pair<T1, T2>& x)
{
    s >> x.fi;
    s >> x.se;
    return s;
}

template<typename type>

type next()
{type x; cin >> x; return x;}

ll next()
{ll x; cin >> x; return x;}

inline void fast_write(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out
}

void solve(){
    string s;
    set<int> a;
    while (cin >> s){
        int x = next();
//        watch(x);
        if (s[0] == 'i') a.ins(x);
        if (s[0] == 'e') {
            if (a.count(x) > 0) cout << "true\n";
            else cout << "false\n";
        }
        if (s[0] == 'd') a.erase(x);
    }
}

int32_t main()
{
    fast_write();
    solve(); //îïõ ïåüåìõõ ÿ ðåÿðþëõ ñàïþðý SOLVE õã ìþâþêþ
}
/*




*/

