#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define unordered_set set

vector<unordered_set<int> > gr;
multiset<int> :: iterator it;
int n;

int get_id(pii a){
    cout << a.fi * 6 + a.se;
}

void make_rib(pii u, pii v){
    gr[get_id(u)].insert(get_id(v));
    gr[get_id(v)].insert(get_id(u));
}

void make_gr(unordered_set<pii>& left){
    gr = vector<unordered_set<int> > (n * 6);
    for (auto u: left){
        for (int d = -1; d <= 1; ++ d){
            for (int d_ = -1; d_ <= 1; ++ d_){
                auto v = u;
                v.fi += d;
                v.se += d_;
                if (left.count(v) > 0) make_rib(u, v);
            }
        }
    }
}

multiset<int> pw;
map<int, unordered_set<int> > pw_id;

void make_pw(){
    for (int i = 0 ;  i < 6 * n; ++ i){
        pw.insert(gr[i].size());
        pw_id[gr[i].size()].insert(i);
    }
}

void erase_update(int u){
    int pw_u = gr[u].size();

    it = pw.find(pw_u);
    pw.erase(it);
    pw_id[pw_u].erase(u);

    pw_u --;
    pw.insert(pw_u);
    pw_id[pw_u].insert(u);
}

void erase_rib(int u, int v){
    erase_update(u);
    erase_update(v);
    gr[u].erase(v);
    gr[v].erase(u);
}

pii get_pii(int id){
    pii ans;
    ans.fi = id / 6;
    ans.se = id % 6;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    unordered_set<pii> left, right;

    for (int i = 0; i < n; ++ i){
        string s;
        cin >> s;
        for (int j = 0;  j < 3; ++ j)
            if (s[i] == '.') left.insert(mp(i, j));
        for (int j = 8; j >=6; j --){
            right.insert(mp(i, j - 6));
        }
    }

    make_gr(left);
    make_gr(right);

    make_pw();

    vector<int> ans;

    unordered_set<int> bad;

    while(!pw.empty()){
        it = pw.begin();
        int u = *pw_id[*it].begin();
        if (bad.count(u) > 0){
            pw.erase(it);
            continue;
        }

        ans.pb(u);
        bad.insert(u);
        for (int v: gr[u]){
            bad.insert(v);
            for (int c: gr[v]){
                if (c != v) erase_rib(v, c);
            }
        }
        for (int v: gr[u]){
            erase_rib(u, v);
        }
    }

    if (ans.size() < k) cout << "PORAZHENIE";
    else{
        cout << "POBEDA" << endl;
        for (int i = 0; i < k; ++ i){
            pii res = get_pii(ans[i]);
            cout << res.fi + 1 << 'A' + res.se << endl;
        }
    }
}
/*
2 2
.**|_|**.
**.|_|***


*/
