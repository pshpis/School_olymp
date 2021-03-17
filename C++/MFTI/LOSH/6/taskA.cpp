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

const bool isDbg=true;
const int INF=1e9+7;

typedef long long lint;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    ios::sync_with_stdio(false);
//    watch("here");
//    cout<<"There"<<endl;
//    if (isDbg) freopen("inputC.txt", "r", stdin);
//    watch("here");
//    cout<<"There"<<endl;
    int n, m;
    cin>>n>>m;
//    watch("here");
//    cout<<"There"<<endl;
    lint s=0;
    lint f=n-1;
//    watch("here");
	vector< vector< pair<int,int> > > g (n);
//	watch("here");
	vector<int> owner;
//	watch("here");
	for (int i=0; i<n; i++)
        owner.push_back(next());
//    watch("here");
	for (int i=0; i<m; i++)
    {
        int x=next()-1, y=next()-1, len=0;
        if (owner[x]!=owner[y]) len=1;
        pair<int, int> a1={y, len}, a2={x,len};
        g[x].pb(a1);
        g[y].pb(a2);
    }
//    watch("here");
	vector<int> d(n, INF), p(n, 0);
	d[s]=0;
	set<pair<int, int>> point;
//    pair<int, int> fake={d[s], s};
    point.insert({d[s], s});
	while (!point.empty())
    {
		int v=(*point.begin()).second;
		point.erase(point.begin());
		for (int j=0; j<g[v].size(); j++)
        {
			int t=g[v][j].first, len=g[v][j].second;
			if (d[t]>d[v]+len)
			{
			    point.erase({d[t], t});
				d[t]=d[v]+len;
				p[t]=v;
				point.insert({d[t], t});
			}
		}
	}
//    watch("here");
	if (d[f]==INF){
        cout<<"impossible";
        return 0;
	}
	vector<int> way;
	way.push_back(f);
	while (p[way[way.size()-1]]!=s){
        way.push_back(p[way[way.size()-1]]);
	}
	way.push_back(s);
	reverse(way.begin(), way.end());
	cout<<d[f]<<" "<<way.size()<<endl;
	for (int i=0; i<way.size(); i++)
        cout<<way[i]+1<<" ";
}

