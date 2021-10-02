#include <iostream>
using namespace std;
int N, M;
inline int max(int a, int b) {
	return a < b ? b : a;
}

int map[1000][1000];
int	 dp[1000][1000];

inline bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= M))
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int r = 0; r < N; r++) 
		for (int c = 0; c < M; c++) 
			cin >> map[r][c];
	dp[0][0] = map[0][0];
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (chk(r - 1, c - 1)) {
				dp[r][c] = max(dp[r][c], map[r][c] + dp[r - 1][c - 1]);
			}
			if (chk(r, c - 1)) {
				dp[r][c] = max(dp[r][c], map[r][c] + dp[r][c - 1]);
			}
			if (chk(r - 1, c)) {
				dp[r][c] = max(dp[r][c], map[r][c] + dp[r - 1][c]);
			}
		}
	}
	cout << dp[N - 1][M - 1];
	return 0;
}