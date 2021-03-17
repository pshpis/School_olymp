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

    int q=next();
    for (int i=0; i<q; i++){
        int n=next();
        vector<int> h;
        int pl=0;
        for (int i=0; i<n; i++){
            int x=next();
            if (x==1) pl=i;
            h.push_back(x);
        }
        bool fl=true;
        int j=pl;
        bool ans1=true;
        while (fl){
            int next;
            if (j==n-1) next=0;
            else next=j+1;
            if (next==pl){
                fl=false;
                continue;
            }
            if (h[next]!=h[j]+1) ans1=false;
            j=next;
        }
//        cout<<"First cycle end"<<endl;
        fl=true;
        j=pl;
        bool ans2=true;
        while(fl){
            int pr;
            if (j==0) pr=n-1;
            else pr=j-1;
            if (pr==pl){
                fl=false;
                continue;
            }
            if (h[pr]!=h[j]+1) ans2=false;
            j=pr;
        }
        if (ans1 || ans2) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

