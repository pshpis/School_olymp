#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second

bool is_sort(const vector<int>& a){
    bool fl = true;
    for (int i = 0; i < a.size() - 1; ++ i){
        if (a[i] > a[i + 1]){
            fl = false;
            break;
        }
    }
    return fl;
}

bool cmp(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0] || (a[0] == b[0] && a.back() < b.back());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int> >  block(n);

    bool fl = false;
    for (int i = 0; i < n; ++ i){
        int m;
        cin >> m;
        for (int j = 0; j < m; ++ j){
            int x;
            cin >> x;
            block[i].pb(x);
        }
//        if (! is_sort(block[i]) && !fl ){
//            cout << "NO";
//            fl = true;
//        }
    }
    //if (fl) return 0;

    sort(block.begin(), block.end(), cmp);

    vector<int> q;
    for (int i = 0; i < n; ++ i){
        for (int j = 0;  j < block[i].size(); ++ j){
            q.pb(block[i][j]);
        }
    }

//    for (int i = 0; i < q.size(); ++ i){
//        cout << q[i] << " ";
//    }
//    cout << endl;
//
//    cout << "END" << endl;
    if (is_sort(q)) cout << "YES";
    else cout << "NO";


}
/*
3
2 1 2
3 7 7 7
1 5

2
2 1 3
1 2


*/

