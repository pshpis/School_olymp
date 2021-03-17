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

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    string s = "";
    for (int i = 0; i < 40; i ++){
        s += (__builtin_popcount(i) % 2) + 'A';
    }
    int n = s.size();
    vector <string> a;
    for (int i = 0; i < n; i ++){
        a.pb(s.substr(i , n - i));
    }
    sort(a.begin() , a.end());

    for (int i = 0; i < n; i ++){
        cout << a[i] << '\n';
    }

}
/*



*/
