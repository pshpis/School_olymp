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
    cout.precision(20);
    int n=next();
    int m=next();
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            cout<<-1;
            return 0;
        }
    }
    vector<int> b(n);
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        if(b[i]==1)
        {
            cout<<-1;
            return 0;
        }
    }
    double s=m;
    s+=s/(a[0]-1);
    for(int i=n-1;i>0;i--)
    {
        s+=s/(b[i]-1);
        s+=s/(a[i]-1);
    }
    s+=s/(b[0]-1);
    cout<<s-m;
}
