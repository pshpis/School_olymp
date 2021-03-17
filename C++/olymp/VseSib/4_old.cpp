#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mp make_pair
#define pw2(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()

#define fi first
#define se second
#define th third

#define ins insert
#define pb push_back
#define eb emplace_back

#define fr(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define wrvec(a) for (int i = 0; i < (a).size(); i ++) cout << (a)[i] << " "; cout << endl;
#define revfr(i, n) for(int (i) = int(n) - 1; (i) >= 0; i --)

//#define int int64_t // int -> long long

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[] = "input.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "output.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int> > vii;
typedef set<int> si;
typedef set<pii> sii;

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

template<typename type>

type next()
{type x; cin >> x; return x;}

ll next()
{ll x; cin >> x; return x;}

const int p = 7;
int n;

unordered_set<ll> h;

vector<ll> p_pow;

int get_id(char c){
    if (c == 'x') return 1;
    if (c == '(') return 2;
    if (c == ')') return 3;
    if (c == '+') return 4;
    if (c == '-') return 5;
    return -1;
}

ll get_hash(string s){
    ll hsh = 0;
    for (int i = 0; i < s.size(); i ++){
        hsh += get_id(s[i]) * p_pow[i];
    }

    return hsh;
}

ll hash_with_sk (ll x, int sz){
    x *= p;
    x += get_id('(');
    x += get_id(')') * p_pow[sz - 1];
    return x;
}

ll hash_with_plus_after(ll x, ll sz){
    x += p_pow[sz - 2] * get_id('+');
    x += p_pow[sz - 1] * get_id('x');
    return x;
}

ll hash_with_plus_before(ll x, ll sz){
    x *= p_pow[2];
    x += get_id('x');
    x += get_id('+') * p;
    return x;
}

ll hash_with_minus_after(ll x, ll sz){
    x += p_pow[sz - 2] * get_id('-');
    x += p_pow[sz - 1] * get_id('x');
    return x;
}

ll hash_with_minus_before(ll x, ll sz){
    x *= p_pow[2];
    x += get_id('x');
    x += get_id('-') * p;
    return x;
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

    cin >> n;
    if (n % 2 == 0){
        cout << 0;
        return 0;
    }

    p_pow.resize(n + 2);

    p_pow[0] = 1;

    for (int i = 1; i <= n; i ++){
        p_pow[i] = p_pow[i - 1] * p;
    }

//    cout << get_hash("x") << endl;
//
//    return 0;

    unordered_set<ll> new_h;
    for (int i = 1; i <= n; i += 2){
        if (i == 1){
            h.insert(get_hash("x"));
            cout << i << " " << h.size() << endl;
            continue;
        }
        for (ll x: h){
            new_h.insert(hash_with_sk(x, i));
            new_h.insert(hash_with_minus_after(x, i));
            new_h.insert(hash_with_minus_before(x, i));
            new_h.insert(hash_with_plus_after(x, i));
            new_h.insert(hash_with_plus_before(x, i));
        }
        cout << i << " " << new_h.size() << endl;
        h = new_h;
        new_h.clear();
    }

    cout << h.size();

}
/*




*/
