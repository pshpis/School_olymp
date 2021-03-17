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
#define fr(i, n) for (int (i)=0; i<int(n); i++)

const bool isDbg=false;

typedef long long lint;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

vector< vector<int> > gr;
vector<bool> vis;

int main()
{
    ios::sync_with_stdio(false);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    int n=next();
    gr=vector< vector<int> > (n);
	vis=vector<bool> (n, false);
    for (int i=1; i<n; i++)
	{
	    int x=next()-1;
		gr[i].push_back(x);
		gr[x].push_back(i);
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
    int max_d=-1;
    for (int i=0; i<n; i++)
        max_d=max(max_d, dist[i]);
    cout<<max_d<<endl;
    vector<int> ans;
    for (int i=0; i<n; i++)
        if (dist[i]==max_d) ans.push_back(i+1);
    cout<<ans.size()<<endl;
    for (int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

