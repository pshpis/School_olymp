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
    int n=next(), k=next();
    string s;
    cin>>s;
    //watch(s);
    if (k==2)
    {
        string pr, pr_;
        for (int i=0; i<n; i++)
            if (i%2==0) pr+="A", pr_+="B";
            else pr+="B", pr_+="A";
        int ans=0, ans_=0;
        for (int i=0; i<n; i++)
        {
            if (s[i]==pr[i]) ans++;
            else ans_++;
        }
        if (ans<ans_)
        {
            cout<<ans<<"\n";
            cout<<pr_;
        }
        else
        {
            cout<<ans_<<"\n";
            cout<<pr;
        }
        return 0;
    }
    int block=0;
    char last='A'-1;
    int ans=0;
    for (int i=0; i<n; i++)
    {
        if (s[i]==last) block++;
        else
        {
            if (i!=0 && block!=0)
            {
                int left=i-block-1;
                char el='A';
                if (last=='A') el='B';
                if (block%2==0)
                {
                    for (int j=left; j<i; j++)
                        if ((j-left)%2==1) s[j]=el, ans++;
                }
                else
                {
                    el='A';
                    if (el==last || el==s[i]) el++;
                    if (el==last || el==s[i]) el++;
                    for (int j=left; j<i; j++)
                        if ((j-left)%2==1) s[j]=el, ans++;
                }
            }
            block=0;
        }
        last=s[i];
    }
    //watch(block);
    if (block>0)
    {
        int j=0;
        char el='A';
        if (s[n-1]==el) el++;
        for (int i=n-block-1; i<n; i++)
        {
            j++;
            if (j%2==0) s[i]=el, ans++;
        }
    }
    cout<<ans<<"\n";
    cout<<s;

}
