#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair

int n, m;
vector<vector<int> > gr;
vector<bool> used;
vector<int> dist, p;

void read_gr(){
    cin>>n>>m;
    gr=vector<vector<int> >(n);
    for (int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        gr[x].pb(y);
        gr[y].pb(x);
    }
}

void bfs(int st){
    dist=vector<int>(n, 1e9+7);
    used=vector<bool>(n, false);
    p=vector<int>(n, 0);
    queue<int> q;
    q.push(st);
    dist[st]=0;
    used[st]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for (int v: gr[u]){
            if (!used[v]){
                used[v]=true;
                q.push(v);
                dist[v]=dist[u]+1;
                p[v]=u;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read_gr();
    int b, b_, pl;
    cin>>b>>b_>>pl;
    b--;
    b_--;
    pl--;
    bfs(pl);
    int ans=min(dist[b], dist[b_]);
    bfs(b);
    ans+=dist[b_];
    ans*=4;
    ans+=10;
    cout<<ans;
}

