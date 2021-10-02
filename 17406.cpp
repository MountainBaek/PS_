#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <string.h>
using namespace std;
struct info { int r, c, s; };
int map[51][51];
info cmd[6];
int N, M, K, ans = INT_MAX;


void rotate(int rr, int cc, int len) {
	int r = rr;
	int c = cc;
	int prev = map[r][c];
	int tmp;

	c++;
	while (c < cc + len) {
		tmp = map[r][c];
		map[r][c] = prev;
		prev = tmp;
		c++;
	}
	c--;

	r++;
	while (r < rr + len) {
		tmp = map[r][c];
		map[r][c] = prev;
		prev = tmp;
		r++;
	}
	r--;

	c--;
	while (cc <= c) {
		tmp = map[r][c];
		map[r][c] = prev;
		prev = tmp;
		c--;
	}
	c++;

	r--;
	while (rr <= r) {
		tmp = map[r][c];
		map[r][c] = prev;
		prev = tmp;
		r--;
	}
	r++;
}

void perm(int idx) {
	if (idx == K) {
		int tmp[51][51];
		memcpy(tmp, map, sizeof(tmp));
		for (int i = 0; i < K; i++)
			for (int j = 1; j <= cmd[i].s; j++)
				rotate(cmd[i].r - j, cmd[i].c - j, j*2+1);

		for (int r = 1; r <= N; r++) {
			int sum = 0;
			for (int c = 1; c <= M; c++) 
				sum += map[r][c];
			ans = sum < ans ? sum : ans;
		}
		memcpy(map, tmp, sizeof(tmp));
		return;
	}
	for (int i = 0; i < K; i++) {
		swap(cmd[i], cmd[idx]);
		perm(idx + 1);
		swap(cmd[i], cmd[idx]);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> K;
	for (int r = 1; r <= N; r++) 
		for (int c = 1; c <= M; c++) 
			cin >> map[r][c];
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		cmd[i] = { r,c,s };
	}
	perm(0);

	cout << ans;
	return 0;
}