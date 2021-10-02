#include <iostream>
#define SIZE 2100000
using namespace std;

int tree[SIZE];
int path[SIZE];
int k;
int size_;
int start;
int max_;

void dfs(int node, int depth, int sum) {
	if (depth > k) {
		path[node / 2] = max_ - sum;
	}
	else {
		dfs(node * 2, depth + 1, sum + tree[node]);
		dfs(node * 2 + 1, depth + 1, sum + tree[node]);
	}
}

int dfs1(int node, int depth, int sum_) {
	if (depth > k) {
		return max_ = sum_ > max_ ? sum_ : max_;
	}
	else {
		dfs1(node * 2, depth + 1, tree[node] + sum_);
		dfs1(node * 2 + 1, depth + 1, tree[node] + sum_);
	}
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> k;
	size_ = (1 << (k + 1));
	start = 1 << k;
	for (int i = 2; i < size_; i++) {
		cin >> tree[i];
	}
	int idx = (1 << k) - 1;
	max_ = dfs1(1, 0, 0);
	dfs(1, 0, 0);
	start = 1 << k;
	while (start > 0) {
		int div;
		if (path[start * 2] <= path[start * 2 + 1]) {
			div = path[start * 2];
			path[start * 2] = 0;
			path[start * 2 + 1] -= div;
		}
		else {
			div = path[start * 2 + 1];
			path[start * 2 + 1] = 0;
			path[start * 2] -= div;
		}
		path[start] += div;
		start--;
	}
	int ans = 0;
	for (int i = 1; i < size_; i++) {
		ans += tree[i];
		ans += path[i];
	}
	cout << ans;
	return 0;
}