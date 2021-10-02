#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
struct info { int r, c; };
int map[1000][1000];
int drc[] = { -1,-1,-1,0,1,1,1,0,-1,0,1,1,1,0,-1,-1 };
int H, W;

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= H || c >= W)) return true;
	else return false;
}

void printM() {
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			cout << map[r][c] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (register int tc = 1; tc <= T; tc++) {
		int ans = 0;
		cin >> H >> W;
		string in;
		for (register int r = 0; r < H; r++) {
			cin >> in;
			for (register int c = 0; c < W; c++) {
				if (in[c] != '.')
					map[r][c] = in[c] - '0';
			}
		}

		queue<info>Q;
		for (register int r = 0; r < H; r++) {
			for (register int c = 0; c < W; c++) {
				if (map[r][c] == 0) {
					for (register int d = 0; d < 8; d++) {
						int nr = r + drc[d];
						int nc = c + drc[d + 8];
						if (!chk(nr, nc)) continue;
						if (map[nr][nc] != 0) {
							map[nr][nc]--;
							if (map[nr][nc] == 0) {
								map[nr][nc] = -1;
								Q.push({ nr,nc });
							}
						}
					}
				}
			}
		}

		while (!Q.empty()) {
			//printM();
			int qs = Q.size();
			while (qs--) {
				int r = Q.front().r;
				int c = Q.front().c;
				Q.pop();
				for (int d = 0; d < 8; d++) {
					int nr = r + drc[d];
					int nc = c + drc[d + 8];
					if (!chk(nr, nc)) continue;
					if (map[nr][nc] != 0) {
						map[nr][nc]--;
						if (map[nr][nc] == 0) {
							map[nr][nc] = -1;
							Q.push({ nr,nc });
						}
					}
				}
			}
			ans++;
		}
		cout << '#' << tc << ' ' << ans << '\n';
		memset(map, 0, sizeof(map));
	}
	return 0;
}