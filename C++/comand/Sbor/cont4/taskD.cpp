#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    int n;
    cin >> n;
    int left = 2000, right = -1;
    int cnt = 0;
    for (int i = 0; i < n; i ++ ){
        char x;
        cin >> x;
        if (x == '1'){
            left = min(left, i);
            right = max(right, i);
            cnt ++;
        }
    }

    if (cnt == 0){
        cout << n;
        return 0;
    }

    int ans1 = (n - left) * 2, ans2 = (right + 1) * 2;
    int ans = max(ans1, ans2);
    cout << ans;
}
/*



*/
