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

const int MAXN = 5e5 + 10;

//Fenvik with 1 indexation

vector<int> a(MAXN, -INF64);
vector<int> t(MAXN, 0);

int sum(int r){
    if (r == 0) return 0;
    int ans = 0;
    for (;r > 0; r -= (r & -r)){
        ans += t[r];
    }
    return ans;
}

void add(int pl, int d){
    for (;pl <= MAXN; pl += (pl & -pl)){
        t[pl] += d;
    }
}

int sum(int l, int r){
    return sum(r) - sum(l - 1);
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

    int n = next();
    for (int i = 0; i < n; i ++){
        int x = next();
        a[i] = x;
        add(i + 1, x);
    }

//    cout << "I start" << endl;

    string s;
    while (cin >> s){
        int p1 = next(), p2 = next();
        if (s == "sum"){
            cout << sum(p1, p2) << "\n";
        }
        else {
            if (a[p1 - 1] == -INF64){
                add(p1, p2);
                a[p1 - 1] = p2;
            }
            else{
                add(p1, p2 - a[p1 - 1]);
                a[p1 - 1] = p2;
            }

        }
    }

}
/*




*/

