/*2210번 숫자판 점프*/
#include <iostream>
#include <math.h>
using namespace std;
int input[5][5];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
int check[1000000];
int size_chk;
int temp_num;

void make_num(int num_cnt,int r,int c) {
	if (num_cnt > 6) {
		if (check[temp_num] != 1) {
			check[temp_num] = 1;
			size_chk++;
		}
	}
	else {
		for (int d = 0; d < 4; d++) {
			int nr = r + drc[d];
			int nc = c + drc[d + 4];
			if (!(nr < 0 || nr >= 5 || nc < 0 || nc >= 5)) {
				temp_num = temp_num + input[nr][nc] * pow(10, 6 - num_cnt);
				make_num(num_cnt + 1, nr, nc);
				temp_num = temp_num - input[nr][nc] * pow(10, 6 - num_cnt);
			}
		}
		
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> input[i][j];
		}
	}

	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			temp_num = temp_num + input[r][c] * pow(10, 5);
			make_num(2, r, c);
			temp_num = temp_num - input[r][c] * pow(10, 5);
		}
	}
	cout << size_chk;
}

/*
1 2 3 4 5
5 3 2 1 4
2 3 1 4 5
4 1 2 3 5
3 2 2 1 1

*/
