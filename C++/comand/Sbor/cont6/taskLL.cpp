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

    int n; cin >> n;
    vector < vector <ll> > a(n , vector <ll> (n));
    ll ans = 0;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cin >> a[i][j];
        }
    }

    if (n == 1){
        cout << a[0][0];
        return 0;
    }

    int N = 1;
    while(N*2 <= n - 1) N *= 2;

    vector < vector <ll> > b(n , vector <ll> (n));

    while (n - 1 != N){
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++){
                b[i][j] = a[i][j];
            }
        }

        n--;

        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++){
                a[i][j] = b[i][j] ^ b[i + 1][j] ^ b[i][j + 1] ^ b[i + 1][j + 1];
            }
        }
    }

    if (n > 1)
        ans = a[0][0] ^ a[n - 1][0] ^ a[0][n - 1] ^ a[n - 1][n - 1];
    else
        ans = a[0][0];

    cout << ans;

}
/*
3
0 7 2
3 6 4
1 8 5


4
1 2 3 4
3 4 1 2
1 2 3 4
3 4 1 ttyo]l.fjljj
2


*/
