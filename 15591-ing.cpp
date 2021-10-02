/*15591¹ø MooTube*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
using pii = pair<int, int>; //pair<next node, cost>
int N, Q;
vector<pii>tree[5001];

int bfs(int K,int V) {
	int res = 0;
	vector<bool>visit(N + 1, 0);
	vector<int>min_cost(N + 1, INT_MAX);
	queue<pii>q;
	q.push({V,INT_MAX}); visit[V] = true;
	while (!q.empty()) {
		int now_node = q.front().first;
		int now_cost = q.front().second;
		q.pop(); int size = tree[now_node].size();
		for (auto i : tree[now_node]) {
			int next_node = i.first;
			int next_cost = i.second;
			if (!visit[next_node]) continue;
			q.push({ next_node,next_cost });
			visit[next_node] = true;
			min_cost[next_node] = min_cost[next_node] > now_cost ? now_cost : next_cost;
		}
	}
	for (int i = 1; i < N + 1; i++) res = min_cost[i] >= K ? res + 1 : res;
	return res;
}



int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i < N; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		tree[s].push_back({ e,v });
		tree[e].push_back({ s,v });
	}
	
	for (int i = 0; i < Q; i++) {
		int K, V;
		cin >> K >> V;
		cout << bfs(K, V) << '\n';
	}
	return 0;
}