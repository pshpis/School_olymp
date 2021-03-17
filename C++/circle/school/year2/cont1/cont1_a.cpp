#include <bits/stdc++.h>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
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
        freopen("C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt", "r", stdin);
    #endif // DEBAG_in
    #ifdef DBG_out
        freopen("C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt", "w", stdout);
    #endif // DEBAG_out

    int n=next(), k=next();
    multiset<pair<int, int>> t;
    int mx_sh=-1;
    map<pair<int, int>, int> t_;
    for (int i=0; i<n; i++){
        int x=next();
        int y=next();
        t.insert(make_pair(x, y));
        mx_sh=max(mx_sh, y);
    }
//    for (it=t.begin(); it!=t.end(); it++){
////        el.second=mx_sh-el.second;
////        t_[el]++;
//        (*it).second=mx_sh-(*it).second;
////        t[el.first]=el.second;
//        t_[(*it)]++;
//    }
    auto t1=t;
    t1.clear();
    for (auto el: t){
//        watch("in__1");
        el.second=mx_sh-el.second;
        t1.insert(el);
        t_[el]++;
    }
    int cnt=n;
    for (auto el: t1){
//        watch(el.first);
//        watch(el.second);
//        watch(cnt);
        if (cnt==k){
            cout<<t_[el];
            return 0;
        }
        cnt--;
    }


}

