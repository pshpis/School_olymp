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
    int n = next();
    vector<int> q1(n), q2(n);
    int sum = 0;
    for (int i = 0; i < n; i ++){
        int x = next();
        if (x == 2) x = -1;
        q1[i] = x;
        sum += x;
    }
    for (int i = 0; i < n; i ++){
        int x = next();
        if (x == 2) x = -1;
        q2[i] = x;
        sum += x;
    }
    reverse(q2.begin(), q2.end());
    int cnt = 0;
    watch(sum);
    while (sum != 0){
        if (q1.size() == 0){
            sum -= q2.back();
            q2.pop_back();
            cnt ++;
            continue;
        }
        if (q2.size() == 0){
            sum -= q1.back();
            q1.pop_back();
            cnt ++;
            continue;
        }
        if (sum > 0){
            int k = max(q1.back(), q2.back());
            sum -= k;
            if (q1.back() == k){
                q1.pop_back();
            }
            else q2.pop_back();
        }
        else{
            int k = min(q1.back(), q2.back());
            sum -= k;
            if (q1.back() == k){
                q1.pop_back();
            }
            else q2.pop_back();
        }
        cnt ++;
    }
    cout << cnt << endl;
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
    for (int i = 0; i < t; i ++)
        test();
}
/*
1
4
2 1 2 1 2 2 2 1



*/

