#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

const ld eps = 1e-12;

ld R , x , y , D , Ds;

ld solve(ld r){
    ld F1 , F2 , S1 , S2;
    F1 = 2*acosl((r*r - R*R + Ds) / (2*r*D));
    F2 = 2*acosl((-r*r + R*R + Ds) / (2*R*D));
    S1 = r*r*(F1 - sinl(F1)) / 2;
    S2 = R*R*(F2 - sinl(F2)) / 2;

    //cout << S1 + S2 << '\n';
    return S1 + S2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    cin >> R >> x >> y;

    if (abs(x) < eps && abs(y) < eps){
        cout << R * sqrt(1.0 / 3.0) << '\n' << R*sqrt(2.0 / 3.0);
        return 0;
    }

    Ds = x*x + y*y;
    D = sqrt(x*x + y*y);

    ld S = acosl(-1)*R*R / 3;
    //cout << acos(-1) << '\n';

    ld l = 0 , r = 2*R;
    while(abs(l - r) > eps){
        ld m = (l + r) / 2;
        if(solve(m) > S) r = m;
        else l = m;
    }
    ld R1 = (l + r) / 2;

    l = 0 , r = 2*D;
    int cnt = 0;
    while(abs(l - r) > eps){
        cnt++;
        ld m = (l + r) / 2;
        if(solve(m) > 2*S) r = m;
        else l = m;
    }
    //cout << cnt << '\n';
    ld R2 = (l + r) / 2;

   // cout << S << '\n';
    //cout << solve(R1) << '\n';

    cout << R1 << '\n' << R2 << '\n';


}
/*
1.0
0.47 0.64



*/
