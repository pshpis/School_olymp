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

int n;
string num;
vector<int> f;
string ans;

void inv(int st, int fin)
{
    for (int i=st; i<fin; i++)
        ans[i]=f[num[i]-'0'-1]+'0';
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>num;
    for (int i=0; i<9; i++)
        f.push_back(next());
    //watch(num);
    ans=num;
    int st=-1, en=n;
    for (int i=0; i<n; i++)
        if (f[num[i]-'1']>(num[i]-'0'))
        {
            st=i;
            //cout<<"YES"<<endl;
            break;
        }
    //watch(st);
    if (st==-1)
    {
        //cout<<"HERE"<<endl;
        cout<<ans;
        return 0;
    }
    for (int i=st; i<n; i++)
        if (f[num[i]-'1']<num[i]-'0')
        {
            en=i;
            break;
        }
    inv(st, en);
    cout<<ans;


}

