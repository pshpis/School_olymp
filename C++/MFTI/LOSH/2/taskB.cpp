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

vector<int> z_func(string s){
    int n = s.size();
    vector<int> z(n, 0);
    z[0]=n;
    int l=0, r=0;
    for (int i=1; i<n; i++){
        z[i]=0;
        if (i<=r) z[i]=min(z[i-l], r-i+1);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
        if (i+z[i]-1>r){
            r=i+z[i]-1;
            l=i;
        }
    }
    return z;
}

vector<int> p_func(string s){
    int n=s.size();
    vector<int> p(n, 0);

    int c=0;
    for (int i=1; i<n; i++){
        while(c>0 && s[i]!=s[c])
            c=p[c-1];
        if (s[i]==s[c])
            ++c;
        p[i]=c;
    }
    return p;
}

int main()
{
    ios::sync_with_stdio(false);
    string s = next<string>();
    vector<int> ans=p_func(s);
    for (auto var:ans) cout<<var<<" ";
}


