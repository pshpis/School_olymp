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

template<typename type>

class List
{
public:
    List()
    {
        Size=0;
        first=nullptr;
        last=nullptr;
    }

    ~List()
    {
        clear();
    }

    void push_back(type el)
    {
        if (first==nullptr)
        {
            first =new Cell<type>(el);
            last = first;
        }
        else
        {
            Cell<type>* curr=last;
            (*curr).Next=new Cell<type>(el, curr);
            last=(*curr).Next;
        }
        Size++;
    }

    void push_front(type el)
    {
        if (first==nullptr)
            first =new Cell<type>(el);
        else
        {
            Cell<type> *curr=first;
            first=new Cell<type>(el, nullptr, first);
            (*curr).Prev=first;
        }
        Size++;
    }

    List(vector<type> el)
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
        Cell<type>* curr=first;
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
        Cell<type>* curr=first;
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
        Cell<type> *curr;
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
        Cell<type>* temp=first;
        first=(*first).Next;
        delete temp;
        if (Size>0) Size--;
    }

    void pop_back()
    {
        if (Size==0) return;
        Cell<type>* temp=last;
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
        Cell<type>* curr=first;
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
        Cell<type>* curr=last;
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
    template<typename type_>
    class Cell
    {
    public:
        Cell *Next;
        Cell *Prev;
        type_ Data;
        Cell()=default;
        Cell(type_ Data_, Cell* Prev_=nullptr, Cell* Next_=nullptr)
        {
            Data=Data_;
            Next=Next_;
            Prev=Prev_;
        }

    };

    Cell<type> *first;
    Cell<type> *last;
    int Size;

};

int main()
{
    ios::sync_with_stdio(false);
    vector<int> num={1, 2, 3, 45, 67, 99, 177};
    List<int> lst(num);
//    for (int i=0; i<lst.size(); i++)
//        cout<<lst.count(lst[i])<<" ";
//    cout<<endl;
//    cout<<lst.count(-1)<<" "<<lst.count(1234)<<endl;
    lst.output();
    lst.pop_back();
    lst.output();
    lst.pop_front();
    lst.output();
    lst.push_back(12);
    lst.output();
    lst.push_front(23);
    lst.output();
    cout<<lst.front()<<endl<<lst.back()<<endl;
    /*
    //cout<<lst.size()<<endl;
    lst.push_back(1);
    //cout<<lst.size()<<endl;
    lst.push_back(2);
    //cout<<lst.size()<<endl;
    lst.push_back(3);
    //cout<<lst.size()<<endl;
    cout<<lst.size()<<endl;
    lst.output();
    lst.rev_output();
    lst.pop_front();
    cout<<lst.size()<<endl;
    lst.output();
//    lst.clear();
//    cout<<lst.size()<<endl;
//    lst.output();

    //cout<<lst.count(1)<<" "<<lst.count(2)<<" "<<lst.count(3)<<" "<<lst.count(45);
    */

}

