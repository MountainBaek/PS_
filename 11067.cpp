#include <iostream>
#include <algorithm>
#include <vector>
#define MAX(a,b) a>b?a:b;
#define MIN(a,b) a<b?a:b;
using namespace std;
struct pnt {
	int x, y;
};
int T, N;

bool cmp(const int &a, const int &b) {
	if (a > b) return true;
	else return false;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		vector<vector<int>>cafe(100005);
		vector<pnt>output;
		output.push_back({ -1, -1 });
		int max_x = -1;
		for (int i = 1; i <= N; i++) {
			int in_x, in_y;
			cin >> in_x >> in_y;
			cafe[in_x].push_back(in_y);
			max_x = MAX(max_x, in_x);
		}
		int min_ = 987654321;
		for (int i = 0; i < cafe[0].size(); i++) {
			min_ = MIN(min_, cafe[0][i]);
		}
		if (min_ != 0) {
			sort(cafe[0].begin(), cafe[0].end(), cmp);
		}
		else {
			sort(cafe[0].begin(), cafe[0].end());
		}
		for (int i = 1; i <= max_x; i++) {
			sort(cafe[i].begin(), cafe[i].end());
		}
		int prev_y = cafe[0][cafe[0].size() - 1];
		for (int i = 1; i <= max_x; i++) {
			int size_ = cafe[i].size();
			if (size_ == 0)continue;
			else {
				if (cafe[i][0] != prev_y) {
					sort(cafe[i].begin(), cafe[i].end(), cmp);
				}
				prev_y = cafe[i][cafe[i].size() - 1];
			}
		}
		for (int i = 0; i <= max_x; i++) {
			if (cafe[i].size() == 0) continue;
			for (int j = 0; j < cafe[i].size(); j++) {
				output.push_back({ i,cafe[i][j] });
			}
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;
			cout << output[num].x << ' ' << output[num].y << '\n';
		}
	}
	return 0;
}