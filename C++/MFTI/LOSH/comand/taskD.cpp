#include <bits/stdc++.h>

using namespace std;

const long long int INF = 1e9 + 7;

int main(){
    int z;
    freopen("input.txt","r",stdin);
    scanf("%d ",& z);
    vector <vector <int> > p(z + 1);
    for (int q = 0;q < z;++q){
        int n,m,t,start,one,two;
        scanf("%d %d %d",& n,& m,& t);
        scanf("%d %d %d",& start,& one,& two);
        vector <int> vok;
        vector <int> itog;
        map <pair <int,int>,int> w;
        vector <vector <pair <int,int> > > gr(n + 1);
        for (int i = 0;i < m;++i){
            int x,y,d;
            scanf("%d %d %d",& x,& y,& d);
            gr[x].push_back({y,d});
            gr[y].push_back({x,d});
            w[{x,y}] = d;
            w[{y,x}] = d;
        }
        for (int i = 0;i < t;++i){
            int r;
            scanf("%d ",& r);
            vok.push_back(r);
        }
        vector <long long int> dist(n + 1,INF),dist1(n + 1,INF),dist2(n + 1,INF);
        dist[start] = 0;
        vector <bool> used(n + 1,true),used1(n + 1,true),used2(n + 1,true);
        for (int i = 0;i < n;++i){
            int v = -1;
            for (int l = 1;l <= n;++l){
                if ((v == -1 || dist[l] < dist[v]) && used[l])
                    v = l;
            }
            if (v == -1 || dist[v] == INF){
                break;
            }
            used[v] = false;
            for (auto e : gr[v]){
                if (dist[e.first] > dist[v] + e.second){
                    dist[e.first] = dist[v] + e.second;
                }
            }
        }
        start = one;
        dist1[start] = 0;
        for (int i = 0;i < n;++i){
            int v = -1;
            for (int l = 1;l <= n;++l){
                if ((v == -1 || dist1[l] < dist1[v]) && used1[l])
                    v = l;
            }
            if (v == -1 || dist1[v] == INF){
                break;
            }
            used1[v] = false;
            for (auto e : gr[v]){
                if (dist1[e.first] > dist1[v] + e.second){
                    dist1[e.first] = dist1[v] + e.second;
                }
            }
        }
        start = two;
        dist2[start] = 0;
        for (int i = 0;i < n;++i){
            int v = -1;
            for (int l = 1;l <= n;++l){
                if ((v == -1 || dist2[l] < dist2[v]) && used2[l])
                    v = l;
            }
            if (v == -1 || dist2[v] == INF){
                break;
            }
            used2[v] = false;
            for (auto e : gr[v]){
                if (dist2[e.first] > dist2[v] + e.second){
                    dist2[e.first] = dist2[v] + e.second;
                }
            }
        }
        for (int i = 0;i < t;++i){
            int g = vok[i];
            long long int mi = min(dist[one] + w[{one,two}] + dist2[g],dist[two] + w[{one,two}] + dist1[g]);
            if (mi <= dist[g]){
                p[q].push_back(g);
            }
        }
    }
    for (int i = 0;i < p.size();++i){
        sort(p[i].begin(),p[i].end());
        for (int l = 0;l < p[i].size();++l)
            cout << p[i][l] << " ";
        cout << "\n";
    }
    return 0;
}
