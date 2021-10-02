/*1726번 로봇*/
#include <iostream>
#include <queue>
#define INF 1000000
using namespace std;
struct info {
	int r, c;
	int dir;
	bool operator==(info cmp) {
		return r == cmp.r && c == cmp.c && dir == cmp.dir;
	}
};

int N, M;
int map[101][101];
int visit[5][101][101];
int drc[] = { 0,0,0,1,-1,1,-1,0,0 };
int cmd[5][5] = {
{0,0,0,0,0},
{0,0,2,1,1},
{0,2,0,1,1},
{0,1,1,0,2},
{0,1,1,2,0}
};

info start, GOAL;

bool chk(int r, int c) {
	if (!(r < 1 || c < 1 || r > N || c > M)) return true;
	return false;
}

void bfs() {
	queue<info>Q;
	Q.push(start);
	while (!Q.empty()) {
		info now = Q.front();
		Q.pop();
		int r = now.r;
		int c = now.c;
		int dir = now.dir;
		if (now == GOAL) {
			cout << visit[dir][r][c];
			return;
		}
		for (int go = 1; go <= 3; go++) {//해당 방향 직진
			int gor = r + drc[dir] * go;
			int goc = c + drc[dir + 4] * go;
			if (!chk(gor, goc)) break;
			if (map[gor][goc] != 0)break;;
			if (visit[dir][gor][goc] != 0)continue;
			visit[dir][gor][goc] = visit[dir][r][c] + 1;
			Q.push({ gor,goc,dir });
		}
		for (int d = 1; d <= 4; d++) { //회전 처리
			if (d == dir) continue;
			if (visit[d][r][c] != 0) continue;
			Q.push({ r,c,d });
			visit[d][r][c] = visit[dir][r][c] + cmd[dir][d];
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> map[r][c];
		}
	}
	int sr, sc, sd, er, ec, ed;
	cin >> sr >> sc >> sd >> er >> ec >> ed;
	start = { sr,sc,sd }, GOAL = { er,ec,ed };
	bfs();
	return 0;
}