#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int info[51][10];
int player[] = { 2,3,4,5,6,7,8,9 };
int N, ans;

void playBall(vector<int> entry) {
	int playerIdx = 0;
	int score = 0;
	for (int i = 1; i <= N; i++) {
		int outCnt = 0;
		int base = 0;
		while (outCnt < 3) {
			int nowRes = info[i][entry[playerIdx++]];
			if (playerIdx == 9) playerIdx = 0;
			switch (nowRes){
			case 0:
				outCnt++;
				break;
			case 1:
				base = base << 1;
				base += 1;
				break;
			case 2:
				base = base << 2;
				base += 2;
				break;
			case 3:
				base = base << 3;
				base += 4;
				break;
			case 4:
				base = base << 4;
				base += 8;
				break;
			}
			int tmp = 120 & base;
			while (tmp) {
				if (tmp % 2 == 1)score++;
				tmp = tmp >> 1;
			}
			base = base & 7;
		}
		
	}
	ans = ans < score ? score : ans;
}


void setOrder(int idx) {
	if (idx == 8) {
		vector<int>entry;
		for (int i = 0; i < 8; i++) {
			entry.push_back(player[i]);
			if (i == 2) entry.push_back(1);
		}
		playBall(entry);
		return;
	}
	for (int i = idx; i < 8; i++) {
		swap(player[i], player[idx]);
		setOrder(idx+1);
		swap(player[i], player[idx]);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int n = 1; n <= 9; n++)
			cin >> info[i][n];
	setOrder(0);
	cout << ans;
	return 0;
}