#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)

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

struct triple{
    int first;
    int second;
    int third;

    triple()=default;
    triple(int fi, int se, int th){
        first=fi;
        second=se;
        third=th;
    }

};

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

    int n=next(), p=next();
    vector<vector<pair<int, int> > > gr(n), gr_(n);
    vector<triple> rib(p);
    map<pair<int, int>, int> rib_dist;
    for (int i=0; i<p; i++){
        int a=next()-1, b=next()-1, dist=next();
//        cout<<"HERE"<<endl;
        gr[a].pb(mp(b, dist));
        gr_[b].pb(mp(a, dist));
        rib.pb(triple(a, b, dist));
        rib_dist[mp(a, b)]=dist;
//        cout<<"HERE"<<endl;

    }
//     cout<<"HERE"<<endl;
    vector<int> st, fsh;
    for (int i=0; i<n; i++){
        if (gr[i].size()==1 && gr_[i].size()==0) st.pb(i);
    }
    int cnt=0;
    vector<triple> res;
//    cout<<"HERE"<<endl;
    for (int v_: st){
//        cout<<"HERE"<<endl;
        int v=v_;
        triple ans;
        ans.first=v;
        int mn_dist=1e9;
        cnt++;
//        watch(v);
//        watch(gr[2].size());
        while (gr[v].size()!=0){
            mn_dist=min(mn_dist, gr[v][0].second);
            v=gr[v][0].first;
//            watch(v);
        }
//        cout<<"HERE"<<endl;
//        watch(v);
        ans.second=v;
        ans.third=mn_dist;
        res.pb(ans);
    }
    cout<<cnt<<endl;
    for (int i=0; i<cnt; i++)
        cout<<res[i].first+1<<" "<<res[i].second+1<<" "<<res[i].third<<endl;
}

