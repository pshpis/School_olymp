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

typedef long long lint;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}
class cell
{
public:
    cell()=default;
    cell(lint _x, lint _y)
    {
        x=_x;
        y=_y;
    }

    void operator= (cell b)
    {
        x=b.x;
        y=b.y;
    }

    lint x;
    lint y;
};
class snake
{
public:
    snake()
    {
        rotation=0;
        turn_cell.pb(cell(0, 0));
        alive=true;
    }

    int angle()
    {
        int rot;
        if (turn_cell[turn_cell.size()-1].x==turn_cell[turn_cell.size()-2].x && turn_cell[turn_cell.size()-1].y>turn_cell[turn_cell.size()-2].y ) rot=0;
        if (turn_cell[turn_cell.size()-1].x>turn_cell[turn_cell.size()-2].x && turn_cell[turn_cell.size()-1].y==turn_cell[turn_cell.size()-2].y ) rot=1;
        if (turn_cell[turn_cell.size()-1].x==turn_cell[turn_cell.size()-2].x && turn_cell[turn_cell.size()-1].y<turn_cell[turn_cell.size()-2].y ) rot=2;
        if (turn_cell[turn_cell.size()-1].x<turn_cell[turn_cell.size()-2].x && turn_cell[turn_cell.size()-1].y==turn_cell[turn_cell.size()-2].y ) rot=3;
        return rot;
    }


    void grow()
    {
        if (!alive) return;
        if (turn_cell.size()==1)
        {
            if (rotation==0) turn_cell.pb( cell(turn_cell[0].x, turn_cell[0].y+1) );
            if (rotation==1) turn_cell.pb( cell(turn_cell[0].x+1, turn_cell[0].y) );
            if (rotation==2) turn_cell.pb( cell(turn_cell[0].x, turn_cell[0].y-1) );
            if (rotation==3) turn_cell.pb( cell(turn_cell[0].x-1, turn_cell[0].y) );
            return;
        }
        if (angle()==rotation) turn_cell.pop_back();
        if (rotation==0)
            if ( !isHere(cell(turn_cell.back().x, turn_cell.back().y+1)) ) turn_cell.pb( cell(turn_cell.back().x, turn_cell.back().y+1) );
                else alive=false;
        if (rotation==1)
            if ( !isHere(cell(turn_cell.back().x+1, turn_cell.back().y)) )turn_cell.pb( cell(turn_cell.back().x+1, turn_cell.back().y) );
                else alive=false;
        if (rotation==2)
            if ( !isHere(cell(turn_cell.back().x, turn_cell.back().y-1)) )turn_cell.pb( cell(turn_cell.back().x, turn_cell.back().y-1) );
                else alive=false;
        if (rotation==3)
            if ( !isHere(cell(turn_cell.back().x-1, turn_cell.back().y)) ) turn_cell.pb( cell(turn_cell.back().x-1, turn_cell.back().y) );
                else alive=false;
    }

    bool isAlive()
    {
        return alive;
    }


    void rotate_left()
    {
        if (!alive) return;
        if (angle()==0) rotation=3;
        else rotation=angle()-1;
    }

    void rotate_right()
    {
        if (!alive) return;
        if (angle()==3) rotation=0;
        else rotation=angle()+1;
    }

    void rotate_forward()
    {
        if (!alive) return;
        rotation=angle();
    }

    bool isHere(cell a)
    {
        if (!alive) return false;
        for (int i=0; i<turn_cell.size()-1; i++)
        {
            if (a.x>=turn_cell[i].x && a.x<=turn_cell[i+1].x && a.y>=turn_cell[i].y && a.y<=turn_cell[i+1].y)
            return true;
        }
        return false;
    }

    snake(vector<cell> a)
    {
        turn_cell=a;
        rotate_forward();
        alive=true;

    }

    vector<cell> turn_cell;
    int rotation;
    bool alive;
};
int main()
{
    ios::sync_with_stdio(false);
}
