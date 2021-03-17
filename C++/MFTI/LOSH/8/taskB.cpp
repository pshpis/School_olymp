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
vector<lint> dp1, dp2;
vector<lint> ans;

void dfs(lint v){
    for (auto u: gr[v]){
        dfs(u);
        dp1[v]=max(dp1[v], dp2[u]+1-ans[u]);
        dp2[v]+=ans[u];
    }
    dp1[v]+=dp2[v];
    ans[v]=max(dp1[v], dp2[v]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    lint n=lnext();
    gr=vector<vector<lint> >(n);
    dp1=vector<lint>(n, 0);
    dp2=dp1;
    ans=vector<lint>(n, 0);
    lint root=-1;
    for (int i=0; i<n; i++){
        lint p=lnext()-1;
        if (p==-1){
            root=i;
            continue;
        }
        gr[p].push_back(i);
    }
//    watch("Hello");
    dfs(root);
    cout<<n-ans[root];
}


