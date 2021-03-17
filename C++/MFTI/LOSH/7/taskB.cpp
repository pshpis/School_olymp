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

const int INF=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    int n=next();
    vector<vector<int> > dist(n, vector<int>(n, INF));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            dist[i][j]=next();
            if (dist[i][j]==-1) dist[i][j]=INF;
        }
    }
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (dist[i][k]<INF && dist[k][j]<INF)
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
//    watch("Here");
    int max_dist=-1;
    int r=INF;
//    watch(n);
    for (int i=0; i<n; i++){
        int ex=-1;
//        watch(i);
        for (int j=0; j<n; j++){
//            watch(j);
            if (dist[i][j]<INF)
            {
                ex=max(ex, dist[i][j]);
                max_dist=max(max_dist, dist[i][j]);
            }
        }
        if (ex!=-1) r=min(r, ex);
    }
    cout<<max_dist<<endl<<r<<endl;
}
