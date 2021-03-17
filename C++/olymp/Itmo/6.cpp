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

set<int> pr1, pr2;
int m1 = 80, m2 = 40;
int nw1 = 15, nw2 = 8;
int p1 = 42, p2 = 21;
int cnt1 = 1, cnt2 = 1;
int max_m = 420;

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

    pr1.insert(0);
    pr2.insert(0);

    int timer = 0;
    int sum_m = m1 + m2;
    while (true){
        timer ++;
        if (timer % nw1 == 0){
            pr1.insert(timer);
            sum_m += m1;
            cnt1 ++;
            if (sum_m > max_m){
                watch(timer);
                watch(cnt1);
                return 0;
            }
        }
        if (timer % nw2 == 0){
            pr2.insert(timer);
            sum_m += m2;
            cnt2 ++;
            if (sum_m > max_m){
                watch(timer);
                watch(cnt2);
                return 0;
            }
        }

        if (!pr1.empty() && timer - (*pr1.begin()) >= p1) {
            pr1.erase(pr1.begin());
            sum_m -= m1;
        }
        if (!pr2.empty() && timer - (*pr2.begin()) >= p2){
            pr2.erase(pr2.begin());
            sum_m -= m2;
        }
    }


}
/*










*/

