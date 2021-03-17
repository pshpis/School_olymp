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

class Point2d{
public:
    int x;
    int y;
    Point2d(int _x=0, int _y=0){
        x=_x;
        y=_y;
    }
};

ostream& operator<<(ostream& s, const Point2d& f)
{
    s<<f.x<<" "<<f.y;
    return s;
}

istream& operator>>(istream& s, Point2d& f)
{
    f.x=next();
    f.y=next();
    return s;
}

int triangle_square(Point2d a, Point2d b, Point2d c){
    return (b.x-a.x)*(c.y-a.y)+(c.x-a.x)*(a.y-b.y);
}

bool int_intersect(int a, int b, int c, int d){
    if (b>a) swap(a, b);
    if (d>c) swap(c, d);
    return min(a, c) >= max(b, d);
}

bool intersect(Point2d a, Point2d b, Point2d c, Point2d d){
    return(
    int_intersect(a.x, b.x, c.x, d.x) &&
    triangle_square(a, b, c)*triangle_square(a, b, d)<=0 &&
    int_intersect(a.y, b.y, c.y, d.y) &&
    triangle_square(c, d, a)*triangle_square(c, d, b)<=0
    );
}
int main()
{
    ios::sync_with_stdio(false);
    Point2d a=next<Point2d>();
    Point2d b=next<Point2d>();
    Point2d c=next<Point2d>();
    Point2d d=next<Point2d>();
    if (intersect(a, b, c, d)) cout<<"YES";
    else cout<<"NO";
}

