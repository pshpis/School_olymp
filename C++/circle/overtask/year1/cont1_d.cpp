#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
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

int main()
{
    ios::sync_with_stdio(false);
    int n=next(), m=next();
    gr=vector< vector<int> > (n);
    vector<bool> link(n, false);
    for (int i=0; i<m; i++)
	{
	    int x=next()-1, y=next()-1;
		gr[x].push_back(y);
		gr[y].push_back(x);
		link[x]=true;
		link[y]=true;
	}
    vector<bool> used(n, false);
    vector<int> was;
    vector<int> color(n, -1);

    while (was.size()!=n)
    {
        int u=0;
        for (int i=0; i<n; i++)
            if (!used[i] && link[i])
            {
                u=i;
                break;
            }
        color[u]=0;
        used[u] = true;
        was.pb(u);
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
                    was.pb(v);
                    q.push(v);
                    color[v]=1-color[u];
                }
            }
        }
    }
    bool pr=true;
    for (int i=0; i<n; i++)
        for (int v: gr[i])
            if (color[v]==color[i]) pr=false;
    if (!pr) cout<<"-1";
    else
    {
        vector<int> ans1, ans2;
        for (int i=0; i<n; i++)
        {
            if (color[i]==0) ans1.pb(i);
            if (color[i]==1) ans2.pb(i);
        }
        cout<<ans2.size()<<"\n";
        for (int i=0; i<ans2.size(); i++)
            cout<<ans2[i]+1<<" ";
        cout<<"\n";
        cout<<ans1.size()<<"\n";
        for (int i=0; i<ans1.size(); i++)
            cout<<ans1[i]+1<<" ";
        cout<<"\n";
    }
}
