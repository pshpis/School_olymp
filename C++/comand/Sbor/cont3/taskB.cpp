#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

#define int int64_t

vector<int> q;
int n;

bool is_lok(int id){
    if (
        q[id] > q[id - 1] && q[id] >= q[id + 1] ||
        q[id] < q[id - 1] && q[id] <= q[id + 1]
    ) return true;
    else return false;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int last = -1e18;
    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        if (x != last) q.pb(x);
        last = x;
    }

    int ans = q.size();
    n = q.size();
    for (int i = 1; i < n - 1; i ++)
        if (!is_lok(i)) ans --;

    cout << ans;
}
/*



*/

