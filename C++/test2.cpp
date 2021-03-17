#include <iostream>

using namespace std;


class Point{
private:
    double x, y;

public:
    explicit Point(double x_ = 0, double y_ = 0): x(x_), y(y_){}

    Point& operator =(Point other){
        x = other.x;
        y = other.y;

        return *this;
    }

    ostream& operator <<(ostream& s){
        s << x << " " << y;
        return s;
    }

    istream& operator >>(istream& s){
        s >> x;
        s >> y;
        return s;
    }

};

int main() {
    Point a(0, 1);
    Point b(0, 0);

    a = b;
    cout << a;

}
