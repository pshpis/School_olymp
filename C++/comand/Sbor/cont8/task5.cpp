#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define eb emplace_back
#define pw2(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second

//#define int int64_t

struct Node{
    unordered_map <int , int> next;
    int term;

    Node(){
        term = 0;
    }
};
int k , w , q;
unordered_map <char , int> to;

Node tree[int(2e6 + 2)];
int sz = 1;

string t;

char rev(char c){
    if (c == tolower(c)){
        c += 'A' - 'a';
    } else {
        c += 'a' - 'A';
    }
    return c;
}

int ans = 0;
void dfs(int i , int pos , int cnt){

    if (pos == t.size()){
        ans += tree[i].term;
        return;
    }
    int next1 = to[t[pos]] , next2 = to[rev(t[pos])];

    if (tree[i].next.count(next1) != 0){
        dfs(tree[i].next[next1] , pos + 1 , cnt);
    }

    if (tree[i].next.count(next2) != 0 && cnt + 1 <= k){
        dfs(tree[i].next[next2] , pos + 1 , cnt + 1);
    }

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    srand(time(0));

    int alph = 0;
    for (char i = 'a'; i <= 'z'; i ++){
        to[i] = alph++;
    }
    for (char i = 'A'; i <= 'Z'; i ++){
        to[i] = alph++;
    }


    cin >> k >> w;

    for (int i = 0; i < w; i ++){
        string s = "";
        cin >> s;
//        for (int e = 0; e < 2e3; e ++) {
//            if (rand() % 2 == 0) s += 'a';
//            else s += 'A';
//        }
        int cur = 0;
        for (int j = 0 ; j < s.size(); j ++){
            int next = to[s[j]];
            if (tree[cur].next.count(next) == 0){
                tree[sz++] = Node();
                tree[cur].next[next] = sz - 1;
            }
            cur = tree[cur].next[next];

        }
        tree[cur].term++;
    }

    cin >> q;
    while(q --> 0){
        cin >> t;
//        t = ""; for (int e = 0; e < 2e3; e ++) {
//            if (rand() % 2 == 0) t += 'a';
//            else t += 'A';
//        }

        ans = 0;
        dfs(0 , 0 , 0);
        cout << ans << '\n';
    }

}
/*
5
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
