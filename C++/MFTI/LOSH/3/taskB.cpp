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

class Line2d
{
public:
    double a;
    double b;
    double c;
    //a*x+b*y+c==0
    Line2d(double _a, double _b, double _c)
    {
        a=_a;
        b=_b;
        c=_c;
    }

    Line2d(Point2d f, Point2d s)
    {
        a=s.y-f.y;
        b=f.x-s.x;
        c=-a*s.x-b*s.y;
    }

    Line2d()=default;

    bool belong(Point2d p)
    {
        return a*p.x+b*p.y+c==0;
    }

    int HalfPlane(Point2d p)
    {
        double a1=a, b1=b, c1=c;
        if (a<0)
        {
            a1*=-1;
            b1*=-1;
            c1*=-1;
        }
        else if (a==0)
            if (b<0)
            {
                a1*=-1;
                b1*=-1;
                c1*=-1;
            }
            else if (b==0)
                if (c<0)
                {
                    a1*=-1;
                    b1*=-1;
                    c1*=-1;
                }

        if (a1*p.x+b1*p.y+c1>0) return 1;
        if (a1*p.x+b1*p.y+c1==0) return 0;
        if (a1*p.x+b1*p.y+c1<0) return -1;
    }

    double tg()
    {
        return -a/b;
    }

    bool intersection(Line2d s)
    {
        if (tg()!=s.tg()) return true;
        else return false;
    }

    Point2d intersect(Line2d s)
    {
        if (!intersection(s)) return Point2d(0, 0);
        double b1=b/a, c1=c/a;
        double b2=s.b/s.a, c2=s.c/s.a;
        double y=(c2-c1)/(b1-b2);
        double x=-b1*y-c1;
        return Point2d(x, y);
    }

};

ostream& operator<<(ostream& s, const Line2d& f)
{
    s<<f.a<<"*x+"<<f.b<<"*y+"<<f.c;
    return s;
}

istream& operator>>(istream& s, Line2d& f)
{
    f.a=next<double>();
    f.b=next<double>();
    f.c=next<double>();
    return s;
}

class LineSection2d
{
public:
    Line2d line;
    Point2d st;
    Point2d fsh;

    LineSection2d(Point2d st_, Point2d fsh_)
    {
        st=st_;
        fsh=fsh_;
        line=Line2d(st, fsh);
    }

    LineSection2d()=default;

    bool belong(Point2d s)
    {
        if (!line.belong(s)) return false;
        if (s==st || s==fsh) return true;
        if (((fsh-st).quater()==(s-st).quater()) && (st.dist(fsh)>=st.dist(s))) return true;
        else return false;
    }

    bool intersection(LineSection2d s)
    {
        if (line.intersection(s.line) && belong(line.intersect(s.line)) ) return true;
        else return false;
    }

    Point2d intersect(LineSection2d s)
    {
        if (intersection(s)) return line.intersect(s.line);
        else return Point2d(0, 0);
    }
};

ostream& operator<<(ostream& s, const LineSection2d& f)
{
    s<<f.st<<" "<<f.fsh;
    return s;
}

istream& operator>>(istream& s, LineSection2d& f)
{
    Point2d p;
    cin>>p;
    Point2d q;
    cin>>q;
    f=LineSection2d(p, q);
    return s;
}

double eps =1e-9;

double func(double a, double b, double c, double d){
    return a*d-b*c;
}

bool paral(Line2d n, Line2d m){
    return abs(func(n.a, n.b, m.a, m.b))<eps;
}

bool same(Line2d n, Line2d m){
    return (
    paral(n, m) &&
    abs(func(n.a, n.c, m.a, m.c))<eps &&
    abs(func(n.b, n.c, m.b, m.c))<eps
    );
}

Point2d intersect(Line2d n, Line2d m){
    Point2d ans;
    double down=func(n.a, n.b, m.a, m.b);
    if (abs(down)<eps) return ans;
    ans.x=-func(n.c, n.b, m.c, m.b)/down;
    ans.y=-func(n.a, n.c, m.a, m.c)/down;
    return ans;
}

Point2d middle(Point2d a, Point2d b){
    return Point2d((a.x+b.x)/2, (a.y+b.y)/2);
}

Line2d normal(Line2d line, Point2d a){
    Point2d b(a.x + line.a, a.y+line.b);
    return Line2d(a, b);
}

double dist(Point2d a, Point2d b){
    return sqrt(pow2(a.x-b.x)+pow2(a.y-b.y));
}

int main()
{
    ios::sync_with_stdio(false);
    cout.precision(7);
    cout.setf(ios::fixed);
    Point2d n=next<Point2d>();
    Point2d a=next<Point2d>(), b=next<Point2d>();
    Line2d l(a, b);
    Line2d h=normal(l, n);
    Point2d c=intersect(h, l);
    if (a.y!=b.y){
        if ((c.y>=a.y && c.y<=b.y) || (c.y<=a.y && c.y>=b.y))
        {
            cout<<dist(n, c);
            return 0;
        }
        cout<<min(dist(n, a), dist(n, b));
        return 0;
    }
    if ((c.x>=a.x && c.x<=b.x) || (c.x<=a.x && c.x>=b.x))
    {
        cout<<dist(n, c);
        return 0;
    }
    cout<<min(dist(n, a), dist(n, b));
    return 0;

}

