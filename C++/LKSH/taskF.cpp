#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iterator>

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
    set<int> num;
    set<int> :: iterator it;
    int n=next();
    map<int, int> num_pl;//num to place in set
    for (int i=0; i<n; i++)
    {
        int x=next();
        num.insert(x);
    }
    num.insert(1e9+7);
    int j_=0;
    for (it=num.begin(); it!=num.end(); it++)
    {
        num_pl[*it]=j_;
        j_++;
    }

    int j=0;
    int mx_length=-1e9-7;
    for (it=num.begin(); it!=num.end(); it++)
    {
        int left=*it;
        int right=left+n;//Halfsegment
        int right_num=*num.lower_bound(right);//after segment
        int length=num_pl[right_num]-j;
        mx_length=max(mx_length, length);

        j++;
    }

    cout<<n-mx_length;
}

