#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include<queue>

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
vector<bool> vis;
vector< vector<int> > comp;

int main()
{
    ios::sync_with_stdio(false);
    int n=next(), m=n-1;
    gr=vector< vector<int> > (n);
	vis=vector<bool> (n, false);
    for (int i=0; i<m; i++)
	{
	    int x=next()-1, y=next()-1;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
    int u=0;
    vector<int> used(n, false);
    vector<int> dist(n, 0);
    vector<int> p(n, 0);
    used[u] = true;
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
                q.push(v);
            }
        }
    }
    lint ev=0, n_ev=0;
    for (int i=0; i<n; i++)
    {
        if (dist[i]%2==0) ev++;
        else n_ev++;
    }
    cout<<ev*n_ev-(n-1);
}
