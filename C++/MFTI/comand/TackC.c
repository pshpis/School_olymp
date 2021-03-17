#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2);
    for (int i = 1; i <= n: ++i) {
        cin >> a[i];
    }
    a[0] = a[n];
    a[n + 1] = a[1];
    for (; k > 0; --k) {
        unordered_map<int, int> m;
        vector<int> old = a;
        for (int i = 1; i <= n; ++i) {
            m[old[i]] = 1;
            a[i] = min(old[i - 1], old[i + 1]);
        }
        a[0] = a[n];
        a[n + 1] = a[1];
        if (n % 2 == 0 && m.size() == 2) {
            break;
        } else if (n % 2 == 1 && m.size() == 1) {
            break;
        }
    }
    if (k == 0) {
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
    } else {
        if (n % 2 == 1) {
            for (int i = 1; i <= n; ++i) {
                cout << a[i] << " ";
            }
        } else if (n % 2 == 0) {
            k %= 2;
            if (k == 1) {
                vector<int> old = a;
                for (int i = 1; i <= n; ++i) {
                    m[old[i]] = 1;
                    a[i] = min(old[i - 1], old[i + 1]);
                }
                a[0] = a[n];
                a[n + 1] = a[1];
                if (n % 2 == 0 && m.size() == 2) {
                    break;
                } else if (n % 2 == 1 && m.size() == 1) {
                    break;
                }
            }
            for (int i = 1; i <= n; ++i) {
                cout << a[i] << " ";
            }
        }
    }
}
