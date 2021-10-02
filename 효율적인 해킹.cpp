#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;
struct info { int idx, cnt; };
int E, V;
vvi child(10001);
int cnt[10001], MAX;
int visit[10001];

void bfs(int s) {
	queue<int>Q;
	Q.push(s);
	visit[s] = s;
	int tmp = 0;
	while (!Q.empty()) {
		int nowIdx = Q.front();
		Q.pop();
		tmp++;
		for (int i = 0; i < child[nowIdx].size(); i++) {
			int nextIdx = child[nowIdx][i];
			if (visit[nextIdx] == s)continue;
			visit[nextIdx] = s;
			Q.push(nextIdx);
		}
	}
	cnt[s] = tmp;
	MAX = max(tmp, MAX);
	
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> E >> V;
	for (int i = 0; i < V; i++) {
		int a, b;
		cin >> a >> b;
		child[b].push_back(a);
	}
	for (int i = 1; i <= E; i++) {
		bfs(i);
	}

	//cout << "MAX : " << MAX << '\n';
	for (int i = 1; i <= E; i++)
		if (cnt[i] == MAX)
			cout << i << ' ';
	return 0;
}