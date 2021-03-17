#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int next(){int x; cin>>x; return x;}

int n, m;
int s, f;
vector<int> d;
vector<vector<pair<int, int> > > gr;
vector<int> used;
vector<int> p;
vector<int> ans;

int32_t main(){
//    ios::sync_with_stdio(false);
    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);

    n=next();
//    m=next();
    s=next()-1;
    f=next()-1;

    gr=vector<vector<pair<int, int> > >(n);
    d=vector<int>(n, 1e18);
    p=vector<int>(n, 0);

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int x=next();
            if (i!=j && x!=-1){
                gr[i].push_back(make_pair(j, x));
            }
        }
    }

    set<pair<int, int> >q;
    d[s]=0;
    q.insert(make_pair(d[s], s));

    while (!q.empty()){
        int v=q.begin()->second;
        q.erase(q.begin());
        for (int i=0; i<gr[v].size(); i++){
            int to=gr[v][i].first, len=gr[v][i].second;
            if (d[to]>d[v]+len){
                q.erase(make_pair(d[to], to));
                d[to]=d[v]+len;
                p[to]=v;
                q.insert(make_pair(d[to], to));
            }
        }
    }

    if (d[f]==1e18){
        cout<<-1;
        return 0;
    }
    cout<<d[f]<<"\n";
    while (p[f]!=s){
        ans.push_back(f+1);
        f=p[f];
    }

    ans.push_back(f+1);
    ans.push_back(s+1);
    reverse(ans.begin(), ans.end());

//    for (int i=0; i<ans.size(); i++){
//        cout<<ans[i]<<" ";
//    }

}
