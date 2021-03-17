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

    int k, n;
    cin >> k >> n;
    vector<vector<int> > tr(k);
    for (int i = 0; i < n ; i ++){
        int id, p;
        cin >> id >> p;
        tr[p - 1].pb(id);
    }
    for (int i = 0; i < k; i ++){
        cout << tr[i].size() << " ";
        for (int j = (int)tr[i].size() - 1; j >= 0; j --){
            cout << tr[i][j] << " ";
        }
        cout << "\n";
    }
}
/*



*/

