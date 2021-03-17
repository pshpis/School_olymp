#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int int64_t

class SegmentTree {
public:
	vector<int> tree;
	vector<int> buff;
	int nei;
	int n;

	int size() {
		return n;
	}

	int func(int a, int b) {
		return max(a, b);
	}

	SegmentTree() {}

	SegmentTree(vector<int> a) {
		nei = -1e9 - 100;
		n = a.size();
		int k = 1;

		while (k < n) k *= 2;
		for (int i = 0; i < k - n; i++) a.push_back(nei);

		n = k;
		tree = vector<int>(2 * n, nei);
		buff = vector<int>(2 * n, 0);

		for (int i = n; i < 2 * n; i++) {
			tree[i] = a[i - n];
		}
		for (int i = n - 1; i > 0; i--) {
			tree[i] = func(tree[2 * i], tree[2 * i + 1]);
		}
	}

	void change(int i, int value) {
		tree[i + n] = value;
		update((i + n) / 2);
	}

	void change_cut(int add, int need_l, int need_r) {
		help_change_cut(add, need_l, need_r, 0, n - 1, 1);
	}

	int get_func(int need_l, int need_r) {
		return get(need_l, need_r, 0, n - 1, 1);
	}


	int get_func_cut(int need_l, int need_r) {
		return get_cut(need_l, need_r, 0, n - 1, 1);
	}

	void watch_tree() {
		for (int i = 0; i < tree.size(); i++)
			cout << tree[i] << " ";
		cout << endl;
	}

	void watch_buff() {
		for (int i = 0; i < buff.size(); i++)
			cout << buff[i] << " ";
		cout << endl;
	}

	void debag() {
		watch_tree();
		cout << "|||||||||||" << endl;
		watch_buff();
		cout << "---------------------" << endl;
	}

private:
	void upd(int i) {
		if (i < n)
			tree[i] = func(tree[2 * i], tree[2 * i + 1]);
	}

	void update(int i) {
		if (i == 0) return;
		tree[i] = func(tree[2 * i], tree[2 * i + 1]);
		update(i / 2);
	}

	int get(int need_l, int need_r, int l, int r, int i) {
		if (l >= need_l && r <= need_r) return tree[i];
		if (l > need_r || r < need_l) return nei;
		int m = (l + r) / 2;
		return func(get(need_l, need_r, l, m, 2 * i),
			get(need_l, need_r, m + 1, r, 2 * i + 1));
	}

	void help_change_cut(int add, int need_l, int need_r, int l, int r, int i) {
		push(l, r, i);
		if (l >= need_l && r <= need_r) {
			buff[i] += add;
			return;
		}
		if (l > need_r || r < need_r) return;
		int m = (l + r) / 2;
		help_change_cut(add, need_l, need_r, l, m, 2 * i);
		help_change_cut(add, need_l, need_r, m + 1, r, 2 * i + 1);
		upd(i);
	}

	int get_cut(int need_l, int need_r, int l, int r, int i) {
	    push(l, r, i);
		if (l > need_r || r < need_l) return nei;
		int ans = nei;
		if (l >= need_l && r <= need_r) ans = tree[i];
		else {
			int m = (l + r) / 2;

			ans = func(get_cut(need_l, need_r, l, m, 2 * i),
				get_cut(need_l, need_r, m + 1, r, 2 * i + 1));

			upd(i);
		}

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

void test() {
	int type; cin >> type;
	int need_l, need_r; cin >> need_l >> need_r;
	need_l--; need_r--;

	if (type == 1) cout << T.get_func_cut(need_l, need_r) << '\n';
	else {
		int add; cin >> add;
		T.change_cut(add, need_l, need_r);
	}

}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	int m; cin >> m;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	T = SegmentTree(a);

	//T.watch_tree();
	//cout << " ------- " << endl;

	for (int i = 0; i < m; i++) {
		test();
	}

}
/*




*/
