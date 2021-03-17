#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

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

int n, m;
vector< vector<int> > gr, table;
vector<int> dist;
vector<int> p;
vector<bool> used;
pair<int, int> st, f;

void read(){
    n=next();
    m=next();
    dist=vector<int>(n*m+1, 0);
    p=vector<int>(n*m+1, 0);
    used=vector<bool>(n*m+1, false);
    table=vector<vector<int> >(n, vector<int>(m, 0));
    gr=vector<vector<int> >(n*m+1);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            table[i][j]=next();
    st.first=next()-1;
    st.second=next()-1;
    f.first=next()-1;
    f.second=next()-1;
}


int table_to_vertex(pair<int, int> t){
    return t.first+m*t.second;
}

pair<int, int> vertex_to_table(int x){
    return make_pair(x%m, x/m);
}

void make_side(int x, int y){
    gr[x].push_back(y);
    gr[y].push_back(x);
}

bool correct_cell(pair<int, int> cell)
{
    return cell.first>=0 && cell.first<m && cell.second>=0 && cell.second<n;
}

void make_gr(){
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++){
            pair<int, int> self={j, i};
            if (table[self.second][self.first]==1) continue;

            pair<int, int> t=self;
            t.first++;
            if (correct_cell(t) && table[t.second][t.first]==0) make_side(table_to_vertex(t), table_to_vertex(self));

            t=self;
            t.first--;
            if (correct_cell(t) && table[t.second][t.first]==0) make_side(table_to_vertex(t), table_to_vertex(self));

            t=self;
            t.second++;
            if (correct_cell(t) && table[t.second][t.first]==0) make_side(table_to_vertex(t), table_to_vertex(self));

            t=self;
            t.second--;
            if (correct_cell(t) && table[t.second][t.first]==0) make_side(table_to_vertex(t), table_to_vertex(self));
        }
}

void bfs(int u){
    used[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int u = q.front();
//        cout<<u+1<<" ";
        q.pop();
        for (int v: gr[u])
        {
            if (!used[v])
            {
                used[v] = true;
                p[v]=u;
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    if (isDbg) freopen("inputD.txt", "r", stdin);
    read();
    if (st.first==f.first && st.second==f.second)
    {
        cout<<0;
        return 0;
    }
    make_gr();
//    watch(table_to_vertex(st));
//    watch(table_to_vertex(f));
    bfs(table_to_vertex(st));
    if (dist[table_to_vertex(f)]==0) cout<<-1;
    else cout<<dist[table_to_vertex(f)];
}

