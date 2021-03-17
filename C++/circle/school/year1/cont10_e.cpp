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

lint next()
{lint x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

const lint INF=(1e9+7);
const lint _INF=0;
lint n;
vector<lint> tree;
vector<lint> num;
lint sum(lint x, lint y)
{
    return x+y;
}
void update(lint i)
{
    if (i==0) return;
    tree[i]=sum(tree[2*i], tree[2*i+1]);
    update(i/2);
}

void change(lint i, lint x)
{
    tree[i+n]=x;
    update((i+n)/2);
}

lint get(lint l, lint r, lint L, lint R, lint i)
{
    if (l<=L && R<=r) return tree[i];
    if (r<L || R<l) return 0;
    lint M=(L+R)/2;
    return sum(
        get(l, r, L, M, 2*i),
        get(l, r, M+1, R, 2*i+1)
    );
}

lint get_max(lint l, lint r)
{
    return get(l, r, 0, n-1, 1);
}


int main()
{
    ios::sync_with_stdio(false);

    n=next()-1;
    int sz=n;
    //watch(n);
    for (lint i=0; i<n; i++)
        num.pb(1);

    //make need length
    lint k2=1;
    while (k2<n)
        k2*=2;
    for (lint i=n; i<k2; i++)
        num.pb(_INF);
    n=k2;

    //build tree
    tree=vector<lint>(2*n, 0);
    for (lint i=n; i<2*n; i++)
        tree[i]=num[i-n];
    for (lint i=n-1; i>0; i--)
        tree[i]=sum(tree[2*i], tree[2*i+1]);
    /*for (lint i=1; i<2*n; i++)
        cout<<tree[i]<<" ";
    cout<<"\n";*/
//    //answer
//    int m=next();
//    for (lint i=0; i<m; i++)
//    {
//        lint type=next();
//        lint first=next()-1, second=next();
//        if (type==1)
//        {
//            change(first, second);
//            /*for (lint i=1; i<2*n; i++)
//                cout<<tree[i]<<" ";
//            cout<<"\n";*/
//        }
//        else
//        {
//            cout<<get_max(first, second-1)<<"\n";
//        }
//    }
    lint ans=0;
    //watch(n);
    for (int i=0; i<sz; i++)
    {
        int k=next()-1;
        char a;
        cin>>a;
        //cout<<"HERE"<<endl;
        if (a=='A')
        {
            ans+=get_max(0, k-1);
            change(k, 0);
            //cout<<"FIRST"<<endl;
        }
        if (a=='B')
        {
            ans+=get_max(k+1, n-1);
            change(k, 0);
            //cout<<"SECOND"<<endl;
        }
        //cout<<"THERE"<<endl;

    }
    cout<<ans<<endl;
    /*cout<<"\nNOW WE WILL START DEBAG\n";
    cout<<"\nThis is tree\n";
    for (lint i=1; i<2*n; i++)
        cout<<tree[i]<<" ";
    cout<<"\n";*/
}
