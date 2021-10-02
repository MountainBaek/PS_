#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
struct pnt {
	int r, c;
	int benefit;
	bool operator==(pnt p) {
		return r == p.r && c == p.c;
	}
};
int map[10][10], visit[10][10], arr[10][10];
int N, M, C, ans;
vector<vector<pnt>>list;

int far[2];
void cal(vector<pnt>sel, int idx, int sum,int benefit,int f) {
	if (sum > C) return;
	if (idx == sel.size()) {
		far[f] = far[f] < benefit ? benefit : far[f];
		return;
	}
	cal(sel, idx + 1, sum + map[sel[idx].r][sel[idx].c], benefit + map[sel[idx].r][sel[idx].c] * map[sel[idx].r][sel[idx].c], f);
	cal(sel, idx + 1, sum, benefit, f);
}
vector<vector<pnt>>farmer;
bool farvist[100];
void sel(int idx,int s) {
	if (idx == 2) {
		for (int i = 0; i < farmer[1].size(); i++)
			if (farmer[1][i] == farmer[0][M - 1])
				return;
		far[0] = far[1] = 0;
		cal(farmer[0], 0, 0, 0, 0);
		cal(farmer[1], 0, 0, 0, 1);
		int tmp = far[0] + far[1];
		ans = ans < tmp ? tmp : ans;
		return;
	}
	else {
		for (int i = s; i < list.size(); i++) {
			if (farvist[i]) continue;
			farvist[i] = true;
			farmer.push_back(list[i]);
			sel(idx + 1, i + 1);
			farmer.pop_back();
			farvist[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> C;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				cin >> map[r][c];
		
		for (int r = 0; r < N; r++) {
			for (int c = 0; c <= N - M; c++) {
				vector<pnt>tmp;
				for (int i = c; i < c + M; i++) {
					tmp.push_back({ r,i });
				}
				list.push_back(tmp);
			}
		}

		sel(0, 0);
		cout << '#' << tc << ' ' << ans << '\n';

		ans = 0;
		memset(visit, 0, sizeof(visit));
		farmer.clear();
		list.clear();
	}
	return 0;
}