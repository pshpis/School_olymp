#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for (int (i)=0; i<int(n); i++)

const bool isDbg=false;

typedef long long lint;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    int n=next();
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
        {
            if (i%2==0){
                if (j%2==0) cout<<"B";
                else cout<<"W";
            }
            else{
                if (j%2==0) cout<<"W";
                else cout<<"B";
            }
        }
        cout<<endl;
    }
}

