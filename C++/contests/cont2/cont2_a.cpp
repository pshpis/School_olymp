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
    int n=next(), m=next();
    lint ans=0;
    lint cnt=0;
    lint max_cnt=(n+1)/2;
    lint p=0;
    vector<int> dr(m, 0);
    for (int i=0; i<n; i++){
        int x=next()-1;
        dr[x]++;
    }
    for (int i=0; i<m; i++){
        int x=dr[i];
        ans+=x-x%2;
        cnt+=x/2;
        p+=x%2;
    }
//    for (int i=0; i<n; i++){
//        int x=next();
//        dr.push_back(x%2);
//        ans+=x%2;
//        cnt+=x/2;
//    }
    cout<<ans+max_cnt-cnt;
}

