#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
struct pnt { 
	int r, c; 
};

int map[16][16];
int N, ans;

bool chk(int r, int c) {
	if (!(r >= N || c >= N)) return true;
	else return false;
}

void dfs(pnt front, pnt rear, int dir, int cnt) {
	if (front.r == N-1 && front.c == N-1) {
		//ans = cnt < ans ? cnt : ans;
		ans++;
		return;
	}
	int r = front.r;
	int c = front.c;
	switch (dir) { 
	case 1://가로
		if (chk(r, c + 1) && map[r][c + 1] == 0)
			dfs({ r,c + 1 }, front, 1, cnt + 1);
		if (chk(r + 1, c + 1) && map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)
			dfs({ r + 1,c + 1 }, front, 3, cnt + 1);
		break;
	case 2://세로
		if (chk(r + 1, c) && map[r + 1][c] == 0)
			dfs({ r + 1,c }, front, 2, cnt + 1);
		if (chk(r + 1, c + 1) && map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)
			dfs({ r + 1,c + 1 }, front, 3, cnt + 1);
		break;
	case 3://대각
		if (chk(r, c + 1) && map[r][c + 1] == 0)
			dfs({ r,c + 1 }, front, 1, cnt + 1);
		if (chk(r + 1, c) && map[r + 1][c] == 0)
			dfs({ r + 1,c }, front, 2, cnt + 1);
		if (chk(r + 1, c + 1) && map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0)
			dfs({ r + 1,c + 1 }, front, 3, cnt + 1);
		break;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
		}
	}
	dfs({ 0,1 }, { 0,0 }, 1, 0);
	cout << ans;
	return 0;
}