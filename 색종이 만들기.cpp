#include <iostream>
using namespace std;
int N;
int map[128][128];

int chk(int n,int color) {
	int cnt = 0;
	for (int R = 0; R < N; R+=n) {
		for (int C = 0; C < N; C+=n) {
			int OK = true;
			for (int r = R; r < R + n; r++) {
				for (int c = C; c < C + n; c++) {
					if (map[r][c] != color) {
						OK = false;
						break;
					}
				}
				if (OK == false)break;
			}
			if (OK == true) {
				for (int r = R; r < R + n; r++)
					for (int c = C; c < C + n; c++)
						map[r][c] = -1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
		}
	}
	int tmp = N;
	int bsum = 0, wsum = 0;
	while (tmp > 0) {
		wsum += chk(tmp, 0);
		bsum += chk(tmp, 1);
		tmp /= 2;
	}
	cout << wsum << '\n' << bsum;
	return 0;
}