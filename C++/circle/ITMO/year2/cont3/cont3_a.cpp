#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
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

    int n=next();
    vector<int> a;
    for (int i=0; i<n; i++) a.pb(next());
    vector<int> dp(n, 1);
    vector<int> p(n, 0);
    for (int i=0; i<n; i++){
        int mx=0;
        int p_=-1;
        for (int j=i-1; j>=0; j--){
            if (a[i]>a[j])
                if (dp[j]>mx){
                    mx=dp[j];
                    p_=j;
                }
        }
        p[i]=p_;
        dp[i]=mx+1;
    }
//    cout<<"DPPP"<<endl;
//    for (int i=0; i<n; i++){
//        cout<<dp[i]<<" ";
//    }
//    cout<<endl;
    int pl=-1;
    int ans=-1e9;
    for (int i=0; i<n; i++){
        if (ans<dp[i]){
            ans=dp[i];
            pl=i;
        }
    }
    int cnt=0;
    vector<int> res;
    while (p[pl]!=-1){
        res.pb(a[pl]);
        pl=p[pl];
    }
//    watch(ans);
    res.pb(a[pl]);
    reverse(res.begin(), res.end());
    cout<<res.size()<<"\n";
    for (int i=0; i<res.size(); i++) cout<<res[i]<<" ";

}

