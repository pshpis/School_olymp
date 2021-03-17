#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

void print(vector <string> ans){
    cout << ans.size() << '\n';
    for (auto t : ans){
        cout << t;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int> > t(2, vector<int>(2, 0));
    cin >> t[0][0] >> t[0][1];
    cin >> t[1][0] >> t[1][1];

    vector <string> ans;

    int add =  min(t[0][0] , t[0][1]);
    for (int i = 1; i < add; i ++){
        ans.pb("1 -\n");
        t[0][0]--;
        t[0][1]--;
    }
    add = min(t[1][0] , t[1][1]);
    for (int i = 1; i < add; i ++){
        ans.pb("2 -\n");
        t[1][0]--;
        t[1][1]--;
    }


    if (t[0][0]*t[1][0] == 1){
        for (int i = 1; i < min(t[0][1] , t[1][1]); i ++){
            ans.pb("4 -\n");
        }
        print(ans);
        return 0;
    }

    if (t[0][1]*t[1][1] == 1){
        for (int i = 1; i < min(t[0][0] , t[1][0]); i ++){
            ans.pb("3 -\n");
        }
        print(ans);
        return 0;
    }

    if (t[0][0] != 1 && t[1][1] != 1){
        for (int i = 1; i < t[0][0]; i ++){
            ans.pb("4 +\n");
        }

        for (int i = 1; i < t[0][0]; i ++){
            ans.pb("1 -\n");
        }
        print(ans);
        return 0;
    }


    if (t[0][1] != 1 && t[1][0] != 1){
        for (int i = 1; i < t[0][1]; i ++){
            ans.pb("3 +\n");
        }

        for (int i = 1; i < t[0][1]; i ++){
            ans.pb("1 -\n");
        }
        print(ans);
        return 0;
    }

    print(ans);
}
/*



*/

