#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)

//#define DBG_in
//#define DBG_out

typedef long long lint;

const int INF=2e9;
const lint INF64=1e18;
const double PI=3.14159265359;
const double EPS=1e-9;
const int MOD=1e9+7;

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
vector<pair<int, int>> ans;
int st_0=0;
vector<int> p_dfs;
void dfs(int st, int h)
{
	vis[st]=true;
	for (int a: gr[st]){
        if (h>1 && a==st_0) ans.pb(make_pair(st, h+1));
		if (!vis[a]) {
            p_dfs[a]=st;
            dfs(a, h+1);
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef DBG_in
        freopen("C:\Users\pshpi\OneDrive\Desktop\in.txt", "r", stdin);
    #endif // DEBAG_in
    #ifdef DBG_out
        freopen("C:\Users\pshpi\OneDrive\Desktop\out.txt", "w", stdout);
    #endif // DEBAG_out

    int n=next(), m=next();
    gr=vector< vector<int> > (n);
	vis=vector<bool> (n, false);
	p_dfs=vector<int>(n, 0);
    for (int i=0; i<m; i++){
        int x=next()-1, y=next()-1;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dfs(st_0, 0);
    if (ans.empty()){
        int u=0;
        vector<int> used(n, false);
        vector<int> dist(n, 0);
        vector<int> p(n, 0);
        used[u]=true;
        queue<int> q;
        q.push(u);
        while (!q.empty())
        {
            int u=q.front();
//            cout<<u+1<<" ";
            q.pop();
            for (int v: gr[u])
            {
                if (!used[v])
                {
                    used[v]=true;
                    p[v]=u;
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
        int max_dist=-1;
        int it=-1;
        for (int i=0; i<n; i++)
        {
            if (dist[i]>max_dist){
                it=i;
                max_dist=dist[i];
            }
        }
        cout<<-1<<"\n"<<it+1;
        return 0;
    }
    else{
        int mx=-1;
        int v=-1;
        for (int i=0; i<ans.size(); i++)
            if (ans[i].second>mx){
                v=ans[i].first;
                mx=ans[i].second;
            }
//        watch(v);
//        watch(mx);
        cout<<mx<<"\n";
        vector<int> vert;
        while (v!=st_0){
            vert.pb(v+1);
            v=p_dfs[v];
        }
        cout<<st_0+1<<" ";
        reverse(vert.begin(), vert.end());
        for (int i=0; i<vert.size(); i++)
            cout<<vert[i]<<" ";
    }
}

