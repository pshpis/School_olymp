#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int w, h, l;
    cin >> w >> h >> l;
    int v0, n;
    cin >> v0 >> n;

    int v_max = w * h * l;

    int u = v0;

    for (int i = 0; i < n; i ++){
        int x; cin >> x;
        v0 += x;
    }

    if (v_max == 0){
        cout << 0;
        return 0;
    }
    cout << max((int) 0, min(u, v0 - v_max));
}
