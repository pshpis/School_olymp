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

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    ll n;
    cin >> n;
    if (n % 3 == 0) cout << "Vasya";
    else cout << "Petya";
    return 0;

    if (n % 2 == 0) cout << "Petya";
    else cout << "Vasya";
}
/*



*/
