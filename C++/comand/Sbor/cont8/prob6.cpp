#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

#define int int64_t

int mypow(int n , int k){
    int res = 1;
    for (int i = 0; i < k; i ++) res *= n;
    return res;
}

int len(int x){
    int cnt = 0;
    while(x > 0){
        x /= 10;
        cnt ++;
    }
    return cnt;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    int n; cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i ++) cin >> num[i];

    vector<map<int, int> > ost_cnt(10);
    for (int i = 0; i < 10; i ++)
        for (int j = 0; j < n; j ++){
            ost_cnt[i][((num[j] % 7) * (mypow(10LL, i + 1)  % 7)) % 7]++;
        }

    int ans = 0;
    for (int i = 0; i < n; i ++){
        int ln = len(num[i]), nd = (7 - num[i] % 7) % 7;
        ans += ost_cnt[ln - 1][nd];
        //cout << num[i] << ' ' << ost_cnt[ln - 1][nd] << '\n';
        if (((num[i] % 7)  * (mypow(10, ln)  % 7)) % 7 == nd) ans --;
    }

    cout << ans;
}
/*
2
1000000000 1000000000


2
4
9

3
127 1996 12


4
11 2 1 12


*/

