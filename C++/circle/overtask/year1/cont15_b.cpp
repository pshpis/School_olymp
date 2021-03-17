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

    int n=next(), r=next()-1;
    vector<bool> home(n, false);
    vector<int> heat(n, 0);
    vector<int> pl;
    for (int i=0; i<n; i++){
        int x=next();
        home[i]=(x==1);
        if (home[i]){
            pl.push_back(i);
            for (int j=max(0, i-r); j<=min(n-1, i+r); j++)
                heat[j]++;
        }
    }
    for (int i=0; i<n; i++)
        if (heat[i]==0){
            cout<<-1;
            return 0;
        }
    int ans=pl.size();
    for (int v: pl){
        bool fl=true;
        for (int j=max(0, v-r); j<=min(n-1, v+r); j++)
            if (heat[j]==1) fl=false;
        if (fl){
            ans--;
            for (int j=max(0, v-r); j<=min(n-1, v+r); j++)
                heat[j]--;
        }
    }
    cout<<ans;
}


