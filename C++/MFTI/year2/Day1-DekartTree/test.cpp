#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pw2(x) ((x)*(x))
#define all(x) (x).begin(), (x).end()
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++ i)
#define fi first
#define se second
#define ins insert

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

inline void fast_wrie(){
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

struct node{
    int key;
    int priority;
    int size;
    node *left, *right;

    node(int key_){
        key = key_;
        size = 1;
        priority = rand(); // ((rand() << 16) + rand()) if rand() is small
        left = nullptr;
        right = nullptr;
    }
};

node* root1 = nullptr;
node* root2 = nullptr;

int size(node* v){
    if (v == nullptr) return 0;
    else return v -> size;
}

void upd(node* v){
    if (v == nullptr) return;
    v  -> size = size(v -> left) + size(v -> right) + 1;
}

node *merge(node *l, node *r){//question why l -> right and r -> left
    if (l == nullptr) return r;
    if (r == nullptr) return l;

    if (l -> priority < r -> priority){
        l -> right = merge(l -> right, r);
        upd(l);
        return l;
    }
    else{
        r -> left = merge(l, r -> left);
        upd(r);
        return r;
    }
}

pair<node*, node*> split(node *root, int k){
    if (root == nullptr){
        return mp(nullptr, nullptr);
    }

    if (root -> key < k){
        auto p = split(root -> right, k);
        root -> right = p.fi;
        upd(root);
        return mp(root, p.se);
    }
    else{
        auto p = split(root -> left, k);
        root -> left = p.second;
        upd(root);
        return mp(p.fi, root);
    }

}

bool find(node *root, int key){
    if (root == nullptr) return false;
    if (root -> key == key) return true;
    if (key < root -> key) return find(root -> left, key);
    else return find(root -> right, key);
}

node* insert(node *root, node *v){
    if (root == nullptr) return v;
    if (v == nullptr) return root;
    if (v -> priority < root -> priority){
        auto p = split(root, v -> key);
        v -> left = p.fi;
        v -> right = p.se;
        upd(v);
        return v;
    }
    if (v -> key < root -> key) root -> left = insert(root -> left, v);
    else root -> right = insert(root -> right, v);
    upd(root);
    return root;
}

node* erase(node *root, int key){
    if (root == nullptr) return root;
    if (root -> key == key) return merge(root -> left, root -> right);
    if (key < root -> key) root -> left = erase(root -> left, key);
    else root -> right = erase(root -> right, key);
    upd(root);
    return root;
}

int find_by_id(node *root, int id){
    if (root == nullptr) return -1e9;
    if (size(root -> left) == id) return root -> key;
    if (id < size(root -> left)) return find_by_id(root -> left, id);
    else return find_by_id(root -> right, id - size(root -> left) - 1);
}

int id_by_key(node* root, int key){
    if (root == nullptr) return 0;
    if (root -> key < key) return id_by_key(root -> right, key) + size(root -> left) + 1;
    else return id_by_key(root -> left, key);
}

void write(node* root){
    if (root == nullptr) return;
    write(root -> left);
    cout << root -> key << " ";
    write(root -> right);
}

void solve(){
    int n = next();
    for (int i = 0; i < n; i ++){
        int id = next();
        char t = next<char>();
        if (t == '+'){
            int key = next();
//            int priority = next();
            node* a = new node(key);
//            a -> priority = priority;
            if (id == 1) root1 = insert(root1, a);
            else root2 = insert(root2, a);
        }
        if (t == 'w'){
            if (id == 1) write(root1);
            else write(root2);
            cout << endl;
        }
        if (t == 'm'){
            if (id == 1){
                root1 = merge(root1, root2);
            }
            else root2 = merge(root1, root2);
        }
    }
}

int32_t main()
{
    fast_wrie();
    solve();
}
/*




*/
