#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pw2(x) ((x)*(x))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define fr(i, n) for(int i = 0; i < int(n); ++ i)
#define fi first
#define se second
#define ins insert

#define int int64_t

//#define FIlE_in
//#define FILE_out

#ifdef FIlE_in
    char file_in[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\in.txt";
#endif // FIlE_in
#ifdef FILE_out
    char file_out[] = "C:\\Users\\pshpi\\OneDrive\\Desktop\\out.txt";
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
{int x; cin >> x; return x;}

ll lnext()
{ll x; cin >> x; return x;}

class SegmentTree{
public:
    vector<int> tree;
    vector<int> buff;
    int nei;
    int n;

    int size(){
        return n;
    }

    int func(int a, int b){
        return min(a, b);
    }

    SegmentTree(){}

    SegmentTree(vector<int> a){
        nei = 1e9 + 100;
        n = a.size();
        int k = 1;

        while (k < n) k *= 2;
        for (int i = 0; i < k - n; i ++) a.push_back(nei);

        n = k;
        tree = vector<int>(2 * n, nei);
        buff = vector<int>(2 * n, 0);

        for (int i = n; i < 2 * n; i ++){
            tree[i] = a[i - n];
        }
        for (int i = n - 1; i > 0; i --){
            tree[i] = func(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void change(int i, int value){
        tree[i + n] = value;
        update((i + n) / 2);
    }

    void change_cut(int add, int need_l, int need_r){
        help_change_cut(add, need_l, need_r, 0, n - 1, 1);
    }

    int get_func(int need_l, int need_r){
        return get(need_l, need_r, 0, n - 1, 1);
    }

    int get_func_cut(int need_l, int need_r){
        return get_cut(need_l, need_r, 0, n - 1, 1);
    }

    void watch_tree(){
        for (int i = 0; i < tree.size(); i ++)
            cout << tree[i] << " ";
        cout << endl;
    }

private:
    void update(int i){
        if (i == 0) return;
        tree[i] = func(tree[2 * i], tree[2 * i + 1]);
        update(i / 2);
    }

    int get(int need_l, int need_r, int l, int r, int i){
        if (l >= need_l && r <= need_r) return tree[i];
        if (l > need_r || r < need_l) return nei;
        int m = (l + r) / 2;
        return func(get(need_l, need_r, l, m, 2 * i),
                    get(need_l, need_r, m + 1, r, 2 * i + 1));
    }

    void help_change_cut(int add, int need_l, int need_r, int l, int r, int i){
        if (l >= need_l && r <= need_r){
            buff[i] += add;
            return;
        }
        if (l > need_r || r < need_r) return;
        int m = (l + r) / 2;
        help_change_cut(add, need_l, need_r, l, m, 2 * i);
        help_change_cut(add, need_l, need_r, m + 1, r, 2 * i + 1);
    }

    int get_cut(int need_l, int need_r, int l, int r, int i){
        if (l > need_r || r < need_l) return nei;
        push(l, r, i);
        int ans = nei;
        if (l >= need_l && r <= need_r) ans = tree[i];
        else{
            int m = (l + r) / 2;
            ans = func(get_cut(need_l, need_r, l, m, 2 * i),
                        get_cut(need_l, need_r, m + 1, r, 2 * i + 1));
        }
        tree[i] = func(tree[2 * i], tree[2 * i + 1]);
        return ans;
    }

    void push(int l, int r, int i) {
		if (i == 0) return;
		tree[i] += buff[i];// смотреть если изменяешь func
		if (i > n - 1) {
			buff[i] = 0;
			return;
		}
		buff[2 * i] += buff[i];
		buff[2 * i + 1] += buff[i];
		buff[i] = 0;
	}
};

SegmentTree T;

void test(){
    int type; cin >> type;
    int need_l, need_r; cin >> need_l >> need_r;
    need_l --; need_r --;

    if (type == 1) cout << T.get_func_cut(need_l, need_r) << '\n';
    else{
        int add; cin >> add;
        T.change_cut(add, need_l, need_r);
    }
}

int to(string& x){
    int n = 0;
    for (int i = 0; i < x.size(); i ++){
        n *= 10;
        n += x[i] - '0';
    }
    return n;
}

void new_test(){
    string s;
    getline(cin, s);
//    watch(s);
    s += " ";
    vector<int> a;
    string x = "";
    for (int i = 0; i < s.size(); i ++){
        if (s[i] == ' '){
            a.push_back(to(x));
//            watch(x);
            x = "";
        }
        else {
            x += s[i];
        }
    }
    int l = a[0], r = a[1];
    if (a.size() == 2){
        if (l <= r) cout << T.get_func_cut(l ,r) << '\n';
        else cout << min(T.get_func_cut(l, T.size() - 1), T.get_func_cut(0, r)) << '\n';
    }
    else{
        int v = a[2];
        if (l <= r) T.change_cut(v, l ,r);
        else{
            T.change_cut(v, l, T.size() - 1);
            T.change_cut(v, 0, r);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i];

    T = SegmentTree(a);
//    T.watch_tree();
//    cout << " ----- " << endl;
    int m; cin >> m;

    string s;
    getline(cin, s);

    for (int i = 0; i < m; i ++){
        new_test();
//        T.watch_tree();
//        cout << " ----- " << endl;
    }

}
/*




*/
