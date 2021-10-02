#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
using namespace std;
struct pnt { int r, c; };
int map[10][10];
int ans[2];
int N;
set<int>used_hap;
set<int>used_cha;

void put(vector<pnt>V, int idx, int cnt, int color) {
	if (idx == V.size()) {
		ans[color] = ans[color] < cnt ? cnt : ans[color];
		return;
	}
	else {
		int hap = V[idx].r + V[idx].c;
		int cha = V[idx].r - V[idx].c;
		if (!binary_search(used_hap.begin(), used_hap.end(), hap) && !binary_search(used_cha.begin(), used_cha.end(), cha)) {
			used_cha.insert(cha);
			used_hap.insert(hap);
			put(V, idx + 1, cnt + 1, color);

			used_cha.erase(used_cha.find(cha));
			used_hap.erase(used_hap.find(hap));
			put(V, idx + 1, cnt, color);
		}
		else
			put(V, idx + 1, cnt, color);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	vector<pnt>B;
	vector<pnt>W;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
			if (map[r][c] == 1 && (r + c) % 2 == 0) B.push_back({ r,c });
			else if (map[r][c] == 1 && (r + c) % 2 == 1) W.push_back({ r,c });
		}
	}
	put(B, 0, 0, 0);
	put(W, 0, 0, 1);
	cout << ans[0] + ans[1];

	return 0;
}