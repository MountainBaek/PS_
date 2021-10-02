#include <iostream>
using namespace std;
int map[100][100];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		cin >> N >> M;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				cin >> map[r][c];
			}
		}

		int cnt = 0;
		for (int c = 0; c < M; c++) {
			bool go = false;
			for (int r = 0; r < N; r++) {
				if (map[r][c] == 1) {
					for (int rr = r + 1; rr < N; rr++)
						if (map[rr][c] == 0)
							cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}