#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

#define watch(x) cout << (#x) << " is " << (x) << endl

typedef long long lint;

using namespace std;

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    map<int, int> chem1, chem2;
    int n=next();
    for (int i=0; i<n; i++)
    {
        int el=next(), mon=next();
        chem1[el]=mon;
    }
    int m=next();
    for (int i=0; i<m; i++)
    {
        int el=next(), mon=next();
        chem2[el]=mon;
    }
    lint sum=0;
    set<int> was;
    for (auto a:chem1)
    {
        int e1=a.first, m1=a.second;
        sum+=max(m1, chem2[e1]);
        was.insert(e1);
    }
    for (auto a:chem2)
    {
        int e1=a.first, m1=a.second;
        if (was.count(e1)==0) sum+=max(m1, chem2[e1]);
    }
    cout<<sum;
}

