#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>
using namespace std;
struct pnt { int r, c; };
int N, L, R;
int map[50][50], visit[50][50];
int drc[] = { 0,0,-1,1,1,-1,0,0 };

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= N))return true;
	return false;
}

bool bfs() {
	bool OK = false;
	for (int rr = 0; rr < N; rr++) {
		for (int cc = 0; cc < N; cc++) {
			if (visit[rr][cc] == 1) continue;
			vector<pnt>UNION;
			queue<pnt>Q;
			Q.push({ rr,cc });
			UNION.push_back({ rr,cc });
			visit[rr][cc] = 1;
			while (!Q.empty()) {
				int r = Q.front().r;
				int c = Q.front().c;
				Q.pop();
				for (int d = 0; d < 4; d++) {
					int nr = r + drc[d];
					int nc = c + drc[d + 4];
					if (!chk(nr, nc)) continue;
					if (visit[nr][nc] == 1) continue;
					int sub = abs(map[r][c] - map[nr][nc]);
					if (L <= sub && sub <= R) {
						visit[nr][nc] = 1;
						UNION.push_back({ nr,nc });
						Q.push({ nr,nc });
						if (!OK) OK = true;
					}
				}
			}
			int sum = 0;
			for (int i = 0; i < UNION.size(); i++)
				sum += map[UNION[i].r][UNION[i].c];
			for (int i = 0; i < UNION.size(); i++)
				map[UNION[i].r][UNION[i].c] = sum / UNION.size();
		}
	}
	
	memset(visit, 0, sizeof(visit));
	return OK;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> L >> R;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> map[r][c];
	int cnt = 0;

	while (1) {
		if (bfs())
			cnt++;
		else
			break;
	}
	cout << cnt;
	return 0;
}