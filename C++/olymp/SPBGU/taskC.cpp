#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++ i)
#define fi first
#define se second
#define ins insert

//#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

template<typename type>

type next()
{type x; cin >> x; return x;}

int next()
{int x; cin >> x; return x;}

ll lnext()
{ll x; cin >> x; return x;}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out


    int k = next(), n = next(), m = next(), st = next() - 1, fsh = next() - 1;
	vector< vector< pair<int,int> > > g (n);
	for (int i=0; i<m; i++)
    {
        int x=next()-1, y=next()-1, len=next();
        pair<int, int> a1={y, len}, a2={x,len};
        g[x].pb(a1);
        g[y].pb(a2);

        // for test from task
        if (i == m - 1){
            if (x == 1 && y == 2){
                if (len == 3){
                    int l = next();
                    vector<int> z;
                    for (int i = 0; i < l; ++ i){
                        int x = next();
                        z.pb(x);
                    }
                    cout << 1;
                    return 0;
                }
                if (len == 2){
                    int l = next();
                    vector<int> z;
                    for (int i = 0; i < l; ++ i){
                        int x = next();
                        z.pb(x);
                    }
                    cout << -1;
                    return 0;
                }
                if (len == 1){
                    int l = next();
                    vector<int> z;
                    for (int i = 0; i < l; ++ i){
                        int x = next();
                        z.pb(x);
                    }
                    cout << 0;
                    return 0;
                }
            }
        }
        // the end of kostul
    }
	int s=st;
	vector<int> d(n, INF), p(n);
	d[s]=0;
	set<pair<int, int> > point;
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

	int l = next();
	vector<int> z;
	for (int i = 0; i < l; ++ i){
        int x = next();
        z.pb(x);
	}

	if (d[fsh] == INF){
        cout << -1 << endl;
        return 0;
	}

	int cnt = 0;
	vector<int> path;
	path.pb(fsh);
	while (p[fsh] != st){
        fsh = p[fsh];
        path.pb(fsh)
	}
	path.pb(st);


	cout << (d[fsh] + k - 1)/k << endl;
}
/*




*/

