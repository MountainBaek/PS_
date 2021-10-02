#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
#define INF INT_MAX
using namespace std;
typedef pair<int, int> pii;

int V, E, S;
int D[20001];
bool sel[20001];
priority_queue<pii> PQ;
vector<pii> adj[300000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> V >> E >> S;

	for (int i = 0; i < E; i++) {
		int v1, v2, val;
		cin >> v1 >> v2 >> val;
		adj[v1].push_back({ val,v2 });
	}

	for (int i = 1; i <= V; i++) {
		D[i] = INF;
	}

	D[S] = 0;
	PQ.push({ 0,S });

	while (!PQ.empty()) {
		pii now = PQ.top();
		int nowIdx = now.second;
		int nowCost = now.first * -1;
		PQ.pop();

		for (auto next : adj[nowIdx]) {
			int nextIdx = next.second;
			int nextCost = next.first;
			if (!sel[nextIdx] && D[nextIdx] > D[nowIdx] + nextCost) {
				D[nextIdx] = D[nowIdx] + nextCost;
				PQ.push({ D[nextIdx] * -1, nextIdx });
			}
		}

		sel[nowIdx] = true;
	}

	for (int i = 1; i <= V; i++) {
		if (D[i] == INF) cout << "INF" << '\n';
		else
			cout << D[i] << '\n';
	}
	return 0;
}