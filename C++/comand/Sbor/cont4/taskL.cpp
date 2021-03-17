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

ll solve(int n , ll k){
    ll k1 = k;
    vector <int> a(n) , b(n);
    iota(a.begin() , a.end() , 1);
    iota(b.begin() , b.end() , 1);
    ll sum = n*(n + 1) / 2;

    if (sum > k){
        //cout << "-1";
        return -1;
    }

    k -= sum;
    for (int i = 0; i < n / 2; i ++){
        if (abs(a[i] - a[n - i - 1]) <= k){
            swap(a[i] , a[n - i - 1]);
            k -= abs(a[i] - a[n - i - 1]);
        } else {
            ll d = abs(a[i] - a[n - i - 1]) - k;
            if ((n - i - 1) - d > i){
                swap(a[i] , a[n - i - 1 - d]);
                k = 0;
                break;
            }
        }
    }

//cout << k1 - k << '\n';

    ll real_ans = 0;
    for (int i = 0; i < n; i ++){
        real_ans += max(a[i] , b[i]);
    }
    //return real_ans - k1;
    cout << real_ans << '\n';
    for (int i = 0; i < n; i ++){
        cout << a[i] << ' ';
        real_ans += max(a[i] , b[i]);
    }
    cout << '\n';
    for (int i = 0; i < n; i ++){
        cout << b[i] << ' ';
    }
    cout << '\n';


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    int n; ll k;
//    cin >> n >> k;

    for (n = 1; n <= 5; n ++){
        for (k = 1; k <= n*n; k ++){
            if (solve(n , k) > 0){
                //cout << n << ' ' << k << '\n';
            }
        }
    }

    //cout << real_ans << '\n';

}
/*

5 20

3 9

10 54


*/
