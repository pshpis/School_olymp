#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

#define int int64_t

int dfs(int st, vector<int>& p, int id, vector<vector<int> >& gr, vector<bool>& used, vector<vector<int> >& c, vector<int>& pok){
    used[st] = true;
    int ans = 0;
    int cl = p[id];
    ans += c[cl][st];
    pok[st] = cl;
    for (int v: gr[st]){
        if (!used[v]){
            ans += dfs(v, p, (id + 1) % 3, gr, used, c, pok);
        }
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    int n;
    cin >> n;
    vector<vector<int> > c(3, vector<int>(n));
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < n; j ++){
            cin >> c[i][j];
        }
    }
    vector<vector<int> > gr(n);
    bool bamb = true;
    for (int i = 0;  i < n - 1; i ++){
        int x, y;
        cin >> x >> y;
        x--; y--;

        gr[x].pb(y);
        gr[y].pb(x);
        if (gr[x].size() > 2) bamb = false;
        if (gr[y].size() > 2) bamb = false;
    }

    if (!bamb){
        cout << -1;
        return 0;
    }

    vector<int> edge;
    for (int i = 0; i < n; i ++){
        if (gr[i].size() == 1) edge.pb(i);
    }

    int st = edge[0], fsh = edge[1];

    vector<int> p = {0, 1, 2};
    vector<bool> used(n, false);
    vector<int> ln;
    vector<int> pok(n, -1);
    int ans = 1e18 + 100;
//    cout << "YES" << endl;
    for (int i = 0; i < 6; i ++){
        used.assign(n, false);
        int ans1 = dfs(st, p, 0, gr, used, c, pok);
        if (ans1 < ans){
            ans = ans1;
            ln = pok;
        }
        next_permutation(p.begin(), p.end());
    }
    cout << ans << endl;
    for (int i = 0; i < ln.size(); i ++){
        cout << ln[i] + 1 << " ";
    }
}
/*



*/

