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
        if (Size==1) pop_front();
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
    int n=next();
    List<int> lst;
    for (int i=0; i<n; i++)
        lst.push_back(next());
    vector<int> ans;
    string res="";
    while (true)
    {
        if (lst.size()==1)
        {
            if (ans.size()==0 || lst.back()>ans[ans.size()-1])
            {
                ans.push_back(lst.back());
                lst.pop_back();
                res+='R';
            }
            break;
        }
        if (lst.back()==lst.front() && (ans.size()==0 || lst.back()>ans[ans.size()-1]))
        {
            vector<int> BackLine, FrontLine;

            while (lst.size()>0 && (BackLine.size()==0 || lst.back()>BackLine[BackLine.size()-1]))
            {
                BackLine.push_back(lst.back());
                lst.pop_back();
            }
            for (int i=BackLine.size()-1; i>=0; i--)
                lst.push_back(BackLine[i]);

            while (lst.size()>0 && (FrontLine.size()==0 || lst.front()>FrontLine[FrontLine.size()-1]))
            {
                FrontLine.push_back(lst.front());
                lst.pop_front();
            }
            for (int i=FrontLine.size(); i>=0; i--)
                lst.push_front(FrontLine[i]);

            for (int i=0; i<max(BackLine.size(), FrontLine.size()); i++)
                if (BackLine.size()>FrontLine.size())
                {
                    ans.pb(BackLine[i]);
                    res+='R';
                }
                else
                {
                    ans.pb(FrontLine[i]);
                    res+='L';
                }
            break;

        }
        if (ans.size()==0)
        {
            ans.push_back(min(lst.front(), lst.back()));
            if (lst.front()<lst.back()) lst.pop_front(), res+='L';
            else lst.pop_back(), res+='R';
            continue;
        }
        if (lst.back()>ans[ans.size()-1] && lst.front()>ans[ans.size()-1])
        {
            ans.push_back(min(lst.front(), lst.back()));
            if (lst.front()<lst.back()) lst.pop_front(), res+='L';
            else lst.pop_back(), res+='R';
            continue;
        }
        if (lst.back()>ans[ans.size()-1] && lst.front()<=ans[ans.size()-1])
        {
            ans.push_back(lst.back());
            lst.pop_back(), res+='R';
            continue;
        }
        if (lst.back()<=ans[ans.size()-1] && lst.front()>ans[ans.size()-1])
        {
            ans.push_back(lst.front());
            lst.pop_front(), res+='L';
            continue;
        }
        break;
    }
    cout<<ans.size()<<endl;
    cout<<res<<endl;
}


