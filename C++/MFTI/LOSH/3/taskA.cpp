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

    bool operator ==(Point2d& b) const
    {
        return (x==b.x && y==b.y);
    }

    Point2d operator -()
    {
        return Point2d(0-x, 0-y);
    }

    void operator +=(Point2d b)
    {
        x+=b.x;
        y+=b.y;
    }

    void operator -=(Point2d b)
    {
        (*this)+=(-b);
    }

    Point2d operator +(Point2d s) const
    {
        return Point2d(x+s.x, y+s.y);
    }

    Point2d operator -(Point2d s) const
    {
        return (*this)+(-s);
    }


    int quater() const
    {
        if (x>0 && y>=0) return 0;
        if (x>=0 && y<0) return 1;
        if (x<0 && y<=0) return 2;
        if (x<=0 && y>0) return 3;
        if (x==0 && y==0) return -1;
    }

    double norm() const
    {
        return x*x+y*y;
    }

    double abs() const
    {
        return sqrt(norm());
    }

    double dist(Point2d& s)
    {
       return (s-(*this)).abs();
    }

    double scal_mult(Point2d& s){
        return x*s.x+y*s.y;
    }

    double vec_mult(Point2d& s){
        return x*s.y-y*s.x;
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

int main()
{
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    Point2d f = next<Point2d>();
    Point2d s = next<Point2d>();
    double cos =f.scal_mult(s)/(f.abs()*s.abs());
    double sin =f.vec_mult(s)/(f.abs()*s.abs());
    cout<<atan2(abs(sin), cos);
}

