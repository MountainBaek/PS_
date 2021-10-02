#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;
int map[101][101];
int dist[101];
int N, M;
priority_queue<pair<int, int>>PQ;//first:idx second:°¡ÁßÄ¡
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		int in;
		cin >> in;
		for (int c = 1; c <= M; c++) {
			map[r][c] = in % 10;
			in /= 10;
		}
	}
	for (int i = 1; i <= N; i++)
		dist[i] = INT_MAX;

	return 0;
}