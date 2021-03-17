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

const lint _INF=-1e9-7;
const lint INF=1e9+7;

lint next()
{lint x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

lint max_pw2(lint k)
{
    lint ans=0;
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
    segm(lint _left, lint _right)
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

    bool isInto(lint p) const
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

    pair<segm, segm> split(lint p) const
    {
        return {intersect(segm(_INF,p-1)), intersect(segm(p+1,INF))};
    }

    lint min_div(lint k) const
    {
        for (lint i=left; i<right; i++)
            if (i%k==0) return i;
        return -1;
    }

    lint mx_pw2() const
    {
        lint ans=-1;
        for (lint i=left; i<right; i++)
            ans=max(ans, max_pw2(i));
        return ans;
    }

    lint size() const
    {
        if (right-left+1>0) return right-left+1;
        return 0;
    }
    /*bool operator>= (segm b) {return left>=b.left;}
    bool operator== (segm b) {return ( left==b.left && right==b.right );}
    bool operator<= (segm b) {return left<=b.left;}*/

    //bool operator> (const segm& b) {return left>b.left;}
    //bool operator< (const segm& b) {return left<b.left;}
    lint left, right;
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

lint str_to_num(string s)
{
    lint result=0;
    for (lint i=0; i<s.size(); i++)
    {
        result*=10;
        result+=s[i]-'0';
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    segm byte_(-128, 127);
    segm short_(-32768, 32767);
    segm lint_(-2147483648, 2147483647);
    segm long_((lint)-9223372036854775808, (lint)9223372036854775807);
    string s;
    cin>>s;
    if (s.size()>19 || (s.size()==19 && s>"9223372036854775807"))
    {
        cout<<"BigInteger";
        return 0;
    }
    lint num=str_to_num(s);
    if (byte_.isInto(num)) cout<<"byte";
    else
    if (short_.isInto(num)) cout<<"short";
    else
    if (lint_.isInto(num)) cout<<"int";
    else
    if (long_.isInto(num)) cout<<"long";
}
