#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define _USE_MATH_DEFINES

typedef long long lint;
typedef double angle;

const double PI=3.1415926535897932384626433832795;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

class vec2d
{
public:
    vec2d()=default;
    vec2d(double _x, double _y)
    {
        x=_x;
        y=_y;
    }

    void operator =(vec2d b)
    {
        x=b.x;
        y=b.y;
    }

    bool operator ==(vec2d b)
    {
        return (x==b.x && y==b.y);
    }

    double dist(vec2d q)
    {
        return sqrt(pw2(x-q.x)+pw2(y-q.y));
    }

    double x;
    double y;
};

typedef vec2d point;
const vec2d zero(0, 0);

point operator -(point p)
{
    point result(-p.x, -p.y);
    return result;
}

class line
{
public:
    line(double _a, double _b, double _c)
    {
        a=_a;
        b=_b;
        c=_c;
    }

    line(point f, point s)
    {
        a=s.x-f.x;
        b=f.y-s.y;
        c=f.x*s.y-f.y*s.x;
    }

    line(point p, double w)
    {
        a=1;
        b=-tan(w);
        c=p.x*tan(w)-p.y;
    }

    belong(point p)
    {
        return (a*p.y+b*p.x+c==0);
    }

    string WhatHalfPlane(point p)
    {
        if (a*p.y+b*p.x+c>0) return "up";
        if (a*p.y+b*p.x+c<0) return "down";
        return "on";
    }

    double angle()
    {
        return atan(-b/a);
    }

    pair<point, point> PointsOnDistance(point p, double dist)
    {
        pair<point, point> result={p, p};
        double _x=( cos( angle() ) )*dist;
        double _y=( sin( angle() ) )*dist;
        (result.first).x-=_x;
        (result.first).y-=_y;
        (result.second).x+=_x;
        (result.second).y+=_y;
        return result;
    }

    double a;
    double b;
    double c;
};
class polygon
{
public:
    polygon(vec2d _A, double a, int _n, double _w=0)
    {
        A=_A;
        side=a;
        w=_w;
        n=_n;
        if (a<=0 || _n<3 )
        {
            side=0;
            n=0;
            w=0;
        }
    }

    void shift_x(double a)
    {
        A.x+=a;
    }

    void shift_y(double a)
    {
        A.y+=a;
    }

    void shift(vec2d a)
    {
        shift_x(a.x);
        shift_y(a.y);
    }

    double area()
    {
        return n*pw2(side)/(4*tan(PI/n));
    }

    double per()
    {
        return 4*side;
    }

    void turn(double v)
    {
        w+=v;
    }

    void homothety(point q, double k)
    {
        shift(-q);
        A.x*=k;
        A.y*=k;
        shift(q);
        side*=k;
    }

    bool belong(point q)
    {
        /*
        Здесь я хочу перебрать все ребра
        с помощью функции PointsOnDistance
        И с помощью функции WhatHalfPlain
        Понять в какой полуплоскости находится наша точка
        Если мы для каждого ребра поймем, что наша точка
        находится в нужной полуплоскости,
        то значит наша точка лежит внутри,
        если нет снаружи
        */
        if (n==0) return A==q;
        point CurrentPoint=A;
        double CurrentAngle=w;
        double BetweenAngle=(n-2)*PI/n;
        for (int i=0; i<n; i++)
        {
            CurrentAngle+=BetweenAngle;
            line direction(CurrentPoint, CurrentAngle);
            pair<point,point> NeedPoints=direction.PointsOnDistance(CurrentPoint, side);
            if (i<n/2)
            {
                CurrentPoint=NeedPoints.second;
                string s=direction.WhatHalfPlane(q);
                if (s=="up") return false;
            }
            else
            {
                CurrentPoint=NeedPoints.first;
                string s=direction.WhatHalfPlane(q);
                if (s=="down") return false;
            }
        }
        return true;
    }

    bool IsOnBorder(point q)
    {
        if (n==0) return A==q;
        point CurrentPoint=A;
        double CurrentAngle=w;
        double BetweenAngle=(n-2)*PI/n;
        for (int i=0; i<n; i++)
        {
            CurrentAngle+=BetweenAngle;
            line direction(CurrentPoint, CurrentAngle);
            pair<point,point> NeedPoints=direction.PointsOnDistance(CurrentPoint, side);
            if (i<n/2)
            {
                CurrentPoint=NeedPoints.second;
                string s=direction.WhatHalfPlane(q);
                if (s=="on") return true;
            }
            else
            {
                CurrentPoint=NeedPoints.first;
                string s=direction.WhatHalfPlane(q);
                if (s=="on") return true;
            }
        }
        return false;
    }

    int n;
    vec2d A;
    double side;
    double w;
};

int main()
{
    ios::sync_with_stdio(false);
    polygon x(point (0, 0), 3, 4);
    if (x.belong(point(1, 1))) cout<<"YES\n";
    else cout<<"NO\n";
}
