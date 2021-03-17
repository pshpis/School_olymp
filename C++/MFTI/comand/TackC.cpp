
#include <bits/stdc++.h>

using namespace std;

int n;

inline int left_(int x) {
    return (x - 1 + n) % n;
}

inline int right_(int x) {
    return (x + 1) % n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> n >> k;
    vector<int> a(n);
    vector<pair<int, int>> sorted(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sorted[i].first = a[i];
        sorted[i].second = i;
    }
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> old, new_;
    vector<int> ans(n, -1);
    for (int j = 0; j < n; ++j) {
        old[sorted[j].second] = 1;
        for (int i = 0; i < k; ++i) {
            if (n % 2 == 1 && old.size() == n) {
                break;
            } else if (n % 2 == 0 && old.size() == n / 2) {
                if ((k - i) % 2 == 1) {
                    for (auto ku : old) {
                        new_[left_(ku.first)] = 1;
                        new_[right_(ku.first)] = 1;
                    }
                    old = new_;
                    new_.clear();
                }
                break;
            }
            for (auto ku : old) {
                new_[left_(ku.first)] = 1;
                new_[right_(ku.first)] = 1;
            }
            old = new_;
            new_.clear();
        }
        for (auto ku : old) {
            if (ans[ku.first] == -1) {
                ans[ku.first] = sorted[j].first;
            }
        }
        bool o = true;
        old.clear();
        for (int i = 0; i < n; ++i) {
            if (ans[i] == -1) {
                o = false;
            }
        }
        if (o) {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}
