#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double v, v_;
    cin>>v>>v_;
    double l, l_;
    cin>>l>>l_;
    if (l/v==l_/v_ || (l+l_)/v==(l+l_)/v_) cout<<"YES";
    else cout<<"NO";
}

