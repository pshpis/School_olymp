#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)

//#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[]="C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
#endif // FILE_out

typedef long long lint;

const int INF=2e9;
const lint INF64=1e18;
const double PI=3.14159265359;
const double EPS=1e-9;
const int MOD=1e9+7;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

//double abs( double x){
//    if (x<0) return -x;
//    else return x;
//}

class Point2d{
public:
    double x, y;
    Point2d()=default;
    Point2d(double _x, double _y){
        x=_x;
        y=_y;
    }

    int quarter(){
        if (x>=0 && y>=0) return 0;
        if (x<0 && y>=0) return 1;
        if (x<0 && y<0) return 2;
        if (x>=0 && y<0) return 3;

    }

    double angle(){
//        if (x==0 && y>=0) return PI/2;
//        if (x==0 && y<0) return 3*PI/2;
//        double ans=atan(fabs(y)/fabs(x))+(PI/2)*quarter();
        return atan2(y, x);
    }

    double norm(){
        return x*x+y*y;
    }

    double abs(){
        return sqrt(norm());
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
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out

    vector<Point2d> a(4);
    vector<Point2d> b(4);
    int n=4;

    for (int i=0; i<n; i++){
        double x, y;
        cin>>x>>y;
        a[i]=Point2d(x, y);
    }
    for (int i=0; i<n; i++){
        double x, y;
        cin>>x>>y;
        b[i]=Point2d(x, y);
    }

    double up_a=-1000, down_a=1000, left_a=1000, right_a=-1000;

    for (int i=0; i<n; i++){
        up_a=max(up_a, a[i].y);
        down_a=min(down_a, a[i].y);
        left_a=min(left_a, a[i].x);
        right_a=max(right_a, a[i].x);
    }
    for (int i=0; i<n; i++){
        if (b[i].x>=left_a && b[i].x<=right_a && b[i].y>=down_a && b[i].y<=up_a){
//            watch(i);
//            watch(b[i]);
//            watch(up_a);
//            watch(down_a);
//            watch(left_a);
//            watch(right_a);
            cout<<"YES";
            return 0;
        }
    }

    for (int i=0; i<n; i++){
        double abs=a[i].abs();
        double ang=a[i].angle();
//        watch(i);
//        watch(a[i]);
//        watch(abs);
//        watch(ang);
//        watch(ang/PI * 180);
//        watch(b[i].quarter());
        ang+=PI/4;
        a[i].x=abs*cos(ang);
        a[i].y=abs*sin(ang);
//        watch(a[i]);
    }
    for (int i=0; i<n; i++){
        double abs=b[i].abs();
        double ang=b[i].angle();
//        watch(i);
//        watch(b[i]);
////        watch(ang);
//        watch(ang/PI * 180);
////        watch(b[i].quarter());
        ang+=PI/4
        ;
        b[i].x=abs*cos(ang);
        b[i].y=abs*sin(ang);
//        watch(b[i]);
    }

    double up_b=-1000, down_b=1000, left_b=1000, right_b=-1000;
    for (int i=0; i<n; i++){
        up_b=max(up_b, b[i].y);
        down_b=min(down_b, b[i].y);
        left_b=min(left_b, b[i].x);
        right_b=max(right_b, b[i].x);
    }
//    watch(up_b);
//    watch(down_b);
//    watch(left_b);
//    watch(right_b);
    for (int i=0; i<n; i++){
//        watch(i);
//        watch(a[i]);
        if (a[i].x-left_b>=-EPS && a[i].x-right_b<=EPS  && a[i].y-down_b>=-EPS && a[i].y-up_b<=EPS){
//            watch(i);
//            watch(a[i]);
            cout<<"YES";
            return 0;
        }
    }

    cout<<"NO";
}

