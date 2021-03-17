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

const lint mod=1e9+7;

/*void rek(int n, int k)
{
    if (n==1)
    {
        if (k!=1)
        {
            ans++;
            ans%=mod;
        }
        return;
    }
    if (n==2)
    {
        if (k!=2)
        {
            ans++;
            ans%=mod;
        }
        return;
    }
    if (n==3)
    {
        if (k!=0)
        {
            ans+=2;
            ans%=mod;
        }
        else
        {
            ans+=3;
            ans%=mod;
        }
        return;
    }
    if (n==0)
    {
        ans++;
        ans%=mod;
        return;
    }
    if (n<0) return;
    for (int i=1; i<=3; i++)
        if (i!=k) rek(n-i, i);
}*/

map<pair<lint, lint>, lint> memory;

lint rek(lint n, lint k)
{
    if (memory[{n, k}]!=-1) return memory[{n, k}];
    lint ans=0;
    for (int i=1; i<=3; i++)
        if (i!=k)
        {
            if (memory[{n-i, i}]==-1) ans+=rek(n-i, i);
            else ans+=memory[{n-i, i}];
            ans%=mod;
        }
    memory[{n, k}]=ans;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    lint n=next();
    for (int i=0; i<=n; i++)
        for (int j=0; j<=3; j++)
            memory[{i, j}]=-1;
    for (int i=0; i<=3; i++)
        memory[{0, i}]=0;
    for (int i=0; i<=3; i++)
    {
        if (i!=1) memory[{1, i}]=1;
        else memory[{1, i}]=0;
    }
    for (int i=0; i<=3; i++)
    {
        if (i!=2) memory[{2, i}]=1;
        else memory[{2, i}]=0;
    }
    for (int i=0; i<=3; i++)
    {
        if (i!=0) memory[{3, i}]=2;
        else memory[{3,i}]=3;
    }
    cout<<rek(n, 0)<<endl;
}

