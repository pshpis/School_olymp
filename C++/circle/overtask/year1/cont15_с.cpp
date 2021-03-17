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
    map<int, int> pl;
    int n=next();
    int l=0, r=0;
    for (int i=0; i<n; i++){
        char q;
        cin>>q;
        int num;
        cin>>num;
        if (i==0){
            pl[num]=l;
            l--;
            r++;
            continue;
        }
        if (q=='L'){
            pl[num]=l;
            l--;
            continue;
        }
        if  (q=='R'){
            pl[num]=r;
            r++;
            continue;
        }
        cout<<min(pl[num]-l, r-pl[num])-1<<" ";
    }
}

