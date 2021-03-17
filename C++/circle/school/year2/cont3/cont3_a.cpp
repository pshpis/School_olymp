#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

#define int int64_t
#define pb push_back
#define watch(x) cout << (#x) << " is " << (x) << endl

int next()
{int x; cin>>x; return x;}

int n, q;
vector<int> a, d;
int k;
int s;

void make_d(){
    for (int i=0; i<n; i++){
        d[i/s]+=a[i];
    }
}

void change(int pl, int v){
    d[pl/s]-=a[pl];
    a[pl]=v;
    d[pl/s]+=v;
}

int sm(int l, int r){
    int it=l/s;
    int ans_left=0;
    if (r-l<=s){
        int ans=0;
        for (int i=l; i<=r; i++) ans+=a[i];
        return ans;
    }
//    cout<<"YES"<<endl;
    if (l%s!=0){
        for (int i=l; i<(l/s)*s+s; i++){
            ans_left+=a[i];
        }
        it++;
    }
//    cout<<"YES"<<endl;
    int ans=0;
    while ((it+1)*s<=r){
        ans+=d[it];
        it++;
    }
    int ans_right=0;
    for (int i=(it)*s; i<=r; i++){
        ans_right+=a[i];
    }
//    watch(it);
//    watch(ans);
//    watch(ans_right);
//    watch(ans_left);
    ans+=ans_left;
    ans+=ans_right;
    return ans;
}

void DBG(){
    watch(n);
    watch(q);
    watch(s);
    watch(k);
    cout<<"This is a"<<endl;
    for (int i=0; i<a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"This is d"<<endl;
    for (int i=0; i<d.size(); i++)
        cout<<d[i]<<" ";
    cout<<endl;

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    n=next();
    q=next();
    s=sqrt(n);
    k=(n+s-1)/s;
    d=vector<int>(k, 0);
    for (int i=0; i<n; i++){
        a.pb(next());
    }
    for (int i=n; i<k*s; i++) a.pb(0);
    make_d();
//    DBG();
    for (int i=0; i<q; i++){
        int fl=next(), l=next(), r=next();
        if (fl==0){
            cout<<sm(l-1, r-1)<<"\n";
        }
        else{
            change(l-1, r);
        }
    }
//    DBG();
}
