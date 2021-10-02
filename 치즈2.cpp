#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
struct pnt { int r, c; };
int map[101][101], visit[101][101], arr[101][101];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
int cheeze, R, C;

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= R || c >= C)) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
			if(map[r][c]==1)
				cheeze++;
		}
	}
	int time = 0;
	while (cheeze > 0) {
		queue<pnt>melt;
		queue<pnt>Q;
		Q.push({ 0,0 });

		while (!Q.empty()) {
			int r = Q.front().r;
			int c = Q.front().c;
			Q.pop();
			for (int d = 0; d < 4; d++) {
				int nr = r + drc[d];
				int nc = c + drc[d + 4];
				if (chk(nr, nc)) {
					if (map[nr][nc] == 0 && visit[nr][nc] == 0) {
						visit[nr][nc] = 1;
						Q.push({ nr,nc });
					}
					else if(map[nr][nc]==1 && visit[nr][nc] != -1) {
						visit[nr][nc]++;
						if (visit[nr][nc] >= 2) {
							melt.push({ nr,nc });
							visit[nr][nc] = -1;
						}
					}
				}
			}
		}
		time++;
		while (!melt.empty()) {
			map[melt.front().r][melt.front().c] = 0;
			melt.pop();
			cheeze--;
		}
		memcpy(visit, arr, sizeof(arr));
	}
	cout << time << '\n';
	return 0;
}