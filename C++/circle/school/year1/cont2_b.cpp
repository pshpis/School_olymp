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

void swap2(vector<int>& a, int i,int j)
{
    int x=a[i];
    a[i]=a[j];
    a[j]=x;
}
int main()
{
    ios::sync_with_stdio(false);
    int n=next();
    vector<int> a;
    /*for (int i=0; i<n; i++)
        a.pb(next());
    for (int i=0; i<n-1; i++)
        for (int j=i; j<n-1; j++)
            if (a[j]>a[j+1]) swap2(a, j, j+1);
     for (int i=0; i<n; i++)
        cout<<a[i]<<" ";
    //cout<<"-1"<<"\n";*/
    if (n>2)
        for (int i=n; i>0; i--)
            cout<<i<<" ";
    else cout<<"-1";
}

