#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char map[100][100];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string in;
	cin >> in;
	int len = in.length();
	int R = 1;
	int C;

	for (int r = 1; r*r <= len; r++)
		if (len%r == 0)
			R = max(R, r);
	C = len / R;

	int idx = 0;
	for (int c = 0; c < C; c++)
		for (int r = 0; r < R; r++)
			map[r][c] = in[idx++];

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			cout << map[r][c];

	return 0;
}