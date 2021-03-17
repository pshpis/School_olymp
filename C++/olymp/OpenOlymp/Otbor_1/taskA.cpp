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

string to_2(int x){
    string s = "";
    while (x > 0){
        s += '0' + x % 2;
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool line_0(string s){
    vector<int> line;
    int cnt = 0;
    bool fl = false;
    for (int i = 0; i < s.size(); i ++){
        if (s[i] == '0' && fl) cnt ++;
        else if (s[i] == '1' && fl){
            line.pb(cnt);
            cnt = 0;
            fl = false;
        }
        else if (s[i] == '0' && !fl){
            fl = true;
            cnt ++;
        }
    }
    if (fl) line.pb(cnt);

//    for (int i = 0; i < line.size(); i ++) cout << line[i] << " ";
//    cout << endl;

    if (line.size() == 2 && line[0] >= 6 && line[1] >= 6) return true;
    else return false;
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

    int n = 48892;
    int k = n;
    while (!line_0( to_2(k) )) k ++;

    watch(n);
    watch(k);
    watch(k - n);
}
/*




*/

