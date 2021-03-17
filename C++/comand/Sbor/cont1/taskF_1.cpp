#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second

bool check(int mask , int i){
    return ((mask >> i) & 1);
}

vector <int> ans[2];

void solve(int n , vector <string> in , int id){

    vector < vector <int> > dp(n , vector <int> ((1 << 3) , 0));

    for (int i = 0; i < n; i ++){
        for (int k = 0; k < (1 << 3); k ++){
            bool flag = false;
            for (int j = 0; j < 3; j ++){
                if ((check(k , j) && check(k , j + 1)) || (in[i][j] == '*' && check(i , j))) flag = true;
            }
            if (flag) continue;
            dp[i][k] = __builtin_popcount(k);
        }
    }


    for (int i = 1; i < n; i ++){
        for (int j = 0; j < (1 << 3); j ++){
            bool flag = false;
            for (int k = 0; k < 3; k ++){
                if ((check(j , k) && check(j , k + 1)) || (in[i][k] == '*' && check(j , k))) continue;
            }
            if (flag) continue;
            int add = __builtin_popcount(j);
            dp[i][j] = add;
            if (i - 2 >= 0) dp[i][j] = max(dp[i][j] , *max_element(dp[i - 2].begin() , dp[i - 2].end()) + add);
            if (i - 1 >= 0){
                if (j == 0) dp[i][j] = max(dp[i][j] , *max_element(dp[i - 1].begin() , dp[i - 1].end()) + add);
                if (j == 1) dp[i][j] = max(dp[i][j] , dp[i - 1][4] + add);
                if (j == 4) dp[i][j] = max(dp[i][j] , dp[i - 1][1] + add);
            }
        }
    }

    for (int i = n; i >= 0; i --){
        int cur = *max_element(dp[i].begin() , dp[i].end());
        for (int j = 0; j < (1 << 3); j ++){
            if (dp[i][j] == cur){
                ans[id][i] = j;
                break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n , k; cin >> n >> k;
    vector <string> in(n);
    ans[0] = ans[1] = vector <int> (n , 0);
    for (int i = 0; i < n; i ++) cin >> in[i];
    vector<string> a[2];
    a[0] = a[1] = vector <string> (n);
    for (int i = 0; i < n; i ++){
        a[0][i] = in[i].substr(0 , 3);
        a[1][i] = in[i].substr(6 , 3);
    }


    solve(n , a[0] , 0); solve(n , a[1] , 1);

    return 0;

    vector <string> ans;
    vector <char> t = {'A' , 'B' , 'C'};

    for (int id = 0; id < 2; id ++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 3; j ++){
                if (check(ans[id][i] , j)){
                    string add = "";
                    add += i + 1 + '0';
                    add += t[j] + id*3;
                }
            }
        }
    }
    if (ans.size() < k){
        cout << "PORAZHENIE";
    } else {
        cout << "POBEDA\n";
        for (int i = 0; i < k; i ++) cout << ans[i] << '\n';
    }

}
/*

2 2
.**|_|**.
**.|_|***

*/
