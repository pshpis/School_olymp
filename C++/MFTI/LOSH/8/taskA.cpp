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

vector<vector<lint> > gr;
vector<pair<lint, lint> > edges;
vector<bool> used, used_;
vector<lint> dp;
map<pair<lint, lint>, lint> ans;
vector<lint> comp;
vector<lint> comp_size;
lint country=0;

void dfs(lint v){
    if (comp[v]==-1){
        comp[v]=country;
        comp_size.push_back(1);
        country++;
//        watch(v);
//        watch(comp[v]);
    }
    else
    {
        comp_size[comp[v]]++;
    }
    dp[v]=1;
    used[v]=true;
    for (auto u: gr[v]){
        comp[u]=comp[v];
        if (!used[u]){
            dfs(u);
            dp[v]+=dp[u];
        }
    }
//    watch(v);
//    watch(dp[v]);
//    watch(comp[v]);
//    watch(comp_size[comp[v]]);
}

void make_ans_dfs(lint v){
    used_[v]=true;
    for (auto u: gr[v]){
        if (!used_[u]){
            ans[{v, u}]=(comp_size[comp[v]]-dp[u])*dp[u];
            ans[{u, v}]=(comp_size[comp[v]]-dp[u])*dp[u];
//            watch(v);
//            watch(comp_size[comp[v]]);
//            watch(dp[u]);
            make_ans_dfs(u);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    lint n=lnext(), m=lnext();
    gr=vector<vector<lint> >(n);
    edges=vector<pair<lint, lint> >(m);
    used=vector<bool>(n, false);
    comp=vector<lint>(n, -1);
    used_=vector<bool>(n, false);
    dp=vector<lint>(n);
    for (int i=0; i<m; i++){
        lint from=lnext()-1, to=lnext()-1;
        edges[i].first=from;
        edges[i].second=to;
        gr[from].push_back(to);
        gr[to].push_back(from);
    }
//    watch("Here");
    for (int i=0; i<n; i++)
        if (!used[i]) dfs(i);
//    watch("After 1 dfs");
    for (int i=0; i<n; i++)
        if (!used_[i]) make_ans_dfs(i);
//    watch("After 2 dfs");
    lint q=lnext();
    for (int i=0; i<q; i++){
        lint j=lnext()-1;
        cout<<ans[edges[j]]<<"\n";
    }

}
