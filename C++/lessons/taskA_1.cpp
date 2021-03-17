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

typedef long long lint;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

class human
{
    public:
    human(bool _isFem, string _nick, int _year, bool _married)
    {
        isFemale=_isFem;
        nickname=_nick;
        year=_year;
        married=_married;
        if (isFemale)
            if (married)
                nickname="Mrs."+nickname;
            else nickname="Miss "+nickname;
        else nickname="Mr."+nickname;
    }

    int getAge(int currYear)
    {
        return currYear-year;
    }

    void output()
    {
        cout<<"Age: "<<getAge(2019)<<"\n";
        cout<<"Name: "<<nickname<<"\n";
        string mar="";
        if (married) mar="Yes";
        else mar="No";
        cout<<"Married: "<<mar<<"\n";
        string gen="";
        if (isFemale) gen="Female";
        else gen="Male";
        cout<<"Gender: "<<gen<<"\n";
        cout<<"Year of birth: "<<year<<"\n";
    }
    bool isFemale;
    string nickname;
    int year;
    bool married;
};

int main()
{
    ios::sync_with_stdio(false);
    human petr(false,"Petr", 2002, false);
    petr.output();
}

