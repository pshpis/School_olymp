#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)
#define fi first
#define se second

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
typedef pair<int, int> pii;

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

    int n = next(), m = next(), d = next();
    d--;
    vector<int> a;
    vector<int> el;
    int left = 0, right = n;
    for (int i = 0; i < m; i ++){
        int x = next();
        a.pb(x);
        left += x;
        el.pb(x);
    }
    set<pii> mem;
    while (true){

        if (right - left <= d){
            cout << "YES" << endl;
            int cnt = 1;
//            cout<<0<<" ";
            int ind = 0;
            for (int v: el){
                for (int j = 0; j < v; j ++){
                    cout<<cnt<<" ";
                    ind++;
                }
                cnt++;
            }
            for (auto p: mem){
//                watch(p.fi);
//                watch(p.se);
                if (ind < p.fi){
                    while (ind < p.fi){
                        ind ++;
                        cout<<"0 ";
                    }
                }
                for (int j = 0; j < p.se; j++){
                    cout<<cnt<<" ";
                    ind ++;
                }
                cnt++;
            }
            for (int j = ind; j < n; j++)
                cout<<"0 ";
            break;
        }
        if (el.empty()){
            cout << "NO";
            break;
        }
        int now = el.back();
//        watch(now);
        el.pop_back();
        right -=  d + now;
        left -= now;
        mem.insert(mp(right, now));
    }

}

