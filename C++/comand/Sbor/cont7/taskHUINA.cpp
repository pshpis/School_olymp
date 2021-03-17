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
    if (n == 1){
        cout << "! " << 1 << endl;
        return 0;
    }
    if (n == 2){
        cout << "? 1" << endl;
        int x;
        cin >> x;
        if (x == 0) cout << "! " << 1 << endl;
        else cout << "! " << 2 << endl;
        return 0;
    }
    cout << "? " << n << endl;
    int x; cin >> x;
    n -= x;

    vector <int> del;
    for (int i = 2; i <= n; i ++){
        if (n % i == 0){
            del.pb(i);
        }
    }

    int l = -1 , r = del.size() - 1;

    cout << "? " << 1 << endl;
    cin >> x;
    if (x == 0){
        cout << "! " << 1 << endl;
        return 0;
    }

    while(r - l > 1){
        int m = ((l + r) / 2), x;
        cout << "? " << del[m] - 1  << endl;
        cin >> x;
        if (x == del[m] - 1) l = m;
        else r = m;

    }

    cout << "! " << del[l] << endl;

}
/*



*/
