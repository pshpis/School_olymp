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
const double EPS=1e-7;

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
        return (abs(x-b.x)<EPS && abs(y-b.y)<EPS);
    }

    vec2d operator-(vec2d b)
    {
        return vec2d(x-b.x, y-b.y);
    }

    vec2d operator -()
    {
        vec2d result(-x, -y);
        return result;
    }

    vec2d operator+(vec2d b)
    {
        return vec2d(x+b.x, y+b.y);
    }

    bool operator !=(vec2d b)
    {
        return !(*this==b);
    }

    double dist(vec2d q)
    {
        return sqrt(pw2(x-q.x)+pw2(y-q.y));
    }

    double norm()
    {
        return x*x+y*y;
    }
    double x;
    double y;
};

typedef vec2d point;
const vec2d zero(0, 0);



ostream& operator<<(ostream& s, const point& x)
{
    s<<x.x<<" "<<x.y;
    return s;
}

istream& operator>>(istream& s, point& x)
{
    cin>>x.x;
    cin>>x.y;
    return s;
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

    line()=default;

    line(point f, point s)
    {
        a=s.x-f.x;
        b=f.y-s.y;
        c=f.x*s.y-f.y+s.x;
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

    int WhatHalfPlane(point p)
    {
        if (a*p.y+b*p.x+c>0) return 1;
        if (a*p.y+b*p.x+c<0) return 0;
        return -1;
    }

    double angle()
    {
        return atan(-b/a);
    }

    pair<point, point> PointsOnDistance(point p, double dist)
    {
        pair<point, point> result={p, p};
        if (abs(a-EPS)==0)
        {
            (result.first).x+=dist;
            (result.second).x-=dist;
            return result;
        }
        if (abs(b-EPS)==0)
        {
            (result.first).y+=dist;
            (result.second).y-=dist;
            return result;
        }

        double _x=( cos( angle() ) )*dist;
        double _y=( sin( angle() ) )*dist;
        (result.first).x-=_x;
        (result.first).y-=_y;
        (result.second).x+=_x;
        (result.second).y+=_y;
        return result;
    }

    point intersection(line sec)
    {
        point ans;
        double zn=a*(sec.b)-(sec.a)*b;
        if (abs(zn)<EPS) cout<<"Error!!!\n";
        ans.x=-(c*sec.b-sec.c*sec.b)/zn;
        ans.y=-(a*sec.c-sec.a*c)/zn;
        return ans;
    }

    bool isParallel(line sec)
    {
        double zn=a*sec.b-sec.a*b;
        return (abs(zn)<EPS);
    }

    line perpendicular(point sec)
    {
        line ans;
        ans.a=-b;
        ans.b=a;
        ans.c=b*sec.x-a*sec.y;
        return ans;
    }

    double dist_to_point(point a)
    {
        line per=perpendicular(a);
        point b=intersection(per);
        return a.dist(b);
    }

    point near_point(point a)
    {
        line per=perpendicular(a);
        point b=intersection(per);
        return b;
    }

    double a;
    double b;
    double c;
};

class circle
{
public:
    circle(point _center, double _r)
    {
        r=_r;
        center=_center;
    }

    vector<point> LineIntersection(line pr)
    {
        vector<point> ans;
        point center_(0,0);
        //pr.c-=abs(center.x)+abs(center.y);
        /*double x0=-pr.a*pr.c/(pr.a*pr.a+pr.b*pr.b)
        double y0=-pr.b*pr.c/(pr.a*pr.a+pr.b*pr.b);*/
        point near=pr.near_point(center_);

        if (pw2(pr.c)-pw2(r)*(pw2(pr.a)+pw2(pr.b))>EPS)
        {
            cout<<"0\n";
            return ans;
        }
        else
        if (abs(pw2(pr.c)-pw2(r)*(pw2(pr.a)+pw2(pr.b)))<EPS)
        {
            cout<<"1\n";
            ans.pb(near+center);
            cout<<near+center<<"\n";
            return ans;
        }
        else
        {
            cout<<"2\n";
            /*double d=(r*r-pw2(pr.c)/
                      (pw2(pr.a)+pw2(pr.b)));
            double mult=sqrt(d/(pw2(pr.a)+pw2(pr.b)));
            pair<point, point> ans_;
            ans_.first=point(center_.x+pr.b*mult, center_.y-pr.a*mult);
            ans_.second=point(center_.x-pr.b*mult, center_.y+pr.a*mult);
            ans.pb(ans_.first);
            ans.pb(ans_.second);
            cout<<near+center<<"\n";
            cout<<near.dist(center_)<<" "<<near.dist(ans[0])<<"\n";*/
            cout<<near+center<<"\n";

            line O_Near(center_, near);
            double OH=center_.dist(near);
            double H_ans=sqrt(r*r-OH*OH);
            line ans1_ans2=O_Near.perpendicular(near);
            pair<point, point> ans_=ans1_ans2.PointsOnDistance(near, H_ans);
            ans.pb(ans_.first);
            ans.pb(ans_.second);
            cout<<OH<<" "<<H_ans<<"\n";
            cout<<ans[0]+center<<"\n";
            cout<<ans[1]+center<<"\n";
            return ans;
        }
    }

    vector<point> CircleIntersection(circle sec)
    {
        double A=-2*(sec.center-center).x;
        double B=-2*(sec.center-center).y;
        double C=(sec.center-center).norm()+r*r-(sec.r)*(sec.r);
        line k(A, B, C);
        return LineIntersection(k);

    }

    bool operator ==(circle b)
    {
        return (center==b.center && abs(r-b.r)<EPS);
    }
    double r;
    point center;
};


int main()
{
    cout.precision(10);
    int n=next();
    for (int i=0; i<n; i++)
    {
        point center;
        cin>>center;
        double r;
        cin>>r;
        circle first(center, r);
        point center2;
        cin>>center2;
        double r2;
        cin>>r2;
        circle second(center2, r2);
        if (first==second) cout<<"3\n";
        else
        vector<point> fake=first.CircleIntersection(second);
    }



}
