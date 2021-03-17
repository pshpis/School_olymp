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

    int n=next(), m=next(), u=next()-1;
    gr=vector< vector<int> > (n);
	vis=vector<bool> (n, false);
    for (int i=0; i<m; i++)
	{
	    int x=next()-1, y=next()-1;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
//	watch("here");
    vector<int> used(n, false);
    vector<int> dist(n, 0);
    vector<int> p(n, 0);
    used[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int u = q.front();
//        cout<<u+1<<" ";
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
//    watch("here");
    int max_d=-1;
    for (int i=0; i<n; i++)
        max_d=max(max_d, dist[i]);
    vector<vector<int> > round(max_d+1);
    round[0].push_back(u);
    int cnt=0;
//    watch(2);
    for (int i=0; i<n; i++){
        if (dist[i]!=0){
            cnt++;
            round[dist[i]].push_back(i);
        }
    }
//    watch("here");
    cout<<cnt+1<<endl;;
    for (int i=0; i<round.size(); i++)
        for (int j=0; j<round[i].size(); j++)
            cout<<round[i][j]+1<<" ";
}

