#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

//#define int int64_t

vector<unordered_set<int> > gr;
int n, m;
vector<int> cl;
bool is_cycle = false;

void read_gr(){
    cin >> n >> m;
    gr = vector<unordered_set<int> >(n);
    cl = vector<int>(n, 0);

    for (int i = 0; i < m; i ++){
        int x, y;
        cin >> x >> y;
        x--; y --;
        gr[x].insert(y);
    }
}

void dfs(int st){
    cl[st] = 1;
    for (int v: gr[st]){
        if (cl[v] == 0) dfs(v);
        if (cl[v] == 1) is_cycle = true;
    }
    cl[st] = 2;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    read_gr();
    for (int i = 0; i < n; i ++){
        if (cl[i] == 0) dfs(i);
    }
    if (n == 1) cout << -1;
    else if (m == 0) cout << 2;
    else if (is_cycle) cout << 0;
    else if (!is_cycle) cout << 1;
}
/*



*/

