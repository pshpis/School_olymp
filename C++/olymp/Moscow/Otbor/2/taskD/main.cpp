#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;

inline void speed_up() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <vector < pair <int, int > > > all;
map <string, int> was;
vector <string> word;

string buff = "";
string ans = "";

void dfs(int v = 0, int x = 0) {
    for (int i = x; i < word[v].size(); ++i)
        buff += word[v][i];
    was[word[v]] = 1;
    for (int i = all[v].size() - 1; i >= 0; --i) {
        if (was[word[all[v][i].second]])
            continue;
        dfs(all[v][i].second, all[v][i].first);
    }
}

int gcp(string a, string b) {
    int ans = 0;
    for (int i = 1; i <= min(a.length(), b.length()); ++i) {
        bool mark = true;
        for (int j = 0; j < i; ++j) {
            if (a[a.size() - i + j] != b[j]) {
                mark = false;
                break;
            }
        }
        if (mark) {
            ans = i;
        }
    }
    return ans;
}


void get_ans(){
    dfs(0);
    ans = buff;
//    return;
    was.clear();
    for (int i = 1; i < n; ++ i) {
        for (int i = 0; i < n; i ++) was[word[i]] = false;
        buff = "";
        dfs(i);
        if (buff.size() < ans.size())
            ans = buff;
    }
}

int main() {
    freopen("d2.txt", "r", stdin);
    freopen("d2ans.txt", "w", stdout);
    speed_up();

    cin >> n;
    vector <string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        was[s[i]] = 0;
    }

    vector <int> is(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && s[i].find(s[j]) != string::npos) {
                is[j] = 0;

            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (is[i]) {
            word.push_back(s[i]);
        }
    }

    n = word.size();
    all.resize(n, vector <pair <int, int> > (n));
    int start = 0;
    for (int i = 0; i < n; ++i) {
        int max_x = 0;
        int p = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            all[i][j] =  {gcp(word[i], word[j]), j};
            if (all[i][j].first == 0)
                start = i;
            if (all[i][j].second > max_x) {
                max_x = all[i][j].second;
                p = j;
            }
        }
        if (max_x <= 1)
            start = p;
        sort(all[i].begin(), all[i].end());
    }


    get_ans();
    cout << ans;

    return 0;
}

