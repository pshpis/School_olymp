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
    vector<int> dist;
    for (int i=0; i<4; i++)
    {
        int x=next();

        dist.pb(x);
    }
    bool ans=true;
    if (abs(dist[0]-dist[1])>dist[2]+dist[3]) ans=false;
    if (abs(dist[0]-dist[2])>dist[1]+dist[3]) ans=false;
    if (abs(dist[0]-dist[3])>dist[2]+dist[1]) ans=false;
    if (abs(dist[1]-dist[2])>dist[0]+dist[3]) ans=false;
    if (abs(dist[1]-dist[3])>dist[0]+dist[2]) ans=false;
    if (abs(dist[2]-dist[3])>dist[0]+dist[1]) ans=false;
    if (ans) cout<<"Yes";
    else cout<<"No";
}

