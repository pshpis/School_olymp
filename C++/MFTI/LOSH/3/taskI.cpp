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
typedef long double ld;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

const lint INF=1e9+7;
vector<pair<ld, ld> > racer;

ld x(lint i, ld t){
    return racer[i].first+racer[i].second*t;
}

ld dist (ld t){
    ld min_dist=1e9+7, max_dist=-1;
    for (lint i=0; i<racer.size(); i++){
        min_dist=min(min_dist, x(i, t));
        max_dist=max(max_dist, x(i, t));
    }
    return max_dist-min_dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(9);
    cout.setf(ios::fixed);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    lint n=next();

    ld l=-INF;
    ld r=INF;
    for (lint i=0; i<n; i++){
        ld x=lnext(), v=lnext();
        racer.push_back({x, v});
    }
    for (int i=0; i<1000; i++){
        ld l_=l+(r-l)/3;
        ld r_=r-(r-l)/3;
        if (dist(l_)<dist(r_)) r=r_;
        else l=l_;
    }
//    watch(l);
//    watch(r);
    ld t=(l+r)/2;
    if (t<0) t=0;
    cout<<t<<" "<<dist(t)<<endl;
}

