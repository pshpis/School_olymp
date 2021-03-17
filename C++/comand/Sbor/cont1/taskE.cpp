#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll red, bl, any;
    ll nd_red, nd_bl, nd_any;

    cin >> red >> bl >> any;
    cin >> nd_red >> nd_bl >> nd_any;

    string ok = "It is a kind of magic\n";
    string bad = "There are no miracles in life\n";

    if (red >= nd_red) red -= nd_red;
    else{
        any -= nd_red - red;
        if (any < 0){
            cout << bad;
            return 0;
        }

        red = 0;
    }

    if (bl >= nd_bl) bl -= nd_bl;
    else{
        any -= nd_bl - bl;
        if (any < 0){
            cout << bad;
            return 0;
        }
        bl = 0;
    }

    any += bl + red;
    if (any >= nd_any) any -= nd_any;
    else{
        cout << bad;
        return 0;
    }
    cout << ok;
}
/*
3 3 1
2 2 1

5 6 5
6 5 6

20 20 0
10 10 20


*/
