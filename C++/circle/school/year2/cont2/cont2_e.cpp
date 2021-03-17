#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)
#define int int64_t

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

vector<int> fact;

int sp_gcd(int a, int b, int& x, int&y){
    if (a==0){
        x=0;
        y=1;
        return b;
    }
    int x_, y_;
    int ans=sp_gcd(b%a, a, x_, y_);
    x=y_-(lint)(b/a)*x_;
//    watch(x);
    y=x_;
    return ans;

}

int conv(int a){
    int x, y;
    int nd=sp_gcd(a, MOD, x, y);
    x=(x%MOD+MOD)%MOD;
    return x;
}

int c(int n, int k){
    int ans=fact[n];
    int del=((lint)fact[k]*fact[n-k])%MOD;
//    watch(del);
//    watch(conv(del));
//    watch(ans);
    ans=((lint)ans*conv(del))%MOD;
    return ans;
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

    int max_n=1e5+100;
    int n=next(), m=next(), q=next();
//    swap(n, m);
    fact=vector<int>(max_n);
    fact[0]=1;
    for (int i=1; i<max_n; i++)
        fact[i]=(((lint)fact[i-1])*i)%MOD;
    for (int i=0; i<=m; i++){
//        watch(i);
//        watch(fact[i]);
//        watch(conv(fact[i]));
//        watch(c(fact[i], i));
    }
//    watch(c(1, 2));
    int ans=c(n+m-2,n-1);
    watch(ans);
    for (int i=0; i<q; i++){
        int x=next()-1, y=next()-1;
        int d=c(x+y, x);
        watch(d);
        d=((lint)d*c(n-1-x+m-1-y, n-1-x))%MOD;
        watch(d);
        ans=max(ans-d, (int64_t)0)%MOD;
        watch(ans);
    }
    cout<<ans<<endl;
}

