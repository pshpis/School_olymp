#include <bits/stdc++.h>

using namespace std;
/*
#define long long long long64_t

#define fi first
#define se second
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    long long m;
    cin >> m;
    vector<long long> presh(n + 1, 0);
    for (long long i = 1; i <= n; ++i) {
        presh[i] = presh[i - 1] + a[i];
    }
    vector<pair<long long, pair<long long, long long>>> shaur(m);
    vector<pair<long long, pair<long long, long long>>> sher(m);
    for (long long i = 1; i <= m; ++i) {
        long long x, y;
        cin >> x >> y;
        shaur[i - 1] = {x, {y, i}};
        sher[i - 1] = {y, {x, i}};
    }
    sort(sher.begin(), sher.end());
    vector<pair<long long, long long>> pref(n + 1, {-1, -1});
    long long now = 0;
    for (long long i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1];
        while (now < m && sher[now].first == i) {
            if (pref[i].first < presh[sher[now].first] - presh[sher[now].second.first - 1]) {
                pref[i].first = presh[sher[now].first] - presh[sher[now].second.first - 1];
                pref[i].second = sher[now].second.second;
            }
            now++;
        }
    }
    pair<long long, long long> q = {-1, -1};
    long long ma = -1e9;
    for (long long i = 0; i < m; ++i) {
        if (pref[shaur[i].first - 1].first == -1) {
            continue;
        }
        if (ma < pref[shaur[i].first - 1].first + presh[shaur[i].second.first ] - presh[shaur[i].first ]) {
            q = {shaur[i].second.second, pref[shaur[i].first - 1].second};
            ma = pref[shaur[i].first - 1].first + presh[shaur[i].second.first ] - presh[shaur[i].first ];
        }
    }
    if (q.first > q.second) {
        swap(q.first, q.second);
    }
    cout << q.first << " " << q.second;
    return 0;
}
    /*
    long long n; cin >> n;

    vector<long long> a(n);
    vector<long long> pref(n + 1, 0);

    for (long long i = 0; i < n; i ++){
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    long long m; cin >> m;
    vector<pair<long long, pair<long long, long long> > q(m);

    for (long long i = 0; i < m; i ++){
        long long l, r; cin >> l >> r;
        l --; r --;
        long long w = pref[r + 1] - pref[l];
        q[i].fi = w;
        q[i].se.fi = l;
        q[i].se.se = r;
    }

    vector<pair<long long, long long> > fsh(n, mp(-1, -1));

    for (long long i = 0; i < m; i ++){
        long long r = q[i].se.se;
        long long w = q[i].fi;
        if (fsh[r] != {-1, -1}){
            if (w > fsh[r].fi){
                fsh[r].fi = w;
                fsh[r].se = i;
            }
        }
        else{
            fsh[r].fi = w;
            fsh[r].se = i;
        }
    }

    pair<long long, long long> pr = {-1, -1};
    for (long long i = 0; i < n; i ++){


    }*/

