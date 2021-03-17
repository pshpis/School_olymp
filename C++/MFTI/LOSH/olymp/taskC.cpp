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
    lint n=lnext();
    lint ans=0;
    if (n==2){
        cout<<0;
        return 0;
    }
    for (lint i=1; pow2(i)<n; i++){
        if (n%i==0){
//            if (i==2){
//                ans++;
//                continue;
//            }
//            if (pow2(i)==n){
//                ans++;
//                continue;
//            }
//            ans+=2;
            ans++;
        }
    }
    cout<<ans;
}

