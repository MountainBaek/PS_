/*17778번 게리맨더링2*/
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

struct PNT { int r, c; };
int N, ANS = INF;
int map[21][21];

bool range_chk(int r, int c, int rs, int re, int cs, int ce) {
	if (rs <= r && r <= re && cs <= c && c <= ce) return true;
	return false;
}

void bfs(int num, int chk[21][21], PNT start, int rs, int re, int cs, int ce) {
	queue<PNT>Q;
	int visit[21][21];
	memset(visit, 0, sizeof(visit));
	chk[start.r][start.c] = num;
	visit[start.r][start.c] = 1;
	Q.push(start);
	while (!Q.empty()) {
		PNT now = Q.front();
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = now.r + ("2011"[d] - '1');
			int nc = now.c + ("1120"[d] - '1');
			if (!range_chk(nr, nc, rs, re, cs, ce)) continue;
			if (chk[nr][nc] == 0 && visit[nr][nc] == 0) {
				Q.push({ nr,nc });
				chk[nr][nc] = num;
				visit[nr][nc] = 1;
			}
		}
	}
}

void cal(int chk[21][21]) {
	int max = 0, min = INF;
	int area[6] = { 0,0,0,0,0,0 };
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int val = map[r][c];
			if (chk[r][c] == 1) area[1] += val;
			else if(chk[r][c] == 2) area[2] += val;
			else if (chk[r][c] == 3) area[3] += val;
			else if (chk[r][c] == 4) area[4] += val;
			else area[5] += val;
		}
	}
	for (int n = 1; n <= 5; n++) {
		max = area[n] > max ? area[n] : max;
		min = area[n] < min ? area[n] : min;
	}
	int res = max - min;
	ANS = res < ANS ? res : ANS;
}

void set_area(int x, int y, int d1, int d2) {
	int chk[21][21];
	memset(chk, 0, sizeof(chk));
	//Line
	for (int i = 0; i <= d1; i++) chk[x + i][y - i] = 5;
	for (int i = 0; i <= d2; i++) chk[x + i][y + i] = 5;
	for (int i = 0; i <= d2; i++) chk[x + d1 + i][y - d1 + i] = 5;
	for (int i = 0; i <= d1; i++) chk[x + d2 + i][y + d2 - i] = 5;

	bfs(1, chk, { 1,1 }, 1, x + d1 - 1, 1, y);			//Area 1
	bfs(2, chk, { 1,N }, 1, x + d2, y + 1, N);			//Area 2
	bfs(3, chk, { N,1 }, x + d1, N, 1, y - d1 + d2 - 1);//Area 3
	bfs(4, chk, { N,N }, x + d2 + 1, N, y - d1 + d2, N);//Area 4

	cal(chk);	
}


void set_base() {
	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 < y; d1++) {
				for (int d2 = 1; d2 <= N - y && x + d1 + d2 <= N; d2++) {
					set_area(x, y, d1, d2);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int r = 1; r <= N; r++) for (int c = 1; c <= N; c++) cin >> map[r][c]; 

	set_base();
	
	cout << ANS;
	return 0;
}