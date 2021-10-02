#include <iostream>
#include <limits.h>
#include <vector>
#include <string.h>
using namespace std;
int N, M, ans = INT_MAX;
int graph[401][401];
bool visit[401];

void dfs(int start, int now, int sum) {
	if (start == now && visit[now]) {
		ans = sum < ans ? sum : ans;
		return;
	}
	if (visit[now]) return;
	if (sum >= ans) return;
	visit[now] = true;
	for (register int next = 1; next <= N; next++) {
		if (graph[now][next] == 0) continue;
		dfs(start, next, sum + graph[now][next]);
	}

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	int tc = 1;
	while (T--) {
		cin >> N >> M;
		for (register int i = 0; i < M; i++) {
			int s, e, c;
			cin >> s >> e >> c;
			graph[s][e] = c;
		}
		for (register int node = 1; node <= N; node++) {
			memset(visit, 0, sizeof(visit));
			dfs(node, node, 0);
		}

		cout << '#' << tc++ << ' ' << (ans==INT_MAX ? -1 : ans)<< '\n';

		ans = INT_MAX;
		memset(visit, 0, sizeof(visit));
		memset(graph, 0, sizeof(graph));

	}
	return 0;
}