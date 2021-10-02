/*3184번 양*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct pnt { int rr, cc; }temp;
int R, C;
string Map[250];
int area_chk[250][250];
queue<pnt>wolf_Q;
queue<pnt>sector;
int wolf, sheep, wolf_cnt, sheep_cnt;
int drc[] = { 0,0,-1,1,-1,1,0,0 };

int area_bfs(int r,int c) {
	temp.rr = r;
	temp.cc = c;
	sector.push(temp);
	if (Map[r][c] == 'v') {
		wolf_cnt = 1;
		sheep_cnt = 0;
	}
	else {
		wolf_cnt = 0;
		sheep_cnt = 1;
	}
	while (!sector.empty()) {
		int r = sector.front().rr;
		int c = sector.front().cc;
		area_chk[r][c] = 1;
		sector.pop();
		for (int d = 0; d < 4; d++) {
			int nr = r + drc[d];
			int nc = c + drc[d + 4];
			if (!(nr < 0 || nr >= R || nc < 0 || nc >= C)) {
				if (Map[nr][nc] != '#'&&area_chk[nr][nc] == 0) {
					temp.rr = nr;
					temp.cc = nc;
					sector.push(temp);
					area_chk[nr][nc] = 1;
					if (Map[nr][nc] == 'v') wolf_cnt++;
					if (Map[nr][nc] == 'o') sheep_cnt++;
				}
			}
		}
	}
	if (wolf_cnt >= sheep_cnt) return -1;
	else return 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		cin >> Map[r];
		for (int c = 0; c < Map[r].size(); c++) {
			if (Map[r][c] == 'v'|| Map[r][c] == 'o') {
				temp.rr = r;
				temp.cc = c;
				wolf_Q.push(temp);
			}
		}
	}
	while (!wolf_Q.empty()) {
		int r = wolf_Q.front().rr;
		int c = wolf_Q.front().cc;
		wolf_Q.pop();
		if (area_chk[r][c] == 0) {
			if (area_bfs(r, c) == 1)
				sheep += sheep_cnt;
			else
				wolf += wolf_cnt;
		}
	}
	
	cout << sheep << ' ' << wolf;
}


/*조건
1. .필드 #울타리 o양 v늑대
2. 한 영역에 양이 더 많으면 늑대 삭제, 늑대가 같거나 더 많으면 양 삭제
과정
1. 늑대와 양의 위치를 큐에 저장
2. 늑대와 양의 위치를 기반으로 BFS
2-1. 현재 늑대,양 위치가 방문했던 곳인지 확인 후 방문 했으면 Pass, 하지 않았으면 BFS시작
2-2. BFS하면서 양과 늑대 수를 카운트(시작 위치가 양이면 양을 1로 시작, 늑대면 늑대를 1로시작)
2-3. 늑대가 많으면 -1 반환 양이 많으면 1 반환
3. BFS반환값이 -1이면 늑대 수를 더하고 1이면 양 수를 더한다.
4. 양과 늑대의 수를 출력

*/