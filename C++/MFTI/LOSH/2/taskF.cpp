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

void make_p(lint n){
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

vector<lint> pref_hash(vector<int>& s){
    lint n=s.size();
    vector<lint> h(n+1, 0);
    for (int i=1; i<=n; i++)
        h[i]=((h[i-1]*p)%mod+(lint)s[i-1])%mod;
    return h;
}

lint substr_hash(lint l, lint r, vector<lint>& h){
    return (h[r+1]-((lint)h[l]*pow_p[r-l+1])%mod+mod)%mod;
}

void transp_matrix(vector<vector<int>>& t, vector<vector<int>>& result)
{
    result.clear();
    result=vector<vector<int>>(t[0].size(), vector<int>(t.size(), 0));
    for (int i=0; i<t[0].size(); i++)
        for (int j=0; j<t.size(); j++)
            result[i][j]=t[j][i];
}

vector<int> find_pal(vector<int>& s){
    int n=s.size();
    vector<int> m(n, 0);
    int l=0, r=0;
    for (int i=0; i<n; i++){
        if (i<=r) m[i]=min(r-i+1, m[l+r-i]);
        while (i-m[i]>=0 && i+m[i]<n && s[i-m[i]]==s[i+m[i]])
            m[i]++;
        if (i+m[i]-1>r){
            r=i+m[i]-1;
            l=i-m[i]+1;
        }
    }
    for (int i=0; i<n; i++) m[i]--;
    return m;
}

int main()
{
    ios::sync_with_stdio(false);
    lint n=lnext(), m=lnext();//string and column
    make_p(max(n, m)+1);
    vector<vector<int>> table(n, vector<int>(m,0));
    for (int i=0; i<n; i++)
        for (int j=0;j<m; j++)
            table[i][j]=next();

    vector<vector<int>> transp;
    transp_matrix(table, transp);

    vector<vector<lint>> table_hash;
    for (int i=0; i<n; i++)
        table_hash.push_back(pref_hash(table[i]));
    vector<vector<lint>> transp_hash;
    for (int i=0; i<m; i++)
        transp_hash.push_back(pref_hash(transp[i]));

    vector<vector<int>> table_pal;
    for (int i=0; i<n; i++)
        table_pal.push_back(find_pal(table[i]));
    vector<vector<int>> transp_pal;
    for (int i=0; i<m; i++)
        transp_pal.push_back(find_pal(transp[i]));

    lint max_len=-1;
    pair<int, int> ans_cell{0, 0};
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int len=min(table_pal[i][j], transp_pal[j][i]);
            if (len<=max_len) continue;
            lint hor_hash =substr_hash(j-len, j+len, table_hash[i]);
            lint vert_hash =substr_hash(i-len, i+len, transp_hash[j]);
            if (hor_hash==vert_hash) ans_cell.first=i+1, ans_cell.second=j+1, max_len=len;
        }
    }
    cout<<max_len<<endl;
    cout<<ans_cell.first<<" "<<ans_cell.second;
}

