#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define int int64_t

int32_t main(){
    int n;
    cin>>n;
    n++;
    if (n==2){
        cout<<1<<endl<<1;
        return 0;
    }
    if (n==3){
        cout<<1<<endl<<"1 1";
        return 0;
    }
    vector<bool> prime(n+100, true);
    prime[0]=false;
    prime[1]=false;
    for (int i=0; i<=n+100; i++){
        if (prime[i]){
            for (int j=i*i; j<=n+100; j+=i){
                prime[j]=false;
            }
        }
    }
    cout<<"2\n";
    for (int i=2; i<=n; i++){
        if (prime[i]) cout<<1<<" ";
        else cout<<2<<" ";
    }
}
/*
    vector<bool> prime(n+1, true);
    prime[0]=false;
    prime[1]=false;
    for (int i=0; i<=n; i++){
        if (prime[i]){
            for (int j=i*i; j<=n; j+=i){
                prime[j]=false;
            }
        }
    }
    long long pr=1;
    for (int i=0; i<=n; i++){
        if (prime[i]){
            cout<<i<<endl;
            pr*=i;

        }
    }
    cout<<pr;
*/
