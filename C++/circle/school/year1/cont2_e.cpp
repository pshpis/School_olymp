#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

typedef long long lint;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    ios::sync_with_stdio(false);
    vector<int> mask(1001, 0);
    int n=next();
    for (int i=0; i<n; i++)
    {
        int x=next();
        mask[x]++;
    }
    vector<int> pref;
    int sum=0;
    for (int i=0; i<1001; i++)
    {
        sum+=mask[i];
        pref.pb(sum);
        //watch(sum);
    }
    int t=next();
    int mx=-1;
    for (int i=1; i<1001; i++)
    {
        int left=i, right=min(1000, i+t);
        mx=max(mx, pref[right]-pref[left-1]);
    }
    cout<<mx;
}

