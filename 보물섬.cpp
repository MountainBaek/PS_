#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct pnt { int r, c; };
int N, M, ans = 1e9;
string map[50];
int visit[50][50],arr[50][50];
int drc[] = { 0,0,-1,1,1,-1,0,0 };

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= M)) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	vector<pnt>land;
	for (int r = 0; r < N; r++) {
		cin >> map[r];
		for (int c = 0; c < M; c++) {
			if (map[r][c] == 'L')
				land.push_back({ r,c });
		}
	}
	int cnt = 0;
	for (int i = 0; i < land.size(); i++) {
		queue<pnt>Q;
		Q.push(land[i]);
		visit[land[i].r][land[i].c] = 1;
		while (!Q.empty()) {
			int r = Q.front().r;
			int c = Q.front().c;
			Q.pop();
			for (int d = 0; d < 4; d++) {
				int nr = r + drc[d];
				int nc = c + drc[d + 4];
				if (chk(nr, nc) && map[nr][nc] == 'L'&&visit[nr][nc] == 0) {
					visit[nr][nc] = visit[r][c] + 1;
					cnt = max(cnt, visit[nr][nc]);
					Q.push({ nr,nc });
				}
			}
		}
		memcpy(visit, arr, sizeof(arr));
	}
	cout << (cnt - 1);
	return 0;
}