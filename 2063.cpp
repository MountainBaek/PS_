#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int T;
int score_[101];
int arr[101];
struct info { int value; int idx; };
info ans;

void reset() {
	memcpy(score_, arr, sizeof(score_));
	ans = { 0,0 };
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		for (int i = 0; i < 1000; i++) {
			int in;
			cin >> in;
			score_[in]++;
		}

		for (int i = 1; i < 101; i++) {
			if (ans.value <= score_[i] && ans.idx < i) {
				ans = { score_[i],i };
			}
		}
		cout << '#' << N << ' ' << ans.idx << '\n';
		reset();
	}
	return 0;
}