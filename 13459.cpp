/*±∏ΩΩ≈ª√‚*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct info { int redR, redC, blueR, blueC, turn; };
struct pnt { int r, c; };
struct tmp { int r, c, movedist;};
string map[10];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
int visit[10][10][10][10];
int N, M;
pnt hall;
queue<info>Q;

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= M)) return true;
	return false;
}

tmp move(int r, int c, int dir) {
	int cnt = 0;
	int rr = r;
	int cc = c;
	while (1) {
		int nr = rr + drc[dir];
		int nc = cc + drc[dir + 4];
		if (!chk(nr, nc)) break;
		if (map[nr][nc] == '#') break;
		rr = nr;
		cc = nc;
		cnt++;
		if (map[rr][cc] == 'O') break;
	}
	return { rr,cc,cnt };
}


void bfs() {
	while (!Q.empty()) {
		int redR = Q.front().redR, redC = Q.front().redC;
		int blueR = Q.front().blueR, blueC = Q.front().blueC;
		int turn = Q.front().turn;
		if (turn >= 10) break;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nRr = redR, nBr = blueR, nRc = redC, nBc = blueC;
			tmp Rm = move(nRr, nRc, d);
			tmp Bm = move(nBr, nBc, d);
			if (Bm.r == hall.r && Bm.c == hall.c) {
				continue;
			}
			if (Rm.r == hall.r &&Rm.c == hall.c) {
				cout << 1;
				return;
			}
			if (Rm.r == Bm.r && Rm.c == Bm.c) {
				if (Rm.movedist < Bm.movedist) {
					Bm.r -= drc[d];
					Bm.c -= drc[d + 4];
				}
				else {
					Rm.r -= drc[d];
					Rm.c -= drc[d + 4];
				}
			}
			nRr = Rm.r; nRc = Rm.c; nBr = Bm.r; nBc = Bm.c;
			//if (!chk(nRr, nRc) || !chk(nBr, nBc)) continue;
			if (visit[nRr][nRc][nBr][nBc] == 1) continue;
			visit[nRr][nRc][nBr][nBc] = 1;
			Q.push({ nRr,nRc,nBr,nBc,turn + 1 });
		}
	}
	cout << 0;
	return;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	int rr, rc, br, bc;
	for (int r = 0; r < N; r++) {
		cin >> map[r];
		for (int c = 0; c < M; c++) {
			if (map[r][c] == 'R') {
				rr = r, rc = c;
			}
			else if (map[r][c] == 'B') {
				br = r, bc = c;
			}
			else if (map[r][c] == 'O') {
				hall.r = r, hall.c = c;
			}
		}
	}
	Q.push({ rr,rc,br,bc,0 });
	visit[rr][rc][br][bc] = 1;
	bfs();
	return 0;
}