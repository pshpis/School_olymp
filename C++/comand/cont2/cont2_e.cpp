#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair

int main(){
    int n, m;
    cin>>n>>m;
    set<pair<int, int> > z;
    vector<vector<int> > t(n+2, vector<int>(m+2, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            char x;
            cin>>x;
            if (x=='*'){
                t[i+1][j+1]=1;
                z.insert(mp(i+1, j+1));
            }
        }
    }
//    cout<<"YES"<<endl;
    int ans=0;
    while (!z.empty()){
//        cout<<"YES"<<endl;
        auto el=*z.begin();
        int x=el.first, y=el.second;
//        watch(x);
//        watch(y);
        int up=0, down=0, left=0, right=0;
        while (!(t[x][y-1]==1 && t[x][y+1]==1)){
            z.erase(mp(x, y));
            up++;
            x++;
//            watch(x);
//            watch(y);
        }
//        cout<<"YES"<<endl;
        // now x and y is center
        pair<int, int> m={x, y};
//        watch(m.first);
//        watch(m.second);
        while (t[x][y-1]==1){
            y--;
            z.erase(mp(x, y));
            left++;
        }
//        cout<<"YES"<<endl;
        y=m.second;
        while (t[x][y+1]==1){
            y++;
            z.erase(mp(x, y));
            right++;
        }
//        cout<<"YES"<<endl;
        y=m.second;
        x=m.first;
        while (t[x+1][y]==1){
            x++;
            z.erase(mp(x, y));
            down++;
        }
//        cout<<"YES"<<endl;
        z.erase(m);
//        watch(up);
//        watch(down);
//        watch(left);
//        watch(right);
        if (up==down && down==left && left==right) ans++;
    }
    cout<<ans;
}

