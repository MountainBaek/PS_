#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, ans = 0;
	cin >> N;
	vvi tree(N);
	vector<bool> visit(N);
	int root;
	for (int i = 0; i < N; i++) {
		int in;
		cin >> in;
		if (in == -1) {
			root = i;
			continue;
		}
		tree[in].push_back(i);
	}
	int del;
	cin >> del;
	visit[del] = true;

	queue<int>Q;
	if (!visit[root]) {
		Q.push(root);
		visit[root] = true;
	}
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		int child = 0;
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			if (visit[next]) continue;
			visit[next] = true;
			child++;
			Q.push(next);
		}
		if (child == 0)ans++;
	}

	cout << ans;
	return 0;
}