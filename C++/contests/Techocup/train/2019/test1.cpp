#include <bits/stdc++.h>

using namespace std;

long long next()
{long long x; cin >> x; return x;}

int MAXN = 1e5;
int n;

vector<int> tree(MAXN);//id from 1;
vector<int> a(MAXN);

void build(int v, int tree_l, int tree_r){
    if (tree_l == tree_r) tree[v]  = a[v];
    else{
        int tree_m = (tree_l + tree_r) / 2;
        build(v * 2, tree_l, tree_m);
        build(v * 2 + 1, tree_m + 1, tree_r);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int __sum(int v, int tree_l, int tree_r, int l, int r){
    if (l > r) return 0;
    if (l == tree_l && r == tree_r){
        return tree[v];
    }
    int tree_m = (tree_l + tree_r) / 2;
    return __sum(v * 2, tree_l, tree_m, l, min(r, tree_m))
            + __sum(v * 2 + 1, tree_m + 1, tree_r, max(tree_m + 1, l), r);
}

int get_sum(int l, int r){
    return __sum(1, 0, n - 1, l, r);
}

void __update(int v, int tree_l, int tree_r, int new_val, int pos){
    if (tree_l == tree_r){
        tree[v] = new_val;
        return;
    }
    else {
        int tree_m = (tree_l + tree_r) / 2;
        if (pos <= tree_m){
            __update(2 * v, tree_l, tree_m, new_val, pos);
        }
        else {
            __update(2 * v + 1, tree_m + 1, tree_r, new_val, pos);
        }
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

void update(int new_val, int pos){
    __update(1, 0, n - 1, new_val, pos);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    build(1, 0, n - 1);


    int m = next();
    for (int i = 0; i < m; i ++){
        char c;
        cin >> c;
        if (c == 's'){
            int l = next() - 1, r = next() - 1;
            cout << get_sum(l, r) << endl;
        }
        if (c == 'u'){
            int new_val = next(), pos = next() - 1;
            update(new_val, pos);
        }
    }
}
