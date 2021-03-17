#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iterator>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i,n) for (int i=0; i<int(n); i++)

typedef long long lint;

using namespace std;

const int _INF=-1e9-7;
const int INF=1e9+7;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

template<typename type>
class Segm
{
public:
    Segm()= default;
    Segm(type _left, type _right)
    {
        left=_left;
        right=_right;
    }

    bool empty() const
    {
        if (left>right) return true;
        return false;
    }

    bool isInto(type p) const
    {
        if (p>=left && p<=right) return true;
        else return false;
    }

    bool isInto(const Segm& b) const
    {
        if (left>right) return false;
        if (left<=b.left && right>=b.right) return true;
        return false;
    }

    Segm intersect(const Segm& b) const
    {
        Segm ans(max(left, b.left), min(right, b.right));
        return ans;
    }

    bool isIntersect(const Segm& b) const
    {
        return !(intersect(b).empty());
    }

    pair<Segm, Segm> split(type p) const
    {
        return {intersect(Segm(_INF,p-1)), intersect(Segm(p+1,INF))};
    }

    lint size() const
    {
        if (right-left+1>0) return right-left+1;
        return 0;
    }

//    bool operator >(Segm<type> b)
//    {
//        if (left>b.left) return true;
//        if (left==b.left && right>b.right) return true;
//        return false;
//    }
//
//    bool operator <(Segm<type> b)
//    {
//        if (left<b.left) return true;
//        if (left==b.left && right<b.right) return true;
//        return false;
//    }
//
//    bool operator >=(Segm<type> b)
//    {
//        return left>=b.left;
//    }
//
//    bool operator <=(Segm<type> b)
//    {
//        return left<=b.left;
//    }
//
//    bool operator ==(Segm<type> b)
//    {
//        return left==b.left && right==b.right;
//    }
//
//    bool operator !=(Segm<type> b)
//    {
//        return !(*this==b);
//    }

//    ostream& operator<<(ostream& s)
//    {
//        s<<left<<" "<<right;
//        return s;
//    }

//    istream& operator>>(istream& s)
//    {
//        s>>left;
//        s>>right;
//        return s;
//    }

    type left, right;
};

template<typename type>

bool operator>(Segm<type> a, Segm<type> b)
{
    if (a.left>b.left)return true;
    if (a.left==b.left && a.right>b.right ) return true;
    return false;
}

template<typename type>

bool operator<(Segm<type> a, Segm<type> b)
{
    if (a.left<b.left)return true;
    if (a.left==b.left && a.right<b.right ) return true;
    return false;
}

template<typename type>

bool operator>=(Segm<type> a, Segm<type> b)
{
    return a.left>=b.left;
}

template<typename type>

bool operator<=(Segm<type> a, Segm<type> b)
{
    return a.left<=b.left;
}

template<typename type>

bool operator==(Segm<type> a, Segm<type> b)
{
    return (a.left==b.left && a.right==b.right);
}

template<typename type>

bool operator!=(Segm<type> a, Segm<type> b)
{
    return !(a==b);
}

template<typename type>

istream& operator>>(istream& s, Segm<type>& x)
{
    s>>x.left;
    s>>x.right;
    return s;
}

template<typename type>

ostream& operator<<(ostream& s, const Segm<type>& x)
{
    s<<x.left<<" "<<x.right;
    return s;
}

template<typename type>
class SegmSet
{
public:
    SegmSet() = default;

    void check()// проверка множества на коректность
    {
        sz=0;
        int i=0;
        Segm<type> last;
        bool fl=false, fl_=false, fl__=false;
        set<Segm<type> > lt;
        for (Segm<type> x: list_Segm)
        {
            if (!x.empty())
            {
                if (i!=0)
                {
                    if (x.isIntersect(last))
                    {
                        Segm<type> fake(min(x.left, last.left), max(x.right, last.right));
                        last=fake;
                        fl=true;
                        continue;
                    }
                    if (x.left==last.right+1)
                    {
                        Segm<type> fake(min(x.left, last.left), max(x.right, last.right));
                        last=fake;
                        fl_=true;
                        continue;
                    }
                    lt.insert(last);
                    sz+=last.size();
                }
                last=x;
                i++;
            }
        }
        lt.insert(last);
        sz+=last.size();
        list_Segm=lt;
    }

    SegmSet(const vector<type>& a)
    {
        for (int i=0; i<a.size(); i++)
        {
            Segm<type> x(a[i], a[i]);
            list_Segm.insert(x);
        }
        check();
    }

    SegmSet(const vector< Segm<type> >& a)
    {
        for (int i=0; i<a.size(); i++)
            list_Segm.insert(a[i]);
        check();
    }

    void output1() const
    {
        for (Segm<type> x: list_Segm)
           cout<<x<<endl;
    }

    void output2() const
    {
        for (Segm<type> x: list_Segm)
            for (type j=x.left; j<=x.right; j++)
                cout<<j<<" ";
    }

    bool empty() const
    {
        return list_Segm.empty();
    }

    int count(int x)
    {
        list_Segm.insert(Segm<type>(INF, INF)); // для коректной работы upper_bound
        Segm<type> _x(x, x);
        Segm<type> ub=*(list_Segm.upper_bound(_x));
        int ans=0;
        if (ub.isInto(x)) ans=1;
        ub=*(--list_Segm.upper_bound(_x));
        if (ub.isInto(x)) ans=1;
        list_Segm.erase(Segm<type>(INF, INF));
        return ans;
    }

    Segm<type> find(int x)
    {
        list_Segm.insert(Segm<type>(INF, INF)); // для коректной работы upper_bound
        Segm<type> _x(x, x);
        Segm<type> ans(0, -1);
        Segm<type> ub=*(list_Segm.upper_bound(_x));
        if (ub.isInto(x)) ans=ub;
        ub=*(--list_Segm.upper_bound(_x));
        if (ub.isInto(x)) ans=ub;
        list_Segm.erase(Segm<type>(INF, INF));
        return ans;
    }

    int count(const Segm<type>& x)
    {
        if (x.empty()) return 0;
        list_Segm.insert(Segm<type>(INF, INF)); // для коректной работы upper_bound
        int ans=0;
        Segm<type> ub=*(list_Segm.upper_bound(x));
        if (ub.isInto(x)) ans=1;
        ub=*(--list_Segm.upper_bound(x));
        if (ub.isInto(x)) ans=1;
        list_Segm.erase(Segm<type>(INF,INF));
        return ans;
    }

    Segm<type> find(const Segm<type>& x)
    {
        Segm<type> ans(1, 0);
        if (x.empty()) return ans;
        list_Segm.insert(Segm<type>(INF, INF)); // для коректной работы upper_bound
        Segm<type> ub=*(list_Segm.upper_bound(x));
        if (ub.isInto(x)) ans=ub;
        ub=*(--list_Segm.upper_bound(x));
        if (ub.isInto(x)) ans=ub;
        return ans;
    }

    void push(const Segm<type>& x)
    {
        if (x.empty()) return;
        list_Segm.insert(Segm<type>(INF, INF)); // для коректной работы upper_bound
        list_Segm.insert(Segm<type>(_INF, _INF));
        Segm<type> left=find(x.left), right=find(x.right);
        if (count(left)>0)
        {
            list_Segm.erase(left);
            sz-=left.size();
        }
        if (count(right)>0)
        {
            list_Segm.erase(right);
            sz-=right.size();
        }
        type l_b=x.left, r_b=x.right;//удалим все внутренности и запомним, что нужно добавить
        Segm<type> add(x.left, x.left), add_(x.right+1, x.right+1);
        //set< Segm<type> > :: iterator;
        auto it=list_Segm.lower_bound(add);
        auto it_=--list_Segm.lower_bound(add_);
        it_++;
        if (!left.empty()) l_b=left.left;
        if (!right.empty()) r_b=right.right;
        while (it!=it_)
        {
            Segm<type> _x=(*it);
            if (count(_x)>0  && x.isInto(_x))
            {
                sz-=_x.size();
                list_Segm.erase(_x);
            }
            it++;
        }
        //далее проверка на соседство
        Segm<type> L=*(--list_Segm.lower_bound(Segm<type>(l_b, l_b)));
        Segm<type> R=*(list_Segm.lower_bound(Segm<type>(r_b+1, r_b+1)));
        if (!L.empty() && L.right==l_b-1)
        {
            l_b=L.left;
            list_Segm.erase(L);
            sz-=L.size();
        }
        if (!R.empty() && R.left==r_b+1)
        {
            r_b=R.right;
            list_Segm.erase(R);
            sz-=R.size();
        }
        list_Segm.insert(Segm<type>(l_b, r_b));
        sz+=r_b-l_b+1;
        list_Segm.erase(Segm<type>(INF,INF));
        list_Segm.erase(Segm<type>(_INF,_INF));
    }

    void push(type p)
    {
        push(Segm<type>(p, p));
    }

    void erase(type p)
    {
        if (count(p)>0)
        {
            Segm<type> x=find(p);
            list_Segm.erase(x);
            pair<Segm<type>, Segm<type>> t = x.split(p);
            if (!(t.first).empty()) list_Segm.insert(t.first);
            if (!(t.second).empty()) list_Segm.insert(t.second);
            sz--;
        }
    }

    void erase(Segm<type> x)
    {
        if (x.empty()) return;
        if (list_Segm.empty()) return;
        auto it_st=list_Segm.begin();
        auto it_last=list_Segm.end();
        it_last--;
        if (x.right > (*it_last).right && x.left < (*it_st).left)
        {
            list_Segm.clear();
            return;
        }
        list_Segm.insert(Segm<type>(INF, INF)); // для коректной работы upper_bound
        list_Segm.insert(Segm<type>(_INF, _INF));
        Segm<type> left=find(x.left), right=find(x.right);
        if (count(left)>0)
        {
            list_Segm.erase(left);
            sz-=left.size();
        }
        if (count(right)>0)
        {
            list_Segm.erase(right);
            sz-=right.size();
        }
        Segm<type> push1, push2;//удалим все что касается нашего сегмента и добавим то что в него не входило
        if ( !left.empty() ) push1=Segm<type>(left.left, x.left-1);
        if (!right.empty()) push2=Segm<type>(x.right+1, right.right);
        Segm<type> add(x.left, x.left), add_(x.right+1, x.right+1);
        auto it=list_Segm.lower_bound(add);
        auto it_=--list_Segm.lower_bound(add_);
        it_++;
        while (it!=it_)
        {
            Segm<type> _x=(*it);
            if (x.isInto(_x))
            {
                sz-=_x.size();
                list_Segm.erase(_x);
            }
            it++;
        }
        if (!push1.empty()) list_Segm.insert(push1), sz+=push1.size();
        if (!push2.empty()) list_Segm.insert(push2), sz+=push2.size();


        list_Segm.erase(Segm<type>(INF,INF));
        list_Segm.erase(Segm<type>(_INF,_INF));
    }

    SegmSet unite(const SegmSet<type>& b) const
    {
        SegmSet ans;
        ans.sz=sz;
        ans.list_Segm=list_Segm;
        for (Segm<type> x: b.list_Segm)
            (ans.list_Segm).insert(x);
        ans.check();
        return ans;
    }

    SegmSet minus(const SegmSet<type>& b) const
    {
        SegmSet ans;
        ans.sz=sz;
        ans.list_Segm=list_Segm;
        for (Segm<type> x: b.list_Segm)
            ans.erase(x);
        return ans;
    }

    SegmSet intersection(const SegmSet<type>& b) const
    {
        SegmSet ans;
        ans.sz=sz;
        ans.list_Segm=list_Segm;
        return ans.minus(ans.minus(b));
    }

    bool isInto(const SegmSet<type>& b)
    {
        for (Segm<type> x: b.list_Segm)
            if (count(x)==0) return false;
        return true;
    }

    int size() const
    {
        return sz;
    }

    auto begin()
    {
        return list_Segm.begin();
    }

    auto end()
    {
        return list_Segm.end();
    }

    vector<type> middle_dist()
    {
        vector<type> ans;
        type rem=(*list_Segm.begin()).right;
        typename set<Segm<type> > :: iterator it;
        for (it=++list_Segm.begin(); it!=list_Segm.end(); it++)
        {
            ans.push_back((*it).left-rem);
            rem=(*it).right;
        }
        return ans;
    }
    set<Segm<type> > list_Segm;
    int sz=0;
};

vector<int> pref_sum(const vector<int>& a)
{
    vector<int> pref;
    pref.push_back(0);
    for (int i=0; i<a.size(); i++)
        pref.push_back(pref[pref.size()-1]+a[i]);
    return pref;
}

int main()
{
    ios::sync_with_stdio(false);
    SegmSet<int> up;
    int n=next();
    int h=next();
    for (int i=0; i<n; i++)
    {
        int x=next();
        int y=next();
        up.push(Segm<int>(x, y));
    }

    vector<int> dist=up.middle_dist();
    //dist.push_back(2*INF);
    set< Segm<int> > :: iterator it;
    int st=0;
    set< Segm<int> > :: iterator st_=up.begin();
    int height=0, length=0;
    int ans=0;
    int i=0;
    for (it=up.begin(); it!=up.end(); it++)
    {
        if (it==--up.end())
        {
            length+=(*it).size();
            height+=1e9-(*it).right;
            if (height>=h) ans=max(ans, length);
            break;
        }
        height+=dist[i];
        length+=(*it).size();
        if (height>=h)
        {
            ans=max(ans, length);
            height-=dist[st];
            length-=(*st_).size();
            st++;
            st_++;
        }
        i++;

    }
    cout<<length;

}

