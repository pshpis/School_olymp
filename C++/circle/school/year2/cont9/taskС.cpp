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

    int n = s.size();

    for (int i = 0; i < n; i ++) s[i] = (s[i] - '0') % 3 + '0';

    int cnt = 0;
    for (int i = 0; i < n; i ++){
        if (s[i] == '0'){
            cnt ++;
            continue;
        }
        if (i + 1 < n && s[i + 1] == '0') continue;
        if (i + 2 < n && s[i + 2] == '0'){
            cnt += int(s[i] - '0' + s[i + 1] - '0' == 3);
            i ++;
            continue;
        }
        if (i + 2 < n){
            int s1 = s[i] - '0' + s[i + 1] - '0';
            int s2 = s[i + 1] - '0' + s[i + 2] - '0';
            int s3 = s[i] - '0' + s[i + 1] - '0' + s[i + 2] - '0';
            if (s1 % 3 == 0){
                cnt ++;
                i ++;
                continue;
            }
            if (s2 % 3 == 0 || s3 % 3 == 0){
                cnt ++;
                i += 2;
                continue;
            }
        }
        if (i + 1 < n){
            int s1 = s[i] - '0' + s[i + 1] - '0';
            if (s1 % 3 == 0){
                cnt ++;
                i ++;
                continue;
            }
        }
    }

    cout << cnt << '\n';

}
/*




*/

