#include <iostream>
#include <algorithm>
using namespace std;
int map[100000][3];
int maxDP[2][3];
int minDP[2][3];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}

	if (N == 1) {
		int MAX = map[0][0], MIN = map[0][0];
		for (int i = 1; i < 3; i++) {
			MAX = max(MAX, map[0][i]);
			MIN = min(MIN, map[0][i]);
		}
		cout << MAX << ' ' << MIN;
		return 0;
	}

	for (int i = 0; i < 3; i++)
		maxDP[0][i] = minDP[0][i] = map[0][i];
	for (int i = 1; i < N; i++) {
		maxDP[1][0] = max(maxDP[0][0], maxDP[0][1]) + map[i][0];
		maxDP[1][1] = max(max(maxDP[0][0], maxDP[0][1]), maxDP[0][2]) + map[i][1];
		maxDP[1][2] = max(maxDP[0][1], maxDP[0][2]) + map[i][2];
		maxDP[0][0] = maxDP[1][0];
		maxDP[0][1] = maxDP[1][1];
		maxDP[0][2] = maxDP[1][2];

		minDP[1][0] = min(minDP[0][0], minDP[0][1]) + map[i][0];
		minDP[1][1] = min(min(minDP[0][0], minDP[0][1]), minDP[0][2]) + map[i][1];
		minDP[1][2] = min(minDP[0][1], minDP[0][2]) + map[i][2];
		minDP[0][0] = minDP[1][0];
		minDP[0][1] = minDP[1][1];
		minDP[0][2] = minDP[1][2];
	}
	int MAX = maxDP[1][0], MIN = minDP[1][0];
	for (int i = 1; i < 3; i++) {
		MAX = max(maxDP[1][i], MAX);
		MIN = min(minDP[1][i], MIN);
	}
	cout << MAX << ' ' << MIN;
	return 0;
}