#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
#endif // FILE_out

typedef long long lint;
typedef pair<int, int> pii;

const int INF=2e9;
const lint INF64=1e18;
const double PI=3.14159265359;
const double EPS=1e-9;
const int MOD=1e9+7;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
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

    vector<vector<int>> a(3);
    for (int i=0; i<3; i++){
        for (int j=0; j<2; j++){
            int x=next();
            a[i].pb(x);
        }
    }
    for (int i=0; i<2; i++){
        int f1=a[1][i];
        int s1=a[1][1-i];
        for (int j=0; j<2; j++){
            int f2=a[2][j];
            int s2=a[2][1-j];
            if ((f1+f2<=a[0][0] && max(s1, s2)<=a[0][1]) || (f1+f2<=a[0][1] && max(s1, s2)<=a[0][0])){
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
}

