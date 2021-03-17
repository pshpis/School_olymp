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

class Point2d
{
public:
   double x;
   double y;
   Point2d()=default;
   Point2d(double x_, double y_)
   {
       x=x_;
       y=y_;
   }
};

ostream& operator<<(ostream& s, const Point2d& f)
{
    s<<f.x<<" "<<f.y;
    return s;
}

istream& operator>>(istream& s, Point2d& f)
{
    f.x=next<double>();
    f.y=next<double>();
    return s;
}

bool square(Point2d f1, Point2d f2, Point2d s1, Point2d s2)
{
    double LeftSide=max(f1.x, s1.x);
    double TopSide=min(f2.y, s2.y);
    double RightSide=min(f2.x, s2.x);
    double BottomSide=max(f1.y, s1.y);
    double Width=RightSide-LeftSide;
    double Height=TopSide-BottomSide;
    if (Width<0 || Height<0) return false;
    else return true;
}

int main()
{
    ios::sync_with_stdio(false);
    Point2d f1=next<Point2d>(), f2=next<Point2d>();
    Point2d s1=next<Point2d>(), s2=next<Point2d>();
    watch(f1);
    watch(f2);
    watch(s1);
    watch(s2);
    if (square(f1, f2, s1, s2) || square(f2, f1, s1, s2) || square(f1, f2, s2, s1) || square(f2, f1, s2, s1))
        cout<<"Yes";
    else cout<<"No";
}
