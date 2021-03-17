#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    long long n;
    cin >> s;
    cin >> n;
    long long a[4];
    for (int i = 0; i < 4 ; ++ i ){
        a[i] = n % 256;
        n /= 256;
    }
    long long v = 0;
    for (int i = 0; i < 4; ++ i){
        v = 256 * v + a[i];
    }
    cout << v << "\n";
}

