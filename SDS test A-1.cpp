#include <iostream>
#include <cmath>
using namespace std;

int T, N, M;//테스트 케이스, 행, 열
int r1, c1, r2, c2;
struct finish {
	int x, y; // x = r y = c
}F[4];
int min_v = 1e9;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M >> r1 >> c1 >> r2 >> c2;

		if (r1 < r2 && c1 < c2) {
			F[0] = { r2,c2 };
			F[1] = { r2 - N,c2 };
			F[2] = { r2,c2 - M };
			F[3] = { r2 - N,c2 - M };
			for (int i = 0; i < 4; i++) {
				if (min_v > abs(r1 - F[i].x) + abs(c1 - F[i].y)) min_v = abs(r1 - F[i].x) + abs(c1 - F[i].y);
			}
		}
		else if (r1 < r2 && c1 > c2) {
			F[0] = { r2,c2 };
			F[1] = { r2 - N,c2 };
			F[2] = { r2,c2 + M };
			F[3] = { r2 - N,c2 + M };
			for (int i = 0; i < 4; i++) {
				if (min_v > abs(r1 - F[i].x) + abs(c1 - F[i].y)) min_v = abs(r1 - F[i].x) + abs(c1 - F[i].y);
			}
		}
		else if (r1 > r2 && c1 < c2) {
			F[0] = { r2,c2 };
			F[1] = { r2 + N,c2 };
			F[2] = { r2,c2 - M };
			F[3] = { r2 + N,c2 - M };
			for (int i = 0; i < 4; i++) {

				if (min_v > abs(r1 - F[i].x) + abs(c1 - F[i].y)) min_v = abs(r1 - F[i].x) + abs(c1 - F[i].y);

			}
		}
		else if (r1 > r2 && c1 > c2) {
			F[0] = { r2,c2 };
			F[1] = { r2 + N,c2 };
			F[2] = { r2,c2 + M };
			F[3] = { r2 + N,c2 + M };
			for (int i = 0; i < 4; i++) {
				if (min_v > abs(r1 - F[i].x) + abs(c1 - F[i].y)) min_v = abs(r1 - F[i].x) + abs(c1 - F[i].y);
			}
		}
		else if (r1 == r2 && c1 < c2) {
			F[0] = { r2, c2 };
			F[1] = { r2,c2 - M };
			for (int i = 0; i < 2; i++) {
				if (min_v > abs(r1 - F[i].x) + abs(c1 - F[i].y)) min_v = abs(r1 - F[i].x) + abs(c1 - F[i].y);
			}

		}
		else if (r1 == r2 && c1 > c2) {
			F[0] = { r2, c2 };
			F[1] = { r2,c2 + M };
			for (int i = 0; i < 2; i++) {
				if (min_v > abs(r1 - F[i].x) + abs(c1 - F[i].y)) min_v = abs(r1 - F[i].x) + abs(c1 - F[i].y);
			}

		}
		else if (r1 < r2 && c1 == c2) {
			F[0] = { r2, c2 };
			F[1] = { r2 - N,c2 };
			for (int i = 0; i < 2; i++) {
				if (min_v > abs(r1 - F[i].x) + abs(c1 - F[i].y)) min_v = abs(r1 - F[i].x) + abs(c1 - F[i].y);
			}

		}
		else if (r1 > r2 && c1 == c2) {
			F[0] = { r2, c2 };
			F[1] = { r2 + N,c2 };
			for (int i = 0; i < 2; i++) {
				if (min_v > abs(r1 - F[i].x) + abs(c1 - F[i].y)) min_v = abs(r1 - F[i].x) + abs(c1 - F[i].y);
			}

		}
		cout << '#' << t + 1 << ' ' << min_v << '\n';
		min_v = 1e9;
	}
}