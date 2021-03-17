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
#define fr(i, n) for (int (i)=0; i<int(n); i++)

const bool isDbg=false;

typedef long long lint;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

lint mod=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    lint n=lnext();
    vector<vector<lint> > dp(2*n+3, vector<lint>(2*n+3, 0));
    dp[0][0]=1;
    for (int i=1; i<=2*n; i++){
        dp[i][0]=dp[i-1][1];
        for (int b=1; b<=i; b++)
            dp[i][b]=(dp[i-1][b-1]+dp[i-1][b+1])%mod;
    }
    vector<lint> dp1(2*n+3, 0);
    dp1[0]=1;
    for (lint i=2; i<=2*n; i+=2){
        for (lint x=0; x<=i-2; x+=2){
            lint y=i-x-2;
            dp1[i]+=(dp1[x]*dp1[y])%mod;
            dp1[i]+=(dp1[y]*dp[x][0])%mod;
            dp1[i]%=mod;
        }
    }
    cout<<dp1[2*n];
}
