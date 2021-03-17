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

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    ll n; ll k;
    cin >> n;
    cin >> k;
    ll k1 = k;
    vector <ll> a(n) , b(n);
    for (int i = 0; i < n; i ++) a[i] = i + 1 , b[i] = i + 1;
    ll sum = n*(n + 1) / 2;

    if (sum > k){
        cout << "-1";
        return 0;
    }

    k -= sum;
    for (int i = 0; i < n / 2 && k > 0; i ++){
        if (abs(a[i] - a[n - i - 1]) <= k){
            swap(a[i] , a[n - i - 1]);
            k -= abs(a[i] - a[n - i - 1]);
        } else {
            int d = abs(a[i] - a[n - i - 1]) - k;
            if ((n - i - 1) - d > i){
                swap(a[i] , a[n - i - 1 - d]);
                k = 0;
                break;
            }
        }
    }


    ll real_ans = 0;
    for (int i = 0; i < n; i ++){
        real_ans += max(a[i] , b[i]);
    }

    //cout << (n*(n + 1) / 2 - ((n / 2) * (n / 2 + 1) / 2))*2 << '\n';

    cout << real_ans << '\n';
    for (int i = 0; i < n; i ++){
        cout << a[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i ++){
        cout << b[i] << ' ';
    }
    cout << '\n';

}
/*
1000000 1000000000000

5 20

3 9

10 54


*/
