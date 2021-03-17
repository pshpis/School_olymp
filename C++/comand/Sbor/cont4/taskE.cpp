#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

#define int int64_t

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    int n;
    cin >> n;
    vector<int> num(n);
    vector<pii> pref(n);
    for (int i = 0;  i < n; i ++)
        cin >> num[i];
    for (int i = n - 1; i >= 0; i --){
        if (i == n - 1) pref[i] = mp(num[i], i);
        else{
            pref[i] = pref[i + 1];
            if (num[i] < pref[i + 1].fi) pref[i] = mp(num[i], i);
        }
    }

    int left = 0, id = 0, ans = 0;
    while (id < n){
        ans += pref[id].fi * (pref[id].se - left + 1);
        left = pref[id].se + 1;
        id = left;
    }
    cout << ans;
}
/*



*/

