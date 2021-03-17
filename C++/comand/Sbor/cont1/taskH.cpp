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
    vector <int> a(n) , b(n);
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++){
        cin >> b[i];
    }

    sort(a.begin() , a.end());
    sort(b.begin() , b.end());

    int p; cin >> p;

    ll ans = 1;
    for (int Pa = 0 , Pb = 0; Pa < n; Pa++){
        while(Pb < n && b[Pb] <= a[Pa]) Pb++;
        ans = (ans * (Pb - Pa)) % p;
    }

    cout << ans;



}
/*
3
3 3 3
1 1 1
100

3
1 2 3
1 2 3
100


*/
