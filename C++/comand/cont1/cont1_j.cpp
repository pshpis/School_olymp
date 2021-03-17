#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <deque>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++i)
#define fs first
#define sc second

//#define DBG_in
//#define DBG_out

typedef long long lint;

const int INF=2e9;
const lint INF64=1e18;
const double PI=3.14159265359;
const double EPS=1e-9;
const int MOD=1e9+7;

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
    cin.tie(0);
    cout.tie(0);

    #ifdef DBG_in
        freopen("in.txt", "r", stdin);
    #endif // DEBAG_in
    #ifdef DBG_out
        freopen("out.txt", "w", stdout);
    #endif // DEBAG_out

    int n=next();
    deque<int> a1, a2;
    map<int, int> p1, p2;
    for (int i=0; i<n; i++){
        int x=next();
        a1.pb(x);
        p1[x]=i;
    }
    for (int i=0; i<n; i++){
        int x=next();
        a2.pb(x);
        p2[x]=i;
    }

    for (int i=0; i<n; i++){
        if (a2[(p1[1]+i)%n]<5 || a1[(p2[1]+i)%n]<5){
            cout<<min(a1[(p2[1]+i)%n],a2[(p1[1]+i)%n])<<" 1\n";
        }
        else{
            if (a2[(p1[2]+i)%n]==2 || a1[(p2[2]+i)%n]==2)
                cout<<4<<" 2\n";
            else cout<<5<<" 3\n";
        }

        int f=a2.back();
        a2.pop_back();
        a2.push_front(f);
    }
}

