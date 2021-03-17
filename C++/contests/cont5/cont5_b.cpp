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
    vector<int> num;
    map<int, vector<int>> pl;
    for (int i=0; i<n; i++){
        int x=next();
        num.push_back(x);
        pl[x].push_back(i);
    }
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());
    vector<int> q;
    int ans=0;
    for (int i=0; i<n; i++)
    {
        ans+=num[i]*i+1;
        q.push_back(pl[num[i]].back());
        pl[num[i]].pop_back();
    }
    cout<<ans<<"\n";
    for (int i=0; i<n; i++){
        cout<<q[i]+1<<" ";
    }
}

