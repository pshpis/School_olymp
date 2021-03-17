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
    lint n =lnext();
    if (n==1){
        cout<<-1;
        return 0;
    }
    if (n==2){
        cout<<1<<" "<<1;
        return 0;
    }
    if (n==3){
        cout<<-1;
        return 0;
    }
    if (n==4){
        cout<<-1;
        return 0;
    }
    if (n==6){
        cout<<-1;
        return 0;
    }
    if (n%2==1){
        cout<<1<<" "<<n-1;
        return 0;
    }

    cout<<4<<" "<<n-4<<endl;
    //comment
}

