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

lint nod(lint x, lint y)
{
	if (y==0 || x == 0)
		return x + y;
	return nod(y, x%y);
}

int main()
{
    ios::sync_with_stdio(false);
    int n=next();
    vector<int> num;
    for (int i=0; i<n; i++)
        num.pb(next());
    int nd=num[0];
    for (int i=1; i<n; i++)
        nd=nod(nd, num[i]);
    int k=next();
    /*watch(n);
    watch(k);
    watch(num[0]);
    watch(nd);*/
    if (k%nd==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

