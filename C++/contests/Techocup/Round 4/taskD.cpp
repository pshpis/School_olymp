#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++ i)
#define fi first
#define se second
#define ins insert

//#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

template<typename type>

type next()
{type x; cin >> x; return x;}

int next()
{int x; cin >> x; return x;}

ll lnext()
{ll x; cin >> x; return x;}

void test(){
    int n;
    cin >> n;
    vector<int> ind_1, ind_2, ind_3, ind_4;
    unordered_set<string> st;
    vector<string> a;
    for (int i = 0; i < n; i ++){
        string x;
        cin >> x;
        a.pb(x);
        st.insert(x);
        if (x[0] == '0' && x[(int)x.size() - 1] == '1') ind_1.pb(i);
        if (x[0] == '1' && x[(int)x.size() - 1] == '0') ind_2.pb(i);
        if (x[0] == '0' && x[(int)x.size() - 1] == '0') ind_3.pb(i);
        if (x[0] == '1' && x[(int)x.size() - 1] == '1') ind_4.pb(i);

    }

    unordered_set<int> no;

    for (int v: ind_1){
        reverse(a[v].begin(), a[v].end());
        if (st.count(a[v]) > 0) no.insert(v);
        reverse(a[v].begin(), a[v].end());
    }

    for (int v: ind_2){
        reverse(a[v].begin(), a[v].end());
        if (st.count(a[v]) > 0) no.insert(v);
        reverse(a[v].begin(), a[v].end());
    }

    if (ind_1.size() == 0 && ind_2.size() == 0){
        if (ind_3.size() > 0 && ind_4.size() > 0){
            cout << -1 << "\n";
            return;
        }
        cout << 0 << "\n";
        return;
    }

    int k = abs((int)ind_1.size() - (int)ind_2.size());
    int ans = k / 2;
    cout << ans << "\n";
    if (ind_1.size() > ind_2.size()){
        int i = 0;
        int cnt = 0;
        vector<int> res;
        while (cnt < ans && i < ind_1.size()){
            if (no.count(ind_1[i]) > 0){
                i ++;
                continue;
            }
            res.pb(ind_1[i]);
            cnt ++;
            i ++;
        }
        if (cnt < ans) cout << -1 << "\n";
        else{
            for (int i = 0; i < res.size(); i ++) cout << res[i] + 1<<" ";
            cout << "\n";
        }
    }
    else{
         int i = 0;
        int cnt = 0;
        vector<int> res;
        while (cnt < ans && i < ind_2.size()){
            if (no.count(ind_2[i]) > 0){
                i ++;
                continue;
            }
            res.pb(ind_2[i]);
            cnt ++;
            i ++;
        }
        if (cnt < ans) cout << -1 << "\n";
        else{
            for (int i = 0; i < res.size(); i ++) cout << res[i] + 1 <<" ";
            cout << "\n";
        }
    }

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

    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        test();
    }
}
/*




*/

