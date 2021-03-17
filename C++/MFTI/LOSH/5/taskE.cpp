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

typedef long long lint;

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
    lint n=lnext(), k=lnext()+1;
//    watch("Here");
    vector<vector<lint> > dp(2*n+3, vector<lint>(2*n+3, 0));
    dp[0][0]=1;
//    watch("Here");
    for (int i=1; i<=2*n; i++){
        dp[i][0]=dp[i-1][1];
        for (int b=1; b<=i; b++)
            dp[i][b]=dp[i-1][b-1]+dp[i-1][b+1];
    }
//    watch("Here");
    if (k>dp[2*n][0]){
        cout<<"N/A";
        return 0;
    }
    int b=0;
    string ans="";
    for (int i=0; i<=2*n-1; i++){
//        cout<<i<<" Begin"<<endl;
        if (k<=dp[2*n-i-1][b+1]){
            ans+='(';
            ++b;
        }
        else{
            ans+=')';
            k-=dp[2*n-i-1][b+1];
            b--;
        }
//        cout<<i<<" End"<<endl;
    }
//    watch(dp[6][0]);
    cout<<ans;
}

