#include <iostream>
#include <queue>
using namespace std;
int N, K, INF = 1e9;
int map[100001];
int dir[] = { -1,1 };
queue<int>Q;

void bfs() {
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		int next;
		for (int d = 0; d < 2; d++) {
			next = now + dir[d];
			if (0 <= next && next <= 100000 && map[next] > map[now]) {
				Q.push(next);
				map[next] = map[now] + 1;
				if (next == K) return;
			}
		}
		next = now * 2;
		if (0 <= next && next <= 100000 && map[next] > map[now]) {
			Q.push(next);
			map[next] = map[now] + 1;
			if (next == K) return;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < 100001; i++)
		map[i] = INF;
	map[N] = 0;
	Q.push(N);
	bfs();
	cout << map[K];
	return 0;
}