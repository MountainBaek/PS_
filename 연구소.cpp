#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
struct pnt { int r; int c; };

vector<pnt> space;
int map[8][8];
int visit[8][8];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
int N, M, ans;

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= M)) return true;
	return false;
}

void bfs(queue<pnt>virus) {
	int safe = 0;
	while (!virus.empty()) {
		int r = virus.front().r;
		int c = virus.front().c;
		virus.pop();
		for (register int d = 0; d < 4; d++) {
			int nr = r + drc[d];
			int nc = c + drc[d + 4];
			if (chk(nr, nc) && map[nr][nc] == 0 && visit[nr][nc] == 0) {
				visit[nr][nc] = 1;
				map[nr][nc] = 2;
				virus.push({ nr,nc });
			}
		}
	}
	for (register int r = 0; r < N; r++) {
		for (register int c = 0; c < M; c++) {
			if (map[r][c] == 0 && visit[r][c] == 0)
				safe++;
		}
	}
	ans = ans < safe ? safe : ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	queue<pnt>virus;
	for (register int r = 0; r < N; r++) {
		for (register int c = 0; c < M; c++) {
			cin >> map[r][c];
			if (map[r][c] == 0)
				space.push_back({ r,c });
			if (map[r][c] == 2) {
				virus.push({ r,c });
				visit[r][c] = 1;
			}
		}
	}

	for (register int w1 = 0; w1 < space.size(); w1++) {
		int r = space[w1].r, c = space[w1].c;
		if (map[r][c] != 0)continue;
		map[r][c] = 1;
		for (register int w2 = w1 + 1; w2 < space.size(); w2++) {
			int rr = space[w2].r, cc = space[w2].c;
			if (map[rr][cc] != 0)continue;
			map[rr][cc] = 1;
			for (register int w3 = w2 + 1; w3 < space.size(); w3++) {
				int rrr = space[w3].r, ccc = space[w3].c;
				if (map[rrr][ccc] != 0)continue;
				map[rrr][ccc] = 1;
				int tmp_map[8][8], tmp_visit[8][8];
				memcpy(tmp_map, map, sizeof(map));
				memcpy(tmp_visit, visit, sizeof(visit));
				bfs(virus);
				memcpy(map, tmp_map, sizeof(map));
				memcpy(visit, tmp_visit, sizeof(visit));
				map[rrr][ccc] = 0;
			}
			map[rr][cc] = 0;
		}
		map[r][c] = 0;
	}
	cout << ans;
	return 0;
}