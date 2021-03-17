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
    int sz=1000;
    vector<lint> diog1(2*sz-1, 0), diog2(2*sz-1, 0);
    int n=next();
    for (int i=0; i<n; i++)
    {
        int x=next()-1;
        int y=next()-1;
        diog1[x+y]++;
        diog2[x-y+sz-1]++;
    }
    lint ans=0;
    for (int i=0; i<diog1.size(); i++)
        ans+=(lint)diog1[i]*(diog1[i]-1)/2;
    for (int i=0; i<diog2.size(); i++)
        ans+=(lint)diog2[i]*(diog2[i]-1)/2;
    cout<<ans<<endl;
}

