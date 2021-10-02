#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
queue<int>Q;
int Map[101][101];
int visit[101];
int N, M;
int a, b;
int p, c;

void bfs() {
	while (!Q.empty()) {
		int r = Q.front();
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (Map[r][i] == 1 && visit[i] == -1) {
				visit[i] = visit[r] + 1;
				Q.push(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	memset(visit, -1, sizeof(visit));
	cin >> N;
	cin >> a >> b;
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> p >> c;
		Map[p][c] = Map[c][p] = 1;
	}
	visit[a] = 0;
	Q.push(a);
	bfs();
	cout << visit[b];
}