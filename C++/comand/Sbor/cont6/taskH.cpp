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

    int n; cin >> n;
    vector <int> x(n) , y(n);
    set<pair <int , int> > s;
    for (int i = 0; i < n; i ++){
        cin >> x[i] >> y[i];
        x[i] *= 2 , y[i] *= 2;
        s.insert({x[i] , y[i]});
    }

    int ans = 0;
    for (int i = 0; i < n;  i ++){
        for (int j = 0; j < n; j ++){
//            ll D = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
//            if (D % 2 != 0 || ll(sqrt(D/2))*ll(sqrt(D/2)) != D/2) continue;

            //cout << i << ' ' << j << '\n';
            ll X = (x[i] + x[j]) / 2 , Y = (y[i] + y[j]) / 2;

            x[i] -= X , y[i] -= Y;
            x[j] -= X , y[j] -= Y;
            //cout << x[i] << ' ' << y[i] << ' ' << x[j] << ' ' << y[j] << '\n';
            if (x[i] != -x[j] || y[i] != -y[j] || !s.count({-y[i] + X , x[i] + Y}) || !s.count({y[i] + X , -x[i] + Y})) {
                x[i] += X , y[i] += Y;
                x[j] += X , y[j] += Y;
                continue;
            }
            x[i] += X , y[i] += Y;
            x[j] += X , y[j] += Y;


            //cout << x[i] << ' ' << y[i] << ' ' << x[j] << ' ' << y[j] << '\n';


            ans++;
        }
    }
    cout << ans / 4;

}
/*
8
0 0
1 1
1 0
0 1
5 7
7 7
6 6
6 8

4
0 1
0 2
2 5
3 8



*/
