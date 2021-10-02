/*5373¹ø Å¥ºù*/
#include <iostream>
using namespace std;
char cube[55]; // 1-9(U) 10-18(D) 18-27(F) 28-36(B) 37-45(L) 46-54(R)
char commd[2];
int T,commd_cnt;

void init() {
	for (int i = 1; i <= 54; i++) {
		if (0 < i && i <= 9) cube[i] = 'w';
		else if (9 < i && i <= 18) cube[i] = 'y';
		else if (18 < i && i <= 27) cube[i] = 'r';
		else if (27 < i && i <= 36) cube[i] = 'o';
		else if (36 < i && i <= 45) cube[i] = 'g';
		else if (45 < i && i <= 54) cube[i] = 'b';
	}
}

void spin_square(int side) {
	int tmp;
	tmp = cube[side]; cube[side] = cube[side + 6]; cube[side + 6] = cube[side + 8]; cube[side + 8] = cube[side + 2]; cube[side + 2] = tmp;
	tmp = cube[side + 1]; cube[side + 1] = cube[side + 3]; cube[side + 3] = cube[side + 7]; cube[side + 7] = cube[side + 5]; cube[side + 5] = tmp;
}

void spin_side(int num) {
	int tmp;
	if (num == 0) { //U
		tmp = cube[34]; cube[34] = cube[45]; cube[45] = cube[21]; cube[21] = cube[46]; cube[46] = tmp;
		tmp = cube[35]; cube[35] = cube[42]; cube[42] = cube[20]; cube[20] = cube[49]; cube[49] = tmp;
		tmp = cube[36]; cube[36] = cube[39]; cube[39] = cube[19]; cube[19] = cube[52]; cube[52] = tmp;
	}
	else if (num == 1) {//D
		tmp = cube[25]; cube[25] = cube[37]; cube[37] = cube[30]; cube[30] = cube[54]; cube[54] = tmp;
		tmp = cube[26]; cube[26] = cube[40]; cube[40] = cube[29]; cube[29] = cube[51]; cube[51] = tmp;
		tmp = cube[27]; cube[27] = cube[43]; cube[43] = cube[28]; cube[28] = cube[48]; cube[48] = tmp;
	}
	else if (num == 2) {//F
		tmp = cube[7]; cube[7] = cube[43]; cube[43] = cube[12]; cube[12] = cube[52]; cube[52] = tmp;
		tmp = cube[8]; cube[8] = cube[44]; cube[44] = cube[11]; cube[11] = cube[53]; cube[53] = tmp;
		tmp = cube[9]; cube[9] = cube[45]; cube[45] = cube[10]; cube[10] = cube[54]; cube[54] = tmp;
	}//
	else if (num == 3) {//B
		tmp = cube[16]; cube[16] = cube[39]; cube[39] = cube[3]; cube[3] = cube[48]; cube[48] = tmp;
		tmp = cube[17]; cube[17] = cube[38]; cube[38] = cube[2]; cube[2] = cube[47]; cube[47] = tmp;
		tmp = cube[18]; cube[18] = cube[37]; cube[37] = cube[1]; cube[1] = cube[46]; cube[46] = tmp;
	}
	else if (num == 4) {//L
		tmp = cube[28]; cube[28] = cube[10]; cube[10] = cube[19]; cube[19] = cube[1]; cube[1] = tmp;
		tmp = cube[31]; cube[31] = cube[13]; cube[13] = cube[22]; cube[22] = cube[4]; cube[4] = tmp;
		tmp = cube[34]; cube[34] = cube[16]; cube[16] = cube[25]; cube[25] = cube[7]; cube[7] = tmp;
	}
	else if (num == 5) {//R
		tmp = cube[36]; cube[36] = cube[9]; cube[9] = cube[27]; cube[27] = cube[18]; cube[18] = tmp;
		tmp = cube[33]; cube[33] = cube[6]; cube[6] = cube[24]; cube[24] = cube[15]; cube[15] = tmp;
		tmp = cube[30]; cube[30] = cube[3]; cube[3] = cube[21]; cube[21] = cube[12]; cube[12] = tmp;
	}

}

void spin(int side,char dir) {
	int d = (dir == '+') ? 1 : 3;
	for (int i = 0; i < d; i++) {
		spin_square((side * 9 + 1));
		spin_side(side);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		init();
		cin >> commd_cnt;
		for (int i = 0; i < commd_cnt; i++) {
			cin >> commd;
			switch (commd[0]) {
			case 'U': spin(0, commd[1]); break;
			case 'D': spin(1, commd[1]); break;
			case 'F': spin(2, commd[1]); break;
			case 'B': spin(3, commd[1]); break;
			case 'L': spin(4, commd[1]); break;
			case 'R': spin(5, commd[1]); break;
			}
		}
		
		for (int i = 1; i <= 9; i++) {
			cout << cube[i];
			if (i % 3 == 0)cout << '\n';
		}
	}
	return 0;
}