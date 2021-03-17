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

#define int int64_t

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

vector<vector<int> > c;

void make_c(int n){
    c = vector<vector<int> >(n + 1, vector<int>(n + 1, 1));
    for (int i = 0; i <= n; i ++){
        for (int j = 0; j <= i; j ++){
            if (j == 0){
                c[i][j] = 1;
                continue;
            }
            if (i == j){
                c[i][j] = 1;
                continue;
            }
            if (j == 1){
                c[i][j] = i;
                continue;
            }
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

int num_obj(vector<int> choose, int n, int k){
    int cnt = 0;
    for (int i = 1; i <= k; i ++)
        for (int j = choose[i - 1] + 1; j <= choose[i] - 1; j ++)
            cnt += c[n - j][k - i];
    return cnt;
}

vector<int> obj_num(int m, int n, int k){
    int next = 1;
    vector<int> choose;
    while (k > 0){
        if (m < c[n - 1][k - 1]){
            choose.push_back(next);
            k --;
        }
        else m -= c[n - 1][k - 1];
        n --;
        next ++;
    }
    return choose;
}

void test1(){ // forward
    int n, k;
    cin >> n >> k;
    vector<int> a(k + 1, 0);
    for (int i = 1; i <= k; i ++) cin >> a[i];
    make_c(n);
    int num = num_obj(a, n, k);
    if (num < c[n - 1][k - 1]){
        cout << "first ";
        vector<int> ans = obj_num(num, n - 1, k - 1);
        for (int i = 0; i < ans.size(); i ++) cout << ans[i] << " ";
        cout << endl;
    }
    else{
        num -= c[n - 1][k - 1];
        cout << "second ";
        vector<int> ans = obj_num(num, n - 1, k );
        for (int i = 0; i < ans.size(); i ++) cout << ans[i] << " ";
        cout << endl;
    }
}

void test2(){ // reverse
    int n, k;
    cin >> n >> k;
    make_c(n);
    string s;
    cin >> s;
    if (s[0] == 'f'){
        vector<int> m(k, 0);
        for (int i = 1; i <= k - 1; i ++) cin >> m[i];
        int num = num_obj(m, n - 1, k - 1);
        vector<int> ans = obj_num(num, n, k);
        for (int i = 0; i < ans.size(); i ++) cout << ans[i] << " ";
        cout << endl;
    }
    else{
        vector<int> m(k + 1, 0);
        for (int i = 1; i <= k; i ++) cin >> m[i];
        int num = num_obj(m, n - 1, k);
        num += c[n - 1][k - 1];
        vector<int> ans = obj_num(num, n, k);
        for (int i = 0; i < ans.size(); i ++) cout << ans[i] << " ";
        cout << endl;
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

    string s;
    cin >> s;

    if (s[0] == 'f') test1();
    else test2();
}
/*




*/

