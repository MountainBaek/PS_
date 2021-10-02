#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
struct pnt {
	int r, c, val;
	bool operator<(const pnt& cmp) const {
		return val > cmp.val;
	}
};
int N, K, T, ans;
int drc[] = { 0,0,-1,1,-1,1,0,0 };
int map[10][10];
bool visit[10][10];

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= N)) return 1;
	return 0;
}

void dfs(int r, int c, int len, bool isDig) {
	for (int d = 0; d < 4; d++) {
		int nr = r + drc[d];
		int nc = c + drc[d + 4];
		if (!chk(nr, nc) || visit[nr][nc]) continue;
		if (map[nr][nc] >= map[r][c]) {
			if (isDig) continue;
			for (int dig = 0; dig <= K; dig++) {
				if (map[nr][nc] - dig >= map[r][c]) continue;
				visit[nr][nc] = 1;
				map[nr][nc] -= dig;
				dfs(nr, nc, len + 1, 1);
				map[nr][nc] += dig;
				visit[nr][nc] = 0;
			}
		}
		else {
			visit[nr][nc] = 1;
			dfs(nr, nc, len + 1, isDig);
			visit[nr][nc] = 0;
		}
	}
	ans = ans < len ? len : ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	int tc = 1;
	while (T--) {
		vector<pnt>top;
		cin >> N >> K;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				cin >> map[r][c];
				top.push_back({ r,c,map[r][c] });
			}
		}

		sort(top.begin(), top.end());

		int max = top[0].val;

		for (int i = 0, size = top.size(); i < size; i++) {
			if (top[i].val != max) break;
			int r = top[i].r;
			int c = top[i].c;
			visit[r][c] = 1;
			dfs(r, c, 1, 0);
			visit[r][c] = 0;
		}
		cout << '#' << tc++ << ' ' << ans << '\n';
		ans = 0;
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}