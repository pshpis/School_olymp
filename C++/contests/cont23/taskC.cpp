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
#define wrvec(a) for (int i = 0; i < (a).size(); i ++) cout << (a)[i] + 1 << " "; cout << endl;
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

    int n = next();
    vi give(n, -1);
    fr(i, n) give[i] = next() - 1;

    vi get(n, -1);

    fr(i, n){
        if (give[i] == -1) continue;
        get[give[i]] = i;
    }

    vi not_have_but_give, not_have_not_give;

    fr(i, n){
        if (give[i] != -1 && get[i] == -1) not_have_but_give.pb(i);
        if (give[i] == -1 && get[i] == -1) not_have_not_give.pb(i);
    }

    fr(i, not_have_not_give.size()){
        give[not_have_not_give[i]] = not_have_not_give[(i + 1) % not_have_not_give.size()];
    }

    if (not_have_not_give.size() == 1){
        give[not_have_not_give[0]] = not_have_but_give.back();
        not_have_but_give.pop_back();
        not_have_but_give.push_back(not_have_not_give[0]);
    }

    fr(i, n){
        if (give[i] == -1){
            give[i] = not_have_but_give.back();
            not_have_but_give.pop_back();
        }
    }

    wrvec(give);

}
/*




*/

