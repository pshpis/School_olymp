#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

#define watch(x) cout << (#x) << " is " << (x) << endl

typedef long long lint;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    int n=next();
    lint last_x=-1, ans=1;
    bool fl=true;
    for (int i=0; i<n; i++)
    {
        int x=next();
        if (x==1) fl=false;
        if (x==1 && last_x!=-1)
        {
            int dist=i-last_x;
            //watch(dist);
            ans*=dist;
            last_x=i;
        }
        if (x==1 && last_x==-1)
            last_x=i;
    }
    if (fl) ans=0;
    cout<<ans;
}

