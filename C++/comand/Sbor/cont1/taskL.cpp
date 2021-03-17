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

    int n;
    cin >> n;
    vector<bool> turn;
    //string s, s1, s2;
    vector <char> s(n*5) , s1(n*5) , s2(n*5);

    for (int i = 0; i < 5*n - 1; i ++){
        cin >> s[i];
        //cout << s[i] << '\n';
    }
    for (int i = 0; i < 5*n - 1; i ++){
        cin >> s1[i];
    }
    for (int i = 0; i < 5*n - 1; i ++){
        cin >> s2[i];
    }
    //cin >> s >> s1 >> s2;
//    getline(cin , s);
//    getline(cin , s1);
//    getline(cin , s2);
//    cout << s << ' ' << s1 << ' ' << s2 << endl;

    int cnt_lef_ev = 0, cnt_lef_lef = 0, cnt_lef_odd = 0, cnt_lef_righ = 0 ;
    int l = s.size();
    for (int i = 0; i < l; ++ i ){
        if (s[i] == '<') turn.pb(false);
        if (s[i] == '>') turn.pb(true);
    }

    for (int i = 0; i < n; ++i){
        if (!turn[i]){
            if (i < n/2) cnt_lef_lef++;
            else cnt_lef_righ++;
            if (i % 2 == 0) cnt_lef_ev++;
            else cnt_lef_odd++;
        }
    }
    int ans1 = n/2 - cnt_lef_odd + cnt_lef_ev, ans2 = n/2 - cnt_lef_ev + cnt_lef_odd,

    ans3 = n/2 - cnt_lef_lef + cnt_lef_righ, ans4 = n/2 - cnt_lef_righ + cnt_lef_lef;


    int ans = min( min(ans1, ans2) , min( ans3, ans4 ) );
    cout << ans << "\n";
}
/*
8
..@>.<@...<@.....@>...@>...@>.<@...<@..
=OO...OO=..OO=.=OO..=OO..=OO...OO=..OO=
./\.../\.../\.../\.../\.../\.../\.../\.



*/


