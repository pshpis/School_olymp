#include <bits/stdc++.h>

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

vector<vector<int>> gr;
vector<int> child;
vector<int> lief;
vector<bool> used;

int dfs(int st){
    used[st]=true;
    int cnt=0;
    int ans=0;
    for (int v: gr[st]){
        if (!used[v]){
            cnt++;
            ans+=dfs(v);
            lief[st]+=lief[v];
        }
    }
    if (cnt==0) lief[st]=1;
    ans+=cnt;
    child[st]=ans;
//    cout<<"DFS"<<endl;
//    watch(child[st]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef DBG_in
        freopen("C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt", "r", stdin);
    #endif // DEBAG_in
    #ifdef DBG_out
        freopen("C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt", "w", stdout);
    #endif // DEBAG_out
    int n=next();
    gr=vector<vector<int> >(n);
    used=vector<bool>(n, false);
    lief=vector<int>(n, 0);
    child=vector<int>(n, 0);
    for (int i=1; i<n; i++){
        int x=next()-1;
        gr[i].pb(x);
        gr[x].pb(i);
    }
    dfs(0);
//    watch(lief[0]);
//    watch(child[0]);
    map<int, int> lief_cnt;
    for (int i=0; i<n; i++){
        lief_cnt[lief[i]]++;
    }
    map<int, int> cnt_lief;
    for (auto el: lief_cnt){
        cnt_lief[el.second]=el.first;
    }
    int ans=0;
    int pr=1;
    for (auto el: lief_cnt){
//        watch(el.first);
//        watch(el.second);
        ans=el.first;
        for (int i=0; i<el.second; i++){
            cout<<ans<<" ";
        }
        pr=el.first;
    }

}
