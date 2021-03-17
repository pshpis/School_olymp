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
    node* left, *right;
    int key, priority, sz;
    node(int key_){
        left = nullptr;
        right = nullptr;
        key = key_;
        priority = rand();
        sz = 1;
    }
};

bool find(node* root, int k){
    if (root == nullptr) return false;
    if (root -> key == k) return true;
    if (root -> key > k) return find(root -> left, k);
    else return find(root -> right, k);
}

int size(node* root){
    if (root == nullptr) return 0;
    else return root -> sz;
}

void up(node* root){
    if (root == nullptr) return;
    else root -> sz = size(root -> left) + size(root -> right) + 1;
}

node* merge(node* left, node* right){
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    if (left -> priority < right -> priority){
        left -> right = merge(left -> right, right);
        up(left);
        return left;
    }
    else {
        right -> left = merge(left, right -> left);
        up(right);
        return right;
    }
}

pair<node*, node*> split(node* root, int k){
    if (root == nullptr) return {nullptr, nullptr};
//    if (root -> key == k){
//        pair<node*, node* > ans;
//        ans.se = root -> right;
//        root -> right = nullptr;
//        ans.fi = root -> left;
//        return ans;
//    }

    if (root -> key > k){
        auto s = split(root -> left, k);
        root -> left = s.se;
        up(root);
        return {s.fi, root};
    }
    else {
        auto s = split(root -> right, k);
        root -> right = s.fi;
        up(root);
        return {root, s.se};
    }
}

node* insert(node* root, int k){
    node* nw = new node(k);
    auto s = split(root, k);
    return merge(merge(s.fi, nw), s.se);
}

void write(node* root){
    if (root == nullptr) return;
    write(root -> left);
    cout << root -> key << " ";
    write(root -> right);
}

node* root = nullptr;

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

    while (true){
        char c = next<char>();
        if (c == 'i'){
            int k = next();
            root = insert(root, k);
        }
        if (c == 'w'){
            write(root);
            cout << endl;
        }
        if (c == 's'){
            cout << size(root) << endl;
        }
        if (c == 'f'){
            int k = next();
            if (find(root, k)) cout << "true" << endl;
            else cout << "false" << endl;
        }
    }


}
/*




*/

