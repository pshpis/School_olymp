#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

//#define int int64_t

const long double eps = 1e-6;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    string ans1 = "Whatever", ans2 = "Power up, Evolve", ans3 = "Evolve, Power up";
    string n1, n2;
    long double inc, mul, inc_;
    cin >> n1 >> inc >> n2 >> mul >> inc_;
    if (abs(inc * mul - inc_) < eps) cout << ans1;
    else if (inc * mul - inc_ > eps) cout << ans2;
    else if (inc * mul - inc_ < eps) cout << ans3;
}
/*



*/

