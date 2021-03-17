#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second

ll next(){ll x; cin >> x; return x;}

int n , x , y;
ll ans = 0;
vector <int> p;
vector <unordered_set <int> > to;

int get(int x){
    if (x != p[x]) p[x] = get(p[x]);
    return p[x];
}

void unite(int x , int y){
    x = get(x) , y = get(y);
    if (to[x].size() > to[y].size()) swap(x , y);
    for (auto t : to[x]){
        to[y].insert(get(t));
    }
    p[x] = y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> n >> m >> x >> y;
    p.resize(n);
    iota(p.begin() , p.end() , 0);

    while(m --> 0){
        int u = next() - 1 , v = next() - 1;

        if (x < y){
            ans += x;
            unite(u , v);
            continue;
        }


    }

}
/*



*/
