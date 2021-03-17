#include <bits/stdc++.h>

using namespace std;

#define int int64_t // int -> long long


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

    int t = next();
    fr(h, t){
        int n = next();
        vi a(n);
        fr(i, n) cin >> a[i];

        bool fl = true;
        int res = 0;

        for (int i = 1; i <= 26; i ++){
            for (int j = i + 1; j <= 26; j ++){
                vi b;
                for (int k = 0; k < n; k ++){
                    if (a[k] == i) b.push_back(1);
                    if (a[k] == j) b.push_back(2);
                }

                vi c;
                int cnt = 0, now = 0, sum = 0;
                for (int k = 0; k < (int)b.size(); k ++){
                    if (k == 0){
                        cnt ++;
                        if (b.size() == 1){
                            c.push_back(cnt);
                            sum = cnt;
                            cnt = 0;
                        }
                        now = b[k];
                        continue;
                    }

                    if (b[k] != b[k - 1]){
                        c.push_back(cnt);
                        sum += cnt;
                        now = b[k];
                        cnt = 0;
                    }

                    cnt ++;
                }
                if (cnt != 0){
                    sum += cnt;
                    c.push_back(cnt);
                }
//
//                if (i == 1 && j == 2){
//                    wrvec(c);
//                }


                int ans = 0;

                int mx = -1;
                for (int k = 0; k < c.size(); k ++){
                    mx = max(c[k], mx);
                }
                ans = mx;

                for (int k = 1; k < (int)c.size() - 1; k ++){
                    ans = max(ans, 2 * min(c[k - 1], c[k + 1]) + c[k]);
                }

                int sum_1 = 0, sum_2 = 0;
                vi pref_sum1(c.size() + 1, 0), pref_sum2(c.size() + 1, 0);
                for (int i = 0; i < c.size(); i ++){
                    if (i % 2 == 0){
                        sum_1 += c[i];
                        pref_sum1[i + 1] = sum_1;
                        pref_sum2[i + 1] = pref_sum2[i];
                    }
                    else {
                        sum_2 += c[i];
                        pref_sum1[i + 1] = pref_sum1[i];
                        pref_sum2[i + 1] = sum_2;
                    }
                }


                for (int i = 0; i < c.size(); i ++){
                    if (i % 2 == 0){

                        int left = pref_sum2[i];
                        int right = sum_2 - left;
//                        if (i == 2){
//                            watch(left);
//                            watch(right);
//                        }
                        ans = max(ans, c[i] + 2 * min((int)left, (int)right) );
                    }
                    if (i % 2 == 1){
                        int left = pref_sum1[i];
                        int right = sum_1 - left;
                        ans = max(ans, c[i] + 2 * min(left, right) );
                    }

//                    if (ans == 8){
//                            watch(i);
//                        break;
//                    }
                }




//                if (i == 1 && j == 2) watch(ans);


                res = max(res, ans);
//                if (res > 7 && fl){
//                    cout << i << " " << j << endl;
//                    fl = false;
//                }
            }
        }

        cout << res << "\n";
    }
}
/*
1
6
1 2 1 1 1 1



*/

