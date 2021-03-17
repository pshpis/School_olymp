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

lint nod(lint x, lint y)
{
	if (y==0 || x == 0)
		return x + y;
	return nod(y, x%y);
}

lint nok(lint x, lint y)
{
    lint ans=x*y/nod(x, y);
    return ans;
}

int main()
{
    int sum=next(), a=0, b=0;
    if (sum%2==0) a=sum/2-1, b=sum/2+1;
    else a=sum/2, b=sum/2+1;
    //watch(a);
    //watch(b);
    while (true)
    {
        if (nod(a,b)==1)
        {
            cout<<a<<" "<<b;
            return 0;
        }
        a--;
        b++;
    }

}

