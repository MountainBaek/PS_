#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

int T, V, E;
int visit[20001];
vi adj[20001];

bool isDivide() {
	for (int node1 = 1; node1 <= V; node1++) {
		int size = adj[node1].size();
		for (int i = 0; i < size; i++) {
			int node2 = adj[node1][i];
			if (visit[node1] == visit[node2])
				return false;
		}
	}
	return true;
}

void bfs(int idx) {
	queue<int>Q;
	Q.push(idx);
	visit[idx] = 1;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		int size = adj[now].size();
		for (int i = 0; i < size; i++) {
			int next = adj[now][i];
			if (visit[next] == 0) {
				switch (visit[now]){
				case 1:
					visit[next] = 2;
					break;
				case 2:
					visit[next] = 1;
					break;
				}
				Q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> V >> E;
		//vii adj(V + 1);
		while (E--) {
			int node1, node2;
			cin >> node1 >> node2;
			adj[node1].push_back(node2);
			adj[node2].push_back(node1);
		}
		
		for (int i = 1; i <= V; i++) {
			if (visit[i] == 0) {
				bfs(i);
			}
		}
		
		cout << (isDivide() ? "YES" : "NO") << '\n';
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= V; i++)
			adj[i].clear();
	}
	return 0;
}