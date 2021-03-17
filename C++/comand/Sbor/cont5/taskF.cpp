#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

//#define int int64_t

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    int n; cin >> n;
    vector <int> cnt(10 , 0);
    cnt[0]++;
    vector <unordered_set<int> > cur(n);
    for (int j = 0; j < n; j ++){
        string s; cin >> s;
        for (int i = 0; i < 6; i ++){
            cur[j].insert(s[i] - '0');
        }
        for (auto t : cur[j]){
            cnt[t]++;
        }
    }

    int mn = n + 2 , j = 9;
    for (int i = 1; i < 10; i ++){
        if (cnt[i] < mn){
            mn = cnt[i] , j = i;
        }
    }

    if (mn == 0){
        cout << j;
        return 0;
    }


    cnt[0]--;


    string ans2 = "1" , ans3 = "a";
    for (int i = 0; i < cnt[0] + 1; i ++){
        ans2 += '0';
    }

    vector<int> cnt2 = cnt;

     for (int i = 0; i < n; i ++){
        if (cur[i].count(0)){
            //cout << i << '\n';
            for (auto t : cur[i]){
                //cout << t << ' ';
                cnt2[t]--;
            }
        }
    }

    for (int i = 1; i < 10; i ++){
        if (cnt2[i] == 0){
            ans3 += char(i + '0');
            break;
        }
    }

    for (int i = 0; i < cnt[0]; i ++){
        ans3 += '0';
    }


    for (int i = 0; i < n; i ++){
        if (cur[i].count(j)){
            //cout << i << '\n';
            for (auto t : cur[i]){
                //cout << t << ' ';
                cnt[t]--;
            }
        }
    }

    int add = j;

    for (int i = 0; i < 10; i ++){
        if (cnt[i] == 0){
            add = i;
            break;
        }
    }


    string ans = "";

    if (add < j){
        if (add == 0){
            ans += '0' + j;
            ans += '0' + add;
            for (int i = 0; i < mn - 1; i ++) ans += '0' + j;
        } else {
            ans += '0' + add;
            for (int i = 0; i < mn; i ++) ans += '0' + j;
        }
    } else {
        for (int i = 0; i < mn; i ++) ans += '0' + j;
        ans += '0' + add;
    }

    if (ans.size() > ans2.size() || (ans > ans2 && ans.size() == ans2.size())){
        ans = ans2;
    }

    if (ans3 != "a" && (ans.size() > ans3.size() || (ans > ans3 && ans.size() == ans3.size()))){
        ans = ans3;
    }

    cout << ans;


}
/*

2
012345
098765

3
123456
789012
345678

6
000000
000000
000000
000000
000000
000000


6
123456
789012
456789
012345
678901


5
111111
222222
333333
444444
555555


*/

