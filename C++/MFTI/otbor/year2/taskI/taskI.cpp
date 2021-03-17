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
#define th third

#define int int64_t

#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[]="in.txt";
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

class triple
{
public:
    triple(int f, int s, int t){
        first = f;
        second = s;
        third = t;
    }

    int first, second, third;
};

bool operator > (triple a, triple b){
    if (a.first > b.first) return true;
    if (a.first == b.first){
        if (a.second > b.second) return true;
        if (a.second == b.second){
            if (a.third > b.third) return true;
        }
    }
    return false;
}

bool operator == (triple a, triple b){
    if (a.first == b.first && a.second == b.second && a.third == b.third) return true;
    return false;
}

bool operator < (triple a, triple b){
    if (!(a == b || a > b)) return true;
    return false;
}

triple operator - (triple a){
    return triple(-a.first,  -a.second, -a.third);
}

triple operator + (triple a, triple b){
    return triple(a.first + b.first, a.second + b.second, a.third + b.third);
}

triple operator - (triple a, triple b){
    return a + (-b);
}

triple operator * (triple a, int k){
    return triple(a.first * k, a.second * k, a.third * k);
}

triple operator * (int k, triple a){
    return triple(a.first * k, a.second * k, a.third * k);
}

triple read_time(){
    int f, s, t;
    char fake;
    cin >> f >> fake >> s >> fake >> t;
    return triple(f - 1, s, t);
}

int sec(triple a){
    return a.first * 3600 + a.second * 60 + a.third;
}

string make_2(int x){
    string ans = "";
    if (x >= 10){
        ans += x / 10 + '0';
        ans += x % 10 + '0';
        return ans;
    }
    ans += '0';
    ans += x + '0';
    return ans;
}

triple dist(triple a, triple b){
    if (a == b) return triple(0, 0, 0);
    if (b > a) return b - a;
    b.first += 12;
    return b - a;
}

void print_time(triple a){
    cout << a.first + 1 << ':' << make_2(a.second) << ':' << make_2(a.third) << endl;
}

void sp_print_time(ostream& s, triple a){
    s << a.first << ':' << a.second << ':' << a.third;
}

ostream& operator<<(ostream& s, const triple& x)
{
    sp_print_time(s, x);
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
    vector<triple> time;
    set<triple> st_time;
    map<triple, int> cnt;

    for (int i = 0; i < n; ++ i){
        triple x = read_time();
        time.pb(x);
        st_time.insert(x);
        cnt[x]++;
    }

    sort(time.begin(), time.end());
    triple last = time[n-1];
    triple d(0, 0, 0);

    for (auto t: st_time){
        d = d + (last - t)*cnt[t];
    }

    auto time_ = time;
    set<triple> st_time_ = st_time;
    map<triple, int> cnt_ = cnt;

    auto f = *st_time_.begin();
    st_time_.erase(f);

    int k = cnt_[f];
    cnt_[f] = 0;

    f.first += 12;
    cnt[f] = k;
    st_time_.insert(f);


    triple last_ = time_[n-1];
    triple d_(0, 0, 0);

    for (auto t: st_time_){
        d_ = d_ + (last_ - t)*cnt_[t];
    }
//
//    cout << endl << "-------------" << endl;
//    watch(d);
//    watch(d_);
//    watch(sec(d));
//    watch(sec(d_));
//    cout << endl << "-------------" << endl;

    int mn_t = sec(d);
    int it = n - 1;

    if (mn_t > sec(d_)){
        mn_t = sec(d_);
        it = 0;
    }

    int t0 = sec(d_);
    bool fl = false;
//    cout << endl << "-------------" << endl;
//    watch(mn_t);
//    watch(it);
//    cout << endl << "-------------" << endl;
    for (int i = 0; i < n - 1; ++ i){
//        if (i == n - 2 || i == n - 3) fl = true;
        triple next = time[i + 1], now = time[i];
        triple d = dist(next, now);
        triple d_ = dist(now, next);

        int t = sec(d);
        int t_ = sec(d_) * (n - 1);

        if (fl){
            watch(now);
            watch(next);
            watch(d);
            watch(d_);
            watch(t);
            watch(t_);
            watch(t0);
        }

        t0 = t0 + t_ - t;

        if (fl) watch(t0);

        if (mn_t > t0){
            mn_t = t0;
            it = i + 1;
        }

        if (fl) cout << endl << "-------------" << endl;
    }
    print_time(time[it]);
}
/*
3
11:30:00
12:10:01
6:10:18

4
12:00:00
1:00:00
2:00:00
5:00:00

4
12:00:00
1:00:00
2:00:00
4:59:59

12
1:00:01
2:00:00
3:00:00
4:00:00
5:00:00
6:00:00
7:00:00
8:00:00
9:00:00
10:00:00
11:00:00
12:00:01

2
1:00:00
10:12:12

5

*/
