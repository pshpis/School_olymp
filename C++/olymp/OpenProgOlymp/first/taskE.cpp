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

//#define int int64_t // int -> long long

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
const int MAXN = 1e5 + 100;

template<typename type>

type next()
{type x; cin >> x; return x;}

ll next()
{ll x; cin >> x; return x;}

int n, m;
vector<pair<int, pii> > e1, e2;

struct SNM{
    vector<int> parent;
    vector<int> r;

    SNM(){
        parent.resize(MAXN);
        r.resize(MAXN);
    }

    void make_set(int v){
        parent[v] = v;
        r[v] = 0;
    }

    int find_set(int v){
        if (parent[v] == v) return v;
        else return parent[v] = find_set(parent[v]);
    }

    void merge_set(int a, int b){
        a = find_set(a);
        b = find_set(b);

        if (a == b) return;
        if (r[a] < r[b]) swap(a, b);
        if (r[a] == r[b]) r[a] ++;
        parent[b] = a;
    }

    bool together(int a, int b){
        return find_set(a) == find_set(b);
    }
};

SNM for_kruskal(int x){
    SNM s;
    for (int i = 0; i < x; i ++) s.make_set(i);
    return s;
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

    cin >> n >> m;
    for (int i = 0; i < m; i ++){
        int a1 = next() - 1, b1 = next() - 1, a2 = next() - 1, b2 = next() - 1, w = next();
        e1.pb(mp(w, mp(a1, b1)));
        e2.pb(mp(w, mp(a2, b2)));
    }

    sort(all(e1));
    reverse(all(e1));

    sort(all(e2));
    reverse(all(e2));

    SNM s1 = for_kruskal(n), s2 = for_kruskal(n);

    vector<int> ans(m, -INF);
    int cnt = 0;

    int sum_w = 0;

    for (int i = 0; i < m; i ++){
        int w = e1[i].fi;
        int a1 = e1[i].se.fi, b1 = e1[i].se.se;
        int a2 = e2[i].se.fi, b2 = e2[i].se.se;
        if (!s1.together(a1, b1) && !s2.together(a2, b2)){
            s1.merge_set(a1, b1);
            s2.merge_set(a2, b2);
            sum_w += w;
            ans[cnt] = sum_w;
            cnt ++;
        }
    }

    for (int i = 0; i < m; i ++){
        if (ans[i] != -INF) cout << ans[i] << "\n";
        else cout << "Impossible\n";
    }


}
/*




*/

