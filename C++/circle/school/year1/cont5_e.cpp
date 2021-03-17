#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
    vector<int> a;
    int n=next();
    for (int i=0; i<n; i++)
    {
        int x=next();
        a.pb(x);
    }
    sort(a.begin(), a.end());
    vector<int> pw2;
    lint x=1;
    while (x<1e9)
    {
        pw2.pb(x);
        x*=2;
    }
    lint ans=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<pw2.size(); j++)
        {
            int key=pw2[j]-a[i];
            bool flag = false;
            int l = 0; // левая граница
            int r = n-1; // правая граница
            int mid=-1e9-1;

            while ((l <= r) && (!flag))
            {
                mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]
                if (a[mid] == key) flag = true; //проверяем ключ со серединным элементом
                if (a[mid] > key) r = mid - 1; // проверяем, какую часть нужно отбросить
                else l = mid + 1;
            }
            if (mid!=i && mid!=-1e9-1 && flag)
            {
                ans++;
            }
        }
    }
    cout<<ans;
}

