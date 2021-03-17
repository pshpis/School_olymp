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

vector <lint> fib;
lint s, k;

vector<lint> fib_sm(lint n)
{
    vector<lint> ans;
    if (n==2 || n==1 || n==0)
    {
        ans.pb(n);
        return ans;
    }
    int mx=-1;
    for (int i=0; i<fib.size(); i++)
        if (fib[i]>n)
        {
            mx=fib[i-1];
            break;
        }
    ans=fib_sm(n-mx);
    ans.pb(mx);
}

int main()
{
    s=lnext();
    k=lnext();
    //watch(s); watch(k);
    fib.push_back(1);
    //watch(fib[0]);
    //cout<<"I was here\n";
    //fib.push_back(1);
    bool fl=false;
    if (k>35)// don't be like me, don't use magic constant!)))
        while (fib[fib.size()-1]<=s)
            fib.push_back(fib[fib.size()-1]*2);
    else
        while (fib[fib.size()-1]<=s)
        {
            fl=true;
            //cout<<"I was here\n";
            int lt=0;
            if (k>fib.size()) lt=fib.size();
                else lt=k;
            //watch(lt);
            //watch(fib.size());
            lint sum=0;
            for (int i=fib.size()-lt; i<fib.size(); i++)
                sum+=fib[i];
            //cout<<"I was here\n";
            fib.pb(sum);
        }
    vector<lint> fake;
    for (int i=1; i<fib.size(); i++)
        fake.pb(fib[i]);
    fib=fake;
    //cout<<"I was here\n";
    /*for (int i=0; i<fib.size(); i++)
        cout<<fib[i]<<" ";
    cout<<endl;*/
    vector<lint> ans=fib_sm(s);
    if (ans.size()==1) ans.pb(0);
    cout<<ans.size()<<"\n";
    for (int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}

