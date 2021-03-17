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
    node *left, *right, *father;
    int key, priority, size, num;

    node(int key_){
        key = key_;
        priority = ((rand() << 16) ^ rand());
        left = nullptr;
        right = nullptr;
        father = nullptr;
        size = 1;
    }

    node(int key_, int priority_){
        key = key_;
        priority = priority_;
        left = nullptr;
        right = nullptr;
        father = nullptr;
        size = 1;
    }

    node (int key_, int priority_, int num_){
        key = key_;
        priority = priority_;
        left = nullptr;
        right = nullptr;
        father = nullptr;
        size = 1;
        num = num_;
    }

};

int size(node *root){
    if (root == nullptr) return 0;
    else return root -> size;
}

void up(node *root){
    if (root == nullptr) return;
    root -> size = size(root -> left) + size(root -> right) + 1;
}

bool is_into(node *root, int k){
    if (root == nullptr) return false;
    if (root -> key == k) return true;
    if (root -> key > k) return is_into(root -> left, k);
    else return is_into(root -> right, k);
}

node* find(node *root, int k){
    if (root == nullptr) return new node(-1e9);
    if (root -> key == k) return root;
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
//    if (is_into(root, v -> key)) return root;
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

void write(node* root){
    if (root == nullptr) return;
    write(root -> left);
    cout << root -> key << " ";
    write(root -> right);
}

void make_father(node *root){
    if (root == nullptr) return;
    if (root -> left != nullptr) (root -> left) -> father = root;
    if (root -> right != nullptr) (root -> right) -> father = root;
    make_father(root -> left);
    make_father(root -> right);
}

template<typename T1, typename T2, typename T3>

struct triple{
    T1 fi;
    T2 se;
    T3 th;
    triple(T1 fi_, T2 se_, T3 th_){
        fi = fi_;
        se = se_;
        th = th_;
    }

    triple() = default;
};

template<typename T1, typename T2, typename T3>

bool operator < (triple<T1, T2, T3> a1, triple<T1, T2, T3> a2){
    if (a1.fi < a2.fi) return true;
    if (a1.fi == a2.fi){
        if (a1.se < a2.se) return true;
        if (a1.se == a2.se){
            if (a1.th < a2.th) return true;
        }
    }
    return false;
}

template<typename T1, typename T2, typename T3>
triple<T1, T2, T3> mt(T1 fi, T2 se, T3 th){
    return triple<T1, T2, T3>(fi, se, th);
}


vector<triple<int, int, int> > ans;

void make_ans(node *root){
    if (root == nullptr) return;

    int i = root -> num;

    if (root -> father == nullptr) ans[i].fi = 0;
    else ans[i].fi = (root -> father) -> num + 1;

    if (root -> left == nullptr) ans[i].se = 0;
    else ans[i].se = (root -> left) -> num + 1;

    if (root -> right == nullptr) ans[i].th = 0;
    else ans[i].th = (root -> right) -> num + 1;

    make_ans(root -> left);
    make_ans(root -> right);
}

node *root = nullptr;

node* make_tree(vector<triple<int, int, int> > a){
    if (a.size() == 0) return nullptr;
    if (a.size() == 1) return new node(a[0].fi, a[0].se, a[0].th);

    vector<triple<int, int, int> > a1, a2;
    fr(i, (int)a.size()){
        if (i < (int)a.size() / 2) a1.pb(a[i]);
        else a2.pb(a[i]);
    }

    node* root1 = make_tree(a1);
    node* root2 = make_tree(a2);

    return merge(root1, root2);
}

void solve(){
    int n = next();
    vector<triple<int, int, int> > a;
    fr(i, n){
        int key = next(), priority = next();
        a.pb(mt(key, priority, i));
//        root = insert(root, new node(key, priority, i));
    }

    sort(all(a));
    root = make_tree(a);

    make_father(root);
    ans.resize(n);
    make_ans(root);

    cout << "YES\n";
    for (int i = 0; i < n; i ++)
        cout << ans[i].fi << " " << ans[i].se << " " << ans[i].th << "\n";
}

int32_t main()
{
    fast_write();
    solve(); //ÏÐÈ ÐÅØÅÍÈÈ Ñ ÒÅÑÒÀÌÈ ÓÁÐÀÒÜ SOLVE ÈÇ ÍÀ×ÀËÀ
}
/*




*/
