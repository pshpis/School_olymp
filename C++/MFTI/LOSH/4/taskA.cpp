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
    lint n=lnext(), k=lnext()+1;
    lint fact=1;

    vector<lint> fib(n+1,0) , ans;
    fib[0]=1;
    fib[1]=2;
    for (int i=2; i<=n; i++)
        fib[i]=fib[i-1]+fib[i-2];
//    bool isAnswer=(k<=fib[n]);
//    if (!isAnswer){
//        cout<<-1;
//        return 0;
//    }

    for (int i=1; i<=n;){
        if (k<=fib[n-i]) {
            ans.push_back(0);
            i++;
        }
        else {
            k-=fib[n-i];
            ans.push_back(1);
            ans.push_back(0);
            i+=2;
        }
    }
    for (int i=0; i<n; i++){
        cout<<ans[i];
    }
    return 0;
}

