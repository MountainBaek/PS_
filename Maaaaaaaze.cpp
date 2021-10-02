#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
#define min(a,b) a<b?a:b
using namespace std;
struct pnt { int r, c, h; };
int map[5][5][5],map2[5][5][5];//[Ãþ][r][c]
int visit[5][5][5], arr[5][5][5];
int tmp[5][5];
int check[5];
int dr[] = { 0,0,1,-1,0,0 };
int dc[] = { 0,0,0,0,1,-1 };
int dh[] = { 1,-1,0,0,0,0 };
int ans = 987654321;

bool chk(int r, int c, int h) {
	if (!(r < 0 || c < 0 || h < 0 || r >= 5 || c >= 5 || h >= 5)) return true;
	return false;
}

void go(queue<pnt>Q) {
	bool END = false;
	while (!Q.empty()) {
		int rr = Q.front().r;
		int cc = Q.front().c;
		int hh = Q.front().h;
		Q.pop();
		for (int d = 0; d < 6; d++) {
			int nr = rr + dr[d];
			int nc = cc + dc[d];
			int nh = hh + dh[d];
			if (chk(nr, nc, nh) && map[nh][nr][nc] == 1 && visit[nh][nr][nc] == 0) {
				visit[nh][nr][nc] = visit[hh][rr][cc] + 1;
				
				if ((nh == 4 && nr == 4 && nc == 4) || (visit[nh][nr][nc] > ans))
					return;

				Q.push({ nr,nc,nh });
			}
		}
	}
}

void spin(int f) {
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			tmp[c][4 - r] = map[f][r][c];
		}
	}
	memcpy(map[f], tmp, sizeof(tmp));
}

void dfs(int dep) {
	if (dep == 5) {
		//Å½»ö
		queue<pnt>Q;
		if (map[0][0][0] == 1) {
			Q.push({ 0,0,0 });
			visit[0][0][0] = 1;
			go(Q);
		}
		if (visit[4][4][4] > 0)
			ans = min(ans, visit[4][4][4] - 1);
		
		memcpy(visit, arr, sizeof(visit));
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			spin(dep);
			dfs(dep + 1);
		}
	}
}

void stack(int idx) {
	if (idx == 5) {
		dfs(0);
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			memcpy(map[idx], map2[i], sizeof(map[idx]));
			stack(idx + 1);
			check[i] = 0;
		}
	}


}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int f = 0; f < 5; f++)
		for (int r = 0; r < 5; r++)
			for (int c = 0; c < 5; c++)
				cin >> map2[f][r][c];
	//½×¾Æº¸±â
	stack(0);
	if (ans == 987654321) ans = -1;
	cout << ans;
	return 0;
}