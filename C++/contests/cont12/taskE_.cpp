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
    char file_in[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

int n;
vi a, ans;
vector<bool> was;

bool ok(int v, int u){
    if (v >= 0 && v < n && u >= 0 && u < n)
        if (abs(a[v] - a[u]) % 2 == 1) return true;
    return false;
}

void dfs(int st){
    ans[st] = -1;
    int right = st + a[st];
    int left = st - a[st];

    bool is_left = true, is_right = true;
    if (left < 0) is_left = false;
    if (right > n - 1) is_right = false;

    if (!is_left && !is_right){
        return;
    }

    int ans_left = -1;
    int ans_right = -1;

    if (is_right){
        if (ok(st, right)) ans_right = 0;
        else
        if (ans[right] == -1){
            ans_right = -1;
        }
        else
        if (ans[right] == -2){
            dfs(right);
            if (ans[right] == -1){
                ans_right = -1;
            }
            else ans_right = ans[right];
        }
        else {
            ans_right = ans_right
        }
    }

    if (is_left){
        if (abs(a[st] - a[left]) % 2 == 1) ans_left = 0;
        else {
            if (was.count(left) > 0) ans_left = -1;
            else
            if (ans[left] == -2){
                dfs(left, was);
                ans_left = ans[left];
            }
            else ans_left = ans[left];
        }
    }

    ans[st] = min(ans_left, ans_right);
    if (ans[st] == -1) ans[st] = max(ans_left, ans_right);
    if (ans[st] != -1) ans[st] ++;

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

    cin >> n;
    a = vi(n);
    ans = vi(n, -2);
    was = vector<bool>(n, false);

    for (int i = 0; i < n; i ++) cin >> a[i];

    for (int i = 0; i < n; i ++){
        unordered_set<int> was;
        dfs(i, was);
    }

    for (int i = 0; i < n; i ++) cout << ans[i] << " ";

    // остлось скомпилить и протестить


}
/*
10
2 1 2 3 2 4 2 5 1 1

-1 1 -1 1 -1 1 1 1 2 3


*/

