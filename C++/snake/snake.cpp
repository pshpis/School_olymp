#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <conio.h>

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

class Cell
{
public:

    int x;
    int y;

    Cell(int _x, int _y)
    {
        x=_x;
        y=_y;
    }

    Cell()=default;

    Cell right()
    {
        return Cell(x+1, y);
    }

    Cell left()
    {
        return Cell(x-1, y);
    }

    Cell up()
    {
        return Cell(x, y-1);
    }

    Cell down()
    {
        return Cell(x, y+1);
    }

    Cell next(int dir)
    {
        if (dir==0) return up();
        if (dir==1) return right();
        if (dir==2) return down();
        if (dir==3) return left();
    }

    bool left(Cell sec)
    {
        if (y==sec.y && x<sec.x) return true;
        else return false;
    }

    bool right(Cell sec)
    {
        if (y==sec.y && x>sec.x) return true;
        else return false;
    }

    bool up(Cell sec)
    {
        if (y<sec.y && x==sec.x) return true;
        else return false;
    }

    bool down(Cell sec)
    {
        if (y>sec.y && x==sec.x) return true;
        else return false;
    }

    bool OnLine(Cell sec, int dir)
    {
        if (dir==0) return up(sec);
        if (dir==1) return right(sec);
        if (dir==2) return down(sec);
        if (dir==3) return left(sec);
    }

    bool OnLine(Cell sec)
    {
        for (int i=0; i<4; i++)
            if (OnLine(sec, i)) return true;
        return false;
    }

    int direct(Cell sec)
    {
        for (int i=0; i<4; i++)
            if (OnLine(sec, i)) return i;
        return -1;
    }

    int dist(Cell sec)
    {
        return (abs(x-sec.x)+abs(y-sec.y));
    }

    bool between(Cell sec, Cell bet)
    {
        if (bet==sec || bet==(*this)) return true;
        if (direct(sec)==direct(bet) && direct(bet)!=-1)
        {
            return (dist(bet)<dist(sec));
        }
        return false;
    }

    bool operator ==(Cell sec)
    {
        return (x==sec.x && y==sec.y);
    }

    void operator =(Cell sec)
    {
        x=sec.x;
        y=sec.y;
    }

    int norm() const
    {
        return x*x+y*y;
    }

    int num(int sz) const
    {
        return y*sz+x;
    }

    bool operator<(Cell sec)
    {
        return norm()<sec.norm();
    }
};

int StLength=4;
int Width=20;
int Height=20;
map<Cell, int> table;

bool operator<(const Cell ft, const Cell sec)
{
    return ft.num(max(Height+2, Width+2))<sec.num(max(Height+2, Width+2));
}

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

class Snake
{
public:
    bool alive;
    DoubleList<Cell> change;
    int dir;

    Snake(Cell st)
    {
        alive=true;
        dir=1;
        change.push_back(st);
        Cell st_(st.x+StLength, st.y);
        change.push_back(st_);
    }

    bool isAlive()
    {
        return alive;
    }

    int first_dir()
    {
        Cell last=change[change.size()-1];
        Cell pr_last=change[change.size()-2];
        for (int dir_=0; dir_<4; dir_++)
            if (last.OnLine(pr_last, dir_)) return dir_;
    }

    void change_dir(int new_dir)
    {
        if (abs(new_dir-dir)!=2) dir=new_dir;
    }

    bool IsHere(Cell sec)
    {
        Node<Cell> el=change[0];
        while (el.Next!=nullptr)
            if ((el.Data).between((*(el.Next)).Data, sec)) return true;
        return false;
    }

    void step()
    {
        if (!alive)
        {
            change.clear();
            return;
        }
        int dir_=first_dir();
        Cell new_first;
        for (int i=0; i<4; i++)
            if (change[0].OnLine(change[1], i))
            {
                new_first=change[0].next(i);
            }
        change.pop_front();
        change.push_front(new_first);

        Cell new_last=change[change.size()-1].next(dir);
        if (table[new_last]==1)
        {
            alive=false;
            change.clear();
            return;
        }
        Node<Cell> el=change[0];
        while (el.Next!=nullptr)
        {
            if ((el.Data).between((*(el.Next)).Data, new_last))
            {
                alive=false;
                change.clear();
                return;
            }
        }

        if (dir==dir_)
        {
            change.pop_back();
            change.push_back(new_last);
        }
        else change.push_back(new_last);
    }

};

Snake sn(Cell(1, 1));
void Draw()
{
    system("cls");
    for (int i=0; i<=Height+1; i++)
    {
        for (int j=0; j<=Width+1; j++)
        {
            Cell ft(j, i);
            if (table[ft]==0)
            {
                if (sn.IsHere(ft) ) cout<<"O";
                    else cout<<" ";
            }
            if (table[ft]==1) cout<<"#";
            //if (table[Cell(i, j)]==2) cout<<"F";
            //cout<<table[Cell(j, i)];
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void Setup()
{
    for (int i=0; i<=Height+1; i++)
        for (int j=0; j<=Width+1; j++)
        {
            Cell ft(j, i);
            table[ft]=0;
        }
//    Draw();
//    Cell Fack(4, 3);
//    watch(table[Fack]);
    for (int j=0; j<=Width+1; j++)
    {
        Cell ft(j, 0);
        Cell sec(j, Height+1);

        table[ft]=1;
        table[sec]=1;
//        cout<<j<<endl;
//        Draw();
//        if (j==5)
//        {
//            cout<<table[Fack]<<endl;
//            cout<<ft<<endl<<sec<<endl;
//            Draw();
//        }
        //if (table[Fack]==1) cout<<"Facking STOP!!!!! J=="<<j<<endl;
    }
    //watch(table[Fack]);
    //Draw();
    for (int i=1; i<=Height; i++)
    {
        table[Cell(0, i)]=1;
        table[Cell(Width+1, i)]=1;
    }
}



void Input()
{
    if (_kbhit())
    {
        switch(_getch())
        {
            case 'a': sn.change_dir(3);
            case 's': sn.change_dir(2);
            case 'd': sn.change_dir(1);
            case 'w': sn.change_dir(0);
            case 'p': sn.step();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    //watch(Height);
    //watch(Width);
    //Draw();
    Setup();
    Draw();
//    watch(table[Cell(4, 3)]);
//    watch(Height);
//    watch(Width);
    cout<<sn.change[0]<<endl<<sn.change[1]<<endl<<sn.change[2]<<endl;
    cout<<sn.first_dir()<<endl<<sn.dir<<endl;
    return 0;
    while(sn.alive)
    {
        Draw();
        Input();
    }
}
/*
||=== Build file: "no target" in "no project" (compiler: unknown) ===|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h||In instantiation of 'constexpr bool std::less<_Tp>::operator()(const _Tp&, const _Tp&) const [with _Tp = Cell]':|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_map.h|478|required from 'std::map<_Key, _Tp, _Compare, _Alloc>::mapped_type& std::map<_Key, _Tp, _Compare, _Alloc>::operator[](const key_type&) [with _Key = Cell; _Tp = int; _Compare = std::less<Cell>; _Alloc = std::allocator<std::pair<const Cell, int> >; std::map<_Key, _Tp, _Compare, _Alloc>::mapped_type = int; std::map<_Key, _Tp, _Compare, _Alloc>::key_type = Cell]'|
C:\study\prog\snake.cpp|405|required from here|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|error: no match for 'operator<' (operand types are 'const Cell' and 'const Cell')|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_pair.h|220|note: candidate: template<class _T1, class _T2> constexpr bool std::operator<(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_pair.h|220|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::pair<_T1, _T2>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|298|note: candidate: template<class _Iterator> bool std::operator<(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|298|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::reverse_iterator<_Iterator>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|348|note: candidate: template<class _IteratorL, class _IteratorR> bool std::operator<(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_IteratorR>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|348|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::reverse_iterator<_Iterator>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|1089|note: candidate: template<class _IteratorL, class _IteratorR> bool std::operator<(const std::move_iterator<_Iterator>&, const std::move_iterator<_IteratorR>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|1089|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::move_iterator<_Iterator>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|1095|note: candidate: template<class _Iterator> bool std::operator<(const std::move_iterator<_Iterator>&, const std::move_iterator<_Iterator>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|1095|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::move_iterator<_Iterator>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\basic_string.h|4982|note: candidate: template<class _CharT, class _Traits, class _Alloc> bool std::operator<(const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&, const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\basic_string.h|4982|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\basic_string.h|4994|note: candidate: template<class _CharT, class _Traits, class _Alloc> bool std::operator<(const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\basic_string.h|4994|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\basic_string.h|5006|note: candidate: template<class _CharT, class _Traits, class _Alloc> bool std::operator<(const _CharT*, const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\basic_string.h|5006|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   mismatched types 'const _CharT*' and 'Cell'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\system_error|200|note: candidate: bool std::operator<(const std::error_code&, const std::error_code&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\system_error|200|note:   no known conversion for argument 1 from 'const Cell' to 'const std::error_code&'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\system_error|274|note: candidate: bool std::operator<(const std::error_condition&, const std::error_condition&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\system_error|274|note:   no known conversion for argument 1 from 'const Cell' to 'const std::error_condition&'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_vector.h|1528|note: candidate: template<class _Tp, class _Alloc> bool std::operator<(const std::vector<_Tp, _Alloc>&, const std::vector<_Tp, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_vector.h|1528|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::vector<_Tp, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_tree.h|1293|note: candidate: template<class _Key, class _Val, class _KeyOfValue, class _Compare, class _Alloc> bool std::operator<(const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>&, const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_tree.h|1293|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_set.h|854|note: candidate: template<class _Key, class _Compare, class _Alloc> bool std::operator<(const std::set<_Key, _Compare, _Alloc>&, const std::set<_Key, _Compare, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_set.h|854|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::set<_Key, _Compare, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_multiset.h|837|note: candidate: template<class _Key, class _Compare, class _Alloc> bool std::operator<(const std::multiset<_Key, _Compare, _Alloc>&, const std::multiset<_Key, _Compare, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_multiset.h|837|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::multiset<_Key, _Compare, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\array|242|note: candidate: template<class _Tp, unsigned int _Nm> bool std::operator<(const std::array<_Tp, _Nm>&, const std::array<_Tp, _Nm>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\array|242|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::array<_Tp, _Nm>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\tuple|928|note: candidate: template<class ... _TElements, class ... _UElements> constexpr bool std::operator<(const std::tuple<_Args1 ...>&, const std::tuple<_Args2 ...>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\tuple|928|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::tuple<_Args1 ...>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_map.h|1087|note: candidate: template<class _Key, class _Tp, class _Compare, class _Alloc> bool std::operator<(const std::map<_Key, _Tp, _Compare, _Alloc>&, const std::map<_Key, _Tp, _Compare, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_map.h|1087|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::map<_Key, _Tp, _Compare, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_multimap.h|988|note: candidate: template<class _Key, class _Tp, class _Compare, class _Alloc> bool std::operator<(const std::multimap<_Key, _Tp, _Compare, _Alloc>&, const std::multimap<_Key, _Tp, _Compare, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_multimap.h|988|note:   template argument deduction/substitution failed:|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_function.h|387|note:   'const Cell' is not derived from 'const std::multimap<_Key, _Tp, _Compare, _Alloc>'|
||=== Build failed: 1 error(s), 3 warning(s) (0 minute(s), 1 second(s)) ===|
*/

