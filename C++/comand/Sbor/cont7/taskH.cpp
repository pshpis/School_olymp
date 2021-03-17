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

int n , m , cur = 0 , ans = 0;
vector < vector <bool> > a , was;
vector < vector <int> > num;
vector <bool> was_num;
vector <int> sz;

vector <int> nxt_i = {1 , -1 , 0 , 0 , 1 , -1 , -1 , 1};
vector <int> nxt_j = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};

void dfs(int i , int j){
    was[i][j] = true;
    sz[cur]++;
    num[i][j] = cur;
    for (int k = 0; k < 8; k ++){
        int x = i + nxt_i[k] , y = j + nxt_j[k];
        if (x < 0 || x >= n || y < 0 || y >= m || was[x][y] || !a[x][y]) continue;
        dfs(x , y);
    }
}

void dfs2(int i , int j){
    was[i][j] = true;
    for (int k = 0; k < 4; k ++){
        int x = i + nxt_i[k] , y = j + nxt_j[k];
        if (x < 0 || x >= n || y < 0 || y >= m || was[x][y] || !a[x][y]) continue;
        dfs2(x , y);
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    cin >> n >> m;
    a = vector < vector <bool> > (n , vector <bool> (m));
    was = vector < vector <bool> > (n , vector <bool> (m , false));
    num = vector < vector <int> > (n , vector <int> (m , -1));
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            char c;
            cin >> c;
            a[i][j] = (c == '*');
        }
    }

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            if (was[i][j] || !a[i][j]) continue;
            //cout << i << ' ' << j << ' ' << cur << endl;
            sz.pb(0);
            dfs(i , j);
            cur++;
        }
    }

    was_num.assign(cur , false);

    //for (int i = 0; i < 2; i ++) cout << sz[i] << '\n';

    vector < vector <bool> > b(n , vector <bool> (m , false));
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && a[i][j] && !was_num[num[i][j]]){
                was_num[num[i][j]] = true;
            }
        }
    }

    for (int i = 0; i < n; i  ++){
        for (int j = 0; j < m; j ++){
            if (num[i][j] >= 0 && !was_num[num[i][j]]){
                b[i][j] = true;
            }
        }
    }

    ans = 0;

    was = vector < vector <bool> > (n , vector <bool> (m , false));

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            //cout << b[i][j];
            if (b[i][j] && !was[i][j]){
                dfs2(i , j);
                ans++;
            }
        }
        //cout << '\n';
    }

    cout << ans;

}
/*
8 8
........
...**..*
.....**.
..*....*
.*.*.***
.*.*....
..**....
........

3 4
.*..
****
..*.


*/
