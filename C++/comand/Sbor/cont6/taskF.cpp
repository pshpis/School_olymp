#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

#define int int64_t

int n;
vector <int> pref[4];
vector <int> l , r;

void upd(int i , int x , int id){
    while(i < n){
        pref[id][i] += x;
        i = i | (i + 1);
    }
}

int sum(int i , int id){
    int ans = 0;
    while(i >= 0){
        ans += pref[id][i];
        i = (i & (i + 1)) - 1;
    }
    return ans;
}

int solve(int k){
    int ans = 0;

    int id_l = upper_bound(l.begin() , l.end() , k) - l.begin();
    int id_r = upper_bound(r.begin() , r.end() , k) - r.begin();

    id_l-- , id_r--;

    int xl , xr;


    if (xl >= 0){
        xl = sum(id_l , 2);
        ans += xl*k - sum(id_l , 0);
    }

    if (xr >= 0){
        xr = sum(id_r , 3);
        ans += xr*k  - sum(id_r , 1);

    }

    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    cin >> n;
    vector <pii> q(n);
    l = r = vector <int>(n);


    pref[0] = pref[1] = pref[2] = pref[3] = vector <int> (n , 0);
    for (int i = 0; i < n; i ++){
        cin >> q[i].fi >> q[i].se;
        l[i] = q[i].fi;
        r[i] = q[i].se;
    }

    sort(l.begin() , l.end());
    sort(r.begin() , r.end());

    int cur = 0;
    for (int i = 0; i < n; i ++){
        int L = q[i].fi , R = q[i].se;
        cur += (R - L + 1);
        int ans = 0;

        int id_l = lower_bound(l.begin() , l.end() , L) - l.begin();
        upd(id_l , L , 0);

        upd(id_l , 1 , 2);
        int id_r = lower_bound(r.begin() , r.end() , R) - r.begin();
        upd(id_r , R , 1);
        upd(id_r , 1 , 3);

        int a = 0 , b = 1e9 + 1;

        //cout << "cur : " << (cur + 1) / 2 << '\n';

        while(b - a > 1){
            int m = (a + b) / 2;

            if (solve(m) < (cur + 1) / 2) a = m;
            else b = m;
        }

        cout << a << '\n';
    }

    //cout << solve(8) << '\n';

}
/*
2
4 8
7 10


1
1 5

2
1 5
1 5


3
4 8
7 10
1 5


*/
