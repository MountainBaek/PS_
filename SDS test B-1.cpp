#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
queue<int>Q;
bool Map[10001][10001];
int visit[10001];
int T;
int N, M, K;
void search(int t) {
	while (!Q.empty()) {
		int s = Q.front();
		Q.pop();
		for (int i = 1; i < N + 1; i++) {
			if (Map[s][i] == 1 && visit[i] == -1) {
				Q.push(i);
				visit[i] = visit[s] + 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	memset(visit, -1, sizeof(visit));

	cin >> T;
	for (int t = 1; t < T + 1; t++) {
		cin >> N >> M >> K;
		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			Map[x][y] = 1;
		}
		Q.push(1);

		visit[1] = 0;
		search(t);
		if (visit[N] < 0 || visit[N]>K)	cout << '#' << t << ' ' << -1 << '\n';
		else cout << '#' << t << ' ' << visit[N] << '\n';
		memset(Map, 0, sizeof(Map));
		memset(visit, -1, sizeof(visit));
	}
}