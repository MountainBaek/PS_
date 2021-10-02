#include <iostream>
#include <queue>
using namespace std;

struct pnt { int r, c; };
struct info { int d, updata; };
int Map[51][51];
int updata[51][51];
pnt am_top, am_bottom;
bool _top, _bottom;
int Q_chk = 0;
int R, C, T;
pnt drc[4] = { {-1,0},{0,1},{1,0},{0,-1} };

void _updata() {
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (Map[r][c] != -1) {
				Map[r][c] += updata[r][c];
				updata[r][c] = 0;
			}
		}
	}
}

queue<pnt> dust_chk(queue<pnt>dust) {
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (Map[r][c] != 0) {
				if (Map[r][c] == -1) {
					if (_top == false) {
						am_top = { r,c };
						_top = true;
					}
					else {
						am_bottom = { r,c };
						_bottom = true;
					}
				}
				else {
					dust.push({ r,c });
					Q_chk++;
				}
			}
		}
	}
	return dust;
}

void wind(int up_down, int r, int c, int d, info prev_dust) {//up_down : 0 (위) 1(아래)
	if (r == am_top.r && c == am_top.c) {
		return;
	}
	else {
		info tmp = { Map[r][c],updata[r][c] };
		Map[r][c] = prev_dust.d;
		int nr = r + drc[d].r;
		int nc = c + drc[d].c;
		if (!(nr < 1 || nr>R || nc<1 || nc>C)) {
			if (Map[nr][nc] != -1) {
				wind(up_down, nr, nc, d, tmp);
			}
		}
		else {
			if (nr < 1 || nr > R) {
				d = 3;
			}
			else if (nc < 1) {
				if (up_down == 0)
					d = 2;
				else
					d = 0;
			}
			else if (nc > C) {
				if (up_down == 0)
					d = 0;
				else
					d = 2;
			}
			nr = r + drc[d].r;
			nc = c + drc[d].c;
			wind(up_down, nr, nc, d, tmp);

		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C >> T;
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cin >> Map[r][c];
		}
	}
	
	int Q_chk_tmp = 0;
	while (T--) {
		queue<pnt>dust;
		Q_chk = 0;
		dust = dust_chk(dust);
		//먼지확산
		while (Q_chk--) {
			int rr = dust.front().r;
			int cc = dust.front().c;
			int temp = Map[rr][cc] / 5;
			dust.pop();
			for (int d = 0; d < 4; d++) {
				int nr = rr + drc[d].r;
				int nc = cc + drc[d].c;
				if (!(nr < 1 || nr >R || nc <1 || nc > C) && Map[nr][nc] != -1) {
					updata[nr][nc] += temp;
					Map[rr][cc] -= temp;
					Q_chk_tmp++;
				}
			}
		}
		Q_chk = Q_chk_tmp;
		_updata();
		//공기청정기 가동
		//위
		pnt blow = { am_top.r,am_top.c };
		info blow_wind = { 0,0 };
		int dir = 1;
		int nr = blow.r + drc[dir].r;
		int nc = blow.c + drc[dir].c;
		wind(0, nr, nc, dir, blow_wind);
		//아래
		blow = { am_bottom.r,am_bottom.c };
		nr = blow.r + drc[dir].r;
		nc = blow.c + drc[dir].c;
		wind(1, nr, nc, dir, blow_wind);
	}
	int ans = 0;
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (Map[r][c] != -1 && Map[r][c] != 0) {
				ans += Map[r][c];
			}
		}
	}
	cout << ans;
	return 0;
}
