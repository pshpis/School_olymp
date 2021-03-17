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

vector<int> num;

bool next_comb(vector<int>& comb, int n)// true if it is not the last combination
{
    int k=comb.size();
    for (int i=k-1; i>=0; i--)
    {
        if (comb[i]<n-k+i+1)//n-k+i+1 == max for a[i]
        {
            comb[i]++;
            for (int j=i+1; j<k; j++)
                comb[j]=comb[j-1]+1;//update a[j] later then a[i]
            return true;//because we find where is not max element
        }
    }
    return false;//because in all position max element
}

lint mult_comb(vector<int>& comb, int mod)
{
    lint mult=1;
    for (int i=0; i<comb.size(); i++)
    {
        mult*=num[comb[i]-1];
        mult%=mod;
    }
    return mult;
}
int main()
{
    ios::sync_with_stdio(false);
    int n=next(), mod=next();
    for (int i=0; i<n; i++)
        num.pb(next());
    lint max_mult=-1e9-7;
    for (int k=1; k<=n; k++)
    {
        vector<int> comb;
        for (int j=1; j<=k; j++)
            comb.pb(j);
        max_mult=max(max_mult, mult_comb(comb, mod));
        while (next_comb(comb, n))
            max_mult=max(max_mult, mult_comb(comb, mod));
    }
    cout<<max_mult;

}

