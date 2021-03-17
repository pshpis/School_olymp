#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pow2(x) ((x)*(x))
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

typedef long long lint;

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

    int q=next();
    for (int i=0; i<q; i++){
        int a=next(), b=next(), c=next();
        cout<<min(max((a+c+1-b)/2, 0), c+1)<<"\n";
    }
}

