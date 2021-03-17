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

/*map<string, int> popular;

class name
{
public:
    string str;
    name()=default;
    name(string s)
    {
        str=s;
    }

    bool operator ==(name b)
    {
        return popular[b]==popular((*this).str);
    }

    bool operator >(name b)
    {
        return popular[b.str]<popular((*this).str);
    }

    bool operator <(name b)
    {
        return popular[b.str]>popular((*this).str);
    }

    bool operator >=(name b)
    {
        return !((*this)<b);
    }

    bool operator <=(name b)
    {
        return !((*this)>b);
    }

    char operator [](int i)
    {
        return str[i];
    }

    ostream& operator<<(ostream& s)
    {
        s<<str;
        return s;
    }

    istream& operator>>(istream& s_)
    {
        cin>>str;
        return s_;
    }
};*/
int main()
{
    ios::sync_with_stdio(false);
    /*int n=next();
    set<string> animal;
    map<string, set<name>> animal_name;
    for (int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        animal.insert(s);
        int k=next();
        for (int j=0; j<k; j++)
        {
            name x;
            cin>>x;
            animal_name[s].insert(x)
        }
    }
    while (animal.size()>1)
    {

    }*/
    /*set<string>:: iterator it;
    set<string>:: iterator it_1;
    int n=next();
    set<string> name;
    map<string, set<string> > feature;
    for(int i=0; i<n; i++)
    {
        string nm;
        cin>>nm;
        name.insert(nm);
        int k=next();
        for (int j=0; j<k; j++)
        {
            string ft;
            cin>>ft;
            feature[nm].insert(ft);
        }
    }
    lint ans=0;
    while (name.size()>1)
    {
        map<string, int> popular;
        int max_pop=-1e9-7;
        string pop_feat;
        for (it=name.begin(); it!=name.end(); it++)
        {
            string nm=*it;
            for (it_1=feature[nm].begin(); it_1!=feature[nm].end(); it_1++)
            {
                popular[*it_1]++;
                max_pop=max(max_pop, popular[*it_1]);
                if (max_pop==popular[*it_1]) pop_feat=*it_1;
            }
        }
        vector<string> er;
        for (it=name.begin(); it!=name.end(); it++)
        {
            string nm=*it;
            if (feature[nm].count(pop_feat)==0)
            {
                er.pb(nm);
            }
            else
            {
                feature[nm].erase(pop_feat);
            }
        }
        for (int i=0; i<er.size(); i++)
        {
            name.erase(er[i]);
        }
        ans++;
    }

    cout<<ans;*/
    int n=next();
    vector<set<string> > feat(n);
    for (int i=0; i<n; i++)
    {
        string fake;
        cin>>fake;
        int k=next();
        for (int j=0; j<k; j++)
        {
            string f;
            cin>>f;
            feat[i].insert(f);
        }
    }

    set<string> :: iterator it;
    lint mx=-1;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
        {
            lint cnt=0;
            for (it=feat[i].begin(); it!=feat[i].end(); it++)
                cnt+=feat[j].count(*it);
            mx=max(mx, cnt);
        }
    cout<<mx+1;



}
/*
4
A 2 a b
B 3 q w e
C 5 q a c d e
D 4 d a b q

4
bird 2 flies makesmilk
cow 4 eatsgrass isawesome makesmilk goesmoo
sheep 1 eatsgrass
goat 2 eatsgrass eatsworms
*/
