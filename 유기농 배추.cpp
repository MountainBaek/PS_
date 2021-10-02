#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
struct pnt { int r, c; };
int N, M, K, idx;
int map[51][51], visit[51][51], arr[51][51];
int drc[] = { 0,0,-1,1,-1,1,0,0 };

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= M)) return true;
	else return false;
}

void bfs(queue<pnt>Q) {
	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = r + drc[d];
			int nc = c + drc[d + 4];
			if (chk(nr, nc) && map[nr][nc] == 1 && visit[nr][nc] == 0) {
				visit[nr][nc] = idx;
				Q.push({ nr,nc });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int r, c;
			cin >> c >> r;
			map[r][c] = 1;
		}

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (map[r][c] == 1 && visit[r][c] == 0) {
					queue<pnt>Q;
					Q.push({ r,c });
					visit[r][c] = ++idx;
					bfs(Q);
				}
			}
		}

		cout << idx << '\n';
		memcpy(visit, arr, sizeof(arr));
		memcpy(map, arr, sizeof(arr));
		idx = 0;
	}
	return 0;
}