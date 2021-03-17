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
const int MOD = 998244353;

typedef vector<int> lnum;

const int base = 1e18;

template<typename type>

type next()
{type x; cin >> x; return x;}

ll next()
{ll x; cin >> x; return x;}

void prod(lnum& a, int b){
    int carry = 0;
    for (size_t i=0; i<a.size() || carry; ++i) {
        if (i == a.size())
            a.push_back (0);
        long long cur = carry + a[i] * 1ll * b;
        a[i] = int (cur % base);
        carry = int (cur / base);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}

void lminus(lnum& a, lnum& b){
    int carry = 0;
    for (size_t i=0; i<b.size() || carry; ++i) {
        a[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = a[i] < 0;
        if (carry)  a[i] += base;
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}

void write(lnum& a){
    printf ("%d", a.empty() ? 0 : a.back());
    for (int i=(int)a.size()-2; i>=0; --i)
	printf ("%09d", a[i]);
}

int del(lnum& a, int b){
    int carry = 0;
    for (int i=(int)a.size()-1; i>=0; --i) {
        long long cur = a[i] + carry * 1ll * base;
        a[i] = int (cur / b);
        carry = int (cur % b);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return carry;
}

lnum read(string s){
    lnum a;
    for (int i=(int)s.length(); i>0; i-=9)
	if (i < 9)
		a.push_back (atoi (s.substr (0, i).c_str()));
	else
		a.push_back (atoi (s.substr (i-9, 9).c_str()));

//    while (a.size() > 1 && a.back() == 0)
//        a.pop_back();

    return a;
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

    int n;
    cin >> n;
    if (n % 2 == 0){
        cout << 0;
        return 0;
    }
//    if (n == 1){
//        cout << 1;
//        return 0;
//    }

    n /= 2;
    vector<lnum> ans(n + 4);
    ans[1] = read("1");
    ans[2] = read("1");
    for (int i = 3; i <= n + 2; i ++){
        lnum x = ans[i - 1];
        prod(x, 6 * i - 9);
        lnum y = ans[i - 2];
        prod(y, i - 3);

        lminus(x, y);

        del(x, i);


        ans[i] = x;
    }

    cout << del(ans[n + 2], MOD);
}
/*




*/

