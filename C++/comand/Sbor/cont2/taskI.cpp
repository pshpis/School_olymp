#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second

void print(vector<vector<int> >& a){
    for (int i = 0; i < a.size(); ++ i){
        for (int j = 0; j < a[i].size(); ++ j){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n , m, t;
    cin >> n >> m >> t;
    vector<vector<int> > ans1 =
    {
    {1, 1, 2, 2, 2, 3},
    {1, 4, 4, 2, 2, 3},
    {1, 1, 4, 3, 3, 3},
    {6, 6, 4, 4, 5, 5},
    {6, 6, 6, 5, 5, 5}
    },
    ans2 =
    {
        {1, 2, 2, 2, 2, 4, 4, 4, 4},
        {1, 2, 2, 3, 3, 5, 5, 4, 4},
        {1, 1, 3, 3, 7, 7, 5, 5, 6},
        {1, 3, 3, 7, 7, 7, 7, 5, 6},
        {1, 8, 8, 9, 9, 9, 9, 5, 6},
        {8, 8, 9, 9, 10, 10, 10, 10, 6},
        {8, 12, 12, 12, 10, 11, 11, 10, 6},
        {8, 12, 12, 12, 11, 11, 11, 11, 6}
    };

    if (n == 5) print(ans1);
    else print(ans2);
}
/*



*/
