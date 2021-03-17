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

#define int int64_t // int -> long long

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

int fast_pow(int a, int k){
    if (k  == 0) return 1;
    if (k == 1) return a;
    if (k % 2 == 0) return pw2(fast_pow(a, k / 2));
    else return pw2(fast_pow(a, k / 2)) * a;
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

    string s;
    cin >> s;
    string pr = "";
    int pow = 1;
    if (s[(int)s.size() - 2] == '^') pow = s[(int)s.size() - 1] - '0';

    if (pow != 1){
        for (int i = 0; i < (int)s.size() - 7; i ++)  pr += s[i];
    }
    else {
        for (int i = 0; i < (int)s.size() - 5; i ++)  pr += s[i];
    }

    set<string> pref_str;

    pref_str.insert("tera");
    pref_str.insert("giga");
    pref_str.insert("mega");
    pref_str.insert("kilo");
    pref_str.insert("deci");
    pref_str.insert("centi");
    pref_str.insert("milli");
    pref_str.insert("micro");
    pref_str.insert("nano");

    map<string, int> pref_num;

    pref_num["tera"] = 12;
    pref_num["giga"] = 9;
    pref_num["mega"] = 6;
    pref_num["kilo"] = 3;
    pref_num["deci"] = -1;
    pref_num["centi"] = -2;
    pref_num["milli"] = -3;
    pref_num["micro"] = -6;
    pref_num["nano"] = -9;

    int ans = 0;

    for (int i = 0; i < pr.size(); i ++){
        string one = "";
        for (int j = 0; j < 4; j ++ ) one += pr[i + j];
        if (pref_str.count(one) > 0){
            ans += pref_num[one];
            i += 3;
            continue;
        }

        one += pr[i + 4];
        if (pref_str.count(one) > 0){
            ans += pref_num[one];
            i += 4;
            continue;
        }
    }

    ans = ans * pow;
    cout << ans << endl;

//    watch(s[(int)s.size() - 2]);
//    cout << pr;
}
/*
meter^2
meterˆ2



*/

