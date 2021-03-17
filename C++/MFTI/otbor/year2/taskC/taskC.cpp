#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)

//#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
#endif // FILE_out

typedef long long ll;

const int INF=2e9;
const ll INF64=1e18;
const double PI=3.14159265359;
const double EPS=1e-9;
const int MOD=1e9+7;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

ll lnext()
{ll x;cin>>x;return x;}

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
    cin >>  s;
    map<char, int> let;
    int ind = -1;

    for (char c: s){
        let[c]++;
    }

    for (char c = 'a'; c <= 'z'; c++){
        if (let[c] == 0) continue;
        if (let[c] % 2 == 0){
            if (ind == 1){
                ind = -1;
                break;
            }
            else {
                ind = 0;
                continue;
            }
        }
        else {
            if (ind == 0){
                ind = -1;
                break;
            }
            else{
                ind = 1;
                continue;
            }
        }
    }
    if (ind == -1) cout << "neither";
    else if (ind == 0) cout << "even";
    else if (ind == 1) cout << "odd";
}

