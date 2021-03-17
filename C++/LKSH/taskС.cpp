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

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

const int _INF=-1e9-7;
const int INF=1e9+7;

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

vector<segm> type;

int type_vertex(int k)
{
    for (int i=0; i<type.size(); i++)
        if (type[i].isInto(k)) return i;
    return -1;
}

set<int> num_s;

int type_s(int k)
{
    int ans=0;
    set<int> :: iterator it;
    for (it=num_s.begin(); it!=num_s.end(); it++)
    {
        int el=*it;
        if (el==k) return ans;
        ans++;
    }
    return -2;
}

vector<vector<int> > gr;
vector<int> s;
set<int> way;
bool fl=false;

void dfs(int st, int i)
{
    if (fl) return;
    way.insert(st);
    if (i>=s.size())
    {
        fl=true;
        return;
    }
    for (int j=0; j<gr[st].size(); j++)
    {
        int v=gr[st][j];
        if (type_vertex(v)==type_s(s[i]) && way.count(v)==0)
            dfs(v, i+1);
    }
    way.erase(st);
    /*for (int j=0; j<rem.size(); j++)
        dfs(rem[j], i+1);*/
}

int main()
{
    string fake;
    cin>>fake;

    int n=fake.size();//string size
    int m=5;//table size

    for (int i=0; i<n; i++)
        s.pb(fake[i]-'A');

    for (int i=0; i<n; i++)
        num_s.insert(s[i]);

    vector<vector<int> > table(m);
    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
        {
            char x;
            cin>>x;
            table[i].pb(x-'A');
        }

    vector<pair<int, int> > vertex;

    int k=0;//vertex size

    set<int> :: iterator it;
    for (it=num_s.begin(); it!=num_s.end(); it++)
    {
        int el=*it;
        segm x(k, k);
        for (int i=0; i<m; i++)
            for (int j=0; j<m; j++)
                if (table[i][j]==el)
                {
                    vertex.push_back(pair<int, int>{i, j});
                    k++;
                }
        x.right=k-1;
        type.pb(x);
    }


    k=vertex.size();
    map<pair<int, int>, int> cell_vertex;
    for (int i=0; i<k; i++)
        cell_vertex[vertex[i]]=i;

    set<pair<int, int> > pair_s;
    for (int i=0; i<n-1; i++)
    {
        pair_s.insert(pair<int, int> {s[i], s[i+1]});
        pair_s.insert(pair<int, int> {s[i+1], s[i]});
    }

    gr=vector<vector<int> >(k);
    for (int i=0; i<m; i++)
        for (int j=0; j<m-1; j++)
        {
            pair<int, int> p={table[i][j], table[i][j+1]};
            if (pair_s.count(p)>0)
            {
                pair<int, int> first={i, j};
                pair<int, int> second={i, j+1};
                int first_vertex=cell_vertex[first];
                int second_vertex=cell_vertex[second];
                gr[first_vertex].pb(second_vertex);
                gr[second_vertex].pb(first_vertex);
            }
        }
    for (int i=0; i<m-1; i++)
        for (int j=0; j<m; j++)
        {
            pair<int, int> p={table[i][j], table[i+1][j]};
            if (pair_s.count(p)>0)
            {
                pair<int, int> first={i, j};
                pair<int, int> second={i+1, j};
                int first_vertex=cell_vertex[first];
                int second_vertex=cell_vertex[second];
                gr[first_vertex].pb(second_vertex);
                gr[second_vertex].pb(first_vertex);
            }
        }

    int type_st=type_s(s[0]);
    for (int i=0; i<k; i++)
        if (type_vertex(i)==type_st)
        {
            dfs(i, 1);
            if (fl)
            {
                cout<<"YES"<<endl;
                return 0;
            }
            way.clear();
        }
    cout<<"NO";
    /*vector<int> pr;
    vector<int> beg;
    for (int i=1; i<n; i++)
    {
        vector<int> new_rem;
        for (int j=0; j<rem.size(); j++)
            for (int v_i=0; v_i<gr[rem[j]].size(); v_i++)
            {
                int v=gr[rem[j]][v_i];
                if(type_vertex(v)==type_s(s[i]))
                {
                    new_rem.pb(v);
                }
            }
        rem=new_rem;
    }

    if (rem.size()>0) cout<<"YES";
    else cout<<"NO";*/
}
