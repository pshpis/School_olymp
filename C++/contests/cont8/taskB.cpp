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

void test(){
    int n = next();
    string s, s_;
    cin >> s >> s_;

    if (s == s_){
        cout << "YES\n";
        cout << "1\n";
        cout << "1 1\n";
        return;
    }

    vector<set<int> > let_pos(26);
    for (int i = 0; i < n; ++ i){
        let_pos[s[i] - 'a'].insert(i);
    }

    vector<pii> ans;
    set<int> :: iterator it;
    for (int i = 0; i < n; ++ i){
        if (s[i] == s_[i]) continue;
        if (let_pos[s[i] - 'a'].empty()){
            cout << "NO\n";
            return;
        }
        int p = -1;
        it = let_pos[s[i] - 'a'].begin();
        if (*it == i){
            it ++;
            if (it == let_pos[s[i] - 'a'].end()){
                cout << "NO\n";
                return;
            }
        }
        p = *it;
        let_pos[s[i] - 'a'].erase(it);
        let_pos[s_[i] - 'a'].insert(p);
        swap(s_[i], s[p]);
        ans.pb(mp(i, p));
    }
    if (s == s_){
        cout<<"YES\n";
        cout<<ans.size()<<"\n";
        for (int i = 0; i < ans.size(); ++ i)
            cout<<ans[i].fi+1<<" "<<ans[i].se+1<<"\n";
        return;
    }
    cout<<"NO\n";
    return;

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

    int q = next();
    for (int i = 0; i < q; i ++)
        test();
}

