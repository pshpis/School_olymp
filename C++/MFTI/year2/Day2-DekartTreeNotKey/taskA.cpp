#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mp make_pair
#define pw2(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

#define ins insert
#define pb push_back
#define eb emplace_back

//#define int int64_t

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

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

template<typename type>

type next()
{type x; cin >> x; return x;}

int next()
{ll x; cin >> x; return x;}

inline void fast_write(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifdef FIlE_in
        freopen(file_in, "r", stdin);
    #endif // FIlE_in
    #ifdef FILE_outvoi
        freopen(file_out, "w", stdout);
    #endif // FILE_out
}

struct node{
    node *left, *right;
    int value;
    int priority;
    int size;
    int mn;
    node(int value_ = 0){
        left = nullptr;
        right = nullptr;
        value = value_;
        size = 1;
        priority = ((rand() << 16) ^ rand());
        mn = value;
    }
};

int size(node *v){
    if (v == nullptr) return 0;
    else return v -> size;
}

int min(node* v){
    if (v == nullptr) return + 1e9 + 7;
    return v -> mn;
}

void up(node* v){
    if (v == nullptr) return;
    v -> size = size(v -> left) + size(v -> right) + 1;
    v -> mn = min(min( min(v -> left), min(v -> right) ), v -> value);
}

node* merge(node* l, node* r){
    if (l == nullptr) return r;
    if (r == nullptr) return l;
    if (l -> priority < r -> priority){
        l -> right = merge(l -> right, r);
        up(l);
        return l;
    }
    else {
        r -> left = merge(l, r -> left);
        up(r);
        return r;
    }
}

pair<node*, node*> split(node* root, int k){
    if (root == nullptr) return mp(nullptr, nullptr);
    if (size(root) + 1 == k) return mp(root, nullptr);
    if (k <= size(root -> left)){
        auto p = split(root -> left, k);
        root -> left = p.se;
        up(root);
        return mp(p.fi, root);
    }
    else {
        auto p = split(root -> right, k - size(root -> left) - 1);
        root -> right = p.fi;
        up(root);
        return mp(root, p.se);
    }
}

int get_by_id(node* root, int id){
    if (root == nullptr) return -INF;
    if (size(root -> left) == id) return root -> value;
    if (id < size(root -> left)) return get_by_id(root -> left, id);
    else return get_by_id(root -> right, id - size(root -> left) - 1);
}

node* insert(node* root, node* v, int pos){
    if (root == nullptr) return v;
    if (v == nullptr) return root;
    pos ++;
    auto p = split(root, pos - 1);
    p.fi = merge(p.fi, v);
    root = merge(p.fi, p.se);
    return root;
}

void write(node *root){
    if (root == nullptr) return;
    write(root -> left);
    cout << root -> value << " ";
    write(root -> right);
    return;
}

int segm_min(node *root, int l, int r){
    auto p1 = split(root, r + 1);
    auto p2 = split(p1.fi, l);
    int res = min(p2.se);
    root = merge(merge(p2.fi, p2.se), p1.se);
    up(root);
    return res;
}

node* buff = nullptr;

node* ctrx(node* root, int l, int r){
    auto p1 = split(root, r + 1);
//    cout << "p1.fi is ";
//    write(p1.fi);
//    cout << endl;
//    cout << "p1.se is ";
//    write(p1.se);
//    cout << endl;
    auto p2 = split(p1.fi, l);
//    cout << "p2.fi is ";
//    write(p2.fi);
//    cout << endl;
//    cout << "p2.se is ";
//    write(p2.se);
//    cout << endl;
    root = merge(p2.fi, p1.se);
//    cout << "root is ";
//    write(root);
//    cout << endl;
    buff = p2.se;
    return root;
}

node* ctrv(node* root, int pos){
    auto p = split(root, pos - 1);
    root = merge(merge(p.fi, buff), p.se);
//    buff = nullptr;
    return root;
}

node* root = nullptr;

// not work in tests with edges

void solve(){
    int n = next(), m = next();
    for (int i = 0; i < n; i ++){
        root = insert(root, new node(i + 1), n);
    }
//    write(root);
//    cout << endl;
    for (int i = 0; i < m; i ++){
        int l = next(), r = next();
        root = ctrx(root, l - 1, r - 1);
//        cout << "After CTR X\n";
//        cout << "root is ";
//        write(root);
//        cout << endl;
//        cout << "buff is ";
//        write(buff);
//        cout << endl;
        root = ctrv(root, 0);
//        cout << "After CTR V\n";
//        write(root);
//        cout << endl;
    }
    write(root);
    cout << endl;
}

int32_t main()
{
    fast_write();
    solve();
}
/*
+ 1 0
+ 2 0
+ 3 2
+ 4 1
+ 5 2

+ 0 5
+ 1 3
+ 1 4
w
? 1 2


FUUUUCKKKKK!!!!

*/


