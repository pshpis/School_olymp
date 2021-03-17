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
    vector<int> tort;
    for (int i=0; i<n; i++)
        tort.pb(next());
    int j=n-1, i=0;
    vector<int> first, second;
    while(j>=0)
    {
        if (j==n-1)
        {
            first.pb(tort[j]);
            second.pb(0);
            j--;
            i++;
            continue;
        }
        first.pb(max(tort[j]+second[i-1], first[i-1]));
        second.pb(min(tort[j]+second[i-1], first[i-1]));
        j--;
        i++;
    }
    cout<<second[n-1]<<" "<<first[n-1];
}

