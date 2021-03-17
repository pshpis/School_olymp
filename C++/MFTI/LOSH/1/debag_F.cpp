#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for (int (i)=0; i<int(n); i++)

typedef long long lint;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

lint gcd(lint x, lint y)
{
	if (y==0 || x == 0)
		return x + y;
	return gcd(y, x%y);
}

lint lcm(lint x, lint y)
{
    lint ans=x*y/gcd(x, y);
    return ans;
}

lint line_gcd(lint a, lint b, lint& x, lint& y)
{
    if (b==0){
        x=1;
        y=0;
        return a;
    }
    lint x1=-1, y1=-1;
    lint d = line_gcd(b, a%b, x1, y1);

    x=y1;
    y=x1-(a/b)*y1;
    return d;
}

pair<lint, lint> deofant(lint a, lint b, lint c)
{
    lint g = gcd(a, b);
    lint isAnswer = (c%g==0);
    if (!isAnswer){
        pair<lint, lint> ans={0, 0};
        return ans;
    }
    bool isSwap=(b>a);
    if (isSwap) swap(a, b);
    lint x=-1, y=-1;
    lint d=line_gcd(a/g, b/g, x, y);
    x*=c;
    y*=c;

    lint x1, y1, a1, b1;
    if (isSwap){
        a1=b/g;
        b1=a/g;
        y1=x/g;
        x1=y/g;
    }
    else{
        a1=a/g;
        b1=b/g;
        y1=y/g;
        x1=x/g;
    }

    lint j=0;
    if (x1>0) j =-(x1/b1);
    else{
        j=abs(x1)/b1;
        if (abs(x1)%b1!=0) j++;
    }
    x1+=j*b1;
    y1-=a1*j;
    pair<lint, lint> ans={x1, y1};
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    lint n=next();
    for (int i=0; i<n; i++){
        lint a=lnext(), b=lnext(), c=lnext();
        auto ans=deofant(a, b, c);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
//    lint cnt=0;
//    while (cnt<1000){
//        lint a=((lint)(((lint)((lint)rand()<<16))|((lint)rand())))%(lint)1e8;
//        lint b=((lint)(((lint)((lint)rand()<<16))|((lint)rand())))%(lint)1e8;
//        lint d=gcd(a, b);
//        lint c=((lint)(((lint)((lint)rand()<<16))|((lint)rand())))%(lint)(1e8/d);
//        c*=d;
//        auto ans=deofant(a, b, c);
//        lint x=ans.first, y=ans.second;
//        if (a*x+b*y!=c) {
//            cout<<"Error"<<endl;
//            watch(a);
//            watch(b);
//            watch(c);
//            watch(x);
//            watch(y);
//        }
//        cnt++;
//    }

}

