#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector <ll> a(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    vector <ll> dp_even(n , 0) , dp_odd(n , 0);
    for (int i = 0; i < n; i ++){
        if (i % 2 == 0){
            dp_even[i] = a[i];
            if (i > 0 && dp_even[i - 1] > 0) dp_even[i] += dp_even[i - 1];
        } else {
            dp_even[i] = dp_even[i - 1] - a[i];
        }
    }
    for (int i = 1; i < n; i ++){
        if (i % 2 == 1){
            dp_odd[i] = a[i];
            if (i > 1 && dp_odd[i - 1] > 0) dp_odd[i] += dp_odd[i - 1];
        } else {
            dp_odd[i] = dp_odd[i - 1] - a[i];
        }
    }

//    for (int i = 0; i < n; i ++){
//        cout << dp_even[i] << ' ';
//    } cout << '\n';

    cout << max(max(*max_element(dp_even.begin() , dp_even.end()) , *max_element(dp_odd.begin() , dp_odd.end())) , 0ll);

}
/*
5
1 2 3 4 5

5
1 -2 3 -4 5

5
-1 -2 -3 -4 -5

*/
