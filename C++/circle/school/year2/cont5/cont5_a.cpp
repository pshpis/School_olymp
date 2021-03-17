#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)

//#define int int64_t

#define FIlE_in
#define FILE_out

#ifdef FIlE_in
    char file_in[]="forest.in";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[]="forest.out";
#endif // FILE_out

typedef long long ll;

const int INF=2e9;
const ll INF64=1e18;
const double PI=3.14159265359;
const long double EPS=1e-11;
const int MOD=1e9+7;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

ll lnext()
{ll x;cin>>x;return x;}

long double v, v_, a;

int x_s=0, y_s=1, x_f=1, y_f=0;

long double dist (long double x1, long double y1, long double x2, long double y2){
    return sqrt(pw2(x1-x2)+pw2(y1-y2));
}

long double time(long double pl){
    long double d=dist(pl, a, x_s, y_s);
    long double d_=dist(pl, a, x_f, y_f);
    long double t=d/v;
    long double t_=d_/v_;
    return t+t_;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out

    cin>>v>>v_>>a;
    long double L=0, R=1;
    while (R-L>EPS){
        long double M=(2*L+R)/3, M_=(L+2*R)/3;
        if (time(M)<time(M_)) R=M_;
        else if (time(M)>time(M_)) L=M;
        else break;
    }
    cout<<(R+L)/2;

}

