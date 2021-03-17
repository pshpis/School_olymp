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

#define int int64_t

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

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    int n=next();
    vector<int> num;
    int mx=-1;
    for (int i=0; i<n; i++){
        int x=next();
        num.push_back(x);
        mx=max(mx, x);
    }
    for (int i=0; i<n; i++){
        num[i]=mx-num[i];
    }
    vector<int> no_zero;
    for (int i=0; i<n; i++){
        if (num[i]!=0) no_zero.push_back(num[i]);
    }

//    cout<<"THIS IS NO ZERO"<<endl;
//    for (int i=0; i<no_zero.size(); i++) cout<<no_zero[i]<<" ";
//    cout<<endl;

    int gcd=0;
    if (no_zero.size()>0) gcd=no_zero[0];
    for (int i=1; i<no_zero.size(); i++){
        gcd=__gcd(no_zero[i], gcd);
    }
    int ans=0;
    for (int i=0; i<no_zero.size(); i++)
        ans+=no_zero[i]/gcd;
    cout<<ans<<" "<<gcd;


}

