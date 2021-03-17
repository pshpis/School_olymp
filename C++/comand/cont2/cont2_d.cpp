#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

int bit(int n){
    int ans=0;
    while (n>0){
        n/=2;
        ans++;
    }
    return ans;
}
int main(){
    int n, b;
    cin>>n>>b;
//    cout<<bit(n)<<" "<<bit(b);
    vector<int> a;
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        a.pb(bit(x));
        //a.pb(bit(next()));
    }
    sort(a.begin(), a.end());
    int ans=0;
    for (int i=0; i<n; i++){
        ans=a[i]*(i+1);
        if (ans>b){
            cout<<i;
            return 0;
        }
    }
    cout<<n;
}

