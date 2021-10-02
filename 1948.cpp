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
1. �ִ� �Ÿ� ���ͽ�Ʈ�� 
2. finish ������ �������� ��, 
	2.1 �̵� �ð��� �ִ밪���� ũ�� --> �ִ밪 ���� �� ��� ����Ʈ ����
	2.2 �̵� �ð��� �ִ밪�� ���� --> ��� ����Ʈ�� �߰�
	2.3 �̵� �ð��� �ִ밪 ���� �۴� --> ����

3. �ִ밪 ��� �� ��� ����Ʈ�� ���� ��� �� ���� ���� ��� (10�� * ?)
*/