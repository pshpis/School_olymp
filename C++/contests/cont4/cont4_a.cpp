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
#define fr(i, n) for (int (i)=0; i<int(n); i++)

const bool isDbg=false;

typedef long long lint;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

void test()
{
    map<int, int> cell;
    int n=next();
    bool fl=false;
    for (int i=0; i<n; i++)
    {
        int x=next();
//        cout<<"NORM"<<endl;
        x=log2(x);
        if (x==11 && !fl){
            cout<<"YES"<<endl;
            fl=true;
        }
        cell[x]++;
    }
    if (fl) return;
    for (auto el: cell)
    {
        if (el.first==11 && el.second>0){
            cout<<"YES"<<endl;
            return;
        }
        cell[el.first+1]+=el.second/2;
        cell[el.first]=el.second%2;
        if (el.first>29) break;
    }
    for (auto el: cell)
    {
        if (el.first==11 && el.second>0){
            cout<<"YES"<<endl;
            return;
        }
        if (el.first>29) break;
    }
    cout<<"NO"<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("in.txt", "r", stdin);
    int q=next();
    for (int i=0; i<q; i++){
        test();
    }

}

/*
6
4
1024 512 64 512
1
2048
3
64 512 2
2
4096 4
7
2048 2 2048 2048 2048 2048 2048
2
2048 4096
*/

