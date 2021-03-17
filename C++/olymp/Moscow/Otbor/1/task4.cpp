#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++ i)
#define fi first
#define se second
#define ins insert

//#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

template<typename type>

type next()
{type x; cin >> x; return x;}

int next()
{int x; cin >> x; return x;}

ll lnext()
{ll x; cin >> x; return x;}

vector<pii> d;
map<pii, vector<pii> > step;

void make_d(){
    for (int i = -2; i <= 2; i ++){
        if (i == 0) continue;
        for (int j = -2; j <= 2; j ++){
            if (j == 0) continue;
            if (abs(i) == abs(j)) continue;
            d.eb(i, j);
        }
    }
}

void sq_5(){
//    map<pii, int> step;
    vector<pii> point;
    vector
    <pii> new_point;
    point.eb(0, 0);
    for (int i = 0; i < 4; i ++){
        for (pii p: point){
            for (pii v: d){
                pii p_ = p;
                p_.fi += v.fi;
                p_.se += v.se;
                if (abs(p_.fi) < 3 && abs(p_.se) < 3){
                    step[p_] = step[p];
                    step[p_].pb(p);
                    new_point.pb(p_);
                }
            }
        }
        point = new_point;
        new_point.clear();
    }

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

    make_d();

    sq_5();

    pii x;
    cin >> x.fi;
    cin >> x.se;

//    watch(x.fi);
//    watch(x.se);

    pii st = {0 , 0};
//    watch(st.fi);
//    watch(st.se);
    bool fl = false;
    if (st.fi < x.fi) fl = true;
//    int cnt = 0;
    while ( abs(st.fi - x.fi) > 2){
        if (st.fi < x.fi){
            cout << st.fi + 2 << " " << st.se - 1 << "\n";
            cout << st.fi + 4 << " " << st.se << "\n";
            st.fi += 4;
        }
        else{
            cout << st.fi - 2 << " " << st.se - 1 << "\n";
            cout << st.fi - 4 << " " << st.se << "\n";
            st.fi -= 4;
        }
//        cout << "YES" << endl;
//        cnt ++;
    }

    while (abs(st.se - x.se) > 2){
        if (st.se < x.se){
            cout << st.fi - 1 << " " << st.se + 2 << "\n";
            cout << st.fi  << " " << st.se + 4 << "\n";
            st.se += 4;
        }
        else{
            cout << st.fi - 1 << " " << st.se - 2 << "\n";
            cout << st.fi << " " << st.se - 4<< "\n";
            st.se -= 4;
        }
    }

    vector<pii> ans = step[{x.fi - st.fi, x.se - st.se}];
    for (int i = 1; i < ans.size(); i ++){
        cout << ans[i].fi + st.fi << " " << ans[i].se + st.se << "\n";
    }

    cout << x.fi << " " << x.se << "\n";
}
/*




*/

