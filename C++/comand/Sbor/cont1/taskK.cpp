#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const double eps = 1e-7;

struct Vector{
    double x , y;

    Vector (){}
    Vector (double x , double y): x(x) , y(y) {}

    double Dist(){
        return sqrt(x*x + y*y);
    }

    void Norm(){
        double D = Dist();
        x /= D , y /= D;
    }
};

Vector operator +(Vector a , Vector b){
    return Vector(a.x + b.x , a.y + b.y);
}
Vector operator -(Vector a , Vector b){
    return Vector(a.x - b.x , a.y - b.y);
}
Vector operator *(Vector a , double x){
    return Vector(a.x*x , a.y*x);
}
Vector operator *(double x , Vector a){
    return Vector(a.x*x , a.y*x);
}
bool operator ==(Vector A , Vector B){
    return (abs(A.x - B.x) < eps && abs(A.y - B.y) < eps);
}

istream &operator >> (istream &str , Vector &a){
    return str >> a.x >> a.y;
}
ostream &operator << (ostream &str , const Vector &a){
    return str << a.x << ' ' << a.y;
}

struct Line{
    double a , b , c;

    Line(){}
    Line(Vector A , Vector B): a(A.y - B.y) , b(B.x - A.x) , c(A.x*(B.y - A.y) + A.y*(A.x - B.x)) {}

    double Dist(Vector A){
        return abs(a*A.x + b*A.y + c) / sqrt(a*a + b*b);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    Vector O , A , B; double R;
    cin >> O >> R >> A >> B;

    Vector S((A.x + B.x) / 2 , (A.y + B.y) / 2);

    Line L(A , B);
    double D = L.Dist(O);
    if (D - R < 0 || abs(D - R) < eps){
        cout << "No way";
        return 0;
    }

    Vector N(L.a , L.b);
    N.Norm(); N = N*D;
    if (!(S + N == O)) N = -1*N;
    N = N*((D - R) / D);

    cout << (N + S);
}
/*4 7 3
0 0
8 0

0 0 2
-5 0
-3 4



*/
