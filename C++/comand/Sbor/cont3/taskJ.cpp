#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int , int> pii;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define eb emplace_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

struct st{
    int x , d , u , t;

    st(){}
    st(int x , int d , int u , int t): x(x) , d(d) , u(u) , t(t) {}
};

int n , m , Cnt = 0;
vector < vector <int> > pref;
vector <st> lst;

int get_sum_pref(int l1 , int r1 , int l2, int r2){
    //cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
    int ans = pref[l2][r2];
    if (l1 > 0) ans -= pref[l1 - 1][r2];
    if (r1 > 0) ans -= pref[l2][r1 - 1];
    if (l1 > 0 && r1 > 0) ans += pref[l1 - 1][r1 - 1];
    return ans;
}

bool check(int k){
    if (k == 0) return true;

    for (int i = 0; i <= n - k; i ++){
        for (int j = 0; j <= m - k; j ++){
            //cout << k << '\n';
            if (get_sum_pref(i , j , i + k - 1 , j + k - 1) == 0) return true;
        }
    }
    return false;
}

void push(int k){
    if (k == 0) return;

    for (int i = 0; i <= n - k; i ++){
        for (int j = 0; j <= m - k; j ++){
            if (get_sum_pref(i , j , i + k - 1 , j + k - 1) == 0){
                lst.pb({i , j , j + k , 1});
                lst.pb({i + k , j , j + k , -1});
                Cnt++;
            }
        }
    }
}

int AA , BB , ans = 1e9;

void solve(vector < vector <char> > jopa , int A , int B){
    if (A < 0 || A >= n || B < 0 || B >= m) return;

    jopa[A][B] = 'X';

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            pref[i][j] = (jopa[i][j] == 'X');
        }
    }

    for (int i = 0; i < n; i ++){
        for (int j = 1; j < m; j ++){
            pref[i][j] += pref[i][j - 1];
        }
    }

    for (int i = 1; i < n; i ++){
        for (int j = 0; j < m; j ++){
            pref[i][j] += pref[i - 1][j];
        }
    }


    int l = 0 , r = min(n , m) , Max;
    while(r - l > 1){
        int m = (l + r) / 2;
        if(check(m)) l = m;
        else r = m;
    }

    if (check(r)) Max = r;
    else Max = l;

    if (Max < ans){
        ans = Max;
        AA = A , BB = B;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector < vector <char> > jopa(n , vector <char> (m));
    pref = vector < vector <int> > (n , vector <int> (m));

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            char c; cin >> c;
            jopa[i][j] = c;
            pref[i][j] = (c == 'X');
        }
    }

    for (int i = 0; i < n; i ++){
        for (int j = 1; j < m; j ++){
            pref[i][j] += pref[i][j - 1];
        }
    }

    for (int i = 1; i < n; i ++){
        for (int j = 0; j < m; j ++){
            pref[i][j] += pref[i - 1][j];
        }
    }




    int Max , l = 0 , r = min(n , m);
    while(r - l > 1){
        int m = (l + r) / 2;
        if(check(m)) l = m;
        else r = m;
    }

    if (check(r)) Max = r;
    else Max = l;

    push(Max);

    sort(lst.begin() , lst.end() , [](const st &a , const st &b) {
        return a.x < b.x || (a.x == b.x && a.t > b.t);
    });


    vector < vector <int> > cnt(n , vector <int> (m , 0));

    for (int x = 0 , i = 0; x < n; x ++){
        if (x > 0) cnt[x] = cnt[x - 1];

//        for (int i = 0; i < n; i ++){
//            for (int j = 0; j < m; j ++){
//                cout << cnt[i][j] << ' ';
//            } cout << '\n';
//        }cout << '\n';

        vector <pii> cur;
        while(i < lst.size() && lst[i].x == x){
            cur.eb(lst[i].d , 1*lst[i].t);
            cur.eb(lst[i].u , -1*lst[i].t);
            i++;
        }
        sort(cur.begin() , cur.end() , [](const pii &a , const pii &b){
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });

        int sum = 0;
        for (int y = 0 , j = 0; y < m; y ++){
            while(j < cur.size() && cur[j].fi == y){
                sum += cur[j].se;
                j++;
            }
            cnt[x][y] += sum;
        }
    }


    //cout << Max << '\n';

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            cout << cnt[i][j] << ' ';
        } cout << '\n';
    }


    int l1 = n , r1 = m , l2 = 0 , r2 = 0;

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            if (cnt[i][j] == Cnt){
                l1 = min(i , l1);
                l2 = max(i , l2);
                r1 = min(j , r1);
                r2 = max(j , r2);
            }
        }
    }

    if (l2 == 0 && l1 == n){
        int L , R;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                if (get_sum_pref(i , j , i , j) == 0){
                    L = i , R = j;
                }
            }
        }
        cout << L + 1 << ' ' << R + 1 << '\n';
        cout << Max;
        return 0;
    }

    int A = (l1 + l2) / 2 , B = (r1 + r2) / 2;
    solve(jopa , A , B);
    solve(jopa , A + 1 , B);
    solve(jopa , A , B + 1);
    solve(jopa , A , B - 1);
    solve(jopa , A - 1 , B);
    solve(jopa , A + 1, B + 1);
    solve(jopa , A - 1 , B - 1);
    solve(jopa , A - 1 , B + 1);
    solve(jopa , A + 1 , B - 1);

    cout << AA + 1 << ' ' << BB + 1 << '\n' << ans;
}
/*
6 4
X..X
X.XX
X.XX
X..X
X..X
X..X


2 6
..XX.X.
..XX.X.

2 6
..XX.X.
..XX.X.

4 4
....
....
....
X...


3 4
....
....
....

3 3
...
...
...

1 4
XX.X

4 10
XXXXXXXXXX
X........X
X........X
XXXXXXXXXX

*/
