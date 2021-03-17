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

lint eler_func(lint n){
    set<lint> prime;
    lint ans= n;
    lint div=2;
    while (n>1){
        while (n%div==0){
            prime.insert(div);
            n/=div;
        }
        div++;
    }
    for (var: prime){
        ans*=(var-1);
        ans/=var;
    }
    return ans;
}

lint pow(lint n, lint mod, lint pw){
    lint ans=1;
    for (int i=0; i<pw; i++){
        ans*=n;
        ans%=mod;
    }
    return ans;
}
int main()
{
    lint a1=next(), a2=next(), mod1=next(), mod2=next();
//    vector<lint> rev1=rev_mod(mod1), rev2=rev_mod(mod2);
    lint m=mod1*mod2, m1=mod2, m2=mod1;
    lint m1_=pow(m1, mod1, eler_func(mod1)-1), m2_=pow(m2, mod2, eler_func(mod2)-1);
    lint ans=(((m1*m1_)%m*a1)%m+((m2*m2_)%m*a2)%m)%m;
    cout<<ans<<endl;
}

