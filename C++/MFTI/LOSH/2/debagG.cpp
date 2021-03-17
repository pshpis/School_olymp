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
#define fr(i, n) for (int (i)=0; i<int(n); i++)

const bool isDbg=false;


const int _INF=-1e9-7;
const int INF=1e9+7;

typedef long long lint;

using namespace std;

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
//                    if (x.left==last.right+1)
//                    {
//                        Segm<type> fake(min(x.left, last.left), max(x.right, last.right));
//                        last=fake;
//                        fl_=true;
//                        continue;
//                    }
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

    int set_size() const
    {
        return list_Segm.size();
    }

    set<Segm<type> > list_Segm;
    int sz=0;
};

vector<int> z_func(string s){
    int n = s.size();
    vector<int> z(n, 0);
    z[0]=n;
    int l=0, r=0;
    for (int i=1; i<n; i++){
        z[i]=0;
        if (i<=r) z[i]=min(z[i-l], r-i+1);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
        if (i+z[i]-1>r){
            r=i+z[i]-1;
            l=i;
        }
    }
    return z;
}

vector<int> z_func(vector<int> s){
    int n = s.size();
    vector<int> z(n, 0);
    z[0]=n;
    int l=0, r=0;
    for (int i=1; i<n; i++){
        z[i]=0;
        if (i<=r) z[i]=min(z[i-l], r-i+1);
        while (i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
        if (i+z[i]-1>r){
            r=i+z[i]-1;
            l=i;
        }
    }
    return z;
}

vector<int> p_func(string s){
    int n=s.size();
    vector<int> p(n, 0);

    int c=0;
    for (int i=1; i<n; i++){
        while(c>0 && s[i]!=s[c])
            c=p[c-1];
        if (s[i]==s[c])
            ++c;
        p[i]=c;
    }
    return p;
}

const lint mod =1e9+7;
const lint p=267;
vector<lint> pow_p;

void make_p(lint n){
    pow_p.push_back(1);
    for (int i=1; i<n; i++)
        pow_p.push_back((pow_p[i-1]*p)%mod);
}

lint myhash(vector<lint>& s){
    lint ans=0;
    int n=s.size();
    for (int i=0; i<n; i++){
        ans+=(s[i]*pow_p[n-i-1])%mod;
        ans%=mod;
    }
}

vector<lint> pref_hash(vector<int>& s){
    lint n=s.size();
    vector<lint> h(n+1, 0);
    for (int i=1; i<=n; i++)
        h[i]=((h[i-1]*p)%mod+(lint)s[i-1])%mod;
    return h;
}

lint substr_hash(lint l, lint r, vector<lint>& h){
    return (h[r+1]-((lint)h[l]*pow_p[r-l+1])%mod+mod)%mod;
}

void transp_matrix(vector<vector<int>>& t, vector<vector<int>>& result)
{
    result.clear();
    result=vector<vector<int>>(t[0].size(), vector<int>(t.size(), 0));
    for (int i=0; i<t[0].size(); i++)
        for (int j=0; j<t.size(); j++)
            result[i][j]=t[j][i];
}

vector<int> find_pal(vector<int>& s){
    vector<int> fake;
    for (int i=0; i<s.size(); i++){
        fake.push_back(-1);
        fake.push_back(s[i]);
    }
    fake.push_back(-1);
    s=fake;
    int n=s.size();
    vector<int> m(n, 0);
    int l=0, r=0;
    for (int i=0; i<n; i++){
        if (i<=r) m[i]=min(r-i+1, m[l+r-i]);
        while (i-m[i]>=0 && i+m[i]<n && s[i-m[i]]==s[i+m[i]])
            m[i]++;
        if (i+m[i]-1>r){
            r=i+m[i]-1;
            l=i-m[i]+1;
        }
    }
    for (int i=0; i<n; i++) m[i]--;
    return m;
}

pair<pair<int, int>, int> make_ivent(int l, int len, int r){
    pair<pair<int, int>, int> ans;
    (ans.first).first=l;
    (ans.first).second=len;
    (ans.second)=r;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputG.txt", "r", stdin);
    string s_;
    getline(cin, s_);
    if (s_.size()==0){
        cout<<0<<endl;
        return 0;
    }
    if (s_.size()==1)
    {
        cout<<0;
        return 0;
    }
    cout<<"---------"<<endl;
    vector<int> s;
    for (int i=0; i<s_.size(); i++)
        s.push_back(s_[i]-'a');
    vector<int> mun=find_pal(s);
    lint sum_mun=0;
    vector<pair<int, int> > ivent;
    set<pair<int, int>> set_ivents;
    int cnt=0;
    bool fl=false;
    for (int i=0; i<mun.size(); i++){
        sum_mun+=(mun[i]+1)/2;
        if (mun[i]<=0) continue;
        fl=true;
        int l=i-mun[i]+1;
        int r=i+mun[i]-1;
        int len=r-l+1;
        ivent.push_back({l, r});
        set_ivents.insert({l, r});
        watch(i);
        watch(l);
        watch(r);
        cout<<"---------"<<endl;
        cnt++;
    }
    if (!fl){
        cout<<0;
        return 0;
    }
    pair<int, int> left;
    cnt=0;
    int y=0;
    for (auto val: set_ivents){
        watch(val.first);
        watch(val.second);

        if (cnt==0){
            left=val;
            cnt++;
            y++;
            continue;
        }
        if (val.first==left.first){
            if (val.second>=left.second){
                left=val;
            }
        }
        else
        if (val.second>left.second) left=val, y++;
        cout<<"Left in the end"<<endl;
        watch(left.first);
        watch(left.second);
        cout<<"---------"<<endl;
        cnt++;
    }
//    for (auto val:set_ivents){
//        int type=val.second;
//        int i=(val.first).second;
//        int bord=(val.first).first;
//        if (cnt==0) {
//                left=ivent[i];
//                continue;
//        }
//        if (type==0){
//            if (bord==left.first){
//                if (left.second<ivent[i].second){
//                    y++;
//                    left=ivent[i];
//                }
//            }
//            if (ivent[i].second>left.second){
//                left=ivent[i];
//            }
//        }
//    }
    cout<<"This is s"<<endl;
    for (int i=0; i<s.size(); i++)
        cout<<s[i]<<" ";
    cout<<endl<<"------------------"<<endl;
    cout<<"This is mun"<<endl;
    for (int i=0; i<mun.size(); i++)
        cout<<mun[i]<<" ";
    cout<<endl<<"------------------"<<endl;
    watch(sum_mun);
    watch(y);
    cout<<"------------------"<<endl;
    cout<<sum_mun-y;
}

