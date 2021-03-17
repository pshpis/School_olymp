#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
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

bool cmp (const pii& a, const pii& b){
    if (a.first < b.first) return true;
    if (b.first < a.first) return false;
    if (a.second > b.second) return true;
    return false;
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

    int n = next();
    deque<pii> form;
    map<pii, set<int> > ind_form;
    for (int i = 0; i < n; ++ i){
        int sz = next(), mn = next();
        form.pb(mp(mn, sz));
        ind_form[mp(mn, sz)].insert(i + 1);
    }

    sort(form.begin(), form.end(), cmp);
    reverse(form.begin(), form.end());
//
//    cout << "----------" << endl;
//
//    for (int i = 0; i < n; ++ i){
//        cout << form[i].first << " " << form[i].second << endl;
//    }

    int k = next();
    vector<pii> ans;
    int sum_mn = 0;

    multiset<int> tb;
    multiset<int> :: iterator it;
    map<int, set<int> > ind_tb;

    for (int i = 0; i < k;  ++ i){
        int x = next();
        tb.insert(x);
        ind_tb[x].insert(i + 1);
    }

    while (!tb.empty() && !form.empty()){
        pii f = form.front();
        form.pop_front();

        int mn = f.first;
        int sz = f.second;

        it = tb.lower_bound(sz);
        if (it == tb.end()) continue;

        ans.pb(mp(
                    *ind_form[f].begin(),
                    *ind_tb[*it].begin()
                  )
               );

        ind_form[f].erase(ind_form[f].begin());
        ind_tb[*it].erase(ind_tb[*it].begin());

        tb.erase(it);
        sum_mn += mn;
    }

    cout << ans.size() << " " << sum_mn << endl;
    for (int i = 0; i < ans.size(); ++ i){
        cout << ans[i].first << " " <<  ans[i].second << endl;
    }
}
/*
4
1 1
2 1
2 3
4 3




*/

