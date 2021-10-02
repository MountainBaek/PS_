#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
struct pnt { int r, c; };
int N, M;
int map[1000][1000];
int visit[2][1000][1000];
int ans[1000][1000];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= M)) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	vector<pnt>wall, space;
	for (int r = 0; r < N; r++) {
		string in;
		cin >> in;
		for (int c = 0; c < M; c++) {
			map[r][c] = in[c] - '0';
			if (map[r][c] == 1) wall.push_back({ r,c });
			else space.push_back({ r,c });
		}
	}
	//ºó°ø°£ ±×·ì
	int idx = 1;
	for (auto s : space) {
		if (visit[0][s.r][s.c] != 0)continue;
		vector<pnt>tmp;
		queue<pnt>Q;
		Q.push(s);
		visit[0][s.r][s.c] = 1;
		tmp.push_back(s);
		int area = 0;
		while (!Q.empty()) {
			area++;
			int r = Q.front().r;
			int c = Q.front().c;
			Q.pop();
			for (int d = 0; d < 4; d++) {
				int nr = r + drc[d];
				int nc = c + drc[d + 4];
				if (!chk(nr, nc)) continue;
				if (map[nr][nc] == 1) continue;
				if (visit[0][nr][nc] != 0) continue;
				visit[0][nr][nc] = 1;
				Q.push({ nr,nc });
				tmp.push_back({ nr,nc });
			}
		}
		for (auto n : tmp) {
			visit[0][n.r][n.c] = area;
			visit[1][n.r][n.c] = idx;
		}
		idx++;
	}
	
	for (auto w : wall) {
		vector<bool>used(idx + 1);
		int area = 1;
		for (int d = 0; d < 4; d++) {
			int nr = w.r + drc[d];
			int nc = w.c + drc[d + 4];
			if (!chk(nr, nc)) continue;
			if (visit[0][nr][nc] != 0 && !used[visit[1][nr][nc]]) {
				used[visit[1][nr][nc]] = true;
				area += visit[0][nr][nc];
			}
		}
		ans[w.r][w.c] = area%10;
	}
	
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cout << ans[r][c];
		}
		cout << '\n';
	}
	return 0;
}