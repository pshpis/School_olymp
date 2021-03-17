#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define mt make_triple

class triple{
public:
    int first;
    int second;
    int third;
    triple()=default;
    triple(int f, int s, int t){
        first=f;
        second=s;
        third=t;
    }
};

triple make_triple(int x, int y, int z){
    triple ans(x, y, z);
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<bool> have_chield(n, false);
    vector<vector<int> > parents(n);
    vector<pair<int, int> > marr;
    vector<triple> fam;
    vector<int> gender(n, 0);
    for (int i=0; i<m; i++){
        int t, x, y;
        cin>>t>>x>>y;
        x--;
        y--;
        if (t<4) fam.pb(mt(t, x, y));
        else marr.pb(mp(x, y));
    }
    for (auto el: fam){
        int t=el.first, x=el.second, y=el.third;
        have_chield[y]=true;
        if (t<3) gender[y]=t;
        parents[x].pb(y);
        if (parents[x].size()==2){
            marr.pb( mp(parents[x][0], parents[x][1]) );
        }
    }
    for (auto el: marr){
        int x=el.first, y=el.second;
        if (have_chield[y]) have_chield[x]=true;
        if (have_chield[x]) have_chield[y]=true;
        if (gender[x]!=0) gender[y]=3-gender[x];
        else if (gender[y]!=0) gender[x]=3-gender[y];
    }
    for (int i=0; i<n; i++){
        if (gender[i]==1) cout<<"f ";
        if (gender[i]==2) cout<<"m ";
        if (gender[i]==0) cout<<"? ";
        if (have_chield[i]) cout<<"+\n";
        else cout<<"-\n";
    }

}

