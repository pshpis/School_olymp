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
    if (n==2)
    {
        cout<<1<<endl;
        cout<<1<<" "<<1;
        return 0;
    }
    if (n%4==0)
    {
        cout<<0<<endl;
        cout<<n/2<<" ";
        for (int i=1; i<=n/4; i++)
        {
            cout<<i<<" "<<n-i+1<<" ";
        }
    }
    if (n%4==3)
    {
        cout<<0<<endl;
        lint sum=0;
        for (int i=1; i<=n; i++)
            sum+=i;
        sum/=2;
        vector<int> ans;
        for (int i=n; i>=1; i--)
        {
            if (sum<=i)
            {
                ans.pb(sum);
                sum-=sum;
                break;
            }
            else sum-=i, ans.pb(i);
        }
        cout<<ans.size()<<" ";
        for (int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
    }
    if (n%4==1 || n%4==2)
    {
        cout<<1<<endl;
        lint sum=0;
        for (int i=1; i<=n; i++)
            sum+=i;
        sum/=2;
        vector<int> ans;
        for (int i=n; i>=1; i--)
        {
            if (sum<=i)
            {
                ans.pb(sum);
                sum-=sum;
                break;
            }
            else sum-=i, ans.pb(i);
        }
        cout<<ans.size()<<" ";
        for (int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
    }
}

