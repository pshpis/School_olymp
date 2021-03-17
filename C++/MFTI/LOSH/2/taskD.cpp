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

vector<int> z_func(vector<int> s){
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

const lint mod =1e9+7;
const lint p=267;
vector<lint> pow_p;

void make_p(lint& n){
    pow_p.push_back(1);
    for (int i=1; i<n; i++)
        pow_p.push_back((pow_p[i-1]*p)%mod);
}

lint myhash(vector<lint>& s){
    lint ans=0;
    int n=s.size();
    for (int i=0; i<n; i++){
        ans+=(s[i]*pow_p[n-i-1])%mod;
        ans%=mod;
    }
}

vector<lint> pref_hash(vector<lint>& s){
    lint n=s.size();
    vector<lint> h(n+1, 0);
    for (int i=1; i<=n; i++)
        h[i]=((h[i-1]*p)%mod+s[i-1])%mod;
    return h;
}

lint substr_hash(lint l, lint r, vector<lint>& h){
    return (h[r+1]-(h[l]*pow_p[r-l+1])%mod+mod)%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    lint n=lnext(), m=lnext();
    vector<lint> s;
    make_p(n);
    for(int i=0; i<n; i++)
        s.push_back(next());
//    watch("1");
    vector<lint> rev = s;
    reverse(rev.begin(), rev.end());
//    watch("1");
    vector<lint> h_s =pref_hash(s);
//    watch("1");
    vector<lint> h_rev =pref_hash(rev);
//    watch("1");
    set<lint> ans;
    for (int i=0; i<n/2; i++){
//        watch("here");
        lint hash_begin=substr_hash(n-1-i,n-1, h_rev);
        lint hash_end=substr_hash(i+1,2*i+1,h_s);
        if (hash_begin==hash_end) ans.insert(n-i-1);
    }
    ans.insert(n);
    for (var: ans) cout<<var<<" ";
}

