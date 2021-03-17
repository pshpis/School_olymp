#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <cmath>

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

lint nod(lint x, lint y)
{
	if (y==0 || x == 0)
		return x + y;
	return nod(y, x%y);
}

lint nok(lint x, lint y)
{
    lint ans=x*y/nod(x, y);
    return ans;
}

class Fraction
{
public:

    Fraction()=default;

    void check()
    {
        lint nd=nod(p, q);
        p/=nd;
        q/=nd;
        if (q<0)
        {
            p=-p;
            q=-q;
        }
    }

    Fraction(lint x, lint y=1)
    {
        p=x;
        q=y;
        check();
    }

    Fraction obr() const
    {
        return Fraction(q, p);
    }

    bool isInteger() const
    {
        return (q==1);
    }

    Fraction operator+(const Fraction& x) const
    {
        Fraction ans(p*x.q+q*x.p, q*x.q);
        return ans;
    }

    Fraction operator-(const Fraction& x) const
    {
        Fraction ans(p*x.q-q*x.p, q*x.q);
        return ans;
    }

    Fraction operator+=(const Fraction& x)
    {
        p=p*x.q+q*x.p;
        q*=x.q;
        check();
        return Fraction(p, q);
    }

    Fraction operator-=(const Fraction& x)
    {
        p=p*x.q-q*x.p;
        q*=x.q;
        check();
        return *this;
    }

    Fraction operator*(const Fraction& x) const
    {
        Fraction ans(p*x.p, q*x.q);
        return ans;
    }

    Fraction operator/(Fraction& x) const
    {
        return (*this)*x.obr();
    }

    bool operator==(const Fraction& x) const
    {
        return (p==x.p && q==x.q);
    }

    bool operator>(const Fraction& x) const
    {
        return p*x.q>q*x.p;
    }

    bool operator<(const Fraction& x) const
    {
        return x>*this;
    }

    lint p;
    lint q;
};

ostream& operator<<(ostream& s, const Fraction& x)
{
    if (x.p!=0) s<<x.p<<"/"<<x.q;
    else s<<0;
    return s;
}

istream& operator>>(istream& s, Fraction& x)
{
    x.p=lnext();
    char fake;
    cin>>fake;
    x.q=lnext();
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    Fraction f1;
    cin>>f1;
    Fraction f2;
    cin>>f2;
    cout<<f1+f2;
}
