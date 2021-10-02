/*9663번 N-Queen*/
#include <iostream>
#include <math.h>
using namespace std;
int N, cnt;
int Q_loc[1000000];
bool OK;
bool promising(int r, int c) {//r,c는 현재 놓고 싶은 위치
	if (r == 1) return true;
	else {
		for (int i = 1; i < r; i++) { // i: 현재 놓고 싶은 행의 이전 행들
			if (c == Q_loc[i] || abs(r-i) == abs(c - Q_loc[i])) return false; 
		}
		return true;
	}
}
void put_Q(int now_row) {
	if (OK == true)return;
	if (now_row > N) {
		for (int i = 1; i <= N; i++) {
			cout << Q_loc[i] << '\n';
		}
		OK = true;
	}
	else {
		for (int c = 1; c <= N; c++) {
			if (Q_loc[now_row] == 0 && promising(now_row, c) == true) {
				Q_loc[now_row] = c;
				put_Q(now_row + 1);
				Q_loc[now_row] = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	put_Q(1);
}