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

class integer_set
{
public:
    integer_set()
    {
        mask=vector<bool>(n, false);
        sz=0;
    }

    void restrict(int k)
    {
        for (int i=n; i>k; i--)
            mask.pop_back();
    }
    void increase(int k)
    {
        for (int i=n+1; i<=k; i++)
            mask.push_back(false);
        mask[i]=
    }
    integer_set(const vector<int>& b)
    {
        sz=0;
        mask=vector<bool>(n, false);
        for (int i=0; i<b.size(); i++)
        {

        }
    }

    integer_set(const vector<bool>& m)
    {
        sz=0;
        mask=m;
        for (int i=0; i<n; i++)
            if (mask[i]) sz++;
    }

    bool add(int x)
    {
        bool ans=!mask[x];
        mask[x]=true;
        if (ans) sz++;
        return ans;
    }

    bool remove(int x)
    {
        bool ans=mask[x];
        mask[x]=false;
        if (ans) sz--;
        return ans;
    }

    bool has(int x) const
    {
        return mask[x];
    }

    bool empty() const
    {
        return sz<=0;
    }

    bool operator[](int x)
    {
        return mask[x];
    }

    integer_set unite(integer_set b)
    {
        for (int i=0; i<n; i++)
            if (mask[i]) b.add(i);
        return b;
    }

    integer_set intersec(integer_set b)
    {
        for (int i=0; i<n; i++)
            if (!mask[i]) b.remove(i);
        return b;
    }

    void output()
    {
        for (int i=0; i<n; i++)
            if (mask[i]) cout<<i<<" ";
        cout<<"\n";
    }

    const int n=0;
private:
    int sz;
    vector<bool> mask;
};

int main()
{
    ios::sync_with_stdio(false);
    integer_set a, b;
    int n=next(), m=next();
    for (int i=0; i<n; i++)
    {
        int x=next();
        a.add(x);
    }
    for (int i=0; i<m; i++)
    {
        int x=next();
        b.add(x);
    }

    (a.unite(b)).output();
}
