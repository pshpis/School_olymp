#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iterator>

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
    int z=next();
    for (int i=0; i<z; i++){
        int n=next();
        map<string, int> type_size;
        set<string> type;
        for (int j=0; j<n; j++){
            string nm, tp;
            cin>>nm>>tp;
            type_size[tp]++;
            type.insert(tp);
        }
        int k1=0;
        int cnt=0;
        for (val: type){
//            watch(val);
//            watch(type_size[val]);
            if (cnt==0){
                k1=type_size[val];
                cnt++;
                continue;
            }
            k1=k1*(type_size[val]+1)+type_size[val];
        }
        cout<<k1<<"\n";
    }
//    int t;
//    cin >> t;
//    vector <int> itog;
//    for (int q = 0;q < t;++q){
//        int n;
//        cin >> n;
//        map <string,int> z;
//        for (int buf = 0;buf < n;++buf){
//            string x,c;
//            cin >> x >> c;
//            z[c]++;
//        }
//
//    }
}
/*
1 6
d a
f b
z b
r c
l c
g c
*/
