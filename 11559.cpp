/*11559번 PuyoPuyo*/
#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
struct pnt {
	int r, c;
	char color;
};
vector<pnt>puyo;
string map[12];
int visit[12][6];
int drc[] = { 0,0,-1,1,-1,1,0,0 };

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= 12 || c >= 6)) return true;
	else return false;
}

void putdown() {
	for (int c = 0; c < 6; c++) {
		vector<char>tmp;
		for (int r = 11; r >= 0; r--) {
			if (map[r][c] == '.')continue;
			tmp.push_back({ map[r][c] });
			map[r][c] = '.';
		}
		for (int r = 11, i = 0; r >= 0; i++, r--) {
			if (i == tmp.size())break;
			map[r][c] = tmp[i];
		}
	}
}

bool bfs() {
	bool OK = false;
	for (int rr = 0; rr < 12; rr++) {
		for (int cc = 0; cc < 6; cc++) {
			if (map[rr][cc] == '.') continue;
			if (visit[rr][cc] == 1)continue;
			queue<pnt>Q;
			Q.push({ rr,cc,map[rr][cc] });
			vector<pnt>group;
			while (!Q.empty()) {
				int r = Q.front().r;
				int c = Q.front().c;
				char color = Q.front().color;
				Q.pop();
				for (int d = 0; d < 4; d++) {
					int nr = r + drc[d];
					int nc = c + drc[d + 4];
					if (chk(nr, nc) && map[nr][nc] == color && visit[nr][nc] == 0) {
						visit[nr][nc] = 1;
						group.push_back({ nr,nc,map[nr][nc] });
						Q.push({ nr,nc,map[nr][nc] });
					}
				}
			}
			//뿌요 삭제
			if (group.size() >= 4) {
				if (!OK)OK = true;
				for (auto i : group) {
					map[i.r][i.c] = '.';
				}
			}
			group.clear();
		}
	}
	// 아래로 내리기
	putdown();
	memset(visit, 0, sizeof(visit));
	return OK;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int r = 0; r < 12; r++) 
		cin >> map[r];
	
	int combo = 0;
	while (1) {
		if (bfs()) combo++;
		else break;
	}
	cout << combo;
	return 0;
}
