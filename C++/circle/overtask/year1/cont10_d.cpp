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

typedef long long lint;

using namespace std;

const int _INF=-1e9-7;
const int INF=1e9+7;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int max_pw2(int k)
{
    int ans=0;
    while (k>1)
    {
        if (k%2==0) k/=2;
        else break;
        ans++;
    }
    return ans;
}

class segm
{
    public:
    segm()= default;
    segm(int _left, int _right)
    {
        left=_left;
        right=_right;
    }

    void output()
    {
        cout<<left<<" "<<right<<"\n";
    }

    bool empty() const
    {
        if (left>right) return true;
        return false;
    }

    bool isInto(int p) const
    {
        if (p>=left && p<=right) return true;
        else return false;
    }

    bool isInto(const segm& b) const
    {
        if (left>right) return false;
        if (left<=b.left && right>=b.right) return true;
        return false;
    }

    segm intersect(const segm& b) const
    {
        segm ans(max(left, b.left), min(right, b.right));
        return ans;
    }

    bool isIntersect(const segm& b) const
    {
        return !(intersect(b).empty());
    }

    pair<segm, segm> split(int p) const
    {
        return {intersect(segm(_INF,p-1)), intersect(segm(p+1,INF))};
    }

    int min_div(int k) const
    {
        for (int i=left; i<right; i++)
            if (i%k==0) return i;
        return -1;
    }

    int mx_pw2() const
    {
        int ans=-1;
        for (int i=left; i<right; i++)
            ans=max(ans, max_pw2(i));
        return ans;
    }

    int size() const
    {
        if (right-left+1>0) return right-left+1;
        return 0;
    }
    /*bool operator>= (segm b) {return left>=b.left;}
    bool operator== (segm b) {return ( left==b.left && right==b.right );}
    bool operator<= (segm b) {return left<=b.left;}*/

    //bool operator> (const segm& b) {return left>b.left;}
    //bool operator< (const segm& b) {return left<b.left;}
    int left, right;
};


bool operator>(segm a, segm b)
{
    if (a.left>b.left)return true;
    if (a.left==b.left && a.right>b.right ) return true;
    return false;
}

bool operator<(segm a, segm b)
{
    if (a.left<b.left)return true;
    if (a.left==b.left && a.right<b.right ) return true;
    return false;
}

bool operator>=(segm a, segm b)
{
    return a.left>=b.left;
}

bool operator<=(segm a, segm b)
{
    return a.left<=b.left;
}

bool operator==(segm a, segm b)
{
    return (a.left==b.left && a.right==b.right);
}

bool operator!=(segm a, segm b)
{
    return !(a==b);
}
ostream& operator<<(ostream& s, const segm& x)
{
    s<<x.left<<" "<<x.right;
    return s;
}

istream& operator>>(istream& s, segm& x)
{
    x.left=next();
    x.right=next();
    return s;
}

segm snext()
{segm x; cin>>x; return x;}

class integer_set
{
public:
    integer_set() = default;

    void check()// ???????? ????????? ?? ???????????
    {
        sz=0;
        int i=0;
        segm last;
        bool fl=false, fl_=false, fl__=false;
        set<segm> lt;
        for (segm x: list_segm)
        {
            if (!x.empty())
            {
                if (i!=0)
                {
                    if (x.isIntersect(last))
                    {
                        segm fake(min(x.left, last.left), max(x.right, last.right));
                        last=fake;
                        fl=true;
                        continue;
                    }
                    if (x.left==last.right+1)
                    {
                        segm fake(min(x.left, last.left), max(x.right, last.right));
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
        list_segm=lt;
    }

    integer_set(const vector<int>& a)
    {
        for (int i=0; i<a.size(); i++)
        {
            segm x(a[i], a[i]);
            list_segm.insert(x);
        }
        check();
    }

    integer_set(const vector<segm>& a)
    {
        for (int i=0; i<a.size(); i++)
            list_segm.insert(a[i]);
        check();
    }

    void output1() const
    {
        for (segm x: list_segm)
           x.output();
    }

    void output2() const
    {
        for (segm x: list_segm)
            for (int j=x.left; j<=x.right; j++)
                cout<<j<<" ";
    }

    bool empty() const
    {
        return list_segm.empty();
    }

    int count(int x)
    {
        list_segm.insert(segm(INF, INF)); // ??? ????????? ?????? upper_bound
        segm _x(x, x);
        segm ub=*(list_segm.upper_bound(_x));
        int ans=0;
        if (ub.isInto(x)) ans=1;
        ub=*(--list_segm.upper_bound(_x));
        if (ub.isInto(x)) ans=1;
        list_segm.erase(segm(INF, INF));
        return ans;
    }

    segm find(int x)
    {
        list_segm.insert(segm(INF, INF)); // ??? ????????? ?????? upper_bound
        segm _x(x, x);
        segm ans(0, -1);
        segm ub=*(list_segm.upper_bound(_x));
        if (ub.isInto(x)) ans=ub;
        ub=*(--list_segm.upper_bound(_x));
        if (ub.isInto(x)) ans=ub;
        list_segm.erase(segm(INF, INF));
        return ans;
    }

    int count(const segm& x)
    {
        if (x.empty()) return 0;
        list_segm.insert(segm(INF, INF)); // ??? ????????? ?????? upper_bound
        int ans=0;
        segm ub=*(list_segm.upper_bound(x));
        if (ub.isInto(x)) ans=1;
        ub=*(--list_segm.upper_bound(x));
        if (ub.isInto(x)) ans=1;
        list_segm.erase(segm(INF,INF));
        return ans;
    }

    segm find(const segm& x)
    {
        segm ans(0, -1);
        if (x.empty()) return ans;
        list_segm.insert(segm(INF, INF)); // ??? ????????? ?????? upper_bound
        segm ub=*(list_segm.upper_bound(x));
        if (ub.isInto(x)) ans=ub;
        ub=*(--list_segm.upper_bound(x));
        if (ub.isInto(x)) ans=ub;
        return ans;
    }

    void push(const segm& x)
    {
        if (x.empty()) return;
        list_segm.insert(segm(INF, INF)); // ??? ????????? ?????? upper_bound
        list_segm.insert(segm(_INF, _INF));
        segm left=find(x.left), right=find(x.right);
        if (count(left)>0)
        {
            list_segm.erase(left);
            sz-=left.size();
        }
        if (count(right)>0)
        {
            list_segm.erase(right);
            sz-=right.size();
        }
        int l_b=x.left, r_b=x.right;//?????? ??? ???????????? ? ????????, ??? ????? ????????
        set<segm> :: iterator it=list_segm.lower_bound(segm(x.left, x.left));
        set<segm> :: iterator it_=--list_segm.lower_bound(segm(x.right+1, x.right+1));
        if (!left.empty()) l_b=left.left;
        if (!right.empty()) r_b=right.right;
        while (*it<=*it_)
        {
            segm _x=(*it);
            if (count(_x)>0  && x.isInto(_x))
            {
                sz-=_x.size();
                list_segm.erase(_x);
            }
            it++;
        }
        //????? ???????? ?? ?????????
        segm L=*(--list_segm.lower_bound(segm(l_b, l_b)));
        segm R=*(list_segm.lower_bound(segm(r_b+1, r_b+1)));
        if (!L.empty() && L.right==l_b-1)
        {
            l_b=L.left;
            list_segm.erase(L);
            sz-=L.size();
        }
        if (!R.empty() && R.left==r_b+1)
        {
            r_b=R.right;
            list_segm.erase(R);
            sz-=R.size();
        }
        list_segm.insert(segm(l_b, r_b));
        sz+=r_b-l_b+1;
        list_segm.erase(segm(INF,INF));
        list_segm.erase(segm(_INF,_INF));
    }

    void push(int p)
    {
        push(segm(p, p));
    }

    void erase(int p)
    {
        if (count(p)>0)
        {
            segm x=find(p);
            list_segm.erase(x);
            pair<segm, segm> t = x.split(p);
            list_segm.insert(t.first);
            list_segm.insert(t.second);
            sz--;
        }
    }

    void erase(segm x)
    {
        if (x.empty()) return;
        list_segm.insert(segm(INF, INF)); // ??? ????????? ?????? upper_bound
        list_segm.insert(segm(_INF, _INF));
        segm left=find(x.left), right=find(x.right);
        if (count(left)>0)
        {
            list_segm.erase(left);
            sz-=left.size();
        }
        if (count(right)>0)
        {
            list_segm.erase(right);
            sz-=right.size();
        }
        segm push1(0,-1) , push2(0, -1);//?????? ??? ??? ???????? ?????? ???????? ? ??????? ?? ??? ? ???? ?? ???????
        if (!left.empty()) push1=segm(left.left, x.left-1);
        if (!right.empty()) push2=segm(x.right+1, right.right);
        set<segm> :: iterator it=list_segm.lower_bound(segm(x.left, x.left));
        set<segm> :: iterator it_=--list_segm.lower_bound(segm(x.right+1, x.right+1));
        while (*it<=*it_)
        {
            segm _x=(*it);
            if (x.isInto(_x))
            {
                sz-=_x.size();
                list_segm.erase(_x);
            }
            it++;
        }
        if (!push1.empty()) list_segm.insert(push1), sz+=push1.size();
        if (!push2.empty()) list_segm.insert(push2), sz+=push2.size();
        list_segm.erase(segm(INF,INF));
        list_segm.erase(segm(_INF,_INF));
    }

    integer_set unite(const integer_set& b) const
    {
        integer_set ans;
        ans.sz=sz;
        ans.list_segm=list_segm;
        for (segm x: b.list_segm)
            (ans.list_segm).insert(x);
        ans.check();
        return ans;
    }

    integer_set minus(const integer_set& b) const
    {
        integer_set ans;
        ans.sz=sz;
        ans.list_segm=list_segm;
        for (segm x: b.list_segm)
            ans.erase(x);
        return ans;
    }

    integer_set intersection(const integer_set& b) const
    {
        integer_set ans;
        ans.sz=sz;
        ans.list_segm=list_segm;
        return ans.minus(ans.minus(b));
    }

    bool isInto(const integer_set& b)
    {
        for (segm x: b.list_segm)
            if (count(x)==0) return false;
        return true;
    }

    int size() const
    {
        return sz;
    }

    void output()
    {
        int i=0;
        for (segm x:list_segm)
        {
            if (i!=list_segm.size()-1)
                if (x.left!=x.right) cout<<x.left<<"-"<<x.right<<",";
                    else cout<<x.left<<",";
            else
                if (x.left!=x.right) cout<<x.left<<"-"<<x.right<<"";
                    else cout<<x.left<<"";
            i++;
        }
    }

    set<segm> list_segm;
    int sz=0;
};

int main()
{
    ios::sync_with_stdio(false);
    string s;
    getline(cin, s);
    vector<int> num;
    int n=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]!=',')
        {
            n*=10;
            n+=s[i]-'0';
        }
        else
        {
            num.pb(n);
            n=0;
        }
    }
    num.pb(n);
    integer_set pages(num);
    pages.output();
}
