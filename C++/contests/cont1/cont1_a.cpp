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

typedef long long lint;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    ios::sync_with_stdio(false);
    int num=next();
    lint ans=0;
    bool fl=false;
    while (true)
    {
        if (num>0 && num<10)
        {
            ans+=9;
            break;
        }
        int d=10-num%10;
        num+=d;
        while (num%10==0) num/=10;
        ans+=d;
    }
    cout<<ans;
}

