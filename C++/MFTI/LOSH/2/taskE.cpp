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
    string s=next<string>();
    lint sz=s.size();
    string fake;
    for (int i=0; i<s.size(); i++){
        fake+="#";
        fake+=s[i];
    }
    fake+="#";
    s=fake;
    //watch(s);
    lint n=s.size();
    vector<lint> m(n, 0);
    lint l=0, r=0;
    for (int i=0; i<n; i++){
        if (i<=r) m[i]=min(r-i+1, m[l+r-i]);
        while (i-m[i]>=0 && i+m[i]<n && s[i-m[i]]==s[i+m[i]])
            m[i]++;
        if (i+m[i]-1>r){
            r=i+m[i]-1;
            l=i-m[i]+1;
        }
    }
    lint ans=0;
    for (int i=0; i<n; i++)
        ans+=(lint)m[i]/2;
    cout<<ans-sz;
}

