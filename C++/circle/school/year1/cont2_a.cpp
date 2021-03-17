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
    int n=next();
    string town;
    getline(cin, town);
    for (int i=0; i<n+1; i++)
    {
        string x;
        getline(cin, x);
    }
    //multiset<pair<string, string> > q;
    if (n%2==0)
        cout<<"home";
    else cout<<"contest";
}
