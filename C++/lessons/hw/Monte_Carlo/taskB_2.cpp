#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>


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

// here your code begins
double PI = 3.141592653589;

class Vec2d {
public:
    double x;
    double y;

    double length() const {
        return sqrt(x * x + y * y);
    }

    void rotate(double alpha) {
        double newx = x * cos(alpha) - y * sin(alpha);
        double newy = y * cos(alpha) + x * sin(alpha);

        x = newx;
        y = newy;
    }

    double argument() const {
        double res = atan2(y, x);
        if (res < 0) res += 2 * PI;
        return res;
    }

    void rotateByPI(double alpha) {
        rotate(alpha * PI);
    }

    void operator+= (const Vec2d& vec) {
        x += vec.x;
        y += vec.y;
    }

    Vec2d operator-() {
        return {-x, -y};
    }

    void print() { cout << "(" << x << "," << y << ")"; }
    void println() {print(); cout << "\n"; }
};

typedef Vec2d Point2d;

class Polygon {
public:
    Point2d _center;
    double _radius;
    double _phi;
    int _n;
    Polygon(Point2d center, double radius, int n, double phi = 0) :
        _center(center), _radius(radius), _n(n), _phi(phi) {
        if (radius < 0. || n < 3) {
            n = 3;
            radius = 0.;
        }
    }

    void shift(const Vec2d& vec) {_center += vec;}

    void shift_ver(double y) {
        shift({0., y});
    }

    void shift_hor(double x) {
        shift({x, 0.});
    }

    void rotate(double alpha) {
        _center.rotate(alpha);
        _phi += alpha;
    }

    void rotateByPI(double alpha) {
        rotate(PI * alpha);
    }

    double side() const {
        return _radius * sin(PI / _n) * 2.;
    }

    double perimeter() const {
        return side() * _n;
    }

    double innerRadius() const {return _radius * cos(PI / _n); }

    double area() const {
        return side() * innerRadius() * _n / 2.;
    }

    bool in(Point2d p) {
        Polygon pol = *this;

        // shift to 0
        pol.shift(-_center);
        p += -_center;

        // rotate to horizontal
        double rotate_angle = -_phi;
        pol.rotate(rotate_angle);
        p.rotate(rotate_angle);

        // rotate point p to first polygon segment
        double p_angle = p.argument();
        p_angle -= (double)((int)(p_angle * _n / (2 * PI))) / _n * 2 * PI;
        p.rotate(p_angle - p.argument());

        // yet another rotation
        p.rotate(-PI/_n);
        pol.rotate(-PI/_n);

        return p.x <= pol.innerRadius();
    }
};
//here your code ends

double MonteKarlo(Polygon& x, int k)//work with n%2==0
{
    double sum=0;
    for (int j=0; j<10; j++)
    {
        int cnt_in=0;
        double all_area=2*x._radius*2*x.innerRadius();
        for (int i=0; i<k; i++)
        {
            double rand_x=2.0*(rand()*1.0)/(RAND_MAX*1.0)*x._radius-x._radius;
            double rand_y=2.0*((rand()*1.0)/(RAND_MAX*1.0))*x.innerRadius()-x.innerRadius();
            if (x.in({rand_x, rand_y})) cnt_in++;
        }
        double result_area=(cnt_in*1.0/k)*all_area;
        sum+=abs(x.area()-result_area)/x.area();
    }
    return sum/10.0;
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("input_2.txt", "r", stdin);
	freopen("output_2.txt", "w", stdout);
	cout.precision(10);
    srand(451);
    Polygon x({0, 0}, 1.0, 10);
    lint k=2;
    int cnt=1;
    while (true)
    {
        cout<<cnt<<" || "<<MonteKarlo(x, k)<<endl;
        k*=2;
        cnt++;
    }
}

