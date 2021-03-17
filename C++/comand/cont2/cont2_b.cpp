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
    int a[n];
    for (int i=0;i < n;i++) cin >> a[i];
    set<int> s;
    int cnt=0,j=0;
    while (s.count(j)==0){
        cnt++;
        s.insert(j);
        j=a[j]-1;
    }
    cout << cnt <<"\n";
}

