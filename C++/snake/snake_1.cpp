#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <conio.h>
#include <ctime>

#define watch(x) cout << (#x) << " is " << (x) << "/n";
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

template<typename type_>
class Node
{
public:
    Node *Next;
    Node *Prev;
    type_ Data;
    Node()=default;
    Node(type_ Data_, Node* Prev_=nullptr, Node* Next_=nullptr)
    {
        Data=Data_;
        Next=Next_;
        Prev=Prev_;
    }

};

template<typename type>

class DoubleList
{
public:
    DoubleList()
    {
        Size=0;
        first=nullptr;
        last=nullptr;
    }

    ~DoubleList()
    {
        clear();
    }

    void push_back(type el)
    {
        if (first==nullptr)
        {
            first =new Node<type>(el);
            last = first;
        }
        else
        {
            Node<type>* curr=last;
            (*curr).Next=new Node<type>(el, curr);
            last=(*curr).Next;
        }
        Size++;
    }

    void push_front(type el)
    {
        if (first==nullptr)
            first =new Node<type>(el);
        else
        {
            Node<type> *curr=first;
            first=new Node<type>(el, nullptr, first);
            (*curr).Prev=first;
        }
        Size++;
    }

    DoubleList(vector<type> el)
    {
        Size=0;
        first=nullptr;
        last=nullptr;
        for (int i=0; i<el.size(); i++)
            push_back(el[i]);
    }


    int size()
    {
        return Size;
    }

    bool find(type el)
    {
        if (Size==0) return false;
        Node<type>* curr=first;
            while ((*curr).Next!=nullptr)
            {
                if ((*curr).Data==el) return true;
                curr=(*curr).Next;
            }
        if ((*curr).Data==el) return true;
        return false;
    }

    int count(type el)
    {
        int result=0;
        if (Size==0) return result;
        Node<type>* curr=first;
            while ((*curr).Next!=nullptr)
            {
                if ((*curr).Data==el) result++;
                curr=(*curr).Next;
            }
        if ((*curr).Data==el) result++;
        return result;
    }

    type& operator[](const int& pl)
    {
        Node<type> *curr;
        if (pl<Size/2)
        {
            curr=first;
            for (int i=0; i<pl; i++)
                curr=(*curr).Next;
        }
        else
        {
            curr=last;
            for (int i=Size; i>pl; i--)
                curr=(*curr).Prev;
        }
        return (*curr).Data;
    }

    void pop_front()
    {
        if (Size==0) return;
        Node<type>* temp=first;
        first=(*first).Next;
        delete temp;
        if (Size>0) Size--;
    }

    void pop_back()
    {
        if (Size==1) pop_front();
        if (Size==0) return;
        Node<type>* temp=last;
        last=(*last).Prev;
        (*last).Next=nullptr;
        delete temp;
        if (Size>0) Size--;
    }


    void clear()
    {
        if (Size==0) return;
        while (Size>0)
            pop_front();
    }

    void output()
    {
        if (Size==0) return;
        Node<type>* curr=first;
        while ((*curr).Next!=nullptr)
        {
            cout<<(*curr).Data<<" ";
            curr=(*curr).Next;
        }
        cout<<(*curr).Data<<endl;
    }

    void rev_output()
    {
        if (Size==0) return;
        Node<type>* curr=last;
        while ((*curr).Prev!=nullptr)
        {
            cout<<(*curr).Data<<" ";
            curr=(*curr).Prev;
        }
        cout<<(*curr).Data<<endl;

    }

    type back()
    {
        return (*last).Data;
    }

    type front()
    {
        return (*first).Data;
    }


private:
    Node<type> *first;
    Node<type> *last;
    int Size;

};

int Width=20;
int Height=20;
int Speed=5;

class Cell
{
public:
    int x, y;
    Cell()=default;
    Cell(int x_, int y_)
    {
        x=x_;
        y=y_;
    }

    int num() const
    {
        return x+y*(Width+1);
    }

    bool operator > (const Cell& sec) const
    {
        return num()>sec.num();
    }

    bool operator ==(const Cell& sec) const
    {
        return num()==sec.num();
    }

    bool operator < (const Cell& sec) const
    {
        return num()<sec.num();
    }

    Cell operator + (const Cell& sec) const
    {
        return Cell(x+sec.x, y+sec.y);
    }

    Cell operator - () const
    {
        return Cell(-x, -y);
    }

    Cell operator - (const Cell& sec) const
    {
        return (*this)+(-sec);
    }

    void operator = (const Cell& sec)
    {
        x=sec.x;
        y=sec.y;
    }

//    ostream& operator<<(ostream& s)
//    {
//        s<<x<<" "<<y;
//        return s;
//    }
//
//    istream& operator>>(istream& s)
//    {
//        s>>x;
//        s>>y;
//        return s;
//    }
};

ostream& operator<<(ostream& s, const Cell& ft)
{
    s<<ft.x<<" "<<ft.y;
    return s;
}

istream& operator>>(istream& s, Cell& ft)
{
    ft.x=next();
    ft.y=next();
    return s;
}

map<Cell, int> table;
bool isFruit=false;

class Snake
{
    DoubleList<Cell> sn;
    int dir;
    bool alive;
    int first_dir()
    {
        if (sn.size()==0) return dir;
        else
        {
            int sz=sn.size();
            Cell p=sn[sz]-sn[sz-1];
            if (p.x==1) return 1;
            if (p.x==-1) return 3;
            if (p.y==-1) return 0;
            if (p.y==1) return 2;
        }
    }
public:
    void ChangeDirection(int new_dir)
    {
        if (sn.size()==1 || abs(first_dir()-new_dir)!=2) dir=new_dir;
    }

    Snake (Cell st)
    {
        sn.clear();
        sn.push_back(st);
        table[st]=3;
        alive=true;
        dir=1;
    }

    Snake (Cell st, int length)
    {

    }
    Snake()
    {
        alive=true;
        dir=1;
        sn.clear();
    }

    bool isAlive()
    {
        return alive;
    }

    bool IsHere(Cell sec)
    {
        for (int i=0; i<sn.size(); i++)
            if (sec==sn[i]) return true;
        return false;
    }

    void step()
    {
        if (!alive) return;
        Cell new_last=sn.back();
        if (dir==1) new_last.x++;
        if (dir==2) new_last.y++;
        if (dir==3) new_last.x--;
        if (dir==0) new_last.y--;
        if (table[new_last]!=2)
        {
            table[sn.front()]=0;
            sn.pop_front();
        }
        else isFruit=false;
        if (table[new_last]==1 || table[new_last]==3)
        {
           alive=false;
           sn.clear();
           return;
        }
        else
        {
            table[new_last]=3;
            sn.push_back(new_last);
        }
    }

    void watch_()
    {
        sn.output();
    }

    void dead()
    {
        alive=false;
        sn.clear();
    }
};

void Setup()
{
    for (int i=0; i<=Height+1; i++)
        for (int j=0; j<=Width+1; j++)
            table[Cell(j, i)]=0;
    for (int j=0; j<=Width+1; j++)
    {
        table[Cell(j, 0)]=1;
        table[Cell(j, Height+1)]=1;
    }
    for (int i=1; i<=Height; i++)
    {
        table[Cell(0, i)]=1;
        table[Cell(Width+1, i)]=1;
    }
}

//Snake sn(Cell(Width/2, Height/2));

int score=-1;

void Draw()
{
    system("cls");
    for (int i=0; i<=Height+1; i++)
    {
        for (int j=0; j<=Width+1; j++)
        {
            Cell t(j, i);
            if (table[t]==1) cout<<"#";
            else if (table[t]==0) cout<<" ";
            else if (table[t]==2) cout<<"F";
            else if (table[t]==3) cout<<"0";
            //cout<<table[t];
        }
        cout<<endl;
    }
    cout<<endl<<"SCORE : "<<score<<endl;
}

void Input(Snake& sn, bool& Game_Begin)
{
    if (_kbhit())
    {
        switch(_getch())
        {
            case 'a':
            {
                sn.ChangeDirection(3);
                if (!Game_Begin) Game_Begin=true;
            }

                break;
            case 's':
            {
                sn.ChangeDirection(2);
                if (!Game_Begin) Game_Begin=true;
            }
                break;
            case 'd':
            {
                sn.ChangeDirection(1);
                if (!Game_Begin) Game_Begin=true;

            }
                break;
            case 'w':
            {
                sn.ChangeDirection(0);
                if (!Game_Begin) Game_Begin=true;
            }
                break;
            case 'q':
                 sn.step();
                 break;
        }
    }
}

void Menu();
int TimeAfter=3;
bool Game_Over=false;
int Record=0;

void Play()
{
    system("cls");
    Cell Fruit;
    score=-1;
    Snake sn(Cell((Width+1)/2, (Height+1)/2));
    table[Cell((Width+1)/2, (Height+1)/2)]=3;
    int k=0;
    bool Game_Begin=false;
    Setup();
    isFruit=false;
    while(sn.isAlive())
    {
        if (!isFruit)
        {
            Fruit=Cell(0, 0);
            while (table[Fruit]!=0)
            {
                Fruit.x=rand()%Width+1;
                Fruit.y=rand()%Height+1;
            }
            table[Fruit]=2;
            isFruit=true;
            score++;
        }
        k++;
        if (Game_Begin && k>Speed)
        {
            sn.step();
            k=0;
        }
        //Input();
        Draw();
        Input(sn, Game_Begin);
    }
    cout<<endl<<endl<<"GAME OVER!!!"<<endl<<endl;
    Record=max(Record, score);
    time_t t_=time(NULL);
    while (time(NULL)-t_<TimeAfter) {}
    Menu();

}

void Records()
{
    cout<<Record<<endl;
    time_t t_=time(NULL);
    while (time(NULL)-t_<TimeAfter) {}
    Menu();
}

void ChangeSpeed()
{
    cout<<"Speed is "<<Speed<<endl;
    Speed=next();
}

void ChangeWidth()
{
    cout<<"Width is "<<Width<<endl;
    Width=next();
}

void ChangeHeight()
{

    cout<<"Height is "<<Height<<endl;
    cin>>Height;
}
void Settings()
{
    cout<<"1. Height"<<endl<<"2. Width"<<endl<<"3. Speed"<<endl;
    int x=0;
    while (!(x>0 && x<4))
    {
        string c;
        getline(cin, c);
        x=c[0]-'0';
        if (x==1) ChangeHeight();
        if (x==2) ChangeWidth();
        if (x==3) ChangeSpeed();
    }
    Menu();
}

void Menu()
{
    system("cls");
    cout<<"1. Settings"<<endl;
    cout<<"2. Play"<<endl;
    cout<<"3. Watch Record"<<endl;
    int x=0;
    while (!(x>0 && x<4))
    {
        string c;
        getline(cin, c);
        x=c[0]-'0';
        if (x==1) Settings();
        if (x==2) Play();
        if (x==3) Records();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    srand(time(0));
    cin.tie(0);
    cout.tie(0);
    Setup();
    Menu();
}
