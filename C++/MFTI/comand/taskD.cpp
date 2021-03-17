#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main(){
    int x, y;
    cin >> x >> y;
    if (min(x, y) == 0) cout << max(x, y);
    else cout << min(x, y);

}
