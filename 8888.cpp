#include <iostream>
#include <string.h>
using namespace std;
int info[2002][2002],arr[2002][2002];
int score[2002],arr2[2002];
int people[2002][3],arr3[2002][3];// [0]:점수,[1]:푼 문제수,[2]:등수

void Reset() {
	memcpy(info, arr, sizeof(info));
	memcpy(score, arr2, sizeof(score));
	memcpy(people, arr3, sizeof(people));
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;// 참가자 수
		int M;// 문제 수
		int P;// 친구 번호
		cin >> N >> M >> P;

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> info[i][j];
				if (info[i][j] == 0) {
					score[j]++;
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (info[i][j] == 1) {
					people[i][0] += info[i][j] * score[j];
					people[i][1]++;
				}
			}
		}

		int HighScorer = 0;
		int HighSolver = 0;
		int LowNumber = 0;
		for (int j = 1; j <= N; j++) {
			if (j == P)
				continue;
			if (people[P][0] < people[j][0])
				HighScorer++;
			else if (people[P][0] == people[j][0]) {
				if (people[P][1] < people[j][1])
					HighSolver++;
				else if (people[P][1] == people[j][1] && j < P)
					LowNumber++;
			}
		}
		people[P][2] = HighScorer + HighSolver + LowNumber + 1;

		cout << '#' << tc << ' ' << people[P][0] << ' ' << people[P][2] << '\n';
		Reset();
	}
	return 0;
}