#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

ll to(string s){
    ll n = 0;
    for (int i = 0 ; i < s.size(); i ++){
        n = n*10 + (s[i] - '0');
    }
    return n;
}

string to(ll n){
    string ans;
    while(n){
        ans = char(((n % 10) + '0')) + ans;
        n /= 10;
    }
    return ans;
}

bool mycmp(string &a , string &b){
    return (a.size() < b.size() || (a.size() == b.size() && a < b));
}

bool _mycmp(string &a , string &b){
    return (a.size() < b.size() || (a.size() == b.size() && a <= b));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a , b; cin >> a >> b;
    if (mycmp(b , a)) swap(a , b);

    unordered_set <string> st;
    for (int i = 1; i < 10; i ++){
        for (int j = -9; j < 10; j ++){
            if (j == 0) continue;
            string add = "";
            for (int k = i; k < 10 && k >= 0; k += j){
                add += k + '0';
                if (add.size() > 1) st.insert(add);
            }
        }
    }


    ll ans = 0;

    ans = (b.size() - a.size() + 1)*9;
    ans -= a[0] - '0' - 1;
    ans -= 10 - (b[0] - '0') - 1;


    string sameA = "" , sameB = "";
    for (int i = 0; i < a.size(); i ++) sameA += a[0];
    for (int i = 0; i < b.size(); i ++) sameB += b[0];

    ans -= mycmp(sameA , a);
    ans -= mycmp(b , sameB);



    for (auto t : st){
        if (_mycmp(a , t) && _mycmp(t , b)) {
            ans++;
            //cout << t << '\n';
        }
    }


    cout << ans;

}
/*



*/
