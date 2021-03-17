#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))


int main(){
    int n;
    cin >> n;
    vector < pair <int , int> > a(n) , b(n);
    for (int i = 0; i < n; i ++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin() , a.end());

    int ans = 0;
    for (int i = 0; i < n; i += 2){
        ans += a[i + 1].first - a[i].first;
    }
    cout << ans*n << '\n';
    for (int i = 0; i < n / 2; i ++){
        for (int j = 0; j < n; j ++){
            cout << a[(j + 2*i) % n].second << ' ';
        }
        cout << '\n';
    }
    for(int i = 0; i < n; i += 2){
        swap(a[i] , a[i + 1]);
    }
    for (int i = 0; i < n / 2; i ++){
        for (int j = 0; j < n; j ++){
            cout << a[(j + 2*i) % n].second << ' ';
        }
        cout << '\n';
    }


}
