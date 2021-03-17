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
set<int> b_set;
vector<int> b_arr;
map<int, int> b_ind;

void make_b(int x){
    int k = x;
    while (x < 1e9){
        b_set.insert(x);
        b_arr.pb(x);
        x *= 10;
        x += k;
    }
}

void test(){
    int n;
    cin >> n;

    set<int> :: iterator it = b_set.upper_bound(n);
    if (it == b_set.end()) cout << b_set.size() << "\n";
    else{
        int x = *it;
        cout << b_ind[x] << "\n";
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

    for (int i = 1; i <= 9; i ++) make_b(i);

    sort(b_arr.begin(), b_arr.end());
//
//    for (int i = 0; i < b_arr.size(); i ++)
//        cout << b_arr[i] << " ";
//    cout << endl << "----------" << endl;

    for (int i = 0; i < b_arr.size(); i ++){
        b_ind[b_arr[i]] = i;
    }

    for (int i = 0; i < t; i ++) test();
}
/*




*/

