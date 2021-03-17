#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

const int C = 2;

int n , q , p;
vector <ll> a , up , down , s;

void upd(int t){
    for (int i = t*C; i < min(n , (t + 1)*C); i ++){
        a[i] = max(a[i] , down[i]);
        a[i] = min(a[i] , up[i]);
    }
    if (s[t] == 1){
        sort(a.begin() + t*C , a.begin() + min((t + 1)*C , n));
    } else if (s[t] == 2){
        sort(a.begin() + t*C , a.begin() + min((t + 1)*C , n) , [](const ll &a , const ll &b){return a > b;});
    }
}

// 1 - s , 2 - r
void upd_sort(int l , int r , int type){
    int L = l / C , R = r / C;

    upd(L); upd(R);

    if (type == 1) {
        sort(a.begin() + l , a.begin() + min(r , (L + 1)*C));
        sort(a.begin() + R*C , a.begin() + min(n , r));
    } else {
        sort(a.begin() + l , a.begin() + min(r , (L + 1)*C) , [](const ll &a , const ll &b){return a > b;});
        sort(a.begin() + R*C , a.begin() + min(n , r) , [](const ll &a , const ll &b){return a > b;});
    }

    for (L = L + 1; L < R; L ++){
        s[L] = type;
    }
}

void upd_lower(int l , int r , ll x){
    int L = l / C , R = r / C;

    upd(L); upd(R);
    while(l < min(r , (L + 1)*C) && l < r){
        a[l] = max(x , a[l]);
        l++;
    }
    while(r > max(l , R*C) && l < r){
        r--;
        a[r] = max(x , a[r]);
    }

    for (L = L + 1; L < R; L ++){
        down[L] = max(down[L] , x);
        up[L] = max(up[L] , down[L]);
    }
}

void upd_upper(int l , int r , ll x){
    int L = l / C , R = r / C;


    upd(L); upd(R);
    while(l < min(r , (L + 1)*C) && l < r){
        a[l] = min(x , a[l]);
        l++;
    }
    while(r > max(l , R*C) && l < r){
        r--;
        a[r] = min(x , a[r]);
    }

    for (L = L + 1; L < R; L ++){
        up[L] = min(up[L] , x);
        down[L] = min(down[L] , up[L]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;
    p--;
    a.resize(n);
    up.assign(n , 1e18);
    down.assign(n , -1e18);
    s.assign(n , 0);
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }

    int q; cin >> q;

    while(q --> 0){
        int type , l , r;
        cin >> type >> l >> r;
        l--;
        if (type == 1){
            upd_sort(l , r , 1);
        } else if (type == 2){
            upd_sort(l , r , 2);
        } else if (type == 3){
            int x; cin >> x;
            upd_lower(l , r , x);
        } else {
            int x; cin >> x;
            upd_upper(l , r , x);
        }
    }

}
/*


*/
