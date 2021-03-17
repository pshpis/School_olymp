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
#define fr(i,n) for (int i=0; i<int(n); i++)

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
    int n=next();
    vector<int> park;
    for (int i=0; i<n; i++) park.push_back(next());
    vector<int> ans;
    for (int i=1; i<n-1; i++)
    {
        if ((park[i]<park[i-1] && park[i]<park[i+1]) || (park[i]>park[i+1] && park[i]>park[i-1]))
            ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for (int i=0; i<ans.size(); i++)
        cout<<ans[i]+1<<" ";
}
