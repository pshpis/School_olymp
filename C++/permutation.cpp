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

bool NextSet(vector<int>& a)
{
    int n=a.size();
    int j=n-2;
    while (j!=-1 && a[j]>=a[j+1]) j--;
    if (j==-1) return false; // больше перестановок нет
    int k=n-1;
    while (a[j]>=a[k]) k--;
    swap(a[j], a[k]);
    int l=j+1, r=n-1; // сортируем оставшуюся часть последовательности
    while (l<r)
    swap(a[l++], a[r--]);
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    vector<int> q={0, 1, 2, 3, 4};
    while (NextSet(q)){
        for (int i=0; i<q.size(); i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
}

