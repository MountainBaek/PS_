#include <iostream>
#define min(a,b) a < b ? a : b
#define INF 987654321
#define SIZE 251
using namespace std;
int N, M, Q;
int adj[SIZE][SIZE];
int main() {
	ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
	cin >> N >> M;
	for (register int i = 1; i <= N; i++) {
		for (register int j = 1; j <= N; j++) {
			if (i == j) continue;
			adj[i][j] = INF;
		}
	}
	for (register int i = 0; i < M; i++) {
		int u, v, b;
		cin >> u >> v >> b;
		adj[u][v] = 0;
		adj[v][u] = b == 0 ? 1 : 0;
	}

	for (register int k = 1; k <= N; k++) {
		for (register int i = 1; i <= N; i++) {
			if (i == k)continue;
			for (register int j = 1; j <= N; j++) {
				if (j == i) continue;
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	cin >> Q;
	for (register int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		cout << adj[a][b] << '\n';
	}
	return 0;
}