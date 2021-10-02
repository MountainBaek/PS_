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
			if (!sel[idx]) { //�켱���� ť�� top�� ������ �湮���� �ʾҴٸ� �� ������ �ּ� �Ÿ� ����.
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

		//�������� ���� ���� �� �����ڽ�Ʈ(cost)�� ���� ������ ����
		for (int i = 1; i <= V; i++) {
			if(!sel[i] && cost[i] < minCost){
				minCost = cost[i];
				idx = i;//�������� ���� cost�迭 ���� �� ���� ���� ����� ������ȣ
			}
		}
		
		ret += minCost;
		sel[idx] = true;
		//pr();
		for (auto e : list[idx]) { // ���� ����(idx)�� ����� �������� ��� ������Ʈ
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