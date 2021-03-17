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
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);

    int q=next();
    multiset<int> s;
    for (int i=0; i<q; i++){
        int n=next();
        int mn=1e5, mx=-1;
        for (int i=0; i<4*n; i++){
            int x=next();
            mx=max(mx, x);
            mn=min(mn, x);
            s.insert(x);
        }
        int mult=mn*mx;
        bool ans=true;
//        for (int v: s){
//            if (mult%v==0){
//                if (s.count(mult/v)==0){
//                    ans=false;
//                    continue;
//                }
//                s.erase(mult/v);
////                s.erase(v);
//            }
//            else {
//                ans=false;
//                continue;
//            }
//        }
        while (!s.empty()){
            int v=*s.begin();
            if (mult%v==0){
                if (s.count(mult/v)==0){
                    ans=false;
                    break;
                }
                s.erase(s.find(v));
                s.erase(s.find(mult/v));
            }
            else{
                ans=false;
                break;
            }
        }
        s.clear();
        if (ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
