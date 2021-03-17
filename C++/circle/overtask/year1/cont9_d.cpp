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

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

int main()
{
    ios::sync_with_stdio(false);
    //cout<<true<<endl;
    int n=next(), m=next();
    vector<vector<bool> > table(n, vector<bool>(m, false));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            char x;
            cin>>x;
            if (x=='.') table[i][j]=true;
        }
    vector<vector<int> > ver_domino(n, vector<int>(m, 0));
    vector<vector<int> > str_domino(n, vector<int>(m, 0));

    for (int j=0; j<m; j++)
        for (int i=1; i<n; i++)
        {
            ver_domino[i][j]=ver_domino[i-1][j];
            if (table[i][j] && table[i-1][j]) ver_domino[i][j]++;

        }
    for (int i=0; i<n; i++)
        for (int j=1; j<m; j++)
        {
            str_domino[i][j]=str_domino[i][j-1];
            if (table[i][j-1] && table[i][j]) str_domino[i][j]++;
        }

//    cout<<"VERTICAL"<<endl;
//    for (int i=0; i<n; i++)
//    {
//        for (int j=0; j<m; j++)
//            cout<<ver_domino[i][j]<<" ";
//        cout<<endl;
//    }
//    cout<<"HORIZONTAL"<<endl;
//    for (int i=0; i<n; i++)
//    {
//        for (int j=0; j<m; j++)
//        {
//            cout<<str_domino[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//
//    watch(table[3][6]);
//    watch(table[2][6]);
//    watch(table[3][5]);
//    watch(ver_domino[3][6]);
//    watch(ver_domino[2][6]);
//    watch(str_domino[3][3]);
//    watch(str_domino[3][5]);
    int k=next();
    for (int i=0; i<k; i++)
    {
        int x1=next()-1, y1=next()-1, x2=next()-1, y2=next()-1;
        lint ans=0;
        for (int i=x1; i<=x2; i++)
            ans+=str_domino[i][y2]-str_domino[i][y1];
        for (int j=y1; j<=y2; j++)
            ans+=ver_domino[x2][j]-ver_domino[x1][j];
        cout<<ans<<endl;
    }
}

