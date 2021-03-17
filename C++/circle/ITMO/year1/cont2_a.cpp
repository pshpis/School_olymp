#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
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

int main()
{
    int n=next();
    /*int x1=next(), y1=next();
    int x2=next(), y2=next();
    for (int i=2; i<n; i++)
    {
        int x3=next(), y3=next();
        int x1_=x1-x2;
        int y1_=y1-y2;
        int x3_=x3-x2;
        int y3_=y3-y2;
        double cos=(x1_*x3_*1.0+y1_*y3_*1.0)*1.0/(sqrt(x1_*x1_*1.0+y1_*y1_*1.0)*sqrt(x3_*x3_*1.0+y3_*y3_*1.0));
        double sin=sqrt(1.0-cos*cos);
        if (sin<0)
        {
            cout<<"NO";
            return 0;
        }
        x1=x2;
        y1=y2;
        x2=x3;
        y2=y3;
    }*/
    vector<pair<int, int> > point;
    for (int i=0; i<n; i++)
    {
        int x=next();
        int y=next();
        point.push_back(pair<int, int>{x, y});
    }
    int x1=point[0].first, y1=point[0].second;
    int x2=point[1].first, y2=point[1].second;
    int x3=point[2].first, y3=point[2].second;
    int x1_=x1-x2;
    int y1_=y1-y2;
    int x3_=x3-x2;
    int y3_=y3-y2;
    bool fl=(x1_*y3_-y1_*x3_>0);

    for (int i=2; i<n; i++)
    {
        int x3=point[i].first, y3=point[i].second;
        int x1_=x1-x2;
        int y1_=y1-y2;
        int x3_=x3-x2;
        int y3_=y3-y2;
        if (x1_*y3_-y1_*x3_>0 != fl)
        {
            cout<<"NO";
            return 0;
        }
        x1=x2;
        y1=y2;
        x2=x3;
        y2=y3;
    }

    x3=point[0].first, y3=point[0].second;
    x1_=x1-x2;
    y1_=y1-y2;
    x3_=x3-x2;
    y3_=y3-y2;
    if (x1_*y3_-y1_*x3_>0 != fl)
    {
        cout<<"NO";
        return 0;
    }
    x1=x2;
    y1=y2;
    x2=x3;
    y2=y3;

    x3=point[1].first, y3=point[1].second;
    x1_=x1-x2;
    y1_=y1-y2;
    x3_=x3-x2;
    y3_=y3-y2;
    if (x1_*y3_-y1_*x3_>0 != fl)
    {
        cout<<"NO";
        return 0;
    }
    x1=x2;
    y1=y2;
    x2=x3;
    y2=y3;

    cout<<"YES";
}
