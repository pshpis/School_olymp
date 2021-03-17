#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t, m;
    cin>>n>>t>>m;
    vector<unordered_set<int> > ex_p(t);
    vector<unordered_set<int> > p_ex(n);
    for (int i=0; i<m; i++){
        int p, ex;
        cin>>p>>ex;
        p--; ex--;
        ex_p[ex].insert(p);
        p_ex[p].insert(ex);
    }
    int mn_sz=1e9;
    int it_mn_sz=0;
    for (int i=0; i<t; i++){
        if (mn_sz>ex_p[i].size()){
            mn_sz=ex_p[i].size();
            it_mn_sz=i;
        }
    }
    unordered_set<int> members;
    for (int i=0; i<n; i++){
        if (ex_p[it_mn_sz].count(i)==0) members.insert(i);
    }
    unordered_set<int> tasks;
    for (int mem: members){
        for (int ex: p_ex[mem])
            tasks.insert(ex);
    }
    cout<<""<<members.size()<<" ";
    unordered_set<int> ans;
    ans.insert(it_mn_sz);
    for (int i=0; i<t; i++){
        if (tasks.count(i)==0) ans.insert(i);
    }
    cout<<ans.size()<<"\n";
    for (auto el: ans){
        cout<<el+1<<" ";
    }
}
/*
6 6 12
1 1
1 2
2 2
2 3
3 3
3 4
4 4
4 5
5 5
5 6
6 6
6 1

*/
