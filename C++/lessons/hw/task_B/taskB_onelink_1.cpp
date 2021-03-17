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
        }
        else
        {
            Cell<type>* curr=first;
            while ((*curr).Next!=nullptr)
                curr=(*curr).Next;
            (*curr).Next=new Cell<type>(el);
        }
        Size++;
    }

    bool empty()
    {
        return (Size==0);
    }

    List(vector<type> el)
    {
        Size=0;
        first=nullptr;
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
        Cell<type> *curr=first;
        for (int i=0; i<pl; i++)
            curr=(*curr).Next;
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

    void push_front(type el)
    {
        if (first==nullptr)
            first =new Cell<type>(el);
        else
            first=new Cell<type>(el, first);
        Size++;
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

    void clear()
    {
        if (Size==0) return;
        while (Size>0)
            pop_front();
    }

private:
    template<typename type_>
    class Cell
    {
    public:
        Cell *Next;
        type_ Data;
        Cell()=default;
        Cell(type_ Data_, Cell* Next_=nullptr)
        {
            Data=Data_;
            Next=Next_;
        }

    };

    Cell<type> *first;
    int Size;

};

int main()
{
    ios::sync_with_stdio(false);
//    vector<int> num={1, 2, 3, 45, 67, 99, 177};
//    List<int> lst(num);
//    watch(lst.size());
//    lst.output();
//    lst.push_front(0);
//    watch(lst.size());
//    lst.output();
//    lst.push_front(-1);
//    watch(lst.size());
//    lst.output();
//    lst.push_front(-1);
//    watch(lst.size());
//    lst.output();
//    List<int> lst;
//    //cout<<lst.size()<<endl;
//    lst.push_back(1);
//    //cout<<lst.size()<<endl;
//    lst.push_back(2);
//    //cout<<lst.size()<<endl;
//    lst.push_back(3);
//    //cout<<lst.size()<<endl;
//    cout<<lst.size()<<endl;
//    lst.output();
//    lst.pop_front();
//    cout<<lst.size()<<endl;
//    lst.output();
//    lst.clear();
//    cout<<lst.size()<<endl;
//    lst.output();
//    cout<<lst.count(1)<<" "<<lst.count(2)<<" "<<lst.count(3)<<" "<<lst.count(45);
    const int INF=1e9+7;
    int n=next();
    vector<int> num;
    for (int i=0; i<n; i++)
        num.push_back(next());
    num.pb(INF);
    vector<int> ans(n, 0);
    int local_max=0;
    for (int i=1; i<n; i++)
    {
        bool fl=(num[i]>num[i+1] && num[i]>num[i-1]);
        if (fl)
        {
            local_max=i;
            continue;
        }
        else ans[i]=i-local_max;
    }



}
