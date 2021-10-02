#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct pnt { int r, c, j; };
int map[200][200], visit[2][200][200];//[0][][] : 이동 횟수, [1][][] : 말 움직임 사용 횟수
int dr[] = { 0,0,-1,1,-2,-2,-1,1,2,2,1,-1 };
int dc[] = { -1,1,0,0,-1,1,2,2,1,-1,-2,-2 };
int K, W, H, cnt;
queue<pnt>Q;

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= H || c >= W)) return true;
	return false;
}

void bfs() {
	Q.push({ 0,0,0 });
	visit[0][0][0] = 0;
	while (!Q.empty()) {
		pnt _now_ = Q.front();
		Q.pop();
		for (int d = 0; d < 12; d++) {
			if (d >= 4 && _now_.j == K)
				break;
			int nr = _now_.r + dr[d];
			int nc = _now_.c + dc[d];
			if (chk(nr, nc) && map[nr][nc] == 0) {
				if (d < 4) {//그냥 움직임
					if ((visit[0][nr][nc] == -1) || (visit[0][nr][nc] != -1 && visit[1][nr][nc] > _now_.j)) {
						visit[1][nr][nc] = _now_.j;
						visit[0][nr][nc] = visit[0][_now_.r][_now_.c] + 1;
						if (nr == H - 1 && nc == W - 1)
							return;
						Q.push({ nr,nc,_now_.j });
					}
				}
				else if (d >= 4 && _now_.j < K) {//말처럼 움직임
					if ((visit[0][nr][nc] == -1) || (visit[0][nr][nc] != -1 && visit[1][nr][nc] > _now_.j + 1)) {
						visit[1][nr][nc] = _now_.j + 1;
						visit[0][nr][nc] = visit[0][_now_.r][_now_.c] + 1;
						if (nr == H - 1 && nc == W - 1)
							return;
						Q.push({ nr,nc,_now_.j + 1 });
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> K >> W >> H;
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			cin >> map[r][c];
			visit[0][r][c] = -1;
		}
	}
	if (W == 1 && H == 1) cout << 0;
	else {
		bfs();
		cout << ((visit[0][H - 1][W - 1] != 0) ? visit[0][H - 1][W - 1] : -1) << '\n';
	}
	return 0;
}