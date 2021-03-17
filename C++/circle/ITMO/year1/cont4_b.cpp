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
#define fr(i,n) for (int i=0; i<int(n); i++)

typedef long long lint;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    ios::sync_with_stdio(false);
    freopen("divisible.in", "r", stdin);
	freopen("divisible.out", "w", stdout);
    string s;
    getline(cin, s);
    vector<int> num(10, 0);
    lint sum=0;
    int n=s.size();
    for (int i=0; i<n; i++)
    {
        num[s[i]-'0']++;
        sum+=s[i]-'0';
    }
    if (sum%3!=0)
    {
        bool fl=false;
        for (int i=sum%3; i<10; i+=3)
            if (num[i]>0)
            {
                num[i]--;
                fl=true;
                break;
            }
        if (!fl)
        {
            int k=0;
            for (int i=3-sum%3; i<10; i+=3)
            {
                while (num[i]>0 && k<2)
                {
                    num[i]--;
                    k++;
                }
                if (k>=2) break;
            }
        }
    }
    for (int i=9; i>=0; i--)
    {
        for (int j=0; j<num[i]; j++)
            cout<<i;
    }


}

//9841984111
