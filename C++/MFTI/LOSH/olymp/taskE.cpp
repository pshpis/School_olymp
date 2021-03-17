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

lint bin_find(vector<lint>& num, lint l, lint r, lint need){
    if (r-l<=1) return l;
    lint c=(l+r)/2;
    if (num[c]>need) return bin_find(num, l, c, need);
    else return bin_find(num, c, r, need);
}
int main()
{
    ios::sync_with_stdio(false);
    lint n=lnext();
    vector<lint> h;
    for (int i=0; i<n; i++)
        h.push_back(lnext());
    lint sum=0;
    for (int i=0; i<n; i++){
        sum+=h[i];
    }
    sort(h.begin(), h.end());
    lint m=lnext();
    vector<lint> suf_sum(n+1, 0);
    for (int i=n-1; i>=0; i--){
        suf_sum[n-i]=suf_sum[n-i-1]+h[i];
    }

    for (lint i=0; i<m; i++){
        lint need_h=lnext();
//        lint ans=0;
//        for (int i=0; i<n; i++){
//            ans+=max(h[i]-need_h, (lint)0);
//        }
//        cout<<ans<<"\n";
//        continue;
        if (need_h==0){
            cout<<sum<<"\n";
            continue;
        }
        lint pl=bin_find(h, 0, n-1, need_h);
        cout<<max(suf_sum[n-pl]-need_h*(n-pl), (lint)0)<<"\n";
    }
}

