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

const lint INF=1e9+7;

vector< vector< pair<lint,lint> > > g;
map<pair<lint, lint>, lint> w;
lint n, m;

bool deikstra(lint nw_w){
    lint s=0;
	vector<lint> d(n, INF), p(n);
	d[s]=0;
	vector<bool> u(n, false);
	for (lint i=0; i<n; i++)
    {
		lint v=-1;
		for (lint j=0; j<n; j++)
			if (!u[j] && (v==-1 || d[v]>d[j])) v=j;
		if (v==-1 || d[v]==INF) break;
		u[v]=true;
		for (lint j=0; j<g[v].size(); j++)
        {
			lint t=g[v][j].first, len=g[v][j].second;
			if (w[{v, t}]<nw_w) continue;
			if (d[t]>d[v]+len)
			{
				d[t]=d[v]+len;
				p[t]=v;
			}
		}
    }
    return d[n-1]<=1440;
}

lint bin_find(lint l, lint r){
    if (r-l<=1) return l;
    lint m=(l+r)/2;
    bool t_m=deikstra(m);
    if (t_m) return bin_find(m, r);
    else return bin_find(l, m);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    n=lnext();
    m=lnext();
    if (n==0){
        cout<<0;
        return 0;
    }
	g=vector< vector< pair<lint,lint> > >(n);
	for (int i=0; i<m; i++)
    {
        lint x=lnext()-1, y=lnext()-1,len=lnext(), m=(lnext()-3e6)/100;
        pair<lint, lint> a1={y, len}, a2={x,len};
        w[{x, y}]=m;
        w[{y, x}]=m;
        g[x].pb(a1);
        g[y].pb(a2);
    }
    if (deikstra(0)) cout<<bin_find(0, 1e7+1);
    else cout<<0;


}

