#include <iostream>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;
ll tree[400001];
int N, Q;

void updata(int node,int val) {
	tree[node] = val;
	node /= 2;
	while (node > 0) {
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		node /= 2;
	}
}

ll sum(int l, int r) {
	ll ans = 0;
	while (l <= r) {
		if (l % 2 == 0)
			l /= 2;
		else {
			ans += tree[l];
			l = l / 2 + 1;
		}
		if (r % 2 == 1)
			r /= 2;
		else {
			ans += tree[r];
			r = r / 2 - 1;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> Q;
	int h = ceil(log2(N));
	int base = 1 << h;
	for (int i = base; i < base + N; i++)
		cin >> tree[i];
	int node = base - 1;
	while (node > 0) {
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		node--;
	}

	for (int i = 0; i < Q; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y)swap(x, y);
		cout << sum(base + x - 1, base + y - 1) << '\n';
		updata(base + a - 1, b);
	}
	return 0;
}