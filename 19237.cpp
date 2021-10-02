#include <iostream>
#include <vector>
#define REMAIN false
#define OUT true
using namespace std;

struct PNT	{ int r, c; };
struct INFO { PNT pnt; int dir;};
struct SHARK { INFO info; bool status; };
int		N, M, K, TIME, shark_cnt;
int		map[2][21][21]; // [0][][] : 상어번호, [1][][] :  상어냄새카운트
SHARK	shark[401];
int		table[401][4][4];
int		drc[] = { -1,1,0,0,0,0,-1,1 };

bool range_chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= N))return true;
	return false;
}

void discount_smell() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (map[0][r][c] != 0 && map[1][r][c] != 0)	map[1][r][c]--;
			if (map[1][r][c] == 0) map[0][r][c] = 0;
		}
	}
}

INFO find_next_pnt(int num) {
	int now_shark_view = shark[num].info.dir;
	//우선 순위에 따라 냄새가 없는 곳을 발견하면 해당좌표 return
	for (int idx = 0; idx < 4; idx++) {
		int d = table[num][now_shark_view][idx];
		int nr = shark[num].info.pnt.r + drc[d];
		int nc = shark[num].info.pnt.c + drc[d + 4];
		if (!range_chk(nr, nc)) continue;
		if (map[1][nr][nc] == 0) {
			return { { nr,nc },d };
		}
	}
	//위에서 냄새가 없는 곳을 찾지 못했을 경우 우선순위에 따라 내 냄새가 있는 좌표 return
	for (int idx = 0; idx < 4; idx++) {
		int d = table[num][now_shark_view][idx];
		int nr = shark[num].info.pnt.r + drc[d];
		int nc = shark[num].info.pnt.c + drc[d + 4];
		if (!range_chk(nr, nc)) continue;
		if (0 < map[1][nr][nc] && map[1][nr][nc] < K && map[0][nr][nc] == num) {
			return { { nr,nc },d };
		}
	}
}

void shark_move() {
	//이동할 방향을 우선 찾고	
	INFO next_pnt_dir[401];
	for (int num = 1; num <= M; num++) {
		if (shark[num].status == OUT) continue;
		int now_shark_view = shark[num].info.dir;
		next_pnt_dir[num] = find_next_pnt(num);
	}
	//지나온 길 냄새 1씩 줄이고
	discount_smell();

	//실제 이동
	for (int num = 1; num <= M; num++) {
		if (shark[num].status == OUT) continue;
		int nr = next_pnt_dir[num].pnt.r;
		int nc = next_pnt_dir[num].pnt.c;
		int ndir = next_pnt_dir[num].dir;
		int next_num = map[0][nr][nc];

		if (next_num == num) {
			map[1][nr][nc] = K;
			shark[num].info.pnt = { nr,nc };
			shark[num].info.dir = ndir;
		}
		else{
			if (next_num == 0) {
				map[0][nr][nc] = num;
				map[1][nr][nc] = K;
				shark[num].info.pnt = { nr,nc };
				shark[num].info.dir = ndir;
			}
			else {
				if (next_num < num) {
					shark[num] = { {{-1,-1},-1},OUT };
					shark_cnt--;
				}
				else {
					shark[next_num] = { {{-1,-1},-1},OUT };
					shark_cnt--;
					map[0][nr][nc] = num;
					map[1][nr][nc] = K;
					shark[num].info.pnt = { nr,nc };
					shark[num].info.dir = ndir;
				}
			}
		}
	}
	TIME++;
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> K;
	shark_cnt = M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[0][r][c];
			if (map[0][r][c] != 0) {
				shark[map[0][r][c]].info.pnt = { r,c };
				map[1][r][c] = K;
			}
		}
	}
	for (int num = 1; num <= M; num++) {
		cin >> shark[num].info.dir;
		shark[num].info.dir--;
	}

	for (int num = 1; num <= M; num++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> table[num][i][j];
				table[num][i][j]--;
			}
		}
	}
	bool flag = false;
	while (TIME < 1000) {
		shark_move();
		if (shark_cnt == 1) { flag = true; break; }
	}

	cout << (flag ? TIME : -1);
	
	return 0;
}