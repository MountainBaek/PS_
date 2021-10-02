#include <iostream>
#include <string.h>
#define ALIVE	false
#define DIE		true
using namespace std;

struct Pnt { int r, c; };
struct SHARK { int intake; Pnt pnt;};
struct FISH { bool status; Pnt pnt;};

int max_intake;

bool range_chk(int r, int c) {
	if (!(r < 0 || r >= 4 || c < 0 || c >= 4)) return true;
	return false;
}

bool fish_move_able_chk(int r, int c, int map[2][4][4]) {
	if (range_chk(r, c) && map[0][r][c] != -1) return true;
	return false;
}


void swap(int num1, int num2, FISH fish[17], int map[2][4][4]) {
	Pnt tmp = fish[num2].pnt;
	fish[num2].pnt = fish[num1].pnt;
	fish[num1].pnt = tmp;

	Pnt p1 = fish[num1].pnt;
	Pnt p2 = fish[num2].pnt;
	map[0][p1.r][p1.c] = num1;
	map[0][p2.r][p2.c] = num2;

	int dir_tmp = map[1][p1.r][p1.c];
	map[1][p1.r][p1.c] = map[1][p2.r][p2.c];
	map[1][p2.r][p2.c] = dir_tmp;
}

void move_fish(FISH fish[17], int map[2][4][4]){
	for (int num = 1; num < 17; num++) {
		if (fish[num].status == DIE) continue;
		int now_r	= fish[num].pnt.r;
		int now_c	= fish[num].pnt.c;
		int now_dir = map[1][now_r][now_c] - 1;

		for (int add = 0; add < 8; add++) {
			int nr = now_r + ("00122210"[(now_dir + add) % 8] - '1');
			int nc = now_c + ("10001222"[(now_dir + add) % 8] - '1');

			if (fish_move_able_chk(nr, nc, map)) {
				map[1][now_r][now_c] = (now_dir + add) % 8 + 1;
				int next = map[0][nr][nc];
				if (next == 0) {
					map[0][nr][nc] = num;
					map[1][nr][nc] = map[1][now_r][now_c];
					fish[num].pnt = { nr,nc };
					map[0][now_r][now_c] = 0;
					map[1][now_r][now_c] = 0;
				}
				else swap(num, next, fish, map);
				break;
			}
			else continue;
		}
	}
}

void feed(SHARK shark, FISH fish[17], int map[2][4][4]) {
	move_fish(fish, map);
	
	int add			= 1;
	int shark_r		= shark.pnt.r;
	int shark_c		= shark.pnt.c;
	int shark_dir	= map[1][shark_r][shark_c] - 1;
	while (1) {
		int nr = shark.pnt.r + ("00122210"[shark_dir] - '1') * add;
		int nc = shark.pnt.c + ("10001222"[shark_dir] - '1') * add;
		int next = map[0][nr][nc];
		add++;
		if (!range_chk(nr, nc)) break;
		if (next != 0) {
			int		aft_map[2][4][4];
			FISH	aft_fish[17];
			memcpy(aft_map, map, sizeof(aft_map));
			memcpy(aft_fish, fish, sizeof(aft_fish));
			
			SHARK aft_shark = { shark.intake + next,{nr,nc} };
			aft_map[0][shark_r][shark_c] = 0;
			aft_map[0][nr][nc] = -1;
			aft_map[1][shark_r][shark_c] = 0;
			aft_fish[next] = { DIE,{-1,-1} };
			feed(aft_shark, aft_fish, aft_map);
		}
	}

	max_intake = shark.intake > max_intake ? shark.intake : max_intake;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int map[2][4][4];
	SHARK shark;
	FISH fish[17];

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			int num, dir;
			cin >> num >> dir;
			map[0][r][c] = num;
			map[1][r][c] = dir;
			fish[num] = { ALIVE,{ r,c } };
		}
	}

	shark = { map[0][0][0],{0,0} };
	fish[map[0][0][0]] = { DIE,{-1,-1} };
	map[0][0][0] = -1;
	feed(shark, fish, map);
	cout << max_intake;
	return 0;
}