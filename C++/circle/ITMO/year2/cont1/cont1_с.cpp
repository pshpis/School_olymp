#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)

#define int int64_t
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

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef DBG_in
        freopen("C:\Users\pshpi\OneDrive\Desktop\in.txt", "r", stdin);
    #endif // DEBAG_in
    #ifdef DBG_out
        freopen("C:\Users\pshpi\OneDrive\Desktop\out.txt", "w", stdout);
    #endif // DEBAG_out

    int n=next(), m=next();
    vector<int> num;
    set<int> fnd;
    vector<int> pr_sum;
    pr_sum.pb(0);
    for (int i=0; i<n; i++){
        int x=next();
        pr_sum.pb(x+pr_sum.back());
        num.pb(x);
        fnd.insert(x);
    }
    for (int i=0; i<m; i++){
        int L=next()-1, R=next()-1;
        int sm=pr_sum[R+1]-pr_sum[L];
        int k=R-L+1;
        if (sm%k!=0) sm+=k;
        int ans=*fnd.lower_bound(sm/k);
        cout<<ans<<endl;
    }
}

