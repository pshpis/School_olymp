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

int main()
{
    //ios::sync_with_stdio(false);
    int n=next(), m=next();
    vector<set<int> > r(n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            r[i].insert(j);
    }
    for (int i=0; i<m; i++)
    {
        int x=next()-1, y=next()-1;
        r[x].erase(y);
        r[y].erase(x);
    }
    int mx=-1, mx_v=-1;
    for (int i=0; i<n; i++)
    {
        //watch(r[i].size());
        //watch(mx);
        int x=r[i].size();
        mx=max(mx, x);
        if (x==mx) mx_v=i;
    }
    /*atch(n);
    watch(m);
    watch(mx);
    watch(mx_v);*/
    vector<pair<int, int> > ans;
    for (auto a: r[mx_v])
    {
        if (mx_v!=a)
        {
            pair<int, int> x={mx_v, a};
            ans.pb(x);
        }
    }
    //cout<<"\n4\n";
    for (auto a:r[mx_v])
        for (int j=0; j<n; j++)
            if (r[mx_v].count(j)<=0 && j!=a)
            {
                pair<int, int> x={a, j};
                ans.pb(x);
            }
    //cout<<"\n5\n";
    cout<<ans.size()<<"\n";
    for (int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
    }
}

