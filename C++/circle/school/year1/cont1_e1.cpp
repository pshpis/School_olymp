#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

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

int max_pw2(int k)
{
    int sq=sqrt(k);
    return sq*sq;
}
int main()
{
    ios::sync_with_stdio(false);
    int n=next();
    int mx_pw2=max_pw2(n);
    n-=mx_pw2;
    int a=sqrt(mx_pw2);
    int per=a+a+a+a;
    if (n==0)
    {
        cout<<per;
        return 0;
    }
    if (n>a) per+=4;
    else per+=2;
    cout<<per<<"\n";
}

