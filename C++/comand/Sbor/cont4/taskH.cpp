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

vector <int> a;
int get_sum(int l , int r){
    int ans = a[r];
    if (l > 0) ans -= a[l - 1];
    return ans;
}

bool check(int i){
    return (i > 0) && (i <= 20);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    int n; cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        if (i > 0) a[i] += a[i - 1];
    }

    vector < vector < vector <bool> > > can(23 , vector < vector <bool> > (n , vector <bool> (n , false)));
    vector <int> dp(n , -1);

    for (int st = 1; st <= 20; st ++){
        for (int i = 0; i < n ; i ++){
            can[st][i][i] = check(st + get_sum(i , i));

            for (int j = i + 1; j < n; j ++){
                if (can[st][i][j - 1] && check(get_sum(i , j) + st)) can[st][i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; i ++){
        if (!check(get_sum(0 , i) + 10)) continue;

        if (can[10][0][i]){
            dp[i] = get_sum(0 , i) + 10;
            continue;
        }
        if (can[10][1][i]){
            dp[i] = get_sum(0 , i) + 10;
            continue;
        }
        for (int j = 1; j < i; j ++){
            if (!check(dp[j - 1]) || !check(get_sum(0 , j - 1) + 10)) continue;
            if (can[get_sum(0 , j - 1) + 10][j + 1][i]){
                dp[i] = get_sum(0 , i) + 10;
                break;
            }
        }
    }

    if (!check(dp[n - 1])) cout << "NO";
    else cout << "YES";

}
/*

4
-9 9 9 1

6
-9 9 9 1 1 -1

5
-9 9 9 1 1


*/
