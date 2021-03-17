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

typedef long long lint;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

vector<vector<int> > gr;
vector<set<int> > comp;
vector<bool> was;

dfs(int st, int i)
{
    comp[i].insert(st);
    was[st]=true;
    for (int v: gr[st])
        if (!was[v]) dfs(v, i);
}
int main()
{
    ios::sync_with_stdio(false);
    int n=next(), m=next(), t=next();
    map<pair<int, int>, int> cell_vertex;
    vector<vector<bool> > table(n, vector<bool>(m, false));// true == '.', false =='*'
    int k=0;//size of graph
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            char x;
            cin>>x;
            if (x=='.')
            {
                table[i][j]=true;
                cell_vertex[{i, j}]=k;
                k++;
            }
        }
    gr=vector<vector<int> >(k);
    was=vector<bool>(k, false);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            if (table[i][j])
            {
                int x=i, y=j;

                x+=1;
                if (table[x][y]) gr[cell_vertex[{i, j}]].push_back(cell_vertex[{x, y}]) , gr[cell_vertex[{x, y}]].push_back(cell_vertex[{i, j}]);
                x-=2;
                if (table[x][y]) gr[cell_vertex[{i, j}]].push_back(cell_vertex[{x, y}]) , gr[cell_vertex[{x, y}]].push_back(cell_vertex[{i, j}]);
                x+=1;

                y+=1;
                if (table[x][y]) gr[cell_vertex[{i, j}]].push_back(cell_vertex[{x, y}]) , gr[cell_vertex[{x, y}]].push_back(cell_vertex[{i, j}]);
                y-=2;
                if (table[x][y]) gr[cell_vertex[{i, j}]].push_back(cell_vertex[{x, y}]) , gr[cell_vertex[{x, y}]].push_back(cell_vertex[{i, j}]);
                y+=1;

            }
        }

    int c=0;//size of comp
    for (int i=0; i<k; i++)
    {
        if (!was[i])
        {
            //vector<int> fake;
            //comp.push_back(fake);
            comp.emplace_back();
            dfs(i, c);
            c++;
        }
    }
    vector<int> vertex_comp;
    for (int i=0; i<c; i++)
        for (int x: comp[i])
            vertex_comp[x]=i;

    vector<int> comp_ans(c, 0);
    for (int i=0; i<c; i++)
        for (int x: comp[i])
            comp_ans[i]+=4-gr[x].size();

    for (int i=0; i<t; i++)
    {
        int x=next()-1, y=next()-1;
        int vertex=cell_vertex[{x, y}];
        int cmp=vertex_comp[vertex];
        cout<<comp_ans[cmp]<<endl;
    }



}

