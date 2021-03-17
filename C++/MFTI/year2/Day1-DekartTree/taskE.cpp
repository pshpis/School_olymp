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

#define fr(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define wrvec(a) for (int i = 0; i < (a).size(); i ++) cout << (a)[i] << " "; cout << endl;
#define revfr(i, n) for(int (i) = int(n) - 1; (i) >= 0; i --)

#define int int64_t // int -> long long

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
typedef vector<pair<int, int> > vii;

const int INF = 2e9;
const ll INF64 = 1e18;
const double PI = 3.14159265359;
const double EPS = 1e-9;
const int MOD = 1e9+7;

//cout for pair
template <typename T1, typename T2>

ostream& operator <<(ostream& s, const pair<T1, T2> x)
{
    s << x.fi << " " << x.se;
    return s;
}

//cin for pair
template <typename T1, typename T2>

istream& operator>>(istream& s, pair<T1, T2>& x)
{
    s >> x.fi;
    s >> x.se;
    return s;
}

template<typename type>

type next()
{type x; cin >> x; return x;}

ll next()
{ll x; cin >> x; return x;}

inline void fast_write(){
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
    node *left, *right;
    int key, priority, size, sum;

    node(int key_){
        key = key_;
        priority = ((rand() << 16) ^ rand());
        left = nullptr;
        right = nullptr;
        size = 1;
        sum = key;
    }
};

int size(node *root){
    if (root == nullptr) return 0;
    else return root -> size;
}

int sum(node* root){
    if (root == nullptr) return 0;
    return root -> sum;
}

void up(node *root){
    if (root == nullptr) return;
    root -> size = size(root -> left) + size(root -> right) + 1;
    root -> sum = sum(root -> left) + sum(root -> right) + root -> key;
}

bool find(node *root, int k){
    if (root == nullptr) return false;
    if (root -> key == k) return true;
    if (root -> key > k) return find(root -> left, k);
    else return find(root -> right, k);
}

node *merge(node* l, node* r){
    if (l == nullptr) return r;
    if (r == nullptr) return l;
    if (l -> priority < r -> priority){
        l -> right = merge(l -> right, r);
        up(l);
        return l;
    }
    else {
        r -> left = merge(l, r -> left); // may be r -> left in both cases
        up(r);
        return r;
    }
}

pair<node*, node*> split(node* root, int k){
    if (root == nullptr) return mp(nullptr, nullptr);

    if (root -> key < k){
        auto p = split(root -> right, k);
        root -> right = p.fi;
        up(root);
        return mp(root, p.se);
    }
    else {
        auto p = split(root -> left, k);
        root -> left = p.se;
        up(root);
        return mp(p.fi, root);
    }
}

node* insert(node* root, node* v){//not think about size
    if (root == nullptr) return v;
    if (v == nullptr) return root;
//    watch(root -> key);
//    watch(v -> key);
//    watch(root -> priority);
//    watch(v -> priority);
    if (root -> priority > v -> priority){
        auto p = split(root, v -> key);
        v -> left = p.fi;
        v -> right = p.se;
        up(v);
        return v;
    }
    if (v -> key < root -> key) root -> left = insert(root -> left, v);
    else root -> right = insert(root -> right, v);
    up(root);
    return root;
}

node* erase(node* root, int k){//not think about size
    if (root == nullptr) return root;

    if (root -> key == k) return merge(root -> left, root -> right);
    if (k < root -> key) root -> left = erase(root -> left, k);
    else root -> right = erase(root -> right, k);
    up(root);
    return root;
}

int find_by_id(node* root, int id){
    if (root == nullptr) return -1e9;
    if (id == size(root -> left)) return root -> key;
    if (id < size(root -> left)) return find_by_id(root -> left, id);
    else return find_by_id(root -> right, id - size(root -> left) - 1);
}

int id_by_key(node* root, int key){
    if (root == nullptr) return 0;
    if (root -> key < key) return id_by_key(root -> right, key) + size(root -> left) + 1;
    else return id_by_key(root -> left, key);
}

int next(node* root, int key){
    if (root == nullptr) return -1;
    int id = id_by_key(root, key);
    if (id == size(root)) return -1;
    return find_by_id(root, id);
}

int prev(node* root, int key){
    if (root == nullptr){
        return -1;
    }
    int id = id_by_key(root, key);
    if (id == 0) return -1;
    id --;
    return find_by_id(root, id);

}

int segm_sum(node* root, int l, int r){
    int res = 0;
    if (find(root, r)) res += r;

    auto p1 = split(root, r);
    auto p2 = split(p1.fi, l);
    res += sum(p2.se);

    root = merge(p2.fi, merge(p2.se, p1.se));

    return res;

}

node *root = nullptr;

void solve(){
    int n = next();
    int last = 0;
    fr(i, n){
        char t;
        cin >> t;
        if (t == '+'){
            int key = next();
            key += last;
            key %= (int)1e9;
            last = 0;
            if (!find(root, key)) root = insert(root, new node(key));
        }
        else {
            int l = next(), r = next();
            int res = segm_sum(root, l, r);
            last = res;
            cout << res << endl;
        }
    }
}

int32_t main()
{
    fast_write();
    solve();
}
/*




*/


