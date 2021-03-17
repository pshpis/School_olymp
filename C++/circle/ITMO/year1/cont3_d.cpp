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
    vector<int> a;
    lint av=0;
    for (int i=0; i<n; i++)
    {
        int x=next();
        av+=x;
        a.pb(x);
    }
    lint cnt1=0;
    av/=n;
    vector<int> b=a;
    for (int i=0; i<n-1; i++)
    {
        if (a[i]<av)
        {
            a[i+1]-=av-a[i];
            cnt1+=av-a[i];
            a[i]+=av-a[i];
        }
        if (a[i]>av)
        {
            a[i+1]+=a[i]-av;
            cnt1+=a[i]-av;
            a[i]-=a[i]-av;
        }
    }
    lint cnt2=0;
    for (int i=n; i>0; i--)
    {
        if (a[i]<av)
        {
            if (a[i-1]<av-a[i])
            {
                int del=(av-a[i])-a[i-1];
                a[i-1]=0;

            }
            a[i-1]-=av-a[i];
            cnt2+=av-a[i];
            a[i]+=av-a[i];
        }
        if (a[i]>av)
        {
            a[i-1]+=a[i]-av;
            cnt2+=a[i]-av;
            a[i]-=a[i]-av;
        }

    }
    cout<<min(cnt1, cnt2);
}

