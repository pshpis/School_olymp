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
    int k=next();
    map<int, int> iq_student;
    set<int> iq;
    for (int i=0; i<n; i++)
    {
        int x=next();
        iq_student[x]=i;
        iq.insert(x);
    }
    if (iq.size()>=k)
    {
        cout<<"YES\n";
        int j=0;
        for (int el:iq)
        {
            if (j<k) cout<<iq_student[el]+1<<" ";
            j++;
        }
    }
    else cout<<"NO\n";
}

