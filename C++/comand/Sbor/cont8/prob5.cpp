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
    //time_t C = time(0);


    const int maxln = 2000;

    int k , w,  q;
    cin >> k >> w;
    unordered_map<string , vector <string> > lst;
    unordered_map<string , vector <bitset<maxln> > > b;
    for (int i = 0; i < w; i ++){
        string s = "" , s1; cin >> s;
        //for (int e = 0; e < 2e3; e ++) s += 'a';
        s1 = s;
        bitset<maxln> a;
        for (int j = 0; j < s.size(); j ++){
            a[j] = (s[j] >= 'A' && s[j] <= 'Z');
            s[j] = tolower(s[j]);
        }

        lst[s].pb(s1);
        b[s].pb(a);
    }

    cin >> q;
    for (int i = 0; i < q; i ++){
        string s = ""; cin >> s;
        //for (int e = 0; e < 2e3; e ++) s += 'a';
        bitset<maxln> a;
        for (int j = 0; j < s.size(); j ++){
            a[j] = (s[j] >= 'A' && s[j] <= 'Z');
            s[j] = tolower(s[j]);
        }


        int ans = 0;
        int sz = b[s].size();
        for (int j = 0; j < sz; j ++){
            ans += ((b[s][j] ^ a).count()) <= k;
        }
        cout << ans << '\n';
    }

    //time_t D = time(0);

    //cout << D - C << '\n';

}
/*
0
1000
1000


2
5
theword
TheWord
THEWORD
thewordandsomeletters
theword
4
theword
The
theword
TheWordAndSomeLetters



*/
