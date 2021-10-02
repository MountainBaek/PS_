#include <iostream>
using namespace std;
int N, R, C, cnt;
int drc[] = { 0,0,1,1,0,1,0,1 };
bool OK;
void dfs(int n, int r, int c) {
	if (OK == true) return;
	if (r == R && c == C) {
		cout << cnt;
		OK = true;
		return;
	}
	if (n == 1) {
		cnt++;
		return;
	}
	if (!(r <= R && R < r + n && c <= C && C < c + n)) {
		cnt += n * n;
		return;
	}
	int size = n / 2;
	for (int d = 0; d < 4; d++)
		dfs(size, r + drc[d] * size, c + drc[d + 4] * size);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> R >> C;
	dfs(2 << N, 0, 0);
	return 0;
}