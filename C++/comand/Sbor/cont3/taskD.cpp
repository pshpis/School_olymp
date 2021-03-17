#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

vector <ll> F(1e3 + 1);
//vector < vector <ll> > S(1e3 + 1 , vector <ll> (1e3 + 1));
//
//
//ll binPow(ll x , ll n , ll m){
//    ll res = 1;
//    while(n){
//        if (n & 1){
//            res = res*x % m;
//        }
//        x = x*x % m;
//        n /= 2;
//    }
//    return res;
//}

ll C(int n , int k , ll m){
    return (((F[n] * binPow(F[k] , m - 2 , m)) % m) * binPow(F[n - k] , m - 2 , m)) % m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n , k , m; cin >> n >> k >> m;
    F[1] = 1;
    F[0] = 1;
    for (int i = 2; i <= 1e3; i ++){
        F[i] = F[i - 1]*i % m;
    }

//    for (int i = 1; i <= 1e3; i ++){
//        S[i][i] = 1;
//        for (int j = i + 1; j <= 1e3; j ++){
//            S[i][j] = j*S[i][j - 1] % m;
//        }
//    }

    //ll ans = (C(n - 2 , k - 1 , m)*S[k][n - 1] % m);
    //cout << S[k][n - 1] << '\n';
    //ll ans = ((C(n - 1 , k , m)*F[n - 2] % m)*binPow(F[k - 1] , m - 2 , m) % m)*binPow(F[n - k - 1] , m - 2 , m) % m;
    cout << ans;

}
/*



*/
