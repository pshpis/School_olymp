#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

int main(){
    int mnn,mxn,mns,mxs;
    cin >> mnn >> mxn >> mns >> mxs;
    int t,d;
    cin >> t >> d;
    bool p=true;
    if (mns>mxn || mns>mnn) p=false;
    for (int i=0;i<=mxn-mxs;i++)
        if (i*t>=d) p=false;
    if (p) cout << "YES\n";
    else cout << "NO\n";
}

