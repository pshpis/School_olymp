#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mp make_pair
#define pw2(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()

#define fi first
#define se second
#define th third

#define ins insert
#define pb push_back
#define eb emplace_back

#define fr(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define wrvec(a) for (int i = 0; i < (a).size(); i ++) cout << (a)[i] << " "; cout << endl;
#define revfr(i, n) for(int (i) = int(n) - 1; (i) >= 0; i --)

#define int int64_t // int -> long long

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[] = "input.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "output.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int> > vii;
typedef set<int> si;
typedef set<pii> sii;

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

template<typename type>

type next()
{type x; cin >> x; return x;}

ll next()
{ll x; cin >> x; return x;}

int n, m, k;

int place_to_id(pii a){
    return a.first * m + a.se;
}

pii id_to_place(int id){
    return mp(id/m, id % m);
}

vector<vector<int>> gr(1e6);

void make_rib(int i, int j, int i_, int j_){
//    cout << i << " " << j << " " << i_ << " " << j_ << " from make rib" << endl;
    gr[place_to_id(mp(i, j))].pb(place_to_id(mp(i_, j_)));
    gr[place_to_id(mp(i_, j_))].pb(place_to_id(mp(i, j)));
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out


    n = next(),  m = next(), k = next();

    pii st, fsh;

    vector<vector<bool> > a(n, vector<bool>(m, true));

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            char c = next<char>();
            if (c == '#') a[i][j] = false;
            if (c == 'S') st = mp(i, j);
            if (c == 'F') fsh = mp(i, j);
        }
    }

//    cout << "After read" << endl;

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            if (!a[i][j]) continue;
//            cout << i << " " << j << endl;
            if (j - 1 >= 0 && a[i][j - 1]) make_rib(i, j, i, j - 1);
            if (j + 1 < m && a[i][j + 1]) make_rib(i, j, i, j + 1);
            if (i - 1 >= 0 && a[i - 1][j]) make_rib(i - 1, j, i, j );
            if (i + 1 < n && a[i + 1][j]) make_rib(i + 1, j, i, j);
//            cout << i << " " << j << endl;
        }
    }

//    cout << "Before DFS" << endl;
//    dist[place_to_id(st)] = 0;
//
//    dfs(place_to_id(st));
//
//    cout << dist[place_to_id(fsh)] << endl;

    int k = (n + 10) * (m + 10);
    int u=place_to_id(st);
    vector<int> used(k, false);
    vector<int> dist(k, 0);
    vector<int> p(k, 0);
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

    if (used[place_to_id(fsh)]) cout << dist[place_to_id(fsh)];
    else cout << -1;



}
/*




*/

