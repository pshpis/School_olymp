#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
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

string solve1(string s){
    //string s; cin >> s;
    int n = s.length();

    s.back()++;
    for (int i = n - 1; i >= 0; i --){
        if (s[i] > '9' && i > 0){
            s[i - 1]++;
            s[i] = '0';
        }
    }
    if(s[0] > '9'){
        s[0] = '0';
        s = '1' + s;
        n++;
    }

    string ans = s;
    for (int i = 0; i < n; i ++) ans[i] = '9';

    for (int i = 2; i < 10; i ++){
        set<int> c;
        string cur = s;
        for (int j = 0; j < 10; j ++){
            if (j % i == 0) {
                c.insert(j);
            }
        }
        if (c.lower_bound(s[0] - '0') == c.end()) continue;

        for(int i = 0; i < n; i ++){
            if (c.lower_bound(s[i] - '0') == c.end()){
                cur[i] = '0';
                cur[i - 1]++;
                for (int j = i + 1; j < n; j ++) cur[j] = '0';
                for (i = i - 1; i > 0; i --){
                    if (c.lower_bound(cur[i] - '0') == c.end()){
                        cur[i] = '0';
                        cur[i - 1]++;
                    } else {
                        cur[i] = *c.lower_bound(cur[i] - '0') + '0';
                    }
                }

                if (c.lower_bound(cur[0] - '0') == c.end()) break;

                ans = min(ans , cur);
                break;
            }

            if (*c.lower_bound(s[i] - '0') != s[i] - '0'){
                cur[i] = *c.lower_bound(s[i] - '0') + '0';
                for (i = i + 1; i < n; i ++) cur[i] = '0';
            } else {
                cur[i] = s[i];
            }
        }
        ans = min(ans , cur);
    }

    return ans;

}

int solve2(int s){
    s++;
    for (int i = s; ; i ++){
        int g = 0;
        int cur = i;
        while(cur){
            g = __gcd(cur % 10 , g);
            cur /= 10;
        }
        if (g > 1) return i;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    cout << solve1(s);


    /*for (int i = 1; i <= 1000; i ++){
        if (solve1(to(i)) != to(solve2(i))){
            //cout << solve1(to(i))[1] - '0' << '\n';
            cout << i << '\n' << solve1(to(i)) << '\n' << to(solve2(i)) << "\n-----\n";
        }
    }*/

}
/*

*/

