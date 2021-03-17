#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

int to(string s){
    int n = 0;
    for (int i = 0 ; i < s.size(); i ++){
        n = n*10 + (s[i] - '0');
    }
    return n;
}

string to(int n){
    string ans;
    while(n){
        ans = char(((n % 10) + '0')) + ans;
        n /= 10;
    }
    return ans;
}

set<string> s;

void solve(int num , string &cur , int sum){
    if (cur.size() > 18) return;

    if (sum == num){
        s.insert(cur);
    }

    for (int i = 0; i < 10; i ++){
        if (sum + i > num || (sum == 0 && i == 0)) continue;
        cur += (i + '0');
        solve(num , cur , sum + i);
        cur.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    for (int i = 2; i <= 3; i ++){
        int sq = sqrt(i);
        bool simple = true;
        for (int j = 2; j <= sq; j ++){
            if (i % j == 0){
                simple = false;
            }
        }
        if (!simple) continue;
        string cur = "";
        solve(i , cur , 0);
    }

    vector <string> a;
    for (auto t : s){
        a.pb(t);
    }

    int t; cin >> t;
    while(t --> 0){
        string l , r;
        cin >> l >> r;

        int ans = (upper_bound(a.begin() , a.end() , r) - a.begin()) - (lower_bound(a.begin() , a.end() , l) - a.begin() + 1);
        cout << ans << '\n';
    }

}
/*



*/
