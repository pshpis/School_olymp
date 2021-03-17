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

int main()
{
    ios::sync_with_stdio(false);
    int n=next();
    set<pair<int, int> > cor, _cor;
    for (int i=0; i<n; i++)
    {
        int x=next();
        int y=next();
        pair<int, int> in(x, y), _in(y, x);
        cor.insert(in);
        _cor.insert(_in);
    }

    int last=-1e9-1;
    lint ans1=0, block=0;
    pair<int, int> mx={1e9+1, 1e9+1};
    cor.insert(mx);
    for (auto x:cor)
    {
        if (last<-1e9)
        {
            last=x.first;
            block=1;
        }
        else
        {
            if (x.first==last)
                block++;
            else
            {
                ans1+=block*(block-1)/2;
                last=x.first;
            }
        }
    }

    int _last=-1e9-1;
    lint ans2=0, _block=0;
    pair<int, int> _mx={1e9+1, 1e9+1};
    _cor.insert(_mx);
    for (auto x:_cor)
    {
        if (_last<-1e9)
        {
            _last=x.first;
            _block=1;
        }
        else
        {
            if (x.first==_last)
                _block++;
            else
            {
                ans2+=_block*(_block-1)/2;
                _last=x.first;
            }
        }
    }

    cout<<ans1+ans2-1;
}

