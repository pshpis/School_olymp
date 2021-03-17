#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, p;
    cin >> n >> p;
    int k = (n * p) / 100;

    cout << "[";
    for (int i = 0; i < n; i ++){
        if (i < k) cout << "*";
        else cout << ".";
    }
    cout << "]";
}
