#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

#define int int64_t

int n , q;
vector <pii> lg;
vector <int> a;
vector <ll> sum;
vector <ll> ans;

void solve(int j){
    vector <int> b(n + q , 0);
    for (int i = 0; i < n; i ++){
        b[i] = ((a[i] >> j) & 1);
        sum[j] += b[i];
    }

    int cnt = n , id = n;
    vector<int> ids;
    vector <int> p(n + q , -1);
    for (int i = 0; i < q; i ++){
        int type = lg[i].fi , x = lg[i].se;
        if (type == 1){
            b[id] = ((x >> j) & 1);
            sum[j] += b[id];
            p[id] = i;
            id++ , cnt++;
        } else if (type == 2){
            x--;
            cnt--;
            if (ids.size() == 0 || ((int(ids.size()) - (lower_bound(ids.begin() , ids.end() , p[x]) - ids.begin())) % 2 == 0)){
                sum[j] -= b[x];
            } else {
                sum[j] -= (b[x] ^ 1);
            }
        } else {
            if (((x >> j) & 1)){
                ids.pb(i);
                sum[j] = cnt - sum[j];
            }
        }
        ans[i] += (sum[j] << j);
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    cin >> n >> q;
    a = vector <int> (n + q);
    sum.assign(31 , 0);
    ans.assign(q , 0);
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    //cout << awk << '\n';
    lg = vector <pii> (q);
    for (int i = 0; i < q; i ++){
        cin >> lg[i].fi >> lg[i].se;
    }

    for (int j = 0; j <= 30; j ++){
        solve(j);
    }

    for (int i = 0; i < q; i ++){
        cout << ans[i] << '\n';
    }

}
/*
6 2
2 3 9 5 6 6
1 3
3 5


6 5
2 3 9 5 6 6
1 3
3 5
2 2
3 2
2 7



*/
