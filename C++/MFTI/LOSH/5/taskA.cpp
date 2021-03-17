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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    string s;
    getline(cin, s);
    lint n=s.size();
    lint bal=0;
    vector<lint> b(n, 0);
    lint ans=0;
    for (lint i=0; i<n; i++){
        if (s[i]=='(') bal++;
        else bal--;
        b[i]=bal;
    }
    if (bal!=0){
        cout<<0<<endl;
        return 0;
    }

    lint mn=1e18;
    for (int i=0; i<n; i++){
        if (mn>b[i]){
            mn=b[i];
            ans=1;
        }
        else if (mn==b[i]) ans++;
    }
   cout<<ans;
}

