#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define vi vector<int>
using namespace std;
struct info {
	int time, path;
};

int V, E, start, finish;
map<int, int> adj[10001];
vector<vi>pathList;
info memo[10001];
priority_queue<pair<int, vi>>PQ;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> V >> E;
	for (register int i = 0; i < E; i++) {
		int v1, v2, t;
		cin >> v1 >> v2 >> t;
		adj[v1].insert({ v2,t });
	}

	cin >> start >> finish;
		
	
	vi tmp;
	tmp.push_back(start);

	PQ.push({ start, tmp});


	for (int i = 1; i <= V; i++) {
		cout <<i<<" : "<< memo[i].time << ' ' << memo[i].path << '\n';
	}
	
	cout << pathList.size();
	return 0;
}

/*
1. 최대 거리 다익스트라 
2. finish 정점에 도착했을 때, 
	2.1 이동 시간이 최대값보다 크다 --> 최대값 갱신 및 경로 리스트 갱신
	2.2 이동 시간이 최대값과 같다 --> 경로 리스트에 추가
	2.3 이동 시간이 최대값 보다 작다 --> 무시

3. 최대값 출력 및 경로 리스트를 통해 사용 된 간선 개수 출력 (10만 * ?)
*/