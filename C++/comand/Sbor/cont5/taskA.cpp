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
    vector <ll> x(n) , y(n);
    for (int i = 0; i < n; i ++){
        cin >> x[i] >> y[i];
    }
    ll A = y[0] - y[1] , B = x[1] - x[0] , C = -x[0]*(y[0] - y[1]) + y[0]*(x[0] - x[1]);
    for (int i = 2; i < n; i ++){
        if (A*x[i] + B*y[i] + C != 0){
            cout << "Yes\n";
            cout << "1 2 " << i + 1;
            return 0;
        }
    }
    cout << "No";

}
/*

3
1 1
2 2
2 3

5
1 2
0 0
3 6
4 8
4 4



*/

