#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)
#define fi first
#define se second

//#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;

const int INF=2e9;
const ll INF64=1e18;
const double PI=3.14159265359;
const double EPS=1e-9;
const int MOD=1e9+7;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

ll lnext()
{ll x;cin>>x;return x;}

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

    int n = next(), m = next();
    vector<vector<pii> > g(n);
    vector<int> baron;

    for (int i = 0; i < n; i ++){
        int x = next();
        baron.pb(x);
    }

    for (int i = 0; i < m; i ++){
        int x = next() - 1, y = next() - 1, dist = 0;
        if (baron[x] != baron[y]) dist = 1;
        g[x].pb(mp(y, dist));
        g[y].pb(mp(x, dist));
    }

//    cout<<"YES"<<endl;
    int s = 0;
	vector<int> d (n, INF),  p (n);
	d[s] = 0;
	set < pair<int,int> > q;
	q.insert (make_pair (d[s], s));
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase (q.begin());

		for (size_t j = 0; j < g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				q.erase (make_pair (d[to], to));
				d[to] = d[v] + len;
				p[to] = v;
				q.insert (make_pair (d[to], to));
			}
		}
	}
//	watch(d[n-1]);
//	cout<<"YES"<<endl;
    s = 0;
	if (d[n-1] == INF){
        cout<<"impossible\n";
        return 0;
	}

	vector<int> ans;
	int f = n - 1;
	int dist = d[f];
//	ans.pb(s);
//	cout<<"YES"<<endl;
//	watch(s);
//	watch(p[s]);
//	return 0;
     while (p[f] != s){
        ans.push_back(f+1);
        f = p[f];
    }

    ans.push_back(f+1);
    ans.push_back(s+1);
    reverse(ans.begin(), ans.end());

    cout << dist << " " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i ++)
        cout << ans[i] << " ";
}

