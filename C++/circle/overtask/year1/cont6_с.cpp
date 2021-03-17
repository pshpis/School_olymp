#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

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

vector< vector<int> > gr;
vector<bool> used;

int main()
{
    ios::sync_with_stdio(false);
    int n=next();

    gr=vector< vector<int> > (n);
	used=vector<bool> (n, false);
    vector<int> dist(n, 0);
    vector<int> p(n, 0);

	for (int i=1; i<n; i++)
    {
        int p=next()-1;
        gr[i].pb(p);
        gr[p].pb(i);
    }

    int u=0;
    int mx_dist=0;
    used[u]=true;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v: gr[u])
        {
            if (!used[v])
            {
                used[v] = true;
                p[v]=u;
                dist[v]=dist[u]+1;
                mx_dist=max(mx_dist, dist[v]);
                q.push(v);
            }
        }
    }
    vector<int> cnt(mx_dist, 0);
    for (int i=0; i<n; i++)
        cnt[dist[i]-1]++;
    int ans=0;
    for (int i=0; i<mx_dist; i++)
    {
        ans+=cnt[i]%2;
    }
    cout<<ans+1;











}

