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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    int n; ll k;
    cin >> n >> k;
    vector <ll> a(n);
    unordered_map<ll , ll> cnt;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin() , a.end());
    a.erase(unique(a.begin() , a.end()) , a.end());

    n = a.size();
    int l = 0 , r = n - 1;

    ll ans = a[r] - a[l];
    int I = 1;
    while(k > 0 && l < r){
        //cout << I << ": ";
        if (cnt[a[l]] < cnt[a[r]]){
            if (cnt[a[l]] * (a[l + 1] - a[l]) <= k){
                //cout << "case 1 ";
                k -= cnt[a[l]] * (a[l + 1] - a[l]);
                cnt[a[l + 1]] += cnt[a[l]];
                l++;
                ans = min(ans , a[r] - a[l]);
            } else {
                //cout << "case 2 ";
                ans = max(0ll , ans - k / cnt[a[l]]);
                k = 0;
            }
        } else {
            if (cnt[a[r]] * (a[r] - a[r - 1]) <= k){
                //cout << "case 3 ";
                k -= cnt[a[r]] * (a[r] - a[r - 1]);
                cnt[a[r - 1]] += cnt[a[r]];
                r--;
                ans = min(ans , a[r] - a[l]);
            } else {
                //cout << "case 4 ";
                ans = max(0ll , ans - k / cnt[a[r]]);
                k = 0;
            }
        }
       // cout << ans << ' ' << k << '\n';
    }

    cout << ans;

}
/*
3 1
100 110 100


2 2
1 3


10 9
4 5 5 7 5 4 5 2 4 3

3 10
100 100 100

4 5
3 1 7 5

4 1
3 1 7 5



*/
