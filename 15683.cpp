/*15683¹ø °¨½Ã*/
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
struct Cam{ int r, c, dir, kinds; }temp[8]; //dir U:0, R:1, D:2, L:3
int Map[8][8];
int N, M;
int cam_cnt;
int Min_B = 100;

bool chk(int r, int c) {
	if (!(r < 0 || r >= N || c < 0 || c >= M)) {
		if (Map[r][c] != 6) return true;
		else return false;
	}
	else return false;
}

void UP(int r,int c){
	int rr = r;
	int cc = c;
	while (1) {
		if (chk(rr-1, cc) == true) {
			rr--;
			Map[rr][cc] = -1;
		}
		else break;
	}
}
void DOWN(int r, int c) {
	int rr = r;
	int cc = c;
	while (1) {
		if (chk(rr+1, cc) == true) {
			rr++;
			Map[rr][cc] = -1;
		}
		else break;
	}
}
void RIGTH(int r, int c) {
	int rr = r;
	int cc = c;
	while (1) {
		if (chk(rr, cc+1) == true) {
			cc++;
			Map[rr][cc] = -1;
		}
		else break;
	}
}
void LEFT(int r, int c) {
	int rr = r;
	int cc = c;
	while (1) {
		if (chk(rr, cc-1) == true) {
			cc--;
			Map[rr][cc] = -1;
		}
		else break;
	}
}

void search() {
	int k, d, r, c;
	for (int cam = 0; cam < cam_cnt; cam++) {
		k = temp[cam].kinds;
		d = temp[cam].dir;
		r = temp[cam].r;
		c = temp[cam].c;
		switch (k) {
		case 1:
			if (d == 0) {
				UP(r, c);
			}
			else if (d == 1) {
				RIGTH(r, c);
			}
			else if (d == 2) {
				DOWN(r, c);
			}
			else {
				LEFT(r, c);
			}
			break;
		case 2:
			if (d == 0 || d == 2) {
				UP(r, c);
				DOWN(r, c);
			}
			else {
				RIGTH(r, c);
				LEFT(r, c);
			}
			break;
		case 3:
			if (d == 0) {
				UP(r, c);
				RIGTH(r, c);
			}
			else if (d == 1) {
				RIGTH(r, c);
				DOWN(r, c);
			}
			else if (d == 2) {
				DOWN(r, c);
				LEFT(r, c);
			}
			else {
				LEFT(r, c);
				UP(r, c);
			}
			break;
		case 4:
			if (d == 0) {
				UP(r, c);
				RIGTH(r, c);
				LEFT(r, c);
			}
			else if (d == 1) {
				UP(r, c);
				RIGTH(r, c);
				DOWN(r, c);
			}
			else if (d == 2) {
				RIGTH(r, c);
				DOWN(r, c);
				LEFT(r, c);
			}
			else {
				UP(r, c);
				DOWN(r, c);
				LEFT(r, c);
			}
			break;
		case 5:
			UP(r, c);
			RIGTH(r, c);
			DOWN(r, c);
			LEFT(r, c);
			break;
		}
	}
	int zero_cnt=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 0) zero_cnt++;
		}
	}
	if (zero_cnt < Min_B) Min_B = zero_cnt;
}

void set_dir(int cnt) {
	if (cnt == cam_cnt) {
		int Map_backup[8][8];
		memcpy(Map_backup, Map, sizeof(Map));
		search();
		memcpy(Map, Map_backup, sizeof(Map));
	}
	else {
		for (int d = 0; d < 4; d++) {
			int dir_backup = temp[cnt].dir;
			temp[cnt].dir = d;
			set_dir(cnt + 1);
			temp[cnt].dir = dir_backup;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> Map[r][c];
			if (0 < Map[r][c] && Map[r][c] < 6) {
				temp[cam_cnt].kinds = Map[r][c];
				temp[cam_cnt].r = r;
				temp[cam_cnt].c = c;
				cam_cnt++;
			}
		}
	}
	set_dir(0);
	cout << Min_B<<endl;
}
/*-----------------------------------------------------------------------------------*/
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
struct Cam { int r, c, dir, kinds; }temp[8]; //dir U:0, R:1, D:2, L:3
int Map[8][8];
int N, M, cam_cnt,blind_area;
int Min_B = 100, Min_area = 100;

bool chk(int r, int c) {
	if (!(r < 0 || r >= N || c < 0 || c >= M)) {
		if (Map[r][c] != 6) return true;
		else return false;
	}
	else return false;
}

void UP(int r, int c) {
	int rr = r;
	int cc = c;
	while (1) {
		if (chk(rr - 1, cc) == true) {
			rr--;
			if (Map[rr][cc] == 0) blind_area--;
			Map[rr][cc] = -1;
		}
		else break;
	}
}
void DOWN(int r, int c) {
	int rr = r;
	int cc = c;
	while (1) {
		if (chk(rr + 1, cc) == true) {
			rr++;
			if (Map[rr][cc] == 0) blind_area--;
			Map[rr][cc] = -1;
		}
		else break;
	}
}
void RIGTH(int r, int c) {
	int rr = r;
	int cc = c;
	while (1) {
		if (chk(rr, cc + 1) == true) {
			cc++;
			if (Map[rr][cc] == 0) blind_area--;
			Map[rr][cc] = -1;
		}
		else break;
	}
}
void LEFT(int r, int c) {
	int rr = r;
	int cc = c;
	while (1) {
		if (chk(rr, cc - 1) == true) {
			cc--;
			if (Map[rr][cc] == 0) blind_area--;
			Map[rr][cc] = -1;
		}
		else break;
	}
}

void search() {
	int k, d, r, c;
	for (int cam = 0; cam < cam_cnt; cam++) {
		k = temp[cam].kinds;
		d = temp[cam].dir;
		r = temp[cam].r;
		c = temp[cam].c;
		switch (k) {
		case 1:
			if (d == 0) {
				UP(r, c);
			}
			else if (d == 1) {
				RIGTH(r, c);
			}
			else if (d == 2) {
				DOWN(r, c);
			}
			else {
				LEFT(r, c);
			}
			break;
		case 2:
			if (d == 0 || d == 2) {
				UP(r, c);
				DOWN(r, c);
			}
			else {
				RIGTH(r, c);
				LEFT(r, c);
			}
			break;
		case 3:
			if (d == 0) {
				UP(r, c);
				RIGTH(r, c);
			}
			else if (d == 1) {
				RIGTH(r, c);
				DOWN(r, c);
			}
			else if (d == 2) {
				DOWN(r, c);
				LEFT(r, c);
			}
			else {
				LEFT(r, c);
				UP(r, c);
			}
			break;
		case 4:
			if (d == 0) {
				UP(r, c);
				RIGTH(r, c);
				LEFT(r, c);
			}
			else if (d == 1) {
				UP(r, c);
				RIGTH(r, c);
				DOWN(r, c);
			}
			else if (d == 2) {
				RIGTH(r, c);
				DOWN(r, c);
				LEFT(r, c);
			}
			else {
				UP(r, c);
				DOWN(r, c);
				LEFT(r, c);
			}
			break;
		case 5:
			UP(r, c);
			RIGTH(r, c);
			DOWN(r, c);
			LEFT(r, c);
			break;
		}
	}
	if (blind_area < Min_area) Min_area = blind_area;
}

void set_dir(int cnt) {
	if (cnt == cam_cnt) {
		int Map_backup[8][8];
		int area_backup = blind_area;
		memcpy(Map_backup, Map, sizeof(Map));
		search();
		memcpy(Map, Map_backup, sizeof(Map));
		blind_area = area_backup;
	}
	else {
		for (int d = 0; d < 4; d++) {
			int dir_backup = temp[cnt].dir;
			temp[cnt].dir = d;
			set_dir(cnt + 1);
			temp[cnt].dir = dir_backup;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> Map[r][c];
			if (0 < Map[r][c] && Map[r][c] < 6) {
				temp[cam_cnt].kinds = Map[r][c];
				temp[cam_cnt].r = r;
				temp[cam_cnt].c = c;
				cam_cnt++;
			}
			else if (Map[r][c] == 0) {
				blind_area++;
			}
		}
	}
	set_dir(0);
	cout << Min_area << endl;
}