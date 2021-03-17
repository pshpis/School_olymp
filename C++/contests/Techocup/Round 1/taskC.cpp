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

lint lcm(lint x, lint y)
{
    lint ans=x*y/__gcd(x, y);
    return ans;
}


void test(){
    int n=next();
    vector<int> tick;
    for (int i=0; i<n; i++)
        tick.pb(next());
    sort(tick.begin(), tick.end());
    int x=next(), a=next(), y=next(), b=next();
    if (x<y){
        swap(x, y);
        swap(a, b);
    }
    int nok=lcm(a, b), s1=0, s2=0, s3=0, ans=0;

    for (int i=n-1; i>=n-n/nok; i--){
        s1+=tick[i];
    }
    ans+=s1*(x+y)/100;

    for (int i=n-n/nok-1; i>=n-n/a; i--){
        s2+=tick[i];
    }
    ans+=s2*x/100;

    for (int i=n-n/a-1; i>=n-n/a-n/b-n/nok; i--){
        s3+=tick[i];
    }
    ans+=s3*y/100;

    int k=next();
    if (k<=ans) cout<<"YES\n";
    else cout<<"NO\n";
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

    int q=next();
    for (int i=0; i<q; i++){
        test();
    }


}

