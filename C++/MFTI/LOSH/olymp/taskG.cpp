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

lint obr(lint a){
    if (a==1) return 0;
    if (a==0) return 1;
    return -1;
}

void new_str(vector<lint>& old, vector<lint>& nw){
    for (int i=0; i<old.size(); i++)
        if (old[i]==1) nw.push_back(nw[i]);
        else nw.push_back(obr(nw[i]));
}

int main()
{
    ios::sync_with_stdio(false);
    int n=next();
    vector<int> first(n);
    for (int i=0; i<n; i++){
        char x= next<char>();
        first[i]=(x=='+');
    }

    vector<lint> old={first[n-1]};
    vector<lint> nw;
    for (int i=n-1; i>=0; i--){
        nw.clear();
        nw.push_back(first[i]);
        new_str(old, nw);
        old=nw;
    }
    for (int i=0; i<n; i++)
        if (old[i]) cout<<'+';
            else cout<<'-';
}

