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
    int h1, d1, t1;
    int h2, d2, t2;
    int d3, t3;
    cin>>h1>>d1>>t1;
    cin>>h2>>d2>>t2;
    cin>>d3>>t3;
    for (int t=0;;t++){
        if (t%t1==0){
            h2-=d1;
            if (h2<=0){
                cout<<"WIN";
                return 0;
            }
        }
        if (t%t2==0){
            h1-=d2;
            if (h1<=0){
                cout<<"FAIL";
                return 0;
            }
        }
        if (t%t3==0){
            h1+=d3;
        }
    }

}

