#include <iostream>
#include <queue>
using namespace std;
struct PNT { int r, c; };
int sea[15][15],visit[15][15]; int N; int T;
PNT start, finish;
int drc[] = { 0,0,-1,1,-1,1,0,0 };

bool range_chk(int r, int c) { return (0 <= r && r < N && 0 <= c && c < N) ? true : false; }

void print() {
	cout << "-----------------------" << endl;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << sea[r][c] << ' ';
		}
		cout << '\n';
	}
	cout << "-----------------------" << endl;
}

void init() {
	cin >> N;
	for (int r = 0; r < N; r++) { for (int c = 0; c < N; c++) { cin >> sea[r][c]; visit[r][c] = 0; if (sea[r][c] == 1)visit[r][c] = -1; } }
	cin >> start.r >> start.c;
	cin >> finish.r >> finish.c;
}

void bfs() {
	int result = -1;
	queue<PNT>Q;
	Q.push(start);
	visit[start.r][start.c] = 1;
	while (!Q.empty()) {
		PNT now = Q.front(); Q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = now.r + ("1102"[d] - '1');
			int nc = now.c + ("2011"[d] - '1');
			if (!range_chk(nr, nc))continue;
			if (visit[nr][nc] != 0)continue;
			if (sea[nr][nc] == 2) visit[nr][nc] = visit[now.r][now.c] + 1 + (2 - (visit[now.r][now.c] + 1) % 3);
			else visit[nr][nc] = visit[now.r][now.c] + 1;
			if (nr == finish.r && nc == finish.c) return;
			Q.push({ nr,nc });
		}
	}
}

void solve(int t) {
    bfs();
	int res = visit[finish.r][finish.c];
	res = (res == 0 ? -1 : res);
	cout << '#' << t << ' ' << res << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) { init(); solve(t); }
	return 0;
}
