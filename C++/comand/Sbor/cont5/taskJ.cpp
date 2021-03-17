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

const int MOD = 1e9 + 7;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i ++){
        cin >> num[i];
    }
    vector<int> suf(n);
    suf[n - 1] = num[n - 1];
    for (int i = n - 2; i >= 0; i --){
        suf[i] = (suf[i + 1] + num[i]) % MOD;
    }

    vector<int> suf2(n, 0);
    for (int i = 0; i < n - 1; i ++){
        suf2[i] = (suf[i + 1] * num[i]) % MOD;
    }

    for (int i = n - 2; i >= 0; i --){
        suf2[i] += suf2[i + 1];
        suf2[i] %= MOD;
    }

    vector<int> suf3(n);
    for (int i = 0; i < n - 1; i ++){
        suf3[i] = (suf2[i + 1] * num[i]) % MOD;
    }

    for (int i = n - 2; i >= 0; i --){
        suf3[i] += suf3[i + 1];
        suf3[i] %= MOD;
    }

    cout << suf3[0];
}
/*



*/

