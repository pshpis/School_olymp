#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)

//#define DBG_in
//#define DBG_out

typedef long long lint;

const int INF=2e9;
const lint INF64=1e18;
const double PI=3.14159265359;
const double EPS=1e-9;
const int MOD=1e9+7;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef DBG_in
        freopen("in.txt", "r", stdin);
    #endif // DEBAG_in
    #ifdef DBG_out
        freopen("out.txt", "w", stdout);
    #endif // DEBAG_out

    for (int i=1000; i<10000; i++){
        int cnt=0;
        vector<int> ans;
        for (int j=1; j<100; j++){
            int k=i-j*j;
            if (k>0 && pow2((int)sqrt(k))==k){
                cnt++;
                ans.pb(j*j);
                ans.pb(k);
            }
        }
        if (cnt>2){
            cout<<i<<endl;
            for (int j=0; j<ans.size(); j+=2)
                cout<<ans[j]<<" + "<<ans[j+1]<<endl;
        }
    }

}

