#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, r;
    cin >> n >> k >> r;
    cout << (n / __gcd(n, k)) * (k + r) - r;
}

