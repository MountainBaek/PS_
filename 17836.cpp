/*공주님을 구하라*/
#include <iostream>
#include <queue>
#include <string.h>
#include <cassert>
using namespace std;
struct info { int r, c, sword; };
int N, M, T;
int map[101][101], visit[2][101][101];
int drc[] = { 0,0,1,-1,-1,1,0,0 };

bool chk(int r, int c) {
	if (!(r<1 || c<1 || r>N || c>M)) return true;
	return false;
}

void bfs() {
	queue<info>Q;
	Q.push({ 1,1,0});
	visit[0][1][1] = 0;
	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		bool sword = Q.front().sword;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = r + drc[d];
			int nc = c + drc[d + 4];
			if (!chk(nr, nc)) continue;
			if (sword) {
				if (visit[sword][nr][nc] == -1) {
					visit[sword][nr][nc] = visit[sword][r][c] + 1;
					if (nr == N && nc == M)return;
					Q.push({ nr,nc,sword });
				}
			}
			else {
				if (map[nr][nc] != 1 && visit[sword][nr][nc] == -1) {
					if (map[nr][nc] == 2) {
						visit[1][nr][nc] = visit[sword][r][c] + 1;
						Q.push({ nr,nc,1 });
					}
					else {
						Q.push({ nr,nc,sword });
						visit[sword][nr][nc] = visit[sword][r][c] + 1;
					}
					if (nr == N && nc == M)return;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> T;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> map[r][c];
		}
	}
	memset(visit, -1, sizeof(visit));
	bfs();
	int ans = -1;
	if (visit[0][N][M] != -1 && visit[1][N][M] != -1)
		ans = visit[1][N][M] < visit[0][N][M] ? visit[1][N][N] : visit[0][N][N];
	else if (visit[0][N][M] == -1 && visit[1][N][M] != -1)
		ans = visit[1][N][M];
	else if (visit[1][N][M] == -1 && visit[0][N][M] != -1)
		ans = visit[0][N][M];

	if (ans > T || ans == -1)cout << "Fail";
	else cout << ans;

	return 0;
}
/*
11 8 100
0 1 2 0 0 0 0 0
0 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0
ans : 31
*/