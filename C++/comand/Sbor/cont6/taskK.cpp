#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

//#define int int64_t

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i ++){
        s[i] = tolower(s[i]);
    }

    s += '$';
    unordered_set<char> gl;
    gl.insert('a');
    gl.insert('e');
    gl.insert('i');
    gl.insert('o');
    gl.insert('u');
    gl.insert('y');
    int cnt = 0;
    bool fl = false;
    int k2 = 0, k3 = 0;
    for (int i = 0; i < s.size(); i ++){
        if (gl.count(s[i]) > 0){
            if (!fl) fl = true;
            cnt ++;
        }
        else{
            if (cnt == 2) k2 ++;
            if (cnt == 3) k3 ++;
            cnt = 0;
            fl = false;
        }
    }
    cout << k2 << " " << k3;

}
/*



*/

