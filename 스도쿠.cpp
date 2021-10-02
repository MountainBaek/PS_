#include <iostream>
#include <vector>
using namespace std;
struct pnt { int r, c; };
int map[9][9];
vector<pnt> E;
bool _END_ = false;

bool chk_R(int r, int c, int n) {
	for (register int rr = 0; rr < 9; rr++) {
		if (map[rr][c] == n) return false;
	}
	return true;
}
bool chk_C(int r, int c, int n) {
	for (register int cc = 0; cc < 9; cc++) {
		if (map[r][cc] == n) return false;
	}
	return true;
}
bool chk_33(int r, int c, int n) {
	int sr = (r / 3) * 3;
	int sc = (c / 3) * 3;
	for (register int rr = sr; rr < sr + 3; rr++) {
		for (register int cc = sc; cc < sc + 3; cc++) {
			if (map[rr][cc] == n)
				return false;
		}
	}
	return true;
}

void dfs(int idx) {
	if (_END_ == true) return;
	if (idx == E.size()) {
		for (register int r = 0; r < 9; r++) {
			for (register int c = 0; c < 9; c++) {
				cout << map[r][c] << ' ';
			}
			cout << '\n';
		}
		_END_ = true;
		return;
	}
	else {
		int r = E[idx].r;
		int c = E[idx].c;
		for (register int n = 1; n < 10; n++) {
			if (chk_R(r, c, n) && chk_C(r, c, n) && chk_33(r, c, n)) {
				map[r][c] = n;
				dfs(idx + 1);
				map[r][c] = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (register int r = 0; r < 9; r++) {
		for (register int c = 0; c < 9; c++) {
			cin >> map[r][c];
			if (map[r][c] == 0)
				E.push_back({ r,c });
		}
	}
	dfs(0);
	return 0;
}