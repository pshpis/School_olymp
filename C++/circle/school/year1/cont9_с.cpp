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

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

const lint INF=1e9+7;

int inv=0;

void Merger(vector<int>& a, int left, int right)
{
    vector<int> ans;
    if (left<=right) return;
    if (left==right-1)
    {
        if (a[left]>a[right])
        {
            inv++;
            swap(a[left], a[right]);
        }
        return;
    }
    int mid=(left+right)/2;
    int a_i=left, b_i=mid+1;

    //cout<<"I was here!!!"<<endl;
    while (ans.size()<right-left+1)
    {
        //cout<<"I was there!!!"<<endl;
        if (a_i==mid)
        {
            ans.pb(a[b_i]);
            b_i++;
            continue;
        }
        if (b_i==right)
        {
            ans.pb(a[a_i]);
            a_i++;
            continue;
        }
        if (a[a_i]>a[b_i])
        {
            inv++;
            ans.pb(a[b_i]);
            b_i++;
        }
        else
        {
            ans.pb(a[a_i]);
            a_i++;
            cout<<"I was here!!!"<<endl;
        }
    }
    for (int i=left; i<=right; i++)
        a[i]=ans[i-left];
}

void MergerSort(vector<int>& a, int left, int right)
{
    if (left<right)
    {
        MergerSort(a, left, (left+right)/2);
        MergerSort(a, (left+right+1)/2, right);
        Merger(a, left, right);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n=next();
    vector<int> a;
    for (int i=0; i<n; i++)
        a.pb(next());

    lint k2=1;
    while (k2<n)
        k2*=2;
    for (lint i=n; i<k2; i++)
        a.pb(INF);
    n=k2;

    MergerSort(a, 0, n-1);
    cout<<inv;
}
