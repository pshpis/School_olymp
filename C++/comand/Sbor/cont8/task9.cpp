#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define eb emplace_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

//#define int int64_t

int n;
vector <ll> a;
ll sum = 0 , D , cur = 0;

ll ask(ll x){
    cout << "? " << x << endl;
    ll y; cin >> y;

    a.pb(x);
    a.pb(y);
    sum += x;

    sum -= a[cur++];

    sum += y;

    return y;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    cin >> n;
    a = vector <ll> (n - 1);

    for (int i = 0; i < n - 1; i ++){
        cin >> a[i];
        sum += a[i];
    }

    ll x = ask(1e9 - sum);


    ll D = ll(1e9) - x;

    ll sq = sqrt(D);
    int cur = 0;

    //cout << D << '\n';

    set<ll> del;
    del.insert(D);
    for (int i = 2; i <= sq; i ++){
        if (D % i == 0){
            del.insert(i);
            del.insert(D / i);
        }
    }

    for (auto t : del){
        sum -= a[cur++];

        //cout << sum + (t - (sum % t)) << '\n';

        x = ask((t - (sum % t)));
        //sum += x;

        if (x == 0){
            cout << "! " << t << endl;
            return 0;
        }
    }


}
/*
4
1 2 3



*/
