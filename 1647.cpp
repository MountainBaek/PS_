#include <iostream>
#include <algorithm>
using namespace std;
struct Edge {
	int v1, v2, cost;
	bool operator < (const Edge& a) const {
		return cost < a.cost;
	}
};

int V, E;
Edge edgelist[1'000'000];
int groupCnt;
int p[100'001];

void init() {
	cin >> V >> E;
	groupCnt = V;

	for (int i = 0; i < E; i++) {
		int v1, v2, cost;
		cin >> v1 >> v2 >> cost;
		edgelist[i] = { v1,v2,cost };
	}

	sort(edgelist, edgelist + E);

	for (int i = 1; i <= V; i++)
		p[i] = i;
}

int findSet(int tar) {
	if (tar == p[tar]) return tar;
	return p[tar] = findSet(p[tar]);
}

void unionSet(int a, int b) {
	int ra = findSet(a);
	int rb = findSet(b);
	if (ra != rb)
		p[rb] = ra;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	
	long long ans = 0;
	for (int i = 0; i < E; i++) {
		if(findSet(edgelist[i].v1) == findSet(edgelist[i].v2))
			continue;
		unionSet(edgelist[i].v1, edgelist[i].v2);
		ans += edgelist[i].cost;
		groupCnt--;
		if (groupCnt == 2) break;
	}
	cout << ans;
	return 0;
}