#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, K;
int drc[] = { -1,-1,-1,0,1,1,1,0,-1,0,1,1,1,0,-1,-1 };
int energy[11][11], add[11][11], death[11][11];
priority_queue<int, vector<int>, greater<int>> tree[11][11];
bool chk(int r, int c) {
	if (!(r<1 || c<1 || r>N || c>N)) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> K;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> add[r][c];
			energy[r][c] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int r, c, a;
		cin >> r >> c >> a;
		tree[r][c].push(a);
	}

	while (K--) {
		//??
		int nowE = 0;
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (tree[r][c].size() == 0)continue;
				priority_queue<int, vector<int>, greater<int>> tmp;
				while (!tree[r][c].empty()) {
					int top = tree[r][c].top();
					tree[r][c].pop();
					if (top <= energy[r][c]) {
						energy[r][c] -= top;
						tmp.push(top + 1);
					}
					else {
						death[r][c] += (top / 2);
					}
				}
				tree[r][c] = tmp;
			}
		}

		//????
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (death[r][c] == 0)continue;
				energy[r][c] += death[r][c];
				death[r][c] = 0;
			}
		}

		//????
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (tree[r][c].size() == 0)continue;
				priority_queue<int, vector<int>, greater<int>> tmp;
				tmp = tree[r][c];
				while (!tmp.empty()) {
					int top = tmp.top();
					tmp.pop();
					if (top % 5 != 0)continue;
					for (int d = 0; d < 8; d++) {
						int nr = r + drc[d];
						int nc = c + drc[d + 8];
						if (!chk(nr, nc))continue;
						tree[nr][nc].push(1);
					}
				}
			}
		}
		//???
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				energy[r][c] += add[r][c];
			}
		}
	}
	int ans = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (tree[r][c].size() == 0)continue;
			ans += tree[r][c].size();
		}
	}
	cout << ans;
	return 0;
}