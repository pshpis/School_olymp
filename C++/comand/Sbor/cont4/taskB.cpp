#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    int n, m, k;
    cin >> n >> m >> k;
    cout << (n * m + min(n,  k) - 1) / min(n, k);
}
/*



*/

