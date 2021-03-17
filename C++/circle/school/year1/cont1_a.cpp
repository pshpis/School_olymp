#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

#define watch(x) cout << (#x) << " is " << (x) << endl

typedef long long lint;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    int n=next();
    string s;
    cin>>s;
    vector<int> ans;
    int d=0;
    bool fl=false;
    int j=0;
    for (int i=0; i<n; i++)
        if (s[i]=='B')
        {
            d++;
            fl=true;
            j=0;
        }
        else
        {
            j++;
            if (fl && j<2) ans.push_back(d);
            d=0;
        }
    if (d>0) ans.push_back(d);
    cout<<ans.size()<<"\n";
    for (int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}
