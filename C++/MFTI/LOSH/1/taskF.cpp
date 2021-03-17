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
//    watch(a);
//    watch(b);
//    watch(x1);
//    watch(y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}
int main()
{
    ios::sync_with_stdio(false);
    int n=next();
    for (int i=0; i<n; i++){
        lint a, b, c;
        cin>>a>>b>>c;
        lint g = gcd(a, b);
        lint isAnswer = (c%g==0);
        if (!isAnswer){
            cout<<"0 0\n";
            continue;
        }
        bool isSwap=(b>a);
        if (isSwap) swap(a, b);
        lint x=-1, y=-1;
        lint d=line_gcd(a/g, b/g, x, y);
        x*=c;
        y*=c;
//        watch(x);
//        watch(y);

        int x1, y1, a1, b1;
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
//        watch(a1);
//        watch(b1);
//        watch(x1);
//        watch(y1);

        int j=0;
        if (x1>0) j =-(x1/b1);
        else{
            j=abs(x1)/b1;
            if (abs(x1)%b1!=0) j++;
        }
        x1+=j*b1;
        y1-=a1*j;
//        watch(j);
//        watch(x1);
//        watch(y1);

//        if (isSwap){
//            y=x1;
//            x=y1;
//        }
//        else{
//            x=x1;
//            y=y1;
//        }
//        if (!isSwap){
//            lint j=x/b;
//            if (x<0) j++;
//            x%=b;
//            y+=j*a;
//        }
//        else{
//            lint j=abs((y)/a);
//            watch(j);
//            if (y<0) j++;
//            watch(j);
//            y%=a;
//            x+=j*b;
//        }
        cout<<x1<<" "<<y1<<"\n";


//        cout<<"\n\nThis is BEDAG!!!\n\n\n"<<endl;
//        watch(a);
//        watch(b);
//        watch(c);
//        watch(g);
//        watch(isSwap);
//        watch(d);
//        watch(x);
//        watch(y);
    }
}

