#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mp make_pair
#define pw2(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()

#define fi first
#define se second
#define th third

#define ins insert
#define pb push_back
#define eb emplace_back

#define fr(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define wrvec(a) for (int i = 0; i < (a).size(); i ++) cout << (a)[i] << " "; cout << endl;
#define revfr(i, n) for(int (i) = int(n) - 1; (i) >= 0; i --)

//#define int int64_t // int -> long long

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[] = "input.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "output.txt";
#endif // FILE_out

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int> > vii;
typedef set<int> si;
typedef set<pii> sii;

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

template<typename type>

type next()
{type x; cin >> x; return x;}

ll next()
{ll x; cin >> x; return x;}

struct node{
    int key, priority;
    node* left, right;

    node(int key_){
        key = key_;
        priority = rand();
        left = nullptr;
        right = nullptr;
    }
};

node* merge(node* a, node* b){
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    if (a -> priority < b -> priority){
        a -> right = merge(a -> right, b);
        return a;
    }
    else {
        b -> left = merge(a, b -> left);
        return b;
    }
}

pair<node*, node*> split(node* root, int x){
    if (root == nullptr) return mp(nullptr, nullptr);
    if (root -> key >= x){
        auto p = split(root -> left, x);
        root -> left = p.se;
        return mp(p.fi, root);
    }
    else {
        auto p = split(root -> right, x);
        root -> right = p.fi;
        return mp(root, p.se);
    }
}

node* insert(node* root, int x){
    if (root == nullptr) return root;
    node* nw(x);
    auto p = split(root, x);
    nw = merge(p.fi, nw);
    nw = merge(nw, p.se);
    return nw;
}

bool find(node* root, int x){
    if (root == nullptr) return false;
    if (root -> key == x) return true;
    if (root -> key > x) return find(root -> left, x);
    else return find(root -> right, x);
}

node* erase(node* root, int x){
    if (root == nullptr) return root;
    if (root -> key == x) return merge(root -> left, root -> right);
    if (root -> key > x){
        return erase(root -> left, x);
    }
    else {
        return erase(root -> right, x);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_out
        freopen(file_out, "w", stdout);
    #endif // FILE_out

}
/*




*/

