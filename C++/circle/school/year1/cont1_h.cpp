#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>

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
    vector< vector<int> > g(n);
    for (int i=0; i<n-1; i++)
    {
        int x=next()-1, y=next()-1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    //BFS begin
    int u=0;
    int mx_c=0;
    vector<int> color(n, -1);
    vector<int> p(n, -1);
    p[u]=u;
    color[u]=0;
    vector<int> used(n, false);
    used[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int cl=0;
        for (int v: g[u])
        {
            if (!used[v])
            {
                used[v] = true;
                p[v]=u;
                q.push(v);
                if (cl!=color[u] && cl!=color[p[u]])
                {
                    color[v]=cl;
                    mx_c=max(mx_c, cl);
                    cl++;
                }
                else
                {
                    cl++;
                    if (cl==color[u] || cl==color[p[u]]) cl++;
                    color[v]=cl;
                    mx_c=max(mx_c, cl);
                    cl++;
                }
            }
        }
    }
    //BFS end
    cout<<mx_c+1<<"\n";
    for (int i=0; i<n; i++)
        cout<<color[i]+1<<" ";
}

