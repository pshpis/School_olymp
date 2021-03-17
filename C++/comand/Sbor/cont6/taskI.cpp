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

int n , k;
ll ans = 0;
// x - y + n - 1 : 0
// x + y         : 1
vector <int> cnt[2];
vector <int> fix;
vector <bool> was;

void solve(int id){
    if (id >= n){
//        for (int i = 0; i < n; i ++){
//            cout << was[i] << " ";
//        }cout << '\n';

        ans++;
        return;
    }

    if (fix[id] != -1){
        solve(id + 1);
    }

    for (int i = 0; i < n; i ++){
        if (was[i] || cnt[0][ id - i + n - 1 ] || cnt[1][ id + i ]) continue;

        was[i] = true;
        cnt[0][ id - i + n - 1 ]++;
        cnt[1][ id + i ]++;

        solve(id + 1);

        was[i] = false;
        cnt[0][ id - i + n - 1 ]--;
        cnt[1][ id + i ]--;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    cin >> n >> k;
    cnt[0].assign(n*2 , 0); cnt[1].assign(2*n , 0);

    fix.assign(n , -1);
    was.assign(n , false);
    for (int i = 0; i < k; i ++){
        int x , y;
        cin >> x >> y;
        x-- , y--;
        fix[x] = y;

        was[y] = true;

        cnt[0][ x - y + n - 1]++;
        cnt[1][ x + y ]++;
    }



    solve(0);

    cout << ans;
}
/*

8 2
2 4
4 5



*/
