#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define l left()
#define r right()

typedef long long lint;
//typedef pair<int, int> segm;

using namespace std;

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
    // a1 is left border, a2 is right border
    segm(int _a1, int _a2)
    {
        a1=_a1;
        a2=_a2;
    }

    void output()
    {
        cout<<a1<<" "<<a2<<"\n";
    }

    int left()
    {
        return a1;
    }

    int right()
    {
        return a2;
    }

    bool isEmpty()
    {
        if (a1>=a2) return true;
        return false;
    }

    bool isInto(int p)
    {
        if (p>=a1 && p<a2) return true;
        else return false;
    }

    bool isInto(segm b)
    {
        if (a1>=a2) return false;
        if (a1<=b.left() && a2>=b.right()) return true;
        return false;
    }

    segm intersect(segm b)
    {
        segm ans(max(a1, b.left()), min(a2, b.right()));
        return ans;
    }

    bool isIntersect(segm b)
    {
        segm a(a1, a2);
        return !((a.intersect(b)).isEmpty());
    }

    pair<segm, segm> split(int p)
    {
        if (p<a1)
        {
            segm ans1(a1, p);
            segm ans2(a1, a2);
            return {ans1, ans2};
        }
        if (p>=a2)
        {
            segm ans1(a1, a2);
            segm ans2(p, a2);
            return {ans1, ans2};
        }
        segm ans1(a1, p);
        segm ans2(p, a2);
        return {ans1, ans2};
    }

    int min_div(int k)
    {
        for (int i=a1; i<a2; i++)
            if (i%k==0) return i;
        return -1;
    }

    int mx_pw2()
    {
        int ans=-1;
        for (int i=a1; i<a2; i++)
            ans=max(ans, max_pw2(i));
        return ans;
    }

    int a1, a2;
};

int main()
{
    ios::sync_with_stdio(false);
    int x=next(), y=next();
    segm a(x, y);
    //int x1=next(), y1=next();
    //segm b(x1, y1);
    //int k=next();
    cout<<a.mx_pw2();
}


