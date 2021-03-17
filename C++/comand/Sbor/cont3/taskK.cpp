#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

int sum_num(int x){
    int sum = 0;
    while(x > 0){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
//    cout << sum_num(x);
    for (int y = x; y < x + 1000; y ++){
        if (x == y - sum_num(y)){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}
/*



*/

