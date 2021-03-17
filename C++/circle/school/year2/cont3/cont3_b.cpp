#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int int64_t
#define pb push_back
#define mp make_pair
#define watch(x) cout << (#x) << " is " << (x) << endl

int next()
{int x; cin>>x; return x;}

int n, q;
vector<int> a, d_min, d_max;
int k;
int s;
int mod_1=12345, mod_2=23456;
vector<multiset<int> > cut;

void make_d(){
    d_min=vector<int>(k, 1e18);
    d_max=vector<int>(k, -1e18);
    for (int i=0; i<n; i++){
        d_min[i/s]=min(d_min[i/s], a[i]);
        d_max[i/s]=max(d_max[i/s], a[i]);
        cut[i/s].insert(a[i]);
    }
}

void change(int pl, int v){
    cut[pl/s].erase(a[pl]);
    a[pl]=v;
    cut[pl/s].insert(a[pl]);
    d_min[pl/s]=*cut[pl/s].begin();
    multiset<int>:: iterator it=cut[pl/s].end();
    it--;
    d_max[pl/s]=*it;
}

pair<int, int> res(int l, int r){
    int it=l/s;
    int ans_left_min=1e18, ans_left_max=-1e18;
    if (r-l<=s){
        int ans_min=1e18, ans_max=-1e18;
        for (int i=l; i<=r; i++){
            ans_min=min(ans_min, a[i]);
            ans_max=max(ans_max, a[i]);
        }
        return mp(ans_min, ans_max);
    }
//    cout<<"YES"<<endl;
    if (l%s!=0){
        for (int i=l; i<(l/s)*s+s; i++){
            ans_left_min=min(ans_left_min, a[i]);
            ans_left_max=max(ans_left_max, a[i]);
        }
        it++;
    }
//    cout<<"YES"<<endl;
    int ans_min=1e18, ans_max=-1e18;
    while ((it+1)*s<r){
        ans_min=min(d_min[it], ans_min);
        ans_max=min(d_max[it], ans_max);
        it++;
    }

    int ans_right_min=1e18, ans_right_max=-1e18;
    for (int i=(it)*s; i<=r; i++){
        ans_right_min=min(a[i], ans_right_min);
        ans_right_max=max(a[i], ans_right_max);
    }
//    watch(it);
//    watch(ans);
//    watch(ans_right);
//    watch(ans_left);
    watch(ans_max);
    watch(ans_left_max);
    watch(ans_right_max);
    watch(ans_min);
    watch(ans_left_min);
    watch(ans_right_min);

    ans_min=min(ans_left_min, ans_min);
    ans_min=min(ans_right_min, ans_min);
    ans_max=max(ans_left_max, ans_max);
    ans_max=max(ans_right_max, ans_max);
    return mp(ans_min, ans_max);
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
    cout<<"This is d_min"<<endl;
    for (int i=0; i<d_min.size(); i++)
        cout<<d_min[i]<<" ";
    cout<<"This is d_max"<<endl;
    for (int i=0; i<d_max.size(); i++)
        cout<<d_max[i]<<" ";
    cout<<endl;

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    n=1e5+100;
    q=next();
    s=sqrt(n);
    k=(n+s-1)/s;
    cut=vector<multiset<int> >(k);
    for (int i=1; i<=n; i++){
        a.pb(i*i%mod_1+i*i*i%mod_2);
    }
//    for (int i=n; i<k*s; i++) a.pb(0);
    make_d();
//    DBG();
    for (int i=0; i<q; i++){
        int x=next(), y=next();
        if (x>0){
            auto ans=res(x-1, y-1);
            watch(ans.second);
            watch(ans.first);
            cout<<ans.second-ans.first<<"\n";
        }
        if (x<0){
            change(-x-1, y);
        }
    }
//    DBG();
}
