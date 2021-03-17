#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)

#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\in.cpp";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\out.cpp";
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

int n;
vector<int> a;
vector<vector<int> > gr;
vector<int> ans;
vector<bool> used;
vector<vector<int> > or_gr;

void dfs(int st){
    used[st]=true;
    int res=0;
    for (int v: gr[st]){
        if (!used[v]){
            or_gr[st].pb(v);
            dfs(v);
            res+=ans[v];
        }
    }
    res+=a[st];
    ans[st]=res;
}

vector<int> new_ans;
vector<bool> new_used;

void new_dfs(int st){
    new_used[st]=true;
    bool fl=true;
    for (int v: gr[st]){
        if (!new_used[v]){
//            watch(v);
            fl=false;
            new_dfs(v);
            new_ans[st]=max(new_ans[st], new_ans[v]);
        }
    }
    new_ans[st]=max(new_ans[st], ans[st]);
}

vector<bool> was;

vector<bool> obr;

void prep(int& st){
    obr[st]=true;
    while (or_gr[st].size()==1){
        st=or_gr[st][0];
        obr[st]=true;
    }
}

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

    n=next();
    for (int i=0; i<n; i++){
        a.pb(next());
    }
    gr=vector<vector<int> >(n);
    or_gr=vector<vector<int> >(n);
    for (int i=0; i<n-1; i++){
        int x=next()-1, y=next()-1;
        gr[x].pb(y);
        gr[y].pb(x);
    }
//    cout<<"HERE  -2!!!"<<endl;
    ans=vector<int>(n);
    used=vector<bool>(n, false);
    int st=0;
    dfs(st);
//    cout<<"OR_GR"<<endl;
//    for (int i=0; i<n; i++){
//        cout<<i+1<<": ";
//        for (int v: or_gr[i]) cout<<v+1<<" ";
//        cout<<endl;
//    }
//    cout<<"ANS"<<endl;
//    for (int i=0; i<n; i++){
//        cout<<ans[i]<<" ";
//    }
//    cout<<endl;
//    cout<<"HERE  -1!!!"<<endl;
    new_ans=vector<int>(n, -1e9);
    new_used=vector<bool>(n, false);
    new_dfs(st);
//    cout<<"NEW_ANS"<<endl;
//    for (int i=0; i<n; i++){
//        cout<<new_ans[i]<<" ";
//    }
//    cout<<endl;
//    cout<<"HERE  0!!!"<<endl;
    int best_ans=-1e9;
    obr=vector<bool>(n, false);
    for (int st_=0; st_<n; st_++){
        if (obr[st]) continue;
        st=st_;
        vector<int> res;
        was=vector<bool>(n, false);
        prep(st);
    //    watch(st);
        int cnt=0;
    //    cout<<"HERE  1!!!"<<endl;
        for (int v: or_gr[st]){
            cnt++;
//            watch(v);
            res.pb(new_ans[v]);
        }
    //    cout<<"RES"<<endl;
    //    for (int i=0; i<res.size(); i++){
    //        cout<<res[i]<<" ";
    //    }
    //    cout<<endl;
    //    cout<<"HERE  2!!!"<<endl;
        if (cnt<2){
//            cout<<"Impossible"<<endl;
            continue;
        }
        sort(res.begin(), res.end());
        vector<int> :: iterator it=res.end();
        it--;
        int all_ans=0;
        all_ans+=*it;
//        watch(all_ans);
        it--;
        all_ans+=*it;
//        watch(all_ans);
        best_ans=max(all_ans, best_ans);
    }
    if (best_ans!=-1e9)
        cout<<best_ans;
    else cout<<"Impossible"<<endl;
}
/*
5
-1 -1 -1 2 9
1 2
2 3
3 4
3 5


19
*/
