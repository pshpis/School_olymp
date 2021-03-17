#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb(x) push_back(x)
#define pow2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for (int (i)=0; i<int(n); i++)

const bool isDbg=false;

typedef long long lint;

using namespace std;

template<typename type>

type next()
{type x;cin>>x;return x;}

int next()
{int x;cin>>x;return x;}

lint lnext()
{lint x;cin>>x;return x;}

struct user {
    bool inc;
    string c;
    int time;
    string name;
    int sum;
    user(string nname = "") {
        name = nname;
        c = "";
        sum = 0;
        inc = false;
    }

    void get(string nc, int nt, int pr) {
    if (inc) return;
    if (c != "") { inc = true; return; }
    c = nc;
    time = nt;
    sum += pr;
    }
    int getRes() {
    return sum;
    }
    void ret(string nc, int nt, int pr, int ntime) {
    if (inc) return;
    if (c != nc) { inc = true; return; }
    c = "";
    sum += pr * ntime;
    }
    void acc(string nc, double k, int pr) {
    if (inc) return;
    if (c != nc) { inc = true; return; }
    c = "";
    sum += (k * pr);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (isDbg) freopen("inputC.txt", "r", stdin);
    int z,n,m, k1, k2,k3;
    string str, str2, str3;
    cin >> z;
    for (int z1 = 0; z1 < z; z1++) {
        cin >> n >> m;
        map<string, user> users;
        map<string, int> price1;
        map<string, int> price2;
        map<string, int> price3;
        for (int i = 0; i < n; i++) {
            cin >> str >> k1 >> k2 >> k3;
            price1[str] = k1;
            price2[str] = k2;
            price3[str] = k3;
        }

        for (int i = 0; i < m; i++) {
            cin >> k1 >> str >> str2;
            if (users[str].name == "") users[str] = user(str);
            user u = users[str];
            if (str2[0] == 'p') {
                cin >> str3;
                u.get(str3, k1, price2[str]);
            }
            if (str2[0] == 'r') {
                cin >> k2;
                u.ret(str, k1, price3[str], k2);
            }
            if (str2[0] == 'a') {
                cin >> k2;
                u.acc(str,k2 * 0.01,price1[str]);
            }

        }
        for (auto au : users) {
            user u = au.second;
            if (u.inc) cout << "INCONSISTENT\n"; else
            cout << u.getRes() << "\n";
        }
    }
}

