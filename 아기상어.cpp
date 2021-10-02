#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
struct Shark { int r, c, size, feed; };
struct info { int r, c, dist; };
int N,moveCnt;
int map[20][20], visit[20][20];
int drc[] = { -1,0,1,0,0,-1,0,1 };
Shark baby;
queue<info>Q, tmp;
bool cmp(const info &a, const info &b) {
	if (a.dist < b.dist) return true;
	else if (a.dist == b.dist) {
		if (a.r < b.r) return true;
		else if (a.r == b.r) return a.c < b.c;
	}
	return false;
}

bool chk(int r, int c) {
	if (r < 0 || c < 0 || r >= N || c >= N) return true;
	return false;
}
void bfs() {
	while (!Q.empty()) {
		int abledist = 987654321;
		vector<info>fish;
		while (!Q.empty()) {
			int r = Q.front().r;
			int c = Q.front().c;
			int dist = Q.front().dist;
			Q.pop();
			for (int d = 0; d < 4; d++) {
				int nr = r + drc[d];
				int nc = c + drc[d + 4];
				if (chk(nr, nc)) continue;
				if (map[nr][nc] > baby.size) continue;
				if (visit[nr][nc] != -1) continue;

				if (map[nr][nc] == baby.size || map[nr][nc] == 0) {
					if (visit[r][c] + 1 <= abledist) {
						visit[nr][nc] = visit[r][c] + 1;
						Q.push({ nr,nc,visit[nr][nc] });
					}
				}
				else {
					if (map[nr][nc] != 0) {
						visit[nr][nc] = visit[r][c] + 1;
						abledist = visit[nr][nc];
						fish.push_back({ nr,nc,visit[nr][nc] });
					}
				}
			}
		}
		if (fish.size() > 0) {
			sort(fish.begin(), fish.end(), cmp);
			map[fish[0].r][fish[0].c] = 0;
			moveCnt += visit[fish[0].r][fish[0].c];
			baby.r = fish[0].r;
			baby.c = fish[0].c;
			baby.feed++;
			if (baby.feed == baby.size) {
				baby.size++;
				baby.feed = 0;
			}
			memset(visit, -1, sizeof(visit));
			visit[baby.r][baby.c] = 0;
			Q.push({ baby.r,baby.c,0 });
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
			if (map[r][c] == 9) {
				baby = { r,c,2,0 };
				map[r][c] = 0;
			}
		}
	}
	memset(visit, -1, sizeof(visit));
	Q.push({ baby.r,baby.c,0 });
	visit[baby.r][baby.c] = 0;
	bfs();
	cout << moveCnt;
	return 0;
}