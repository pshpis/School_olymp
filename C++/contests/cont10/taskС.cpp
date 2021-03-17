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
//#define fi first
//#define se second
//#define th third
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

class triple
{
public:

    triple() = default;
    triple(int fi, int se, int th): first(fi) , second(se) , third(th){}

    int first;
    int second;
    int third;
};

istream& operator>>(istream& s, triple& x)
{
    s >> x.first >> x.second >> x.third;
    return s;
}

ostream& operator<<(ostream& s, triple& x)
{
    s << x.first << " " << x.second << " " << x.third;
    return s;
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
    vector<vector<int> > triple_id(n);
    unordered_set<int> edge;
    vector<triple> tr;
    for (int i = 0; i < n - 2; ++ i){
        int x = next() - 1, y = next() - 1, z = next() - 1;
//        watch(x);
//        watch(y);
//        watch(z);
        triple t;
        t.first = x;
        t.second = y;
        t.third = z;
//        watch(t);
        tr.pb(t);
//        watch(t);
//        watch(tr[i]);

        triple_id[x].pb(i);
        triple_id[y].pb(i);
        triple_id[z].pb(i);

        if (triple_id[x].size() == 1) edge.insert(x);
        if (triple_id[y].size() == 1) edge.insert(y);
        if (triple_id[z].size() == 1) edge.insert(z);

        if (triple_id[x].size() == 2) edge.erase(x);
        if (triple_id[y].size() == 2) edge.erase(y);
        if (triple_id[z].size() == 2) edge.erase(z);
    }

    if (tr.size() == 1){
        auto t = tr[0];
        cout << t.first + 1 << " " << t.second + 1 << " " << t.third + 1 << "\n";
        return 0;
    }

//    cout <<" HERE \n --- " << endl;
    vector<int> q(n, -100);
    unordered_set<int> :: iterator it = edge.begin();
    q[0] = *it;
//    watch(q[0]);
    it ++;
    q[n - 1] = *it;

    if (q[0] == tr[triple_id[q[0]][0]].third){
        q[1] = tr[triple_id[q[0]][0]].first;
        q[2] = tr[triple_id[q[0]][0]].second;
//        watch(1);
    }
    else
    if (q[0] == tr[triple_id[q[0]][0]].second){
        q[1] = tr[triple_id[q[0]][0]].first;
        q[2] = tr[triple_id[q[0]][0]].third;
//        watch(2);
    }
    else
    if (q[0] == tr[triple_id[q[0]][0]].first){
        q[1] = tr[triple_id[q[0]][0]].third;
        q[2] = tr[triple_id[q[0]][0]].second;
        watch(3);
        watch(triple_id[q[0]][0]);
        watch(tr[triple_id[q[0]][0]]);

    }

    watch(q[0]);
    watch(q[1]);
    watch(q[2]);

    cout <<" HERE \n --- " << endl;
    for (int i = 3; i < n - 1; i ++){
        watch(i);
        for (int j =  0; j < triple_id[i - 1].size(); j ++){
            watch(j);
            auto t = tr[triple_id[q[i - 1]][j]];
            unordered_set<int> t_;
            int sm = 0;
            t_.insert(t.first); sm += t.first;
            t_.insert(t.second); sm += t.second;
            t_.insert(t.third); sm += t.third;

            if (t_.count(q[i - 2]) > 0) q[i] = sm - q[i - 1] - q[i - 2];
        }
    }

    for (int i = 0; i < n; ++ i){
        cout << q[i] + 1<< " ";
    }
    cout << endl;
}
/*
5
4 3 2
2 3 5
4 1 2

6
1 2 3
2 3 4
3 4 5
4 5 6


*/

