#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
struct pnt { int r, c; };
int map[10][10];
vector<pnt>one;
int oneVisit[100];
int Paper[6] = { 0,5,5,5,5,5 };
int oneCnt;
int ans = 987654321;

bool rangeChk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= 10 || c >= 10)) return true;
	return false;
}

void dfs(int dep) {
	int r = -1, c = -1;
	for (register int i = 0; i < one.size(); i++) {
		if (map[one[i].r][one[i].c] == 1) {
			r = one[i].r;
			c = one[i].c;
			break;
		}
	}
	if (r == -1 && c == -1) {
		ans = min(ans, dep);
		return;
	}
	int size = 5;
	while (size > 0) {
		if (rangeChk(r + size-1, c + size-1)) {
			break;
		}
		size--;
	}

	for (int s = size; s > 0; s--) {
		if (Paper[s] == 0) continue;
		bool OK = true;
		for (int rr = r; rr < r + s; rr++) {
			for (int cc = c; cc < c + s; cc++) {
				if (map[rr][cc] != 1) {
					OK = false;
					break;
				}
			}
		}
		if (!OK) continue;
		for (int rr = r; rr < r + s; rr++) {
			for (int cc = c; cc < c + s; cc++) {
				map[rr][cc] = -1;
			}
		}
		Paper[s]--;
		dfs(dep + 1);
		Paper[s]++;
		for (int rr = r; rr < r + s; rr++) {
			for (int cc = c; cc < c + s; cc++) {
				map[rr][cc] = 1;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 10; c++) {
			cin >> map[r][c];
			if (map[r][c] == 1) one.push_back({ r,c });
		}
	}
	oneCnt = one.size();
	dfs(0);
	if (ans == 987654321) ans = -1;
	cout << ans;
	return 0;
}