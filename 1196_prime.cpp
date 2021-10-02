#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = INT_MAX;

int V, E;
int cost[100001];
int parent[100001];
bool sel[100001];
vector<pii>list[100001];

void pr() {
	for (int i = 1; i <= V; i++) {
		if (cost[i] == INF) cout << "INF ";
		else cout << cost[i]<<' ';
	}
	cout << endl;
}

int primePQ() {
	int ret = 0;
	
	priority_queue<pii> PQ;
	PQ.push({ 0,1 });//first : cost, second : idx
	for (int v = 1; v <= V; v++) {
		int idx = -1; int minCost = INF;
		while (!PQ.empty()) {
			pii tmp = PQ.top();
			PQ.pop();
			idx = tmp.second;
			if (!sel[idx]) { //우선순위 큐의 top의 정점이 방문되지 않았다면 그 정점은 최소 거리 정점.
				minCost = tmp.first * -1;
				break;
			}
		}

		ret += minCost;
		sel[idx] = true;

		for (auto e : list[idx]) {
			if (sel[e.first]) continue;
			PQ.push({ e.second * -1,e.first });
		}
	}
	
	return ret;
}


int primeNaive() {
	int ret = 0;
	cost[1] = 0;
	for (int v = 1; v <= V; v++) {
		int minCost = INF;
		int idx = -1;

		//선택하지 않은 정점 중 연결코스트(cost)가 제일 작은것 선택
		for (int i = 1; i <= V; i++) {
			if(!sel[i] && cost[i] < minCost){
				minCost = cost[i];
				idx = i;//선택하지 않은 cost배열 원소 중 제일 작은 비용의 정점번호
			}
		}
		
		ret += minCost;
		sel[idx] = true;
		//pr();
		for (auto e : list[idx]) { // 현재 정점(idx)에 연결된 정점들의 비용 업데이트
			if (sel[e.first]) continue;
			cost[e.first] = cost[e.first] > e.second ? e.second : cost[e.first];
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> V >> E;
	
	for (int i = 1; i <= V; i++) {
		cost[i] = INF;
		parent[i] = -1;
	}

	for (int i = 0; i < E; i++) {
		int v1, v2, val;
		cin >> v1 >> v2 >> val;
		list[v1].push_back({ v2,val });
		list[v2].push_back({ v1,val });
	}
	int res = primePQ();
	//int res = primeNaive();
	cout << res << endl;

	return 0;
}