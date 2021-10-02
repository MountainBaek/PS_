#include <iostream>
#define min(a,b) a<b?a:b
using namespace std;
int adj[501][501];
int conn[501];
int N, M, INF = 987654321;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (register int i = 1; i <= N; i++) {
		for (register int j = 1; j <= N; j++) {
			adj[i][j] = INF;
		}
	}

	for (register int i = 0; i < M; i++) {
		int stu1, stu2;
		cin >> stu1 >> stu2;
		adj[stu1][stu2] = 1;
	}

	for (register int k = 1; k <= N; k++) {
		for (register int i = 1; i <= N; i++) {
			for (register int j = 1; j <= N; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	int ans = 0;
	for (register int i = 1; i <= N; i++) {
		for (register int j = 1; j <= N; j++) {
			if (adj[i][j] != INF) {
				conn[i]++;
				conn[j]++;
				if (conn[i] == N - 1) ans++;
				if (conn[j] == N - 1) ans++;
			}
		}
	}
	cout << ans;
	return 0;
}