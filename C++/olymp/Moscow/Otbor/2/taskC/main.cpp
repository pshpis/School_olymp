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

#define FIlE_in
#define FILE_out

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

vector<bool> used;
vector<set<int> > g;
vector<int> val;


int dfs(int st, vector<unordered_set<int> >& gr, vector<vector<int> >& a, vector<int>& comp){
    used[st] = true;
    comp.pb(st);
    int ans = a[st].size();
    for (int v: gr[st]){
        if (!used[v]){
            ans += dfs(v, gr, a, comp);
        }
    }
    return ans;
}

bool is_rib(int i, int j){
    return g[i].count(j) > 0;
}

bool check(set<int>& candidates, set<int>& wrong){
    for (int i: wrong){
        bool q = false;
        for (int j: candidates){
            if (!is_rib(i, j)){
                q = true;
                break;
            }
        }
        if (!q) return false;
    }
    return true;
}

int mx = -1;
set<int> ans;

int cnt = 0;

void extend(set<int>& compsub, set<int>& candidates, set<int>& wrong){
    cnt ++;
//    cout << cnt << "\n";
    if (cnt > 5000){
        mx = -1;
        return;
    }
    while (!candidates.empty() && check(candidates, wrong)){
        int v = *candidates.begin();
        compsub.insert(v);
        set<int> new_candidates, new_wrong;
        for (int i: candidates){
            if (is_rib(i, v) && i != v) new_candidates.insert(i);
        }
        for (int i: wrong){
            if (is_rib(i, v) && i != v) new_wrong.insert(i);
        }
        if (new_candidates.empty() && new_wrong.empty()){
            int sum = 0;
            bool fl = true;
//            for (int i: compsub)
//                for (int j: compsub)
//                    if (is_rib(i, j)) fl = false;
            if (fl){
                for (int i: compsub){
                    sum += val[i];
                }
                if (sum > mx){
                    ans = compsub;
                    mx = sum;
                }
            }
        }
        else {
            extend(compsub, new_candidates, new_wrong);
        }
        candidates.erase(v);
        compsub.erase(v);
        wrong.insert(v);
    }

}

void solve(){
    int n = next(), m = next();
    g.clear();
    ans.clear();
    mx = -1;
    used.clear();
    val.clear();
    cnt = 0;
    vector<vector<int> > a(m + 100);
    vector<vector<int> > obr(n + 100);
    for (int i = 0; i < m; i ++){
        int k = next();
        a[i].resize(k);
        for (int j = 0; j < k; j ++){
            a[i][j] = next() - 1;
            obr[a[i][j]].pb(i);
        }
    }

    g.resize(m);
    val.resize(m);
    for (int i = 0; i < m; i ++) val[i] = a[i].size();

    for (int i = 0; i < n; i ++){
        int k = obr[i].size();
        for (int j = 0; j < k; j ++){
            for (int j_ = j + 1; j_ < k; j_ ++){
                g[obr[i][j]].insert(obr[i][j_]);
                g[obr[i][j_]].insert(obr[i][j]);
            }
        }
    }



    vector<set<int> > gr(m);
    for (int i = 0; i < m; i ++){
//        cout << i + 1<< " : ";
        for (int j = i + 1; j < m; j ++){
            if (g[i].count(j) == 0){
                gr[i].insert(j);
                gr[j].insert(i);
//                cout << j + 1 << " ";
            }
        }
//        cout << "\n";
    }
    g = gr;

//    cout << "Before extend" << endl;

    set<int> compsub, candidates, wrong;

    for (int i = 0; i < m; i ++) candidates.insert(i);
    extend(compsub, candidates, wrong);

//    cout << "After extend" << endl;

    int mx_val = -1, id_mx_val = -1;
    for (int i = 0; i < m; i ++){
        if (val[i] > mx_val){
            mx_val = val[i];
            id_mx_val = i;
        }
    }

    if (mx > mx_val){
        cout << ans.size() << "\n";
        bool fl = true;
        for (int v: ans){
            cout << v + 1 << " ";
            if (v + 1 < 1 || v + 1 > m) fl = false;
        }
        if (!fl) cout << "\n WTF!!!!!\n------------------";
        cout << "\n";
    }
    else {
        cout << 1 << "\n";
        cout << id_mx_val + 1 << "\n";
    }

    ans.clear();
    mx = -1;

//    cout << endl;
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

    int t = next();
    for (int i = 0; i < t; i ++)
        solve();
}
/*




*/

