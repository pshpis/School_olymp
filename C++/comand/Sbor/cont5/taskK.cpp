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

    string s; cin >> s;
    int cntO = 0 , cntZ = 0 , cntS = 0 , cntB = 0;
    vector <int> cnt(26 , 0);
    int n = s.size();
    for (int i = 0; i < n; i ++){
        if (s[i] >= 'a' && s[i] <= 'z') {
            cnt[s[i] - 'a']++ , cntB++;
        }
        if (s[i] == '<') cntO++;
        if (s[i] == '>') cntZ++;
        if (s[i] == '/') cntS++;
    }

    if (cntO != cntZ || cntO / 2 != cntS || cntB < cntO){
        cout << "Impossible";
        return 0;
    }
    cntO /= 2;


    for (int i = 0; i < 26; i ++){
        if (cnt[i] % 2 == 1) {
            cout << "Impossible";
            return 0;
        }
    }

    string ans = "";
    int cur = 0;

    while(cntO--){
        if (cntO == 0){
            string add = "";
            for (int i = 0; i < 26; i ++){
                while(cnt[i]){
                    cnt[i] -= 2;
                    add += char(i + 'a');
                }
            }
            ans += "<" + add + ">" + "</" + add + ">";
            break;
        }

        while(cnt[cur] == 0) cur++;



        string add = "";
        add += char(cur + 'a');
        ans += "<" + add + ">" + "</" + add + ">";
        cnt[cur] -= 2;

    }

    cout << ans;

}
/*
<test></test>

test<tist>/<>

te<ste>st/<t>

<>test<>//<>test<>

*/

