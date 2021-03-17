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

void test()
{
    int n=next();
    pair<int, int> a, b;
    a.first=next();
    a.second=next();
    if (a.first>a.second){
        b.first=a.first-1;
        b.second=b.first;
        if (a.first==1){
            b.first=0;
            b.second=1;
        }
    }
    else{
        b.first=a.first;
        b.second=a.first;
    }
    if (a.second<b.second){
        a.second+=n;
        a.first-=1;
    }
    a.second-=b.second;
    a.first-=b.first;
    if (a.first==0 || a.first==a.second){
        cout<<"YES\n";
        if (a.first==0) cout<<1<<" "<<a.second<<"\n";
        else cout<<2<<" "<<a.first<<" "<<a.second<<"\n";
        if (b.first==0) cout<<1<<" "<<b.second<<"\n";
        else cout<<2<<" "<<b.first<<" "<<b.second<<"\n";
        return;
    }
    cout<<"NO\n";
}

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

    int q=next();
    for (int i=0; i<q; i++)
        test();
}

