#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
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

int main()
{
    ios::sync_with_stdio(false);
    int n=next();
    map<char, int> color;
    for (int i=0; i<n; i++)
    {
        char x;
        cin>>x;
        color[x]++;
    }
    bool is_R=(color['R']>=1), is_B=(color['B']>=1), is_G=(color['G']>=1);
    if (is_R && is_B && is_G)
    {
        cout<<"BGR";
        return 0;
    }
    if ( (is_B && is_R) || (is_B && is_G) || (is_G && is_R) )
    {
        if (color['R']==0)
        {
            if (color['B']>1 && color['G']>1)
            cout<<"BGR";
            if (color['B']>1 && color['G']==1)
            cout<<"GR";
            if (color['B']==1 && color['G']>1)
            cout<<"BR";
            if (color['B']==1 && color['G']==1)
            cout<<"R";
            return 0;
        }
        if (color['B']==0)
        {
            if (color['R']>1 && color['G']>1)
            cout<<"BGR";
            if (color['R']>1 && color['G']==1)
            cout<<"BG";
            if (color['R']==1 && color['G']>1)
            cout<<"BR";
            if (color['R']==1 && color['G']==1)
            cout<<"B";
            return 0;
        }
        if (color['G']==0)
        {
            if (color['R']>1 && color['B']>1)
            cout<<"BGR";
            if (color['R']>1 && color['B']==1)
            cout<<"BG";
            if (color['R']==1 && color['B']>1)
            cout<<"GR";
            if (color['R']==1 && color['B']==1)
            cout<<"G";
            return 0;
        }
    }
    if (color['R']>0)
    {
        cout<<"R";
        return 0;
    }
    if (color['G']>0)
    {
        cout<<"G";
        return 0;
    }
    if (color['B']>0)
    {
        cout<<"B";
        return 0;
    }
}
