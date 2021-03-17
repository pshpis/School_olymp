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

string string_from_num(int a){
    string ans = "";

    bool fl = false;
    if (a < 0) {
        fl = true;
        a = -a;
    }

    while (a > 0){
        ans += a % 10 + '0';
        a /= 10;
    }

//    if (fl) ans += '-';
    reverse(all(ans));

    return ans;
}

int fast_pow(int a, int k){
    if (k  == 0) return 1;
    if (k == 1) return a;
    if (k % 2 == 0) return pw2(fast_pow(a, k / 2));
    else return pw2(fast_pow(a, k / 2)) * a;
}

struct LongNum{
    int big, small, pow10;

    LongNum(int x){
        small = x % pow10;
        big = x / pow10;
        pow10 = fast_pow(10, 12);
    }

    LongNum(){
        pow10 = fast_pow(10, 12);
        big = 0;
        small = 0;
    }

    void prod10(){
        small *= 10;
        big *= 10;
        big += small / pow10;
        small %= pow10;
    }

    void prod10(int k){
        for (int i = 0; i < k; i ++) prod10();
    }

    void write(){
        string small_str = string_from_num(small);
        reverse(all(small_str));
        if (small_str.size() < 11 && big > 0){
            small_str += "0";
        }

        reverse(all(small_str));

        cout << string_from_num(big) << small_str << endl;
    }
};

LongNum long_sum(LongNum a, LongNum b){
    LongNum result;
    result.big = a.big + b.big;
    result.small = a.small + b.small;
    result.big += result.small / result.pow10;
    result.small = result.small % result.pow10;

    return result;
}

LongNum long_minus(LongNum a, LongNum b){
    b.big = -b.big;
    b.small = -b.small;
    return long_sum(a, b);
}

LongNum abs(LongNum a){
    a.big = abs(a.big);
    a.small = abs(a.small);
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

    string s;
    cin >> s;

    int zn = +1;
    int sum = 0;
    vector<pii> a;
    for (int i = 0; i < s.size(); i ++){
        if (s[i] == '+'){
            zn = 1;
            continue;
        }

        if (s[i] == '-'){
            zn = -1;
            continue;
        }

        int j = i;
        int num = 0;
        int len = 0;
        while (s[j] >= '0' && s[j] <= '9' && j < s.size()){
            num *= 10;
            num += s[j] - '0';
            len ++;
            j ++;
        }

        num *= zn;
        sum += num;

        a.pb(mp(num, len));
        i = j - 1;
    }

//    for (int i = 0; i < a.size(); i ++){
//        cout << a[i].first << "  " << string_from_num(a[i].first) << " " << a[i].second << endl;
//    }

    if (a.size() == 1){
        int k = a[0].first;
        string str_k = string_from_num(k);
        if (k >= 0){
            int pos = -1;
            for (int i = 0; i < (int)str_k.size() - 1; i ++){
                if (str_k[i] < str_k[i + 1]){
                    pos = i;
                    break;
                }
            }

            if (pos == -1) pos = str_k.size() - 1;

            string ans = "";
            for (int i = 0; i < str_k.size(); i ++){
                if (i == pos) continue;
                ans += str_k[i];
            }

            cout << ans << endl;
            return 0;
        }
    }

    LongNum max_sum;
    max_sum.small = 0;
    max_sum.big = -1e11;
//    max_sum.write();

    for (int i = 1; i < a.size(); i ++){
        LongNum last_num(a[i - 1].first), new_num(a[i].first);
        LongNum last_res = long_sum(last_num, new_num);


        LongNum new_res = last_num;
        new_res.prod10(a[i].second);
        new_res = long_sum(new_res, abs(new_num));
        LongNum new_sum = long_sum(LongNum(sum), long_minus(new_res, last_res));
//        cout << new_sum << endl;
        if (new_sum.big > max_sum.big || (new_sum.big == max_sum.big && new_sum.small > max_sum.small)) max_sum = new_sum;
    }

    max_sum.write();
}
/*




*/
