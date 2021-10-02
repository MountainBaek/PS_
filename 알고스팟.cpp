#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct pnt { int r, c };
int N, M, cnt;
int map[100][100], visit[2][100][100];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= M)) return true;
	return false;
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> M >> N;
	string in;
	for (int r = 0; r < N; r++) {
		cin >> in;
		for (int c = 0; c < M; c++) {
			map[r][c] = in[c] - '0';
		}
	}
	queue<pnt>Q;
	Q.push({ 0,0 });
	visit[0][0][0] = 1;
	visit[1][0][0] = 0;
	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		for (int d = 0; d < 4; d++) {
			int nr = r + drc[d];
			int nc = c + drc[d + 4];
			if (chk(nr, nc) && visit[nr][nc] == 0) {
				visit[0][nr][nc] = 1;
				if (map[nr][nc] == 1)
					visit[1][nr][nc] = visit[1][r][c] + 1;
				Q.push({ nr,nc });
			}
		}
	}
	return 0;
}