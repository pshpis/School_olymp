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

void test(){
    int n=next(), k=next(), d=next();
    vector<int> a;
    unordered_map<int, int> cnt;
    unordered_set<int> el_;
    for (int i=0; i<n; i++){
        int x=next();
        a.pb(x);
    }

    for (int i=0; i<d; i++){
        cnt[a[i]]++;
        el_.insert(a[i]);
    }
    int mn=el_.size();
    int sz=el_.size();
    for (int i=d; i<n; i++){
        if (cnt[a[i-d]]==1) sz--;
        cnt[a[i-d]]--;
        if (cnt[a[i]]==0) sz++;
        cnt[a[i]]++;
//        el.erase(el.find(a[i-d]));
//        if (el.count(a[i-d])==0) sz--;
//        if (el.count(a[i])==0) sz++;
//        el.insert(a[i]);
        mn=min(mn, sz);
    }
    cout<<mn<<"\n";
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

    int t=next();
    for (int i=0; i<t; i++){
        test();
    }

}

