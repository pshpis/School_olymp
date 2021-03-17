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
#define x first
#define y second
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

void step1(pii& st, int& n, int k, set<pii>& ans){
    ans.insert(st);

    for (int i = 0; i < n; i ++){
        st.y ++;
        ans.insert(st);
    }

    for (int i = 0; i < n; i ++){
        st.x ++;
        ans.insert(st);
    }

    n += k;

    for (int i = 0; i < n; i ++){
        st.y --;
        ans.insert(st);
    }

    for (int i = 0; i < n; i ++){
        st.x --;
        ans.insert(st);
    }

    n += k;
}

void robot1(pii st, int n, set<pii>& ans){
    int k = n;
    for(int i = 0; i < 5; i ++) step1(st, n, k, ans);
}

int step2(pii& st, int& n, int k, set<pii>& ans){
    int cnt = 0;

    for (int i = 0; i < n; i ++){
        st.y ++;
        cnt += ans.count(st);
    }

    for (int i = 0; i < n; i ++){
        st.x ++;
        cnt += ans.count(st);
    }

    n += k;

    for (int i = 0; i < n; i ++){
        st.y --;
        cnt += ans.count(st);
    }

    for (int i = 0; i < n; i ++){
        st.x --;
        cnt += ans.count(st);
    }

    n += k;

    return cnt;
}

int robot2(pii st, int n, set<pii>& ans){
    int k = n;
    int cnt = 0;
    for (int i = 0; i < 5; i ++){
        cnt += step2(st, n, k, ans);
    }
    return cnt;
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

    pii st1 = {0, 0};
    pii st2 = {9, -9};

    set<pii> ans;
    int n1 = 5;
    robot1(st1, n1, ans);

    int mx = -1;
    int n2 = 1000;

    int last = -1;
    for (int i = 2; i <= n2; i ++){
        if (robot2(st2, i, ans) > mx){
            last = i;
            mx = robot2(st2, i, ans);
        }
    }

    watch(last);
    watch(mx);
}
/*




*/

