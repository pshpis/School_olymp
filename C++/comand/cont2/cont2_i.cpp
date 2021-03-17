#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

int main(){
    int n , m , d;
    cin >> n >> m >> d;
    string p , t;
    cin >> p >> t;
    vector < vector <bool> > dp(m , vector <bool> (n , false));
    int ans = 0;
    for (int i = 0; i < n; i ++){
        if (p[i] == t[0]){
            dp[0][i] = true;
            ans = 1;
        }
    }

    for (int i = 1; i < m; i ++){
        for (int j = 0; j < n; j ++){
            if (p[j] != t[i]) continue;
            for (int k = 0; k < n; k++){
                if (abs(k - j) > d) continue;
                dp[i][j] = (dp[i][j] | dp[i - 1][k]);
                if (dp[i][j]) ans = i + 1;
            }
        }
    }
    cout << ans;

}
