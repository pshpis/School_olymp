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

    int n;
    cin >> n;
    int min_even = 1e9, min_neven = 1e9, sum_even = 0, sum_neven = 0, sz_neven = 0, sz_even = 0;

    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        if (x % 2 == 0){
            sum_even += x;
            sz_even ++;
            min_even = min(min_even, x);
        }
        else {
            sum_neven += x;
            sz_neven ++;
            min_neven = min(min_neven, x);
        }
    }

    if (sz_even == 1 && sz_neven == 1){
        cout << -1;
        return 0;
    }

    int ans = sum_even + sum_neven;
    if (sz_neven % 2 == 1) ans -= min_neven;
    if (sz_even % 2 == 1) ans -= min_even;
    cout << ans;
}
/*



*/

