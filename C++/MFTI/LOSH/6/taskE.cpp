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

const int INF=1e9+1;

int main()
{
    ios::sync_with_stdio(false);
    if (isDbg) freopen("inputE.txt", "r", stdin);
    lint n=lnext(), s=lnext()-1, f=lnext()-1;
    vector< vector< pair<int,int> > > g (n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int x=next();
            if (x>=0 && i!=j){
                pair<int, int> a1={j, x}, a2={i, x};
                g[i].push_back(a1);
//                watch(i);
//                watch(j);
//                watch(x);
//                g[j].push_back(a2);
            }
        }
    }
	vector<int> d(n, INF), p(n);
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
//	for (int i=0; i<d.size(); i++){
//        cout<<d[i]<<" ";
//	}
	if (d[f]==INF) cout<<-1;
	else cout<<d[f];
}

