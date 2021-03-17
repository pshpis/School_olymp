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

int main()
{
    ios::sync_with_stdio(false);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    lint n=lnext(), k=lnext()+1, max_n=100;
    if (n==0){
        if (k==1) cout<<0<<endl;
        else cout<<"N/A";
        return 0;
    }
    vector<vector<lint> > dp(2*max_n+2, vector<lint>(2*max_n+2, 0));
    for (lint t=max_n; t>=1; t--){
        for (lint i=1; i<=n; i++){
            if (t>i){
                dp[i][t]=0;
                continue;
            }
            if (i==t){
                dp[i][t]=1;
                continue;
            }
            dp[i][t]=dp[i-t][t]+dp[i][t+1];
        }
    }
    if (dp[n][1]<k) {
        cout<<"N/A";
        return 0;
    }
    vector<lint> ans;
    lint s=0;
    lint t=1;
//    watch("here");
    lint cnt=0;
    while(n>s){
//        watch(cnt);
        lint cnt_=0;
        while(n-s-t>0 && dp[n-s-t][t]<k){
//            cout<<endl<<"I am in the second cycle"<<endl;
//            watch(cnt_);
            k-=dp[n-s-t][t];
//            watch(k);
            ++t;
//            watch(t);
            cnt_++;
//            cout<<"End of second cycle"<<endl;
        }
//        watch(k);
//        watch(t);
        ans.push_back(t);
        s+=t;
//        watch(s);
        cnt++;
    }
//    watch("there");

    cout<<ans.size()<<endl;
    for (int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}

