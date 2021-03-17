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

string get2_10(int x){
    string ans = "";
    while (x > 0){
        ans += '0' + x % 2;
        x /= 2;
    }
    while(ans.size() < 8) ans += '0';
    reverse(ans.begin(), ans.end());
    return ans;
}

int get10_16(const string& x){
    int ans = 0;
    for (int i = 0 ; i < x.size(); i ++){
        ans *= 16;
        if (x[i] <= '9') ans += x[i] - '0';
        else ans += x[i] - 'A' + 10;
    }
    return ans;
}

int get10_2(const string& x){
    int ans = 0;
    for (int i = 0; i < x.size(); i ++){
        ans *= 2;
        ans += x[i] - '0';
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i ++){
        string x;
        cin >> x;
        s +=  get2_10(get10_16(x));
    }
    string symb = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    string x = "";
    int cnt = 0;
    string ans = "";
    for (int i = 0; i < s.size(); i ++){
        cnt ++;
        if (cnt == 7){
            cnt = 1;
            int k = get10_2(x);
            ans += symb[k];
//            watch(x);
//            watch(k);
            x = "";
        }
        x += s[i];
    }
    while (x.size() < 6) x += "0";
    int k = get10_2(x);
    ans += symb[k];
    while(ans.size() % 4 != 0) ans += "=";
//    watch(x);
//    watch(k);
    cout << ans;
}
/*



*/

