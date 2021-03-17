#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include<queue>

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

const lint INF= 9*1e18;

vector<lint> dist;
vector<bool> used;
vector<lint> bfs_dist;

class Edge
{
public:
    lint from;
    lint to;
    lint w;
    Edge(lint from_, lint to_, lint w_){
        from=from_;
        to=to_;
        w=w_;
    }
};

istream& operator>>(istream& s, Edge& x)
{
    s>>x.from;
    s>>x.to;
    s>>x.w;
    x.from--;
    x.to--;
    return s;
}

ostream& operator<<(ostream& s, const Edge& x)
{
    s<<x.from<<" "<<x.to<<" "<<x.w;
    return s;
}

vector<Edge> edges;

class Node{
public:
    lint to;
    lint w;
    Node(lint to_, lint w_);
    void insert(lint from);
    Node(Edge e);
};

vector<vector<Node> >gr;

Node::Node(lint to_, lint w_){
    to=to_;
    w=w_;
}

void Node::insert(lint from){
    gr[from].push_back(*this);
}

Node::Node(Edge e){
    to=e.to;
    w=e.w;
}

void bfs(lint u){
    used[u] = true;
    queue<lint> q;
    q.push(u);
    while (!q.empty())
    {
        lint u = q.front();
        q.pop();
        for (Node nd: gr[u])
        {
            lint v=nd.to;
            if (!used[v])
            {
                used[v] = true;
                bfs_dist[v]=bfs_dist[u]+1;
                q.push(v);
            }
        }
    }
}

vector<bool> bad_used;

void bad_bfs(lint u){
    bad_used[u] = true;
    queue<lint> q;
    q.push(u);
    while (!q.empty())
    {
        lint u = q.front();
        q.pop();
        for (Node nd: gr[u])
        {
            lint v=nd.to;
            if (!bad_used[v])
            {
                bad_used[v] = true;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);

    lint n=lnext(), m=lnext(), s=lnext()-1;
    dist=vector<lint>(n, INF);
    used=vector<bool>(n, false);
    bfs_dist=vector<lint>(n, 0);
    gr=vector<vector<Node> >(n);

    for (lint i=0; i<m; i++){
        lint from=lnext()-1,to=lnext()-1, w=lnext();
        Edge e(from, to, w);
        Node nd(e);
        nd.insert(from);
        edges.push_back(e);
    }
//    watch("Here");
    bfs(s);
//    watch("Here");
    dist[s]=0;
    for (lint i=0; i<n-1; i++)
        for (auto e:edges)
            if (dist[e.from]<INF)
                dist[e.to]=min(dist[e.to], dist[e.from]+e.w);

//    watch("Here");
    vector<lint> new_dist=dist;
    for (auto e:edges)
        if (new_dist[e.from]<INF)
            new_dist[e.to]=min(new_dist[e.to], new_dist[e.from]+e.w);

    vector<bool> isShort(n, true);
    set<lint> bad;
    for (lint i=0; i<n; i++)
        if (dist[i]>new_dist[i]) isShort[i]=false, bad.insert(i);
    bad_used=vector<bool>(n, false);
    for  (auto val: bad)
        bad_bfs(val);
    for (int i=0; i<n; i++)
        if (bad_used[i]) bad.insert(i);
//    watch("Here");

    for (lint i=0; i<n; i++){
        if (!used[i]){
            cout<<"*\n";
            continue;
        }
        if (bad.count(i)>0){
            cout<<"-\n";
            continue;
        }
        cout<<dist[i]<<"\n";
    }
//    dist[s]=0;
//    for (int i=0; i<n-1; i++)
//        for (auto val: e){
//            if (dist[val.from]<INF)
//                dist[val.to]=min(dist[val.to], dist[val.from]+val.w);
//        }


}


