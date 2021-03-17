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

int n;

vector<int> a, d;

int rec(int i, unordered_set<int>& was){
    if (was.count(i) > 0){
        if (d[i] != -2) return d[i];
        return -1;
    }

    was.insert(i);
    if (d[i] != -2) return d[i];
    int l = -2, r = -2;

    if (i + a[i] < n) r = i + a[i];
    if (i - a[i] >= 0) l = i - a[i];

//    watch(l);
//    watch(r);
//    watch(i);
//    watch(a[i]);

    if (l == -2 && r == -2){
        d[i] = -1;
        return d[i];
    }
    if (l == -2){
        if (abs(a[i] - a[r]) % 2 == 1) d[i] = 1;
        else{
            int k1 = rec(r, was);
            if (k1 == -1) d[i] = k1;
            else d[i] = k1 + 1;
        }
//        cout << "YES_1" << endl;
        return d[i];
    }
    if (r == -2){
        if (abs(a[i] - a[l]) % 2 == 1) d[i] = 1;
        else{
            int k1 = rec(l, was);
            if (k1 == -1) d[i] = k1;
            else d[i] = k1 + 1;
        }
//        cout << "YES_2" << endl;
        return d[i];
    }
    if ((abs(a[i] - a[l]) % 2 == 1 && a[l] >= 0) || (abs(a[i] - a[r]) % 2 == 1 && a[r] >= 0)){
        d[i] = 1;
//        cout << "YES_3" << endl;
        return d[i];
    }
    else{
        int k1 = rec(l, was);
        int k2 = rec(r, was);
        int k = min(k1, k2);
        if (k == -1) k = max(k1, k2);
        if (k == -1) d[i] = k;
        else d[i] = k + 1;
//        cout << "YES" << endl;
        return d[i];
    }
    return d[i];
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
    a = vector<int> (n);
    d = vector<int> (n, -2);
    for (int i = 0; i < n; i ++) cin >> a[i];

    for (int i = 0; i < n; i ++){
        unordered_set<int> was;
        rec(i, was);
    }

    for (int i = 0; i < n; i ++) cout << d[i] << " ";
}
/*
3
2 1 2

10
2 1 2 3 2 4 2 5 1 1


*/

