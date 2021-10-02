#include <iostream>
#include <string>
using namespace std;
char Board[51][51];
int R, C;
int min_cnt = 1e9;
int temp;
int pt1_cnt, pt2_cnt;
string pattern1[8] = { "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW" };
string pattern2[8] = { "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB" };

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C;
	for (int m = 0; m < R; m++) {
		for (int n = 0; n < C; n++) {
			cin >> Board[m][n];
		}
	}

	for (int i = 0; i <= R - 8; i++) {
		for (int j = 0; j <= C - 8; j++) {
			for (int r = 0; r < 8; r++) {
				for (int c = 0; c < 8; c++) {
					if (Board[r + i][c + j] != pattern1[r][c]) pt1_cnt++;
					else if (Board[r + i][c + j] != pattern2[r][c]) pt2_cnt++;
				}
			}
			if (pt1_cnt <= pt2_cnt) temp = pt1_cnt;
			else temp = pt2_cnt;
			if (temp < min_cnt) min_cnt = temp;
			pt1_cnt = 0;
			pt2_cnt = 0;
		}
	}
	cout << min_cnt;
}